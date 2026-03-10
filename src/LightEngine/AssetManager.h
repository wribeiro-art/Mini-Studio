#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
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

