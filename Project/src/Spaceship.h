#pragma once
#include <SFML/Graphics.hpp>

class Spaceship
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f size;
	sf::Vector2f position;

public:

	void Init(sf::Texture* texture);

	void Draw(sf::RenderWindow& window);

	sf::RectangleShape& GetShape();

	virtual void Move(sf::Vector2f move) = 0;
};