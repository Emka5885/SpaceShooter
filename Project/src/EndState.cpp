#include "EndState.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "Definitions.h"

EndState::EndState(GameDataReference& data, int score) : data(data), score(score)
{
}

void EndState::Init()
{
	scoreText = sf::Text(("Your score: " + std::to_string(score)), data->assets.GetFont(defaultFont), 75);
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
	scoreText.setPosition({ WIDTH / 2, 100 });
	scoreText.setFillColor(sf::Color::White);
	scoreText.setOutlineColor(sf::Color(50, 50, 50));
	scoreText.setOutlineThickness(3);
	scoreTextShadow = scoreText;
	scoreTextShadow.setFillColor(scoreText.getOutlineColor());
	scoreTextShadow.setPosition({ WIDTH / 2 + 6, 105 });

	sf::Text buttonsText("Restart", data->assets.GetFont(defaultFont), 50);
	buttonsText.setFillColor(sf::Color::White);
	buttonsText.setOutlineColor(sf::Color(50, 50, 50));
	buttonsText.setOutlineThickness(2);
	sf::Vector2f buttonsSize(250, 100);

	restartButton = Button(buttonsSize, buttonsText, { WIDTH / 2, 305 }, 10);

	buttonsText.setString("Menu");
	mainMenuButton = Button(buttonsSize, buttonsText, { WIDTH / 2, restartButton.GetShape().getPosition().y + 200 }, 10);

	sf::sleep(sf::seconds(0.2));
}

void EndState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		// check menu type
		if (event.type == sf::Event::Closed)
		{
			sf::sleep(sf::seconds(1));
			data->window.close();
		}
		else if (type == restart)
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new GameState(data)), true);
		}
		else if (type == mainMenu)
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
		// clicked
		if (data->input.isButtonClicked(restartButton.GetShape(), sf::Mouse::Left, data->window))
		{
			restartButton.Clicked();
			type = restart;
		}
		else if (data->input.isButtonClicked(mainMenuButton.GetShape(), sf::Mouse::Left, data->window))
		{
			mainMenuButton.Clicked();
			type = mainMenu;
		}
		// hovered
		if (event.type == sf::Event::MouseMoved)
		{
			if (data->input.isButtonHovered(restartButton.GetShape(), data->window))
			{
				restartButton.ChangeHover(true);
			}
			else
			{
				restartButton.ChangeHover(false);
			}

			if (data->input.isButtonHovered(mainMenuButton.GetShape(), data->window))
			{
				mainMenuButton.ChangeHover(true);
			}
			else
			{
				mainMenuButton.ChangeHover(false);
			}
		}
	}
}

void EndState::Update()
{
}

void EndState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	data->window.draw(scoreTextShadow);
	data->window.draw(scoreText);
	restartButton.DrawButton(data->window);
	mainMenuButton.DrawButton(data->window);

	data->window.display();
}
