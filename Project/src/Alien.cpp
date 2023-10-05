#include "Alien.h"

Alien::Alien(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	this->position = position;
	this->size = size;
	Init(texture);
}

void Alien::Move()
{
}
