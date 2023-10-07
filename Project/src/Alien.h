#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"

class Alien : public Spaceship
{
private:


public:
	Alien() {}
	Alien(sf::Texture* texture, sf::Vector2f position = { -150, -150 }, sf::Vector2f size = { 64, 64 });

	void Move();
	void Update();
};