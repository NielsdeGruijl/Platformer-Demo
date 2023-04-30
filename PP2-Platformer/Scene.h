#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Pawn.h"
#include "GameObject.h"

class Scene
{
	private:
		std::vector<GameObject*> gameObjectsInScene;
		std::vector<Pawn*> physicsObjectsInScene;
	
	public:
		Scene(std::string ID);
		~Scene();
	
		void OnSceneLoaded();
		void Update();
		void Render(sf::RenderWindow* window);
		void AddGameObject(GameObject& objToAdd);

		void CheckAABB(Pawn* a, GameObject*);
		void CheckCollisionDirection(Pawn* a, GameObject* b);
		void CollisionResponse(Pawn* a, GameObject* b);

		const std::vector<GameObject*> GetGameObjectsInScene();
};