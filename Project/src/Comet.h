#pragma once
#include <SFML/Graphics.hpp>

class Comet
{
private:
	sf::RectangleShape shape;
	int x, y;

	bool destroy = false;

public:
	Comet(sf::Texture* texture);

	void Init(sf::Texture* texture);
	void Update();
	void Draw(sf::RenderWindow& window);

	void CheckIfDestroy();

	bool& GetDestroy ();
};