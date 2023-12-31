#include "GameState.h"
#include "MainMenuState.h"
#include "EndState.h"
#include "Definitions.h"
#include <iostream>

GameState::GameState(GameDataReference& data) : data(data)
{
	data->window.setMouseCursorVisible(false);
	data->audio.PlayMusic();

	widgets = new Widgets(data);
	player = new Player(data->assets.GetTexture(spaceship_image), { WIDTH / 2, HEIGHT / 2 });

	int alienTexture = rand() % 3;
	if (alienTexture == 0)
	{
		aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_01_image)));
	}
	else if (alienTexture == 1)
	{
		aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_02_image)));
	}
	else
	{
		aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_03_image)));
	}
	newAlienClock.restart();
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
		if (data->input.isKeyPressed(sf::Keyboard::Space))
		{
			if (!restartCoolingSystemFromZero)
			{
				if (!spacePressed)
				{
					coolingSystemClock.restart();
					restartCoolingSystemFromZero = false;
					coolingSystemMustWork = true;
				}
				spacePressed = true;
				if (attackClock.getElapsedTime().asSeconds() > 0.1)
				{
					int randomBullet = rand() % 10;
					switch (randomBullet)
					{
					case 0:
						player->Attack(data->assets.GetTexture(bullet_01_image));
						break;
					case 1:
						player->Attack(data->assets.GetTexture(bullet_02_image));
						break;
					case 2:
						player->Attack(data->assets.GetTexture(bullet_03_image));
						break;
					case 3:
						player->Attack(data->assets.GetTexture(bullet_04_image));
						break;
					case 4:
						player->Attack(data->assets.GetTexture(bullet_05_image));
						break;
					case 5:
						player->Attack(data->assets.GetTexture(bullet_06_image));
						break;
					case 6:
						player->Attack(data->assets.GetTexture(bullet_07_image));
						break;
					case 7:
						player->Attack(data->assets.GetTexture(bullet_08_image));
						break;
					case 8:
						player->Attack(data->assets.GetTexture(bullet_09_image));
						break;
					case 9:
						player->Attack(data->assets.GetTexture(bullet_10_image));
						break;
					}
					attackClock.restart();
				}
			}
		}
		else if (data->input.isKeyReleased() && spacePressed)
		{
			spacePressed = false;
			coolingSystemMustWork2 = true;
			coolingSystemRegenerationClock.restart();
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
	LaserCoolingSystem();

	for (int i = 0; i < aliens.size(); i++)
	{
		aliens[i]->Update();
	}

	for (int i = 0; i < aliens.size(); i++)
	{
		if (aliens[i]->GetDestroy())
		{
			delete aliens[i];

			int alienTexture = rand() % 3;
			if (alienTexture == 0)
			{
				aliens[i] = new Alien(data->assets.GetTexture(aliens_01_image));
			}
			else if (alienTexture == 1)
			{
				aliens[i] = new Alien(data->assets.GetTexture(aliens_02_image));
			}
			else
			{
				aliens[i] = new Alien(data->assets.GetTexture(aliens_03_image));
			}
			break;
		}
	}

	if (newAlienClock.getElapsedTime().asSeconds() >= newAlienCounter)
	{
		int alienTexture = rand() % 3;
		if (alienTexture == 0)
		{
			aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_01_image)));
		}
		else if (alienTexture == 1)
		{
			aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_02_image)));
		}
		else
		{
			aliens.emplace_back(new Alien(data->assets.GetTexture(aliens_03_image)));
		}
		newAlienClock.restart();

		newAlienCounter += 3;
	}

	if (collision.CheckIfAlienHitPlayer(aliens, *player))
	{
		player->RemoveOneHeart();
		data->audio.PlayHitSound();
		widgets->SetNewNumberOfFullHearts(player->GetPlayerHealth());
	}

	widgets->SetNewScore(widgets->GetScore() + collision.CheckIfBulletHitAlien(aliens, player->GetBullets()));

	if (player->GetPlayerHealth() <= 0)
	{
		data->audio.PlayGameOverSound();
		data->machine.RemoveState();
		data->machine.AddState(stateReference(new EndState(data, widgets->GetScore())), true);
		sf::sleep(sf::seconds(1));
	}
}

void GameState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	for (int i = 0; i < aliens.size(); i++)
	{
		aliens[i]->Draw(data->window);
	}

	player->BulletsDraw(data->window);

	player->Draw(data->window);

	widgets->Draw(data->window);

	data->window.display();
}

void GameState::LaserCoolingSystem()
{
	if (spacePressed && widgets->GetCoolingSystemBarFill() > 0)
	{
		if (restartCoolingSystemFromHundred)
		{
			widgets->SetNewCoolingSystemBarFill(100 - int(coolingSystemClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM));
		}
		else
		{
			if (coolingSystemMustWork2)
			{
				coolingSystemMustWork2 = false;
				previousStateOfCoolingSystem = 100 - widgets->GetCoolingSystemBarFill();
			}
			if (100 - int(previousStateOfCoolingSystem + coolingSystemClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM) < 0)
			{
				widgets->SetNewCoolingSystemBarFill(0);
			}
			else
			{
				widgets->SetNewCoolingSystemBarFill(100 - int(previousStateOfCoolingSystem + coolingSystemClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM));
			}
		}
	}
	else if (spacePressed)
	{
		widgets->SetNewCoolingSystemBarFill(0);
		widgets->SetNewCoolingSystemBarFillColor(sf::Color::Red);
		spacePressed = false;
		restartCoolingSystemFromZero = true;
		restartCoolingSystemFromHundred = false;
		coolingSystemClock.restart();
	}
	else
	{
		if (restartCoolingSystemFromZero)
		{
			if (int(coolingSystemClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM) > 100)
			{
				widgets->SetNewCoolingSystemBarFill(100);
				restartCoolingSystemFromZero = false;
				restartCoolingSystemFromHundred = true;
				widgets->SetNewCoolingSystemBarFillColor();
			}
			else
			{
				widgets->SetNewCoolingSystemBarFill(int(coolingSystemClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM));
				coolingSystemMustWork = true;
				restartCoolingSystemFromHundred = false;
			}
		}
		else
		{
			if (coolingSystemMustWork)
			{
				coolingSystemMustWork = false;
				previousStateOfCoolingSystem = widgets->GetCoolingSystemBarFill();
			}
			if ((previousStateOfCoolingSystem + coolingSystemRegenerationClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM) > 100)
			{
				widgets->SetNewCoolingSystemBarFill(100);
				restartCoolingSystemFromHundred = true;
			}
			else
			{
				widgets->SetNewCoolingSystemBarFill(previousStateOfCoolingSystem + coolingSystemRegenerationClock.getElapsedTime().asSeconds() * 100 / MAX_TIME_WITHOUT_USING_COOLING_SYSTEM);
				restartCoolingSystemFromHundred = false;
			}
		}
	}
}
