#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "HorizontalBar.h"

class Widgets
{
private:
	GameDataReference& data;

	sf::Text numberOfBullets;
	std::vector<sf::RectangleShape> hearts;
	sf::Text scoreText;
	int score = 0;

	int coolingSystemBarFill = 100;

	HorizontalBar* coolingSystemBar;

public:
	Widgets(GameDataReference& data);

	void Init();

	void SetNewNumberOfFullHearts(const int& number, bool init = false);
	void SetNewCoolingSystemBarFill(const int& percent);
	void SetNewCoolingSystemBarFillColor(sf::Color color = sf::Color(160, 230, 255));
	void SetNewScore(const int& score);

	void Draw(sf::RenderWindow& window);

	const int& GetScore();
	const int& GetCoolingSystemBarFill();
};