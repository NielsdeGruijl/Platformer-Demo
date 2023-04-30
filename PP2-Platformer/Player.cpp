#include <iostream>

#include "Player.h"
#include "Scene.h"


using sf::Keyboard;

Player::Player(std::string ID, std::string FileName, float _speed) 
	: Pawn(ID, FileName), moveSpeed(_speed)
{
	this->moveDir = Vector2(0, 0);
	this->goDirection = this->moveDir;
}

Player::~Player()
{
}

void Player::Update()
{
	CalculateDeltaTime();
	Input();
	MovePlayer();
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

void Player::MovePlayer()
{
	moveDir.Normalize();

	Vector2 dir = moveDir * moveSpeed * deltaTime;
	this->goDirection = this->moveDir;

	if (dir.GetLength() > 0) 
	{
		Move(dir);
		sf::Vector2f spritePos = this->sprite.getPosition();
	}
	//std::cout << this->sprite.getPosition().x << this->sprite.getPosition().y << '\n';
}

void Player::CalculateDeltaTime()
{
	deltaTime = elapsedTime.getElapsedTime().asSeconds() - lastFrameTimeElapsed.asSeconds();
	lastFrameTimeElapsed = elapsedTime.getElapsedTime();

	//std::cout << deltaTime << '\n';
}