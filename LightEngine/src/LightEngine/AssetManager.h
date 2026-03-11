#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <map>

//class AssetManager
//{
//	std::map<const char*, sf::Texture*> mTexture;
//private:
//	sf::Texture* LoadTexture(const char* path);
//
//public:
//	sf::Texture* GetTexture(const char* path);
//};


class AssetManager
{
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

public:
	sf::Texture GetTexture() { return mTexture; };
	sf::Sprite GetSprite() { return mSprite; };

	void LoadImage();
};

