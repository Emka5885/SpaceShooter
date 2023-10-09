#include "Widgets.h"
#include "Definitions.h"

Widgets::Widgets()
{
}

Widgets::Widgets(GameDataReference& data)
{
	Init(data);
}

void Widgets::Init(GameDataReference& data)
{
	numberOfBullets = sf::Text("Available bullets: " + std::to_string(MAX_BULLETS), data->assets.GetFont(defaultFont), 30);
	numberOfBullets.setFillColor(sf::Color::White);
	numberOfBullets.setOutlineColor(sf::Color::Black);
	numberOfBullets.setOutlineThickness(2);
	numberOfBullets.setOrigin(numberOfBullets.getGlobalBounds().width / 2, numberOfBullets.getGlobalBounds().height / 2);
	numberOfBullets.setPosition(WIDTH - 50 - numberOfBullets.getGlobalBounds().width / 2, HEIGHT - 50 - numberOfBullets.getGlobalBounds().height / 2);
}

void Widgets::SetNewNumberOfBullets(const int& number)
{
	numberOfBullets.setString("Available bullets: " + std::to_string(MAX_BULLETS - number));
	numberOfBullets.setOrigin(numberOfBullets.getGlobalBounds().width / 2, numberOfBullets.getGlobalBounds().height / 2);
	numberOfBullets.setPosition(WIDTH - 50 - numberOfBullets.getGlobalBounds().width / 2, HEIGHT - 50 - numberOfBullets.getGlobalBounds().height / 2);
}

void Widgets::Draw(sf::RenderWindow& window)
{
	window.draw(numberOfBullets);
}
