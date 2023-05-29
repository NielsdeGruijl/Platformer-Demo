#pragma once

#include <iostream>
#include "GameObject.h"
#include "Pawn.h"

enum CollisionSide
{
	noCol,
	left,
	right,
	top,
	bottom
};

class AABBCollision
{
	private:
		std::vector<Vector2> intersections;

		CollisionSide colDir;

		Vector2 bRadius;
		float bLeft;
		float bRight;
		float bTop;
		float bBottom;

	public:
		void CalculateIntersection(Pawn* pA, CollisionSide colSide);
		void CheckAABB(Pawn* pA, GameObject* goB);
		void CheckCollisionDirection(Pawn* pA, GameObject* goB);
		void CollisionResponse(Pawn* pA, GameObject* goB);
};