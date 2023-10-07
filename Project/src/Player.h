#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Bullet.h"

class Player : public Spaceship
{
private:
	std::vector<Bullet> bullets;

public:
	Player() {}
	Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size = { 128, 128 });

	void Attack();

	void Move(sf::Vector2f move);
	void Update();

	void BulletsDraw(sf::RenderWindow& window);
};