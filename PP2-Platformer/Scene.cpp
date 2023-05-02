#include "Scene.h"

#include <math.h>

Scene::Scene(std::string ID)
{
	bLeft = 0;
	bRight = 0;
	bTop = 0;
	bBottom = 0;
}

Scene::~Scene() 
{
	
}

void Scene::Update() 
{
	for (int i = 0; i < gameObjectsInScene.size(); i++) 
	{
		gameObjectsInScene[i]->Update();
	}

	//for (int i = 0; i < physicsObjectsInScene.size(); i++)
	//{
	//	for (int j = 0; j < gameObjectsInScene.size(); j++)
	//	{
	//		if (gameObjectsInScene.at(j) == physicsObjectsInScene.at(i))
	//		{
	//			//std::cout << "Object I is object J" << '\n';
	//			continue;
	//		}

	//		CheckAABB(physicsObjectsInScene.at(i), gameObjectsInScene.at(j));
	//	}
	//}
	
	CheckAABB(physicsObjectsInScene.at(0), gameObjectsInScene.at(1));

	switch (colDir)
	{
		case left:
			std::cout << "colDir left" << '\n';
			break;
		case right:
			std::cout << "colDir right" << '\n';
			break;
		case top:
			std::cout << "colDir top" << '\n';
			break;
		case bottom:
			std::cout << "colDir bottom" << '\n';
			break;
		default:
			std::cout << "no collision" << '\n';
			break;
	}

	
}

void Scene::Render(sf::RenderWindow* window) 
{
	for (int i = 0; i < gameObjectsInScene.size(); i++)
	{
		gameObjectsInScene[i]->Render(window);
	}
}

void Scene::AddGameObject(GameObject& objToAdd) 
{
	if (dynamic_cast<Pawn*>(&objToAdd))
	{
		physicsObjectsInScene.push_back(dynamic_cast<Pawn*>(&objToAdd));
	}

	gameObjectsInScene.push_back(&objToAdd);
	objToAdd.SetScene(this);
}

void Scene::CheckAABB(Pawn* pA, GameObject* goB)
{	
	if (abs(pA->GetPosition().x - goB->GetPosition().x) > pA->GetRadius().x + goB->GetRadius().x) return;
	if (abs(pA->GetPosition().y - goB->GetPosition().y) > pA->GetRadius().y + goB->GetRadius().y) return;

	bRadius = Vector2(goB->GetRadius().x + pA->GetRadius().x, goB->GetRadius().y + pA->GetRadius().y);
	float bTop = goB->GetPosition().y - bRadius.y;
	float bBottom = goB->GetPosition().y + bRadius.y;
	float bLeft = goB->GetPosition().x - bRadius.x;
	float bRight = goB->GetPosition().x + bRadius.x;
	
	CheckCollisionDirection(pA, goB);
	CollisionResponse(pA, goB);
}


void Scene::CheckCollisionDirection(Pawn* pA, GameObject* goB) 
{
	horizontalParallel = false;
	verticalParallel = false;
	intersections.clear();
	Vector2 lastDir = pA->GetPosition() - pA->GetLastPosition();
	bool leftCol = false;
	bool topCol = false;

	// was pawn moving left or right
	
	if (lastDir.x > 0)
	{
		CalculateIntersection(pA, left);
		leftCol = true;
	}
	else if (lastDir.x < 0)
	{
		CalculateIntersection(pA, right);
		leftCol = false;
	}

	if (horizontalParallel) return;

	// was pawn moving up or down
	if (lastDir.y > 0)
	{
		CalculateIntersection(pA, top);
		topCol = true;
	}
	else if (lastDir.y < 0)
	{
		CalculateIntersection(pA, bottom);
		topCol = false;
	}

	if (verticalParallel) return;

	if (intersections.size() > 1)
	{
		Vector2 distance1 = intersections.at(0) - pA->GetLastPosition();
		Vector2 distance2 = intersections.at(1) - pA->GetLastPosition();

		if (distance1.GetLength() < distance2.GetLength())
		{
			if (leftCol)
				colDir = left;
			else
				colDir = right;
		}
		else
		{
			if (topCol)
				colDir = top;
			else
				colDir = bottom;
		}
	}
}

void Scene::CalculateIntersection(Pawn* pA, CollisionSide colSide)
{
	Vector2 p1 = pA->GetLastPosition();
	Vector2 p2 = pA->GetPosition();
	float m, m1, m2, b;
	float intersectPos;
	
	m1 = (p1.y - p2.y);
	m2 = (p1.x - p2.x);

	if (m2 > 0)
		m = m1 / m2;
	else
		m = m1;
	
	b = p2.y - (m * 5);

	if (m1 == 0) horizontalParallel = true;
	if (m2 == 0) verticalParallel = true;

	switch (colSide)
	{
		case left:
			if (verticalParallel)
				return;
			if (horizontalParallel)
				colDir = left;
				return;
			intersectPos = (m * bLeft) + b;
			break;
		case right:
			if (verticalParallel)
				return;
			if (horizontalParallel)
				colDir = right;
				return;
			intersectPos = (m * bRight) + b;
			break;
		case top:
			if (horizontalParallel)
				return;
			if (verticalParallel)
				colDir = top;
				return;
			intersectPos = (bTop - b) / m;
			break;
		case bottom:
			if (horizontalParallel)
				return;
			if (verticalParallel)
				colDir = bottom;
				return;
			intersectPos = (bBottom - b) / m;
			break;
	}
}

void Scene::HandleIntersection(CollisionSide colSide, float intersectPos)
{
	if (intersectPos > bTop && intersectPos < bBottom)
	{
		if(colSide == left)
			intersections.push_back(Vector2(bLeft, intersectPos));
		if(colSide == right)
			intersections.push_back(Vector2(bRight, intersectPos));
	}
	if (intersectPos > bLeft && intersectPos < bRight)
	{
		if(colSide == top)
			intersections.push_back(Vector2(bTop, intersectPos));
		if (colSide == bottom)
			intersections.push_back(Vector2(bBottom, intersectPos));
	}
}

void Scene::CollisionResponse(Pawn* a, GameObject* b)
{
	switch (colDir)
	{
		case left:
			a->SetPosition(Vector2(b->GetPosition().x - b->GetRadius().x - a->GetRadius().x, a->GetPosition().y));
			break;
		case right:
			a->SetPosition(Vector2(b->GetPosition().x + b->GetRadius().x + a->GetRadius().x, a->GetPosition().y));
			break;
		case top:
			a->SetPosition(Vector2(a->GetPosition().x, b->GetPosition().y - b->GetRadius().y - a->GetRadius().y));
			break;
		case bottom:
			a->SetPosition(Vector2(a->GetPosition().x, b->GetPosition().y + b->GetRadius().y + a->GetRadius().y));
			break;
		default:
			std::cout << "Unable to identify collision direction" << '\n';
			break;
	}
}

const std::vector<GameObject*> Scene::GetGameObjectsInScene()
{
	return gameObjectsInScene;
}