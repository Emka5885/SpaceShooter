#include "HorizontalBar.h"

HorizontalBar::HorizontalBar(sf::Vector2f position, sf::Vector2f size)
{
	Init(position, size);
}

void HorizontalBar::Init(sf::Vector2f position, sf::Vector2f size)
{
	onePartOfFull = size.x / 100;

	empty.setFillColor(sf::Color(15, 15, 15));
	empty.setSize(size);
	empty.setOutlineColor(sf::Color(50, 50, 50));
	empty.setOutlineThickness(5);
	empty.setOrigin(size.x / 2, size.y / 2);
	empty.setPosition(position);

	full.setFillColor(sf::Color(160, 230, 255));
	full.setPosition(position.x - size.x / 2, position.y - size.y / 2);

	SetNewBarFill(100);
}

void HorizontalBar::SetNewBarFillColor(sf::Color color)
{
	full.setFillColor(color);
}

void HorizontalBar::SetNewBarFill(int percent)
{
	full.setSize({ onePartOfFull * percent, empty.getSize().y });
}

void HorizontalBar::Draw(sf::RenderWindow& window)
{
	window.draw(empty);
	window.draw(full);
}
