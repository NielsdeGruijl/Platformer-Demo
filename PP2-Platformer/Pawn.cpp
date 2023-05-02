#include "Pawn.h"

Pawn::Pawn(std::string ID, std::string FileName)
	: Sprite(ID, FileName)
{

}

Pawn::~Pawn()
{
}

void Pawn::SetPosition(const Vector2 pos)
{
	LastPos = this->goPosition;
	Sprite::SetPosition(pos);
}

Vector2 Pawn::GetLastPosition() const
{
	return LastPos;
}

void Pawn::Move(const Vector2 movement)
{
	LastPos = this->goPosition;
	this->sprite.move(movement.ToSfVector());
	this->goPosition = Vector2(goPosition + movement);
}