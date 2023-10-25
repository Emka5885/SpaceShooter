#include "Audio.h"
#include <iostream>

Audio::Audio()
{
	Init();
}

void Audio::Init()
{
	if (!backgroundMusic.openFromFile("res/music/battle-of-the-dragons-8037.wav"))
	{
		std::cout << "Error - background music" << std::endl;
		musicFileExist = false;
	}
	else
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(70);
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
	if (!hitSoundBuffer.loadFromFile("res/sounds/metal-hit-cartoon-7118.wav"))
	{
		std::cout << "Error - hit sound" << std::endl;
		hitSoundFileExist = false;
	}
	else
	{
		hitSound.setBuffer(hitSoundBuffer);
	}
	if (!gameOverSoundBuffer.loadFromFile("res/sounds/083822_8-bit-quotgame-overquot-82872.wav"))
	{
		std::cout << "Error - game over sound" << std::endl;
		gameOverSoundFileExist = false;
	}
	else
	{
		gameOverSound.setBuffer(gameOverSoundBuffer);
	}
	
}

void Audio::PlayMusic(bool menu)
{
	if (musicFileExist && menu)
	{
		backgroundMusic.play();
	}
}

void Audio::StopMusic()
{
	if (musicFileExist)
	{
		backgroundMusic.stop();
	}
}

void Audio::PlayButtonSound()
{
	if(buttonSoundFileExist)
		buttonsSound.play();
}

void Audio::PlayHitSound()
{
	if(hitSoundFileExist)
		hitSound.play();
}

void Audio::PlayGameOverSound()
{
	if(gameOverSoundFileExist)
		gameOverSound.play();
}
