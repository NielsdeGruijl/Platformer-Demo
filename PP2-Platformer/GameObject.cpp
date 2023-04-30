#include "GameObject.h"

GameObject::GameObject(std::string ID) : ID(ID)
{
}

GameObject::~GameObject()
{
}

void GameObject::SetScene(Scene* _scene)
{
	this->scene = _scene;
}

void GameObject::SetPosition(const Vector2 pos)
{
	this->goPosition = pos;
}

Vector2 GameObject::GetPosition() const
{
	return goPosition;
}

Vector2 GameObject::GetSize() const
{
	return goSize;
}

Vector2 GameObject::GetDirection() const
{
	return goDirection;
}