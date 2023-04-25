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