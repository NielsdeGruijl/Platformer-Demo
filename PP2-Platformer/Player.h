#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Player : public Sprite
{
	private:
	
	public:
		Player(std::string ID, std::string FileName);
		~Player();

		void Input();
};