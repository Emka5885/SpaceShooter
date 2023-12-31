#pragma once
#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Bullet.h"

class Player : public Spaceship
{
private:
	std::vector<Bullet> bullets;
	int health;

	sf::CircleShape collisionCircle;

public:
	Player(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size = { 128, 128 });

	void Attack(sf::Texture* bulletTexture);

	void Move(sf::Vector2f move);
	void Update();

	void BulletsDraw(sf::RenderWindow& window);

	void RemoveOneHeart();

	std::vector<Bullet>& GetBullets();
	const int& GetNumberOfBulletsUsed();
	const int& GetPlayerHealth();
	const sf::CircleShape& GetCollisionCircle();
};