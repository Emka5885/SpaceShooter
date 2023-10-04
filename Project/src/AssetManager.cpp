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
	LoadTexture(spaceship_image, spaceship_path);
	LoadTexture(aliens_01_image, aliens_01_path);
	LoadTexture(aliens_02_image, aliens_02_path);
	LoadTexture(aliens_03_image, aliens_03_path);
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