#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Widgets
{
private:
	GameDataReference& data;

	sf::Text numberOfBullets;
	std::vector<sf::RectangleShape> hearts;

public:
	Widgets(GameDataReference& data);

	void Init();

	void SetNewNumberOfFullHearts(const int& number, bool init = false);
	void SetNewNumberOfBullets(const int& number);

	void Draw(sf::RenderWindow& window);
};