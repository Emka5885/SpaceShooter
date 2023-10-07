#include "Bullet.h"
#include "Definitions.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction) : direction(direction)
{
	Init(position);
}

void Bullet::Init(sf::Vector2f position)
{
	shape.setRadius(BULLET_RADIUS);
	shape.setOrigin(BULLET_RADIUS / 2, BULLET_RADIUS / 2);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::White);
}

void Bullet::Move()
{
	shape.move(direction.x * BULLET_SPEED, direction.y * BULLET_SPEED);

	if (shape.getPosition().x < -200 || shape.getPosition().x > WIDTH + 200 || shape.getPosition().y < -200 || shape.getPosition().y > HEIGHT + 200)
	{
		remove = true;
	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

const bool& Bullet::IsToBeRemoved()
{
	return remove;
}
