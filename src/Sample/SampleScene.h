#pragma once
#include <iostream>
#include "AssetManager.h"
#include "Scene.h"

class PhysicalEntity;

class StaticEntity;

class GameManager;

class SampleScene : public Scene
{
    PhysicalEntity* Ball;
    StaticEntity* Wall;
    AssetManager assetManager;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
    void OnRender(sf::RenderWindow& window);
};