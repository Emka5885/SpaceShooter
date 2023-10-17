#include "Player.h"
#include "Definitions.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	this->position = position;
	this->size = size;
	health = MAX_HEALTH;
	Init(texture);

	collisionCircle.setRadius(size.x / 2);
	collisionCircle.setOrigin(collisionCircle.getRadius(), collisionCircle.getRadius());
	collisionCircle.setPosition(position);
}

void Player::Attack(sf::Texture* bulletTexture)
{
	bullets.emplace_back(Bullet(shape.getPosition(), shape.getRotation(), bulletTexture));
	bullets.emplace_back(Bullet(shape.getPosition(), shape.getRotation(), bulletTexture, false));
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
	collisionCircle.setPosition(shape.getPosition().x, shape.getPosition().y);
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

void Player::RemoveOneHeart()
{
	health--;
}

std::vector<Bullet>& Player::GetBullets()
{
	return bullets;
}

const int& Player::GetNumberOfAvailableBullets()
{
	return bullets.size();
}

const int& Player::GetPlayerHealth()
{
	return health;
}

const sf::CircleShape& Player::GetCollisionCircle()
{
	return collisionCircle;
}
