#include "Alien.h"
#include "Definitions.h"
#include <iostream>

Alien::Alien(sf::Texture* texture, sf::Vector2f size)
{
	this->size = size;
	this->position = InitPosition();
	Init(texture);
}

sf::Vector2f Alien::InitPosition()
{
	float x = rand() % (WIDTH + 300) - 150;
	float y = rand() % (HEIGHT + 300) - 150;

	return { x,y };
}

void Alien::Move(sf::Vector2f move)
{
	std::cout << "move";
}

void Alien::Update()
{
	std::cout << "update";
}
