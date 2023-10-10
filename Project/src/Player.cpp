#include "Player.h"
#include "Definitions.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	this->position = position;
	this->size = size;
	health = MAX_HEALTH;
	Init(texture);
}

void Player::Attack()
{
	if (bullets.size() < MAX_BULLETS)
	{
		sf::Vector2f direction;
		switch (int(shape.getRotation()))
		{
		case 0:
			direction = { 0, -1 };
			break;
		case 45:
			direction = { 1, -1 };
			break;
		case 90:
			direction = { 1, 0 };
			break;
		case 135:
			direction = { 1, 1 };
			break;
		case 180:
			direction = { 0, 1 };
			break;
		case 225:
			direction = { -1, 1 };
			break;
		case 270:
			direction = { -1, 0 };
			break;
		case 315:
			direction = { -1, -1 };
			break;
		}

		bullets.emplace_back(Bullet(shape.getPosition(), direction));
	}
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

	int newPositionX = shape.getPosition().x + move.x * PLAYER_SPEED;
	int newPositionY = shape.getPosition().y + move.y * PLAYER_SPEED;
	if (newPositionX < 0 || newPositionX > WIDTH)
	{
		move.x = 0;
	}
	if (newPositionY < 0 || newPositionY > HEIGHT)
	{
		move.y = 0;
	}

	shape.move({ move.x * PLAYER_SPEED, move.y * PLAYER_SPEED });
}

void Player::Update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Move();
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].IsToBeRemoved())
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::BulletsDraw(sf::RenderWindow& window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}
}

const int& Player::GetNumberOfAvailableBullets()
{
	return bullets.size();
}

const int& Player::GetPlayerHealth()
{
	return health;
}
