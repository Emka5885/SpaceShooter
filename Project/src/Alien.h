#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"

class Alien : public Spaceship
{
private:


public:
	Alien(sf::Texture* texture, sf::Vector2f size = { 64, 64 });

	sf::Vector2f InitPosition();
	void Move(sf::Vector2f move);
	void Update();
};