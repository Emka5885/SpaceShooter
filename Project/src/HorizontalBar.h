#pragma once
#include <SFML/Graphics.hpp>

class HorizontalBar
{
private:
	sf::RectangleShape empty;
	sf::RectangleShape full;

	float onePartOfFull;

public:
	HorizontalBar(sf::Vector2f position, sf::Vector2f size = {250, 30});

	void Init(sf::Vector2f position, sf::Vector2f size);

	void SetNewBarFill(int percent);

	void Draw(sf::RenderWindow& window);
};