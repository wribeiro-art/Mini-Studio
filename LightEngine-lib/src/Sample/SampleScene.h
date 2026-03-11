#pragma once
#include "Scene.h"

class Player;

class StaticEntity;

class SampleScene : public Scene
{
    Player* Ball;
    StaticEntity* Wall;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};