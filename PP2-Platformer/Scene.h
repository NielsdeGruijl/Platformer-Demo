#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Pawn.h"
#include "GameObject.h"

enum CollisionSide
{
	noCol,
	left,
	right,
	top,
	bottom
	
};


class Scene
{
	private:
		std::vector<GameObject*> gameObjectsInScene;
		std::vector<Pawn*> physicsObjectsInScene;
		
		CollisionSide colDir;

		bool horizontalParallel, verticalParallel;
		std::vector<Vector2> intersections;
		Vector2 bRadius;
		float bLeft;
		float bRight;
		float bTop;
		float bBottom;
	
	private:
		void CalculateIntersection(Pawn* pA, CollisionSide colSide);
		void HandleIntersection(CollisionSide colSide, float intersectPos);
		void CheckAABB(Pawn* pA, GameObject* goB);
		void CheckCollisionDirection(Pawn* pA, GameObject* goB);
		void CollisionResponse(Pawn* pA, GameObject* goB);

	public:
		Scene(std::string ID);
		~Scene();
		
		void Update();
		void Render(sf::RenderWindow* window);
		void AddGameObject(GameObject& objToAdd);

		const std::vector<GameObject*> GetGameObjectsInScene();
};