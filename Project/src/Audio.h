#pragma once
#include <SFML/Audio.hpp>

class Audio
{
private:

	sf::SoundBuffer buttonsSoundBuffer;
	sf::Sound buttonsSound;

	sf::Music backgroundMusic;

	bool musicFileExist = true;
	bool buttonSoundFileExist = true;

public:
	Audio();

	void Init();

	void PlayMusic();
	void StopMusic();
	void PlayButtonSound();
};