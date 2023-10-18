#include "StoryState.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "Definitions.h"
#include <fstream>
#include <iostream>

StoryState::StoryState(GameDataReference& data) : data(data)
{
}

void StoryState::Init()
{
	data->window.setMouseCursorVisible(false);

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

	skipText = sf::Text("Press SPACE to skip", data->assets.GetFont(defaultFont), 20);
	skipText.setOrigin(skipText.getGlobalBounds().width, skipText.getGlobalBounds().height);
	skipText.setPosition(WIDTH - 25, HEIGHT - 25);
	skipText.setFillColor(sf::Color(255, 255, 255, skipAlpha));

	skipShape.setFillColor(sf::Color(0, 0, 0, skipAlpha));
	skipShape.setSize({ skipText.getGlobalBounds().width + 10, skipText.getGlobalBounds().height + 10 });
	skipShape.setOrigin(skipShape.getGlobalBounds().width, skipShape.getGlobalBounds().height);
	skipShape.setPosition(skipText.getPosition().x + 5, skipText.getPosition().y + 5);

	clock.restart();
	skipClock.restart();
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
		if (data->input.isKeyPressed(sf::Keyboard::Escape) && !changeState)
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
			changeState = true;
		}
		if (data->input.isKeyPressed(sf::Keyboard::Space) && !changeState)
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new GameState(data)), true);
			changeState = true;
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

	if (skipClock.getElapsedTime().asSeconds() >= 5 && displaySkip)
	{
		if (skipAlpha < 255)
		{
			skipAlpha += 5;
			skipText.setFillColor(sf::Color(255, 255, 255, skipAlpha));
			skipShape.setFillColor(sf::Color(0, 0, 0, skipAlpha));
		}
		else
		{
			displaySkip = false;
			skipClock.restart();
		}
	}
	else if (skipClock.getElapsedTime().asSeconds() >= 8 && !displaySkip)
	{
		if (skipAlpha > 0)
		{
			skipAlpha -= 5;
			skipText.setFillColor(sf::Color(255, 255, 255, skipAlpha));
			skipShape.setFillColor(sf::Color(0, 0, 0, skipAlpha));
		}
	}
}

void StoryState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	data->window.draw(skipShape);
	data->window.draw(skipText);

	for (int i = 0; i < story.size(); i++)
	{
		data->window.draw(story[i]);
	}

	data->window.display();
}
