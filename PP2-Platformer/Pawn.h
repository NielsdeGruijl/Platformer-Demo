#pragma once

#include "Sprite.h"

class Pawn : public Sprite
{
	private:
		Vector2 LastPos;
	public:

	public:
		Pawn(std::string ID, std::string FileName);
		~Pawn();

		void SetPosition(const Vector2 pos) override;
		Vector2 GetLastPosition() const;

		void Move(const Vector2 movement);
};