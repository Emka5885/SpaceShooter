#include "MainMenuState.h"
#include "Definitions.h"
#include "StoryState.h"

MainMenuState::MainMenuState(GameDataReference& data) : data(data)
{
	comet = new Comet(data->assets.GetTexture(comet_image));
}

void MainMenuState::Init()
{
	data->window.setMouseCursorVisible(true);
	data->audio.PlayMusic();

	title = sf::Text(TITLE, data->assets.GetFont(defaultFont), 100);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition({ WIDTH / 2, 100 });
	title.setFillColor(sf::Color::White);
	title.setOutlineColor(sf::Color(50,50,50));
	title.setOutlineThickness(3);
	titleShadow = title;
	titleShadow.setFillColor(title.getOutlineColor());
	titleShadow.setPosition({ WIDTH / 2 + 6, 105 });

	sf::Text buttonsText("Play", data->assets.GetFont(defaultFont), 50);
	buttonsText.setFillColor(sf::Color::White);
	buttonsText.setOutlineColor(sf::Color(50,50,50));
	buttonsText.setOutlineThickness(2);
	sf::Vector2f buttonsSize(250, 100);

	playButton = Button(buttonsSize, buttonsText, {WIDTH / 2, 305}, 10);

	buttonsText.setString("Quitt");
	quittButton = Button(buttonsSize, buttonsText, { WIDTH / 2, playButton.GetShape().getPosition().y + 200 }, 10);

	sf::sleep(sf::seconds(0.2));
}

void MainMenuState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		// check menu type
		if (event.type == sf::Event::Closed || type == quitt)
		{
			sf::sleep(sf::seconds(1));
			data->window.close();
		}
		else if (type == play)
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StoryState(data)), true);
		}
		// clicked
		if (data->input.isButtonClicked(quittButton.GetShape(), sf::Mouse::Left, data->window))
		{
			quittButton.Clicked();
			data->audio.PlayButtonSound();
			type = quitt;
		}
		else if (data->input.isButtonClicked(playButton.GetShape(), sf::Mouse::Left, data->window))
		{
			playButton.Clicked();
			data->audio.PlayButtonSound();
			type = play;
		}
		// hovered
		if (event.type == sf::Event::MouseMoved)
		{
			if (data->input.isButtonHovered(playButton.GetShape(), data->window))
			{
				playButton.ChangeHover(true);
			}
			else
			{
				playButton.ChangeHover(false);
			}

			if (data->input.isButtonHovered(quittButton.GetShape(), data->window))
			{
				quittButton.ChangeHover(true);
			}
			else
			{
				quittButton.ChangeHover(false);
			}
		}
	}
}

void MainMenuState::Update()
{
	comet->Update();

	if (comet->GetDestroy())
	{
		delete comet;

		comet = new Comet(data->assets.GetTexture(comet_image));
	}
}

void MainMenuState::Draw()
{
	data->window.clear(sf::Color::Black);
	data->window.draw(data->backgroundImage);

	comet->Draw(data->window);

	data->window.draw(titleShadow);
	data->window.draw(title);
	playButton.DrawButton(data->window);
	quittButton.DrawButton(data->window);

	data->window.display();
}