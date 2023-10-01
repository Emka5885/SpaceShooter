#pragma once
#include "State.h"
#include "Game.h"
#include "Button.h"

enum menuType { defaultMenu, play, quitt };

class MainMenuState :public State
{
public:
	MainMenuState(GameDataReference& data);

	void Init();
	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataReference& data;

	sf::RectangleShape backgroundShape;

	sf::Text title;
	sf::Text titleShadow;
	Button playButton;
	Button quittButton;

	menuType type = defaultMenu;
};