#include "Sprite.h"

Sprite::Sprite(std::string ID, std::string FileName) : GameObject(ID)
{
	this->texture.loadFromFile(FileName);
	this->sprite.setTexture(this->texture);

	//this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2, this->sprite.getGlobalBounds().height / 2);
}

Sprite::~Sprite()
{
	
}

void Sprite::Render(sf::RenderWindow* window) 
{
	window->draw(this->sprite);
}

void Sprite::Update() {

}

void Sprite::SetValues(sf::Vector2f pos) 
{
	this->sprite.setPosition(pos);;
}

void Sprite::SetValues(sf::Vector2f pos, sf::Vector2f size)
{
	this->sprite.setPosition(pos);
	this->sprite.setScale(size);
}