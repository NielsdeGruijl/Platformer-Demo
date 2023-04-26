#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Vector2.h"

class Player : public Sprite
{
	private:
		float moveSpeed;
		Vector2 moveDir;
		sf::Clock elapsedTime;
		sf::Time lastFrameTimeElapsed;
		float deltaTime;
	public:
		Player(std::string ID, std::string FileName, float speed, bool isPhysicsObject);
		~Player();

		void Update() override;

		void Input();
		void Move();
		void CalculateDeltaTime();
};