#include "Player.h"
#include "Definitions.h"

Player::Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	this->position = position;
	this->size = size;
	Init(texture);
}

void Player::Move(sf::Vector2f move)
{
	if (move.y == 0)
	{
		if (move.x == -1)
		{
			shape.setRotation(270);
		}
		else if (move.x == 1)
		{
			shape.setRotation(90);
		}
	}
	else if(move.y == -1)
	{
		if (move.x == -1)
		{
			shape.setRotation(315);
		}
		else if (move.x == 1)
		{
			shape.setRotation(45);
		}
		else
		{
			shape.setRotation(0);
		}
	}
	else
	{
		if (move.x == -1)
		{
			shape.setRotation(225);
		}
		else if (move.x == 1)
		{
			shape.setRotation(135);
		}
		else
		{
			shape.setRotation(180);
		}
	}

	shape.move({ move.x * PLAYER_SPEED, move.y * PLAYER_SPEED });
}
