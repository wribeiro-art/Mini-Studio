#pragma once

#include "Scene.h"

class DummyEntity;
class PhysicalEntity;
class StaticEntity;

class SampleScene : public Scene
{
	PhysicalEntity* Ball;
	StaticEntity* Wall;

private:


public:
	int currentbutton = 0;

	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	int GetButtonPressed();
	float ReturnJoystickValueX();
	float ReturnJoystickValueY();
};


