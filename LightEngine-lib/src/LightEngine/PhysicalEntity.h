#pragma once
#include "Entity.h"

class PhysicalEntity: public Entity
{
protected:
	float GravityAcceleration = 9.81f;

private:
	sf::Vector2f mPosition;
	float mGravitySpeed = 0.f;


public:
	void Fall(float deltatime);

};

