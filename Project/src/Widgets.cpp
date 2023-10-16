#include "Widgets.h"
#include "Definitions.h"


Widgets::Widgets(GameDataReference& data) : data(data)
{
	Init();
}

void Widgets::Init()
{
	numberOfBullets = sf::Text("Available bullets: " + std::to_string(MAX_BULLETS), data->assets.GetFont(defaultFont), 30);
	numberOfBullets.setFillColor(sf::Color::White);
	numberOfBullets.setOutlineColor(sf::Color::Black);
	numberOfBullets.setOutlineThickness(2);
	numberOfBullets.setOrigin(numberOfBullets.getGlobalBounds().width / 2, numberOfBullets.getGlobalBounds().height / 2);
	numberOfBullets.setPosition(WIDTH / 2, HEIGHT - 75 - numberOfBullets.getGlobalBounds().height / 2);

	scoreText = sf::Text("Score: 0", data->assets.GetFont(defaultFont), 50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOutlineColor(sf::Color::Black);
	scoreText.setOutlineThickness(2);
	scoreText.setOrigin(scoreText.getGlobalBounds().width, scoreText.getGlobalBounds().height);
	scoreText.setPosition(WIDTH - 50, 65);
}

void Widgets::SetNewNumberOfFullHearts(const int& number, bool init)
{
	if (number >= 0)
	{
		if (init)
		{
			sf::RectangleShape heart({ 50, 50 });
			heart.setOrigin(heart.getSize().x / 2, heart.getSize().y / 2);
			heart.setTexture(data->assets.GetTexture(healthFull_image));

			for (int i = 0; i < number; i++)
			{
				heart.setPosition(25 + 60 * i + heart.getSize().x / 2, 25 + heart.getSize().y / 2);
				hearts.emplace_back(heart);
			}
		}
		else
		{
			hearts[number].setTexture(data->assets.GetTexture(healthEmpty_image));
		}
	}
}

void Widgets::SetNewNumberOfBullets(const int& number)
{
	numberOfBullets.setString("Available bullets: " + std::to_string(MAX_BULLETS - number));
	numberOfBullets.setOrigin(numberOfBullets.getGlobalBounds().width / 2, numberOfBullets.getGlobalBounds().height / 2);
	numberOfBullets.setPosition(WIDTH / 2, HEIGHT - 75 - numberOfBullets.getGlobalBounds().height / 2);
}

void Widgets::SetNewScore(const int& score)
{
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setOrigin(scoreText.getGlobalBounds().width, scoreText.getGlobalBounds().height);
	scoreText.setPosition(WIDTH - 50, 65);
}

void Widgets::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < hearts.size(); i++)
	{
		window.draw(hearts[i]);
	}

	window.draw(scoreText);
	window.draw(numberOfBullets);
}
