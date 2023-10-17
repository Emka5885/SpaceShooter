#include "Bullet.h"
#include "Definitions.h"

Bullet::Bullet(sf::Vector2f position, int rotate, sf::Texture* texture, bool bulletRight) : right(bulletRight)
{
	Init(position, rotate, texture);
}

void Bullet::Init(sf::Vector2f position, int rotate, sf::Texture* texture)
{
	shape.setRadius(BULLET_RADIUS);
	shape.setOrigin(BULLET_RADIUS, BULLET_RADIUS);

	switch (rotate)
	{
	case 0:
		direction = { 0, -1 };
		if(right)
			shape.setPosition(position.x + 38, position.y - 20);
		else
			shape.setPosition(position.x - 38, position.y - 20);
		break;
	case 45:
		direction = { 1, -1 };
		if (right)
			shape.setPosition(position.x + 32, position.y + 20);
		else
			shape.setPosition(position.x - 32, position.y - 20);
		break;
	case 90:
		direction = { 1, 0 };
		if (right)
			shape.setPosition(position.x - 20, position.y + 38);
		else
			shape.setPosition(position.x - 20, position.y - 38);
		break;
	case 135:
		direction = { 1, 1 };
		if (right)
			shape.setPosition(position.x - 32, position.y + 20);
		else
			shape.setPosition(position.x + 32, position.y - 20);
		break;
	case 180:
		direction = { 0, 1 };
		if (right)
			shape.setPosition(position.x - 38, position.y + 20);
		else
			shape.setPosition(position.x + 38, position.y + 20);
		break;
	case 225:
		direction = { -1, 1 };
		if (right)
			shape.setPosition(position.x - 32, position.y - 20);
		else
			shape.setPosition(position.x + 32, position.y + 20);
		break;
	case 270:
		direction = { -1, 0 };
		if (right)
			shape.setPosition(position.x - 20, position.y - 38);
		else
			shape.setPosition(position.x - 20, position.y + 38);
		break;
	case 315:
		direction = { -1, -1 };
		if (right)
			shape.setPosition(position.x + 32, position.y - 20);
		else
			shape.setPosition(position.x - 32, position.y + 20);
		break;
	}

	shape.setTexture(texture);
	shape.setRotation(rotate);
}

void Bullet::Move()
{
	shape.move(direction.x * BULLET_SPEED, direction.y * BULLET_SPEED);

	if (shape.getPosition().x < -200 || shape.getPosition().x > WIDTH + 200 || shape.getPosition().y < -200 || shape.getPosition().y > HEIGHT + 200)
	{
		SetRemoved(true);
	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Bullet::SetRemoved(bool newRemove)
{
	remove = newRemove;
}

const sf::CircleShape& Bullet::GetShape()
{
	return shape;
}

const bool& Bullet::IsToBeRemoved()
{
	return remove;
}
