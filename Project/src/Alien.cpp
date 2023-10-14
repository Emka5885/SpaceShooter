#include "Alien.h"
#include "Definitions.h"
#include <iostream>
#include <cmath>

Alien::Alien(sf::Texture* texture, sf::Vector2f size)
{
	this->size = size;
	this->position = InitPosition();
	Init(texture);
}

sf::Vector2f Alien::InitPosition()
{
	if (rand() % 2 == 0)
	{
		diagonalMovement = true;
	}

	float x, y;
	int random = rand() % 4;
	if (random == 0)
	{
		x = -150;
		y = rand() % HEIGHT;

		endPosition.x = WIDTH + 300;
		if (diagonalMovement)
		{
			endPosition.y = rand() % HEIGHT;
		}
		else
		{
			endPosition.y = y;
		}
	}
	else if (random == 1)
	{
		x = WIDTH + 150;
		y = rand() % HEIGHT;

		endPosition.x = -150;
		if (diagonalMovement)
		{
			endPosition.y = rand() % HEIGHT;
		}
		else
		{
			endPosition.y = y;
		}
	}
	else if (random == 2)
	{
		x = rand() % WIDTH;
		y = -150;

		endPosition.y = HEIGHT + 300;
		if (diagonalMovement)
		{
			endPosition.x = rand() % WIDTH;
		}
		else
		{
			endPosition.x = x;
		}
	}
	else
	{
		x = rand() % WIDTH;
		y = HEIGHT + 150;

		endPosition.y = -150;
		if (diagonalMovement)
		{
			endPosition.x = rand() % WIDTH;
		}
		else
		{
			endPosition.x = x;
		}
	}

	TurnToMove(std::atan2((endPosition.y - y), (endPosition.x - x)) * 180.0 / PI);

	return { x,y };
}

void Alien::TurnToMove(int rotation)
{
	shape.setRotation(rotation + 90);
}

void Alien::Move(sf::Vector2f move)
{
	shape.move((endPosition.x - position.x) / move.x, (endPosition.y - position.y) / move.y);
}

void Alien::Update()
{
	Move({ 800, 800 });

	CheckIfDestroy();
}

void Alien::CheckIfDestroy()
{
	if (endPosition.x / abs(endPosition.x) == 1)
	{
		if (endPosition.y / abs(endPosition.y) == 1)
		{
			if (shape.getPosition().y > endPosition.y || shape.getPosition().x > endPosition.x)
			{
				SetDestroy(true);
			}
		}
		else
		{
			if (shape.getPosition().y < endPosition.y || shape.getPosition().x < endPosition.x)
			{
				SetDestroy(true);
			}
		}
	}
	else
	{
		if (endPosition.y / abs(endPosition.y) == 1)
		{
			if (shape.getPosition().y > endPosition.y || shape.getPosition().x < endPosition.x)
			{
				SetDestroy(true);
			}
		}
		else
		{
			if (shape.getPosition().y < endPosition.y || shape.getPosition().x < endPosition.x)
			{
				SetDestroy(true);
			}
		}
	}
}

void Alien::SetDestroy(bool destroy)
{
	this->destroy = destroy;
}

const bool& Alien::GetDestroy()
{
	return destroy;
}
