#pragma once
#include "Scene.h"

class PhysicalEntity;

class StaticEntity;

class SampleScene : public Scene
{
    PhysicalEntity* Ball;
    StaticEntity* Wall;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};