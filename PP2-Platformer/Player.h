#pragma once

#include <SFML/Graphics.hpp>
#include "Pawn.h"
#include "Vector2.h"

class Player : public Pawn
{
	private:
		float inputDir = 0;
		float moveSpeed = 0;
		float jumpForce = 0;
		float tempJumpForce = 0;
		float gravity = 0;
		float tempGravity = 0;
		float tempKnockback = 0;
		float knockbackFalloff;

		bool isTakingKnockback = false;
		bool isJumping = false;
		
		Vector2 moveDir;
		Vector2 knockbackDir;
	public:
		Player(std::string ID, std::string FileName);
		~Player();

		void Update() override;

		void SetMovementValues(float speed, float jumpForce);

		void Input();
		void MovePlayer();
		void Jump();
		void ResetJumpForce();
		void TakeKnockback(float knockbackForce, Vector2 dir);
};