#pragma once

#include <SFML/Graphics.hpp>
#include "Pawn.h"
#include "Vector2.h"

class Player : public Pawn
{
	private:
		float moveSpeed;
		Vector2 moveDir;
		sf::Clock elapsedTime;
		sf::Time lastFrameTimeElapsed;
		float deltaTime;
	public:
		Player(std::string ID, std::string FileName, float speed);
		~Player();

		void Update() override;

		void Input();
		void MovePlayer();
		void CalculateDeltaTime();
};