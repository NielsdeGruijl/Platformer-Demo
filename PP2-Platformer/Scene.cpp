#include "Scene.h"

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
	gameObjectsInScene.push_back(&objToAdd);
}