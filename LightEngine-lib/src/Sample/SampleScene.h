#pragma once
#include "Scene.h"
#include "PhysicalEntity.h"

class Entity;

class Ball : public PhysicalEntity
{
public:
    void OnCollision(Entity* other) override;
};

class SampleScene : public Scene
{
    Ball* ball;
    Entity* wall;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};
