#include "Scene.h"

#include <math.h>

Scene::Scene(std::string ID)
{
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

	for (int i = 0; i < physicsObjectsInScene.size(); i++)
	{
		if (physicsObjectsInScene.at(i)->GetID() == "Player")
		{
			dynamic_cast<Player*>(physicsObjectsInScene.at(i))->isGrounded = false;
		}
		for (int j = 0; j < gameObjectsInScene.size(); j++)
		{
			if (gameObjectsInScene.at(j) == physicsObjectsInScene.at(i))
			{
				continue;
			}

			collisionChecker.CheckAABB(physicsObjectsInScene.at(i), gameObjectsInScene.at(j));
		}
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

const std::vector<GameObject*> Scene::GetGameObjectsInScene()
{
	return gameObjectsInScene;
}