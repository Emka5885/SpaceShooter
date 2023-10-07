#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::Vector2f position, sf::Vector2f direction);

	void Init(sf::Vector2f position);
	void Move();

	void Draw(sf::RenderWindow& window);

	const bool& IsToBeRemoved();

private:
	sf::CircleShape shape;
	sf::Vector2f direction;
	bool remove = false;
};