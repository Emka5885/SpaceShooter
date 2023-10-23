#include "Audio.h"
#include <iostream>

Audio::Audio()
{
	Init();
}

void Audio::Init()
{
	if (!backgroundMusic.openFromFile("res/music/file.wav"))
	{
		std::cout << "Error - background music" << std::endl;
		musicFileExist = false;
	}
	else
	{
		backgroundMusic.setLoop(true);
	}

	if (!buttonsSoundBuffer.loadFromFile("res/sounds/toy-button-105724.wav"))
	{
		std::cout << "Error - button sound" << std::endl;
		buttonSoundFileExist = false;
	}
	else
	{
		buttonsSound.setBuffer(buttonsSoundBuffer);
	}
}

void Audio::PlayMusic()
{
	if(musicFileExist)
		backgroundMusic.play();
}

void Audio::StopMusic()
{
	if(musicFileExist)
		backgroundMusic.stop();
}

void Audio::PlayButtonSound()
{
	if(buttonSoundFileExist)
		buttonsSound.play();
}
