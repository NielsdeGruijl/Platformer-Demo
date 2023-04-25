#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "GameObject.h"

class Scene
{
	private:
		std::vector<GameObject*> gameObjectsInScene;
	
	public:
		Scene(std::string ID);
		~Scene();
	
		void OnSceneLoaded();
		void Update();
		void Render(sf::RenderWindow* window);
		void AddGameObject(GameObject& objToAdd);
};