#include "Vector2.h"
#include <math.h>

Vector2::Vector2() 
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

Vector2::Vector2(sf::Vector2f* vector)
{
	this->x = vector->x;
	this->y = vector->y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator*(float f1)
{
	return Vector2(x * f1, y * f1);
}

float Vector2::GetLength()
{
	return sqrtf(x * x + y * y);
}

void Vector2::Normalize()
{
	float length = GetLength();

	x /= length;
	y /= length;
}

sf::Vector2f Vector2::ToSfVector()
{
	return sf::Vector2f(x, y);
}