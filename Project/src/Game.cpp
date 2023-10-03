#include "Game.h"
#include "Definitions.h"
#include "MainMenuState.h"

void Game::Init()
{
	data->backgroundImage.setSize({ WIDTH, HEIGHT });
	data->backgroundImage.setTexture(data->assets.GetTexture(background));

	srand(time(NULL));
	data->window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close | sf::Style::Titlebar);
	data->window.setFramerateLimit(60);

	data->machine.AddState(stateReference(new MainMenuState(data)), true);
}


void Game::Run()
{
	float newTime, frameTime;

	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->data->window.isOpen())
	{
		this->data->machine.ProcessStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->data->machine.GetActiveState()->HandleInput();

			if (!this->data->window.isOpen())
			{
				return;
			}

			this->data->machine.GetActiveState()->Update();

			accumulator -= dt;
		}
		this->data->machine.GetActiveState()->Draw();
	}
}