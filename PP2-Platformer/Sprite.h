#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GameObject.h"

class Sprite : public GameObject
{
	private:
		sf::Texture texture;
		sf::Sprite sprite;
	public:
		Sprite(std::string ID, std::string FileName);
		~Sprite();

		void Render(sf::RenderWindow* window) override;
		void Update() override;

		void SetValues(sf::Vector2f position);
		void SetValues(sf::Vector2f position, sf::Vector2f size);
};
