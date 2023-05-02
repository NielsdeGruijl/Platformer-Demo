#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GameObject.h"

class Sprite : public GameObject
{
	private:
		sf::Texture texture;
	public:	
		bool isPhysicsObject;
		float xRadius;
		float yRadius;
		sf::Sprite sprite;

	public:
		Sprite(std::string ID, std::string FileName);
		~Sprite();

		void Render(sf::RenderWindow* window) override;
		void Update() override;
		void SetPosition(const Vector2 pos) override;

		void SetPos(sf::Vector2f position);
		void SetSize(sf::Vector2f size);
};
