#pragma once
#include "Scene.h"

class Player;
class StaticEntity;
class Controller;

class SampleScene : public Scene
{
    Player* Ball;
    StaticEntity* Wall;
	Controller* Controller1;

	bool mDebug = false;
	bool mPsychicMode = false;
public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};