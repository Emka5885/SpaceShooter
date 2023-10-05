#include "Spaceship.h"

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

sf::RectangleShape& Spaceship::GetShape()
{
	return shape;
}
