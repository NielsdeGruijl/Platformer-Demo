#include <iostream>

#include "Player.h"
#include "Scene.h"

using sf::Keyboard;

Player::Player(std::string ID, std::string FileName) : Pawn(ID, FileName)
{
	this->moveDir = Vector2(0, 0);
	this->knockbackDir = Vector2(0, 0);

	this->gravity = 100;
	this->tempGravity = gravity;
	this->knockbackFalloff = 50;
}

Player::~Player()
{
}

void Player::Update()
{
	Pawn::Update();
	Input();
	MovePlayer();

	//std::cout << isGrounded << '\n';
}

void Player::SetMovementValues(float speed, float jumpForce)
{
	this->moveSpeed = speed;
	this->jumpForce = jumpForce;
}

void Player::Input()
{
	if (isTakingKnockback) return;
	if (Keyboard::isKeyPressed(Keyboard::Space) && isGrounded)
	{
		tempJumpForce = jumpForce;
		isJumping = true;
		isGrounded = false;
		tempGravity = gravity;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		inputDir = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		inputDir = 1;
	}
	else
	{
		inputDir = 0;
	}
}

void Player::Jump()
{

}

void Player::MovePlayer()
{
	moveDir.x = inputDir * moveSpeed * deltaTime;
	
	if (isJumping)
	{
		moveDir.y = -tempJumpForce * deltaTime;
		tempJumpForce -= (gravity * 20) * deltaTime;

		//std::cout << tempJumpForce << '\n';

		if (tempJumpForce <= 0)
			isJumping = false;
	}

	if (!isGrounded && !isJumping)
	{
		moveDir.y = tempGravity * deltaTime;
		tempGravity += (gravity * 15) * deltaTime;
		//std::cout << tempGravity << '\n';
	}
	
	if(isGrounded)
	{
		moveDir.y = 0;
	}

	if (moveDir.GetLength() > 0)
	{
		Move(moveDir);
		sf::Vector2f spritePos = this->sprite.getPosition();
		//std::cout << spritePos.x << ", " << spritePos.y << '\n';
	}

	if (isTakingKnockback)
	{
		Move(knockbackDir * tempKnockback * deltaTime);
		tempKnockback -= knockbackFalloff;
	}
}

void Player::ResetJumpForce()
{
	tempJumpForce = 0;
}

void Player::TakeKnockback(float knockbackForce, Vector2 dir)
{
	tempKnockback = knockbackForce;
	isTakingKnockback = true;
}