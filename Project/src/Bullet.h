#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::Vector2f position, int rotate, sf::Texture* texture, bool bulletRight = true);

	void Init(sf::Vector2f position, int rotate, sf::Texture* texture);
	void Move();

	void Draw(sf::RenderWindow& window);

	void SetRemoved(bool newRemove);

	const sf::CircleShape& GetShape();
	const bool& IsToBeRemoved();

private:
	sf::CircleShape shape;
	sf::Vector2f direction;
	bool remove = false;
	bool right;
};