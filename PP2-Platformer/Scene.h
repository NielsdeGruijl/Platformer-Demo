#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sprite.h"
#include "GameObject.h"

class Scene
{
	private:
		std::vector<GameObject*> gameObjectsInScene;
		std::vector<GameObject*> physicsObjectsInScene;
	
	public:
		Scene(std::string ID);
		~Scene();
	
		void OnSceneLoaded();
		void Update();
		void Render(sf::RenderWindow* window);
		void AddGameObject(GameObject& objToAdd);

		int CheckAABB(Sprite& a, Sprite& b);
		void CollisionResponse(Sprite& a, Sprite& b);
};