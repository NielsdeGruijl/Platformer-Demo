#pragma once

#include "Sprite.h"

class Pawn : public Sprite
{
	private:
		Vector2 lastPos;
		sf::Clock elapsedTime;
		sf::Time lastFrameTimeElapsed;
	public:
		bool isGrounded;
		bool isColliding;
		
		float deltaTime;
	public:
		Pawn(std::string ID, std::string FileName);
		~Pawn();

		void Update() override;

		void SetPosition(const Vector2 pos) override;
		Vector2 GetLastPosition() const;
		void SetLastPosition(const Vector2 newLastPos);

		void Move(const Vector2 movement);

		void CalculateDeltaTime();
};