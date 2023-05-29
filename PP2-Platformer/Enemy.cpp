#include "Enemy.h"

Enemy::Enemy(std::string ID, std::string FileName, int leftBoundary, int rightBoundary) : Pawn(ID, FileName)
{
	this->leftBoundary = leftBoundary;
	this->rightBoundary = rightBoundary;

	moveDir = Vector2(1, 0);
	moveSpeed = 200;
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	Pawn::Update();
	Walk();
}

void Enemy::Walk()
{
	Move(moveDir * moveSpeed * deltaTime);

	if (goPosition.x - (sprite.getGlobalBounds().width / 2) <= leftBoundary || goPosition.x + (sprite.getGlobalBounds().width / 2) >= rightBoundary)
	{
		moveDir = moveDir * -1;
	}
}