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

int Scene::CheckAABB(Sprite& a, Sprite& b)
{
	if (a.sprite.getPosition().x - b.sprite.getPosition().x > a.xRadius + b.xRadius) return;
	if (a.sprite.getPosition().y - b.sprite.getPosition().y > a.yRadius + b.yRadius) return;
	
	CollisionResponse(a, b);
}

void Scene::CollisionResponse(Sprite& a, Sprite& b)
{

}