#include "StoryState.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "Definitions.h"
#include <fstream>

StoryState::StoryState(GameDataReference& data) : data(data)
{
}

void StoryState::Init()
{
	std::fstream file("res/story.txt");
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		storyFromFile.emplace_back(line);
	}
	file.close();

	sf::Text text(storyFromFile[0], data->assets.GetFont(storyFont), 58);
	text.setFillColor(sf::Color::Yellow);
	text.setOutlineThickness(2);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(WIDTH / 2, HEIGHT + 70);
	story.emplace_back(text);

	for (int i = 1; i < storyFromFile.size(); i++)
	{
		text.setString(storyFromFile[i]);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		text.setPosition(WIDTH / 2, HEIGHT + 70);
		story.emplace_back(text);
	}

	clock.restart();
}

void StoryState::HandleInput()
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

void StoryState::Update()
{
	if (clock.getElapsedTime().asSeconds() >= 1.5 && actuallyStorySize < story.size())
	{
		actuallyStorySize++;
		clock.restart();
	}

	int counter = 0;
	for (int i = 0; i < actuallyStorySize; i++)
	{
		if (story[i].getPosition().y > -50)
		{
			story[i].move(0, -0.8 - (i * 0.02));
			story[i].scale(0.9994, 0.999);
		}
		else
		{
			counter++;
		}
	}

	if (counter == actuallyStorySize)
	{
		data->machine.RemoveState();
		data->machine.AddState(stateReference(new GameState(data)), true);
	}
}

void StoryState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	for (int i = 0; i < story.size(); i++)
	{
		data->window.draw(story[i]);
	}

	data->window.display();
}
