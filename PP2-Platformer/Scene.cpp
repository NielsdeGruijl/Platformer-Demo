#include "Scene.h"

#include <math.h>

Scene::Scene(std::string ID)
{

}

Scene::~Scene() 
{
	
}

void Scene::OnSceneLoaded() 
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

void Scene::CheckAABB(Pawn* a, GameObject* b)
{	
	if (a->GetPosition().x < b->GetPosition().x + b->GetSize().x && //left collision
		a->GetPosition().x + a->GetSize().x > b->GetPosition().x && //right collision
		a->GetPosition().y < b->GetPosition().y + b->GetSize().y && //top collision
		a->GetPosition().y + a->GetSize().y > b->GetPosition().y)	//bottom collision
	{
		CheckCollisionDirection(a, b);
		CollisionResponse(a, b);
	}
}

enum ColDir
{
	left,
	right,
	top,
	bottom
};

ColDir colDir;

void Scene::CheckCollisionDirection(Pawn* a, GameObject* b) 
{
	Vector2 colDir = a->GetPosition() - a->GetLastPosition();
	Vector2 bLeft = b->GetPosition

}

void Scene::CollisionResponse(Pawn* a, GameObject* b)
{
	switch (colDir)
	{
		case left:
			a->SetPosition(Vector2(b->GetPosition().x + b->GetSize().x, a->GetPosition().y));
			break;
		case right:
			a->SetPosition(Vector2(b->GetPosition().x - a->GetSize().x, a->GetPosition().y));
			break;
		case top:
			a->SetPosition(Vector2(a->GetPosition().x, b->GetPosition().y + b->GetSize().y));
			break;
		case bottom:
			a->SetPosition(Vector2(a->GetPosition().x, b->GetPosition().y - a->GetSize().y));
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