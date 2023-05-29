#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Pawn.h"
#include "GameObject.h"
#include "AABBCollision.h"
#include "Player.h"


class Scene
{
	private:
		std::vector<GameObject*> gameObjectsInScene;
		std::vector<Pawn*> physicsObjectsInScene;

		AABBCollision collisionChecker;

	public:
		Scene(std::string ID);
		~Scene();
		
		void Update();
		void Render(sf::RenderWindow* window);
		void AddGameObject(GameObject& objToAdd);

		const std::vector<GameObject*> GetGameObjectsInScene();
};