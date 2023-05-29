#include "Pawn.h"

Pawn::Pawn(std::string ID, std::string FileName)
	: Sprite(ID, FileName)
{

}

Pawn::~Pawn()
{
}

void Pawn::Update()
{
	CalculateDeltaTime();
}

void Pawn::SetPosition(const Vector2 pos)
{
	Sprite::SetPosition(pos);
}

Vector2 Pawn::GetLastPosition() const
{
	return lastPos;
}

void Pawn::SetLastPosition(const Vector2 newLastPos)
{
	lastPos = newLastPos;
}

void Pawn::Move(const Vector2 movement)
{
	lastPos = this->goPosition;
	
	this->sprite.move(movement.ToSfVector());
	this->goPosition = goPosition + movement;
}

void Pawn::CalculateDeltaTime()
{
	deltaTime = elapsedTime.getElapsedTime().asSeconds() - lastFrameTimeElapsed.asSeconds();
	lastFrameTimeElapsed = elapsedTime.getElapsedTime();

	//std::cout << deltaTime << '\n';
}
