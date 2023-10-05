#pragma once
#include "State.h"
#include "Game.h"
#include "Player.h"

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

	Player player;

	sf::RectangleShape aliens1, aliens2, aliens3;
};