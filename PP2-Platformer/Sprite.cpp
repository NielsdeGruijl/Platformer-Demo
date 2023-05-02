#include "Sprite.h"
#include "Vector2.h"

Sprite::Sprite(std::string ID, std::string FileName) : GameObject(ID)
{
	this->texture.loadFromFile(FileName);
	this->sprite.setTexture(this->texture);

	this->SetSize(sf::Vector2f(1, 1));
	this->SetPos(sf::Vector2f(0, 0));
}

Sprite::~Sprite()
{
	
}

void Sprite::Render(sf::RenderWindow* window) 
{
	window->draw(this->sprite);
}

void Sprite::Update() 
{
}

void Sprite::SetPosition(const Vector2 pos)
{
	GameObject::SetPosition(pos);
	this->sprite.setPosition(pos.ToSfVector());
	
}

void Sprite::SetPos(sf::Vector2f pos) 
{
	this->sprite.setPosition(pos);

	this->goPosition = Vector2(&pos);
}

void Sprite::SetSize(sf::Vector2f size)
{
	this->sprite.setScale(size);

	this->xRadius = this->sprite.getGlobalBounds().width / 2;
	this->yRadius = this->sprite.getGlobalBounds().height / 2;
	this->sprite.setOrigin(xRadius, yRadius);

	this->goRadius.x = this->xRadius;
	this->goRadius.y = this->yRadius;
}

