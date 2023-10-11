#include "GameState.h"
#include "MainMenuState.h"
#include "Definitions.h"
#include <iostream>

GameState::GameState(GameDataReference& data) : data(data)
{
	widgets = new Widgets(data);
	player = new Player(data->assets.GetTexture(spaceship_image), { WIDTH / 2, HEIGHT / 2 });
	alien1 = new Alien(data->assets.GetTexture(aliens_01_image));
	alien2 = new Alien(data->assets.GetTexture(aliens_02_image));
	alien3 = new Alien(data->assets.GetTexture(aliens_03_image));
}

void GameState::Init()
{
	widgets->SetNewNumberOfFullHearts(player->GetPlayerHealth(), true);
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
		if (data->input.isKeyPressed(sf::Keyboard::Escape))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
		if (data->input.isKeyPressed(sf::Keyboard::Space) && attackClock.getElapsedTime().asSeconds() > 0.1)
		{
			player->Attack();
			attackClock.restart();
		}
	}

	sf::Vector2f move;
	if (data->input.isKeyPressed(sf::Keyboard::W))
	{
		move.y = -1;
	}
	else if (data->input.isKeyPressed(sf::Keyboard::S))
	{
		move.y = 1;
	}
	if (data->input.isKeyPressed(sf::Keyboard::A))
	{
		move.x = -1;
	}
	else if (data->input.isKeyPressed(sf::Keyboard::D))
	{
		move.x = 1;
	}
	player->Move(move);
}

void GameState::Update()
{
	player->Update();
	widgets->SetNewNumberOfBullets(player->GetNumberOfAvailableBullets());
}

void GameState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	player->Draw(data->window);
	player->BulletsDraw(data->window);

	widgets->Draw(data->window);

	data->window.display();
}
