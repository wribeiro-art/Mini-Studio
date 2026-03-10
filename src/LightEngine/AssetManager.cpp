#include "AssetManager.h"

void AssetManager::LoadImage()
{
	if (!mTexture.loadFromFile("C:\\Users\\wribeiro\\Downloads\\Mini-Studio-main\\Mini-Studio-main\\LightEngine-lib\\Nikon-D810-Image-Sample-6.jpg"))
    {
        std::cout << "Erreur chargement image" << std::endl;
    }

    mTexture.loadFromFile("C:\\Users\\wribeiro\\Downloads\\Mini-Studio-main\\Mini-Studio-main\\LightEngine-lib\\Nikon-D810-Image-Sample-6.jpg");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(0, 0);
}
