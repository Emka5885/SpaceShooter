#include "AssetManager.h"
#include "Definitions.h"

AssetManager::AssetManager()
{
	InitFonts();
	InitTextures();
}

void AssetManager::InitFonts()
{
	LoadFont(defaultFont, defaultFont_path);
	LoadFont(storyFont, storyFont_path);
}

void AssetManager::InitTextures()
{
	LoadTexture(background, background_path);
	LoadTexture(comet_image, comet_path);

	LoadTexture(spaceship_image, spaceship_path);
	LoadTexture(healthFull_image, healthFull_path);
	LoadTexture(healthEmpty_image, healthEmpty_path);

	LoadTexture(aliens_01_image, aliens_01_path);
	LoadTexture(aliens_02_image, aliens_02_path);
	LoadTexture(aliens_03_image, aliens_03_path);

	LoadTexture(bullet_01_image, bullet_01_path);
	LoadTexture(bullet_02_image, bullet_02_path);
	LoadTexture(bullet_03_image, bullet_03_path);
	LoadTexture(bullet_04_image, bullet_04_path);
	LoadTexture(bullet_05_image, bullet_05_path);
	LoadTexture(bullet_06_image, bullet_06_path);
	LoadTexture(bullet_07_image, bullet_07_path);
	LoadTexture(bullet_08_image, bullet_08_path);
	LoadTexture(bullet_09_image, bullet_09_path);
	LoadTexture(bullet_10_image, bullet_10_path);
}

void AssetManager::LoadTexture(const char* name, const char* fileName)
{
	sf::Texture texture;

	if (texture.loadFromFile(fileName))
	{
		this->textures[name] = texture;
	}
}

sf::Texture* AssetManager::GetTexture(const char* name)
{
	return &this->textures.at(name);
}

void AssetManager::LoadFont(const char* name, const char* fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
}

sf::Font& AssetManager::GetFont(const char* name)
{
	return this->fonts.at(name);
}