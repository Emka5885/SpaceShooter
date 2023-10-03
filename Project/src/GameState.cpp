#include "GameState.h"
#include "MainMenuState.h"
#include "Definitions.h"

GameState::GameState(GameDataReference& data) : data(data)
{
}

void GameState::Init()
{
}

void GameState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			data->window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
	}
}

void GameState::Update()
{
	
}

void GameState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);


	data->window.display();
}
