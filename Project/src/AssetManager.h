#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
public:
	AssetManager();
	~AssetManager() { }

	void InitFonts();
	void InitTextures();

	void LoadTexture(const char* name, const char* fileName);
	sf::Texture* GetTexture(const char* name);

	void LoadFont(const char* name, const char* fileName);
	sf::Font& GetFont(const char* name);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
};