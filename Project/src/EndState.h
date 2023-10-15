#pragma once
#include "State.h"
#include "Game.h"
#include "Button.h"

enum endType { defaultEnd, restart, mainMenu };

class EndState :public State
{
public:
	EndState(GameDataReference& data, int score = 0);

	void Init();
	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataReference& data;

	sf::Text scoreText;
	sf::Text scoreTextShadow;

	Button restartButton;
	Button mainMenuButton;

	int score;

	endType type = defaultEnd;
};