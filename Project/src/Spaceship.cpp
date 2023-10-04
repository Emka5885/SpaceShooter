#include "Spaceship.h"

Spaceship::Spaceship(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size) : position(position), size(size)
{
	Init(texture);
}

void Spaceship::Init(sf::Texture* texture)
{
	shape.setSize(size);
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	shape.setPosition(position);
	shape.setTexture(texture);
}

void Spaceship::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
