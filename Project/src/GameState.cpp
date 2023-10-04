#include "GameState.h"
#include "MainMenuState.h"
#include "Definitions.h"

GameState::GameState(GameDataReference& data) : data(data)
{
}

void GameState::Init()
{
	spaceship = Spaceship(data->assets.GetTexture(spaceship_image), { WIDTH / 2, HEIGHT / 2 }, { 128,128 });

	aliens1.setSize({ 64,64 });
	aliens1.setOrigin(aliens1.getSize().x / 2, aliens1.getSize().y / 2);
	aliens2 = aliens1;
	aliens3 = aliens1;

	aliens1.setTexture(data->assets.GetTexture(aliens_01_image));
	aliens2.setTexture(data->assets.GetTexture(aliens_02_image));
	aliens3.setTexture(data->assets.GetTexture(aliens_03_image));
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

	spaceship.Draw(data->window);

	data->window.display();
}
