#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"

class Player : public Spaceship
{
private:


public:
	Player() {}
	Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size = { 128, 128 });

	void Move(sf::Vector2f move);
};