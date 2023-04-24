#include "Scene.h"

Scene::Scene()
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
	for (int i = 0; i < listOfGameObjects.size(); i++) 
	{
		listOfGameObjects[i].Update();
	}
}

void Scene::Render(sf::RenderWindow* window) 
{
	for (int i = 0; i < listOfGameObjects.size(); i++)
	{
		listOfGameObjects[i].Render();
	}
}