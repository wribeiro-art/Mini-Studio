#pragma once
#include "Scene.h"

class PhysicalEntity;

class Entity;

class SampleScene : public Scene
{
    PhysicalEntity* Ball;
    Entity* Wall;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;

    int GetButtonPressed();
    float ReturnJoystickValueX();
    float ReturnJoystickValueY();
};