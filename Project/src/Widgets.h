#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Widgets
{
private:
	sf::Text numberOfBullets;


public:
	Widgets();
	Widgets(GameDataReference& data);

	void Init(GameDataReference& data);

	void SetNewNumberOfBullets(const int& number);

	void Draw(sf::RenderWindow& window);
};