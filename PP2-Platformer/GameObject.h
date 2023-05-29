#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector2.h"

class Scene;

class GameObject 
{
private:
	const std::string ID;

protected:
	Scene* scene = 0;
	Vector2 goPosition;
	Vector2 goRadius;
public:
	GameObject(std::string ID);
	~GameObject();

	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	void SetScene(Scene* scene);

	std::string GetID();

	virtual void SetPosition(const Vector2 pos);
	Vector2 GetPosition() const;
	Vector2 GetRadius() const;
};