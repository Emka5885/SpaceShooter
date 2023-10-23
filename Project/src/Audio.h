#pragma once
#include <SFML/Audio.hpp>

class Audio
{
private:

	sf::SoundBuffer buttonsSoundBuffer;
	sf::Sound buttonsSound;

	sf::Music menuBackgroundMusic;
	sf::Music gameBackgroundMusic;

	bool menuMusicFileExist = true;
	bool gameMusicFileExist = true;
	bool buttonSoundFileExist = true;

public:
	Audio();

	void Init();

	void PlayMusic(bool menu = true);
	void StopMusic();
	void PlayButtonSound();
};