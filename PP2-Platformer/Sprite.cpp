#include "Sprite.h"
#include "Vector2.h"

Sprite::Sprite(std::string ID, std::string FileName) : GameObject(ID)
{
	this->texture.loadFromFile(FileName);
	this->sprite.setTexture(this->texture);

	this->SetSize(Vector2(1, 1));
	this->sprite.setOrigin(xRadius, yRadius);
	this->SetPosition(Vector2(0, 0));
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

void Sprite::SetSize(Vector2 size)
{
	this->sprite.setScale(size.ToSfVector());

	this->xRadius = this->sprite.getGlobalBounds().width / 2;
	this->yRadius = this->sprite.getGlobalBounds().height / 2;

	this->goRadius.x = this->xRadius;
	this->goRadius.y = this->yRadius;
}

void Sprite::SetColor(sf::Color color)
{
	this->sprite.setColor(color);
}

