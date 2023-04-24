#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "GameObject.h"

class Scene
{
private:
	std::vector<GameObject> listOfGameObjects;

public:
	Scene();
	~Scene();

	void OnSceneLoaded();
	void Update();
	void Render(sf::RenderWindow* window);

	void InitializeGameObjects();
};