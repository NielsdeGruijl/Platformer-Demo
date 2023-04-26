#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Scene;

class GameObject 
{
private:
	const std::string ID;
	Scene* scene;
public:
	GameObject(std::string ID, bool isPhysicsObject);
	~GameObject();

public:
	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	void SetScene(Scene* scene);
};