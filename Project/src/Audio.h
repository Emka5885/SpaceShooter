#pragma once
#include <SFML/Audio.hpp>

class Audio
{
private:

	sf::SoundBuffer buttonsSoundBuffer, hitSoundBuffer, gameOverSoundBuffer;
	sf::Sound buttonsSound, hitSound, gameOverSound;

	sf::Music backgroundMusic;

	bool musicFileExist = true;
	bool buttonSoundFileExist = true;
	bool hitSoundFileExist = true;
	bool gameOverSoundFileExist = true;

public:
	Audio();

	void Init();

	void PlayMusic(bool menu = true);
	void StopMusic();
	void PlayButtonSound();
	void PlayHitSound();
	void PlayGameOverSound();
};