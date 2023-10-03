#pragma once
#include "State.h"
#include "Game.h"

class StoryState :public State
{
public:
	StoryState(GameDataReference& data);

	void Init();
	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataReference& data;

	std::vector<sf::Text> story;

	std::vector<std::string> storyFromFile;

	int actuallyStorySize = 1;

	sf::Clock clock;
};