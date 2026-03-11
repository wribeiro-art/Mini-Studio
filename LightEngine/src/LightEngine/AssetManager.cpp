#include "AssetManager.h"


//sf::Texture* AssetManager::LoadTexture(const char* path)
//{
//    sf::Texture* texture = new sf::Texture(path);
//
//}
//
//
//
//sf::Texture* AssetManager::GetTexture(const char* path)
//{
//    return nullptr;
//}










void AssetManager::LoadImage()
{
	if (!mTexture.loadFromFile("C:\\Users\\wribeiro\\Downloads\\Mini-Studio-William\\Mini-Studio-William\\ai-generated-7483596_960_720.jpg"))
    {
        std::cout << "chiant" << std::endl;
    }
    else
    {
        std::cout << "Image chargee !" << std::endl;
    }
    mTexture.loadFromFile("C:\\Users\\wribeiro\\Downloads\\Mini-Studio-William\\Mini-Studio-William\\ai-generated-7483596_960_720.jpg");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(0, 0);
}