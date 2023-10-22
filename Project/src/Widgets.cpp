#include "Widgets.h"
#include "Definitions.h"


Widgets::Widgets(GameDataReference& data) : data(data)
{
	coolingSystemBar = new HorizontalBar({ WIDTH / 2, HEIGHT - 100 });
	Init();
}

void Widgets::Init()
{
	numberOfBullets = sf::Text("Laser cooling system", data->assets.GetFont(defaultFont), 18);
	numberOfBullets.setFillColor(sf::Color::White);
	numberOfBullets.setOutlineColor(sf::Color::Black);
	numberOfBullets.setOutlineThickness(2);
	numberOfBullets.setOrigin(numberOfBullets.getGlobalBounds().width / 2, numberOfBullets.getGlobalBounds().height / 2);
	numberOfBullets.setPosition(WIDTH / 2, HEIGHT - 50 - numberOfBullets.getGlobalBounds().height / 2);

	scoreText = sf::Text("Score: " + std::to_string(score), data->assets.GetFont(defaultFont), 50);
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

void Widgets::SetNewCoolingSystemBarFill(const int& percent)
{
	coolingSystemBarFill = percent;
	coolingSystemBar->SetNewBarFill(coolingSystemBarFill);
}

void Widgets::SetNewScore(const int& score)
{
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setOrigin(scoreText.getGlobalBounds().width, scoreText.getGlobalBounds().height);
	scoreText.setPosition(WIDTH - 50, 65);
	this->score = score;
}

void Widgets::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < hearts.size(); i++)
	{
		window.draw(hearts[i]);
	}

	window.draw(scoreText);

	coolingSystemBar->Draw(data->window);
	window.draw(numberOfBullets);
}

const int& Widgets::GetScore()
{
	return score;
}

void Widgets::SetNewCoolingSystemBarFillColor(sf::Color color)
{
	coolingSystemBar->SetNewBarFillColor(color);
}

const int& Widgets::GetCoolingSystemBarFill()
{
	return coolingSystemBarFill;
}
