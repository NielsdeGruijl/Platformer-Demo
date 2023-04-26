#include "Player.h"
#include <iostream>


using sf::Keyboard;

Player::Player(std::string ID, std::string FileName, float _speed, bool _isPhysicsObject) 
	: Sprite(ID, FileName, _isPhysicsObject), moveSpeed(_speed)
{
}

Player::~Player()
{
}

void Player::Update()
{
	CalculateDeltaTime();
	Input();
	Move();
}

void Player::Input()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		moveDir.y = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		moveDir.y = 1;
	}
	else
	{
		moveDir.y = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		moveDir.x = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		moveDir.x = 1;
	}
	else
	{
		moveDir.x = 0;
	}
}

void Player::Move()
{
	moveDir.Normalize();

	Vector2 dir = moveDir * moveSpeed * deltaTime;

	if (dir.GetLength() > 0) 
	{
		this->sprite.move(dir.ToSfVector());
	}
	

	//std::cout << this->sprite.getPosition().x << this->sprite.getPosition().y << '\n';
}

void Player::CalculateDeltaTime()
{
	deltaTime = elapsedTime.getElapsedTime().asSeconds() - lastFrameTimeElapsed.asSeconds();
	lastFrameTimeElapsed = elapsedTime.getElapsedTime();

	std::cout << deltaTime << '\n';
}