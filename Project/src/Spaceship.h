#pragma once
#include <SFML/Graphics.hpp>

class Spaceship
{
private:
	sf::RectangleShape shape;
	sf::Vector2f size;
	sf::Vector2f position;

public:
	Spaceship() {}
	Spaceship(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size = {128, 128});

	void Init(sf::Texture* texture);

	void Draw(sf::RenderWindow& window);

	sf::RectangleShape& GetShape();
};