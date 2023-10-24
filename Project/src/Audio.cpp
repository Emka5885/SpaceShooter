#include "Audio.h"
#include <iostream>

Audio::Audio()
{
	Init();
}

void Audio::Init()
{
	if (!menuBackgroundMusic.openFromFile("res/music/battle-of-the-dragons-8037.wav"))
	{
		std::cout << "Error - menu background music" << std::endl;
		menuMusicFileExist = false;
	}
	else
	{
		menuBackgroundMusic.setLoop(true);
		menuBackgroundMusic.setVolume(70);
	}
	if (!gameBackgroundMusic.openFromFile("res/music/file.wav"))
	{
		std::cout << "Error - game background music" << std::endl;
		gameMusicFileExist = false;
	}
	else
	{
		gameBackgroundMusic.setLoop(true);
		gameBackgroundMusic.setVolume(70);
	}

	if (!buttonsSoundBuffer.loadFromFile("res/sounds/button-4-88356.wav"))
	{
		std::cout << "Error - button sound" << std::endl;
		buttonSoundFileExist = false;
	}
	else
	{
		buttonsSound.setBuffer(buttonsSoundBuffer);
	}
}

void Audio::PlayMusic(bool menu)
{
	if (menuMusicFileExist && menu)
	{
		menuBackgroundMusic.play();
	}
	else if (gameMusicFileExist && !menu)
	{
		gameBackgroundMusic.play();
	}
}

void Audio::StopMusic()
{
	if (menuMusicFileExist)
	{
		menuBackgroundMusic.stop();
	}
	if (gameMusicFileExist)
	{
		gameBackgroundMusic.stop();
	}
}

void Audio::PlayButtonSound()
{
	if(buttonSoundFileExist)
		buttonsSound.play();
}
