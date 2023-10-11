#pragma once
#include "State.h"
#include "Game.h"
#include "Player.h"
#include "Alien.h"
#include "Widgets.h"

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

	Alien* alien1 = nullptr;
	Alien* alien2 = nullptr;
	Alien* alien3 = nullptr;
};