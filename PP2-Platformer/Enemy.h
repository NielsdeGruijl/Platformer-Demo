#pragma once
#include "Pawn.h"

class Enemy : public Pawn
{
	private:
		int leftBoundary, rightBoundary;
		Vector2 moveDir;
		float moveSpeed;
	public:
		Enemy(std::string ID, std::string FileName, int leftBoundary, int rightBoundary);
		~Enemy();
		
		void Update() override;
		void Walk();
};