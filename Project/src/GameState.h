#pragma once
#include "State.h"
#include "Game.h"
#include "Player.h"
#include "Alien.h"
#include "Widgets.h"
#include "Collision.h"

class GameState :public State
{
public:
	GameState(GameDataReference& data);

	void Init();
	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataReference& data;

	Player* player;
	sf::Clock attackClock;

	Widgets* widgets;

	Collision collision;

	std::vector<Alien*> aliens;
	sf::Clock newAlienClock;

	int newAlienCounter = 5;

	sf::Clock coolingSystemClock;
};