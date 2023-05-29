#include "AABBCollision.h"
#include "Player.h"
#include "Enemy.h"

void AABBCollision::CheckAABB(Pawn* pA, GameObject* goB)
{
	Vector2 goPos = goB->GetPosition();
	Vector2 goRadius = goB->GetRadius();
	Vector2 pawnPos = pA->GetPosition();
	Vector2 pawnRadius = pA->GetRadius();

	if (abs(pawnPos.x - goPos.x) > pawnRadius.x + goRadius.x) return;
	if (abs(pawnPos.y - goPos.y) > pawnRadius.y + goRadius.y) return;

	bRadius = Vector2(goRadius.x + pawnRadius.x, goRadius.y + pawnRadius.y);
	bTop = goPos.y - bRadius.y;
	bBottom = goPos.y + bRadius.y;
	bLeft = goPos.x - bRadius.x;
	bRight = goPos.x + bRadius.x;

	CheckCollisionDirection(pA, goB);
 	CollisionResponse(pA, goB);
}


void AABBCollision::CheckCollisionDirection(Pawn* pA, GameObject* goB)
{
	intersections.clear();
	Vector2 pawnLastPos = pA->GetLastPosition();
	Vector2 objectPos = goB->GetPosition();

	if (pawnLastPos.x > bLeft && pawnLastPos.x < bRight && (pawnLastPos.y < bTop || pawnLastPos.y > bBottom))
	{
		if (pawnLastPos.y < objectPos.y)
			colDir = top;
		else
			colDir = bottom;
	}
	else if (pawnLastPos.y > bTop && pawnLastPos.y < bBottom && (pawnLastPos.x <= bLeft || pawnLastPos.x >= bRight))
	{
		if (pawnLastPos.x < objectPos.x)
			colDir = left;
		else
			colDir = right;
	}
	else
	{
		bool leftCol = false, topCol = false;

		if (pawnLastPos.x < objectPos.x)
		{
			CalculateIntersection(pA, left);
			leftCol = true;
		}
		else
		{
			CalculateIntersection(pA, right);
		}

		if (pawnLastPos.y < objectPos.y)
		{
			topCol = true;
			CalculateIntersection(pA, top);
		}
		else
		{
			CalculateIntersection(pA, bottom);
		}

		Vector2 distance1 = intersections.at(0) - pawnLastPos;
		Vector2 distance2 = intersections.at(1) - pawnLastPos;

		float dist1 = distance1.GetLength();
		float dist2 = distance2.GetLength();

		if (dist1 < dist2)
		{
			if (leftCol)
				colDir = left;
			else
				colDir = right;
		}
		else
		{
			if (topCol)
				colDir = top;
			else
				colDir = bottom;
		}
	}
}

void AABBCollision::CalculateIntersection(Pawn* pA, CollisionSide colSide)
{
	Vector2 p1 = pA->GetLastPosition();
	Vector2 p2 = pA->GetPosition();
	float m, m1, m2, b;
	float intersectPos;

	m1 = (p1.y - p2.y);
	m2 = (p1.x - p2.x);
	m = m1 / m2;

	b = p2.y - (m * p2.x);

	switch (colSide)
	{
		case left:
			intersectPos = (m * bLeft) + b;
			intersections.push_back(Vector2(bLeft, intersectPos));
			break;
		case right:
			intersectPos = (m * bRight) + b;
			intersections.push_back(Vector2(bRight, intersectPos));
			break;
		case top:
			intersectPos = (bTop - b) / m;
			intersections.push_back(Vector2(intersectPos, bTop));
			break;
		case bottom:
			intersectPos = (bBottom - b) / m;
			intersections.push_back(Vector2(intersectPos, bBottom));
			break;
	}
}

void AABBCollision::CollisionResponse(Pawn* a, GameObject* b)
{
	Player* player = dynamic_cast<Player*>(a);
	Vector2 pawnPos = a->GetPosition();
	bool playerEnemyCol = false;

	if (a->GetID() == "Player" && b->GetID() == "Enemy")
	{
		playerEnemyCol = true;
	}

	switch (colDir)
	{
		case left:
			a->SetPosition(Vector2(bLeft, pawnPos.y));
			a->SetLastPosition(Vector2(bLeft - 1, pawnPos.y));
			if (playerEnemyCol)
			{
				player->TakeKnockback(500, Vector2(-1, 0));
			}
			break;
		case right:
			a->SetPosition(Vector2(bRight, pawnPos.y));
			a->SetLastPosition(Vector2(bRight + 1, pawnPos.y));
			if (playerEnemyCol)
			{
				player->TakeKnockback(500, Vector2(1, 0));
			}
			break;
		case top:
			if(!a->isGrounded)
				a->isGrounded = true;

			a->SetPosition(Vector2(pawnPos.x, bTop));
			a->SetLastPosition(Vector2(pawnPos.x, bTop - 1));
			//std::cout << "topCol" << a->isGrounded << '\n';
			break;
		case bottom:
			a->SetPosition(Vector2(pawnPos.x, bBottom));
			a->SetLastPosition(Vector2(pawnPos.x, bBottom + 1));

			if (a->GetID() == "Player")
			{
				player->ResetJumpForce();
			}
			break;
		default:
			std::cout << "Unable to identify collision direction" << '\n';
			break;
	}
}