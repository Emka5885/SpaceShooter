#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	this->position = position;
	this->size = size;
	Init(texture);
}

void Player::Move()
{
}
