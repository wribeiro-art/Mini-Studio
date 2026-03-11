//#pragma once
//#include "Entity.h"
//
//class PhysicalEntity: public Entity
//{
//protected:
//	float GravityAcceleration = 9.81f;
//
//private:
//	sf::Vector2f mPosition;
//	float mGravitySpeed = 0.f;
//
//
//public:
//	void Fall(float deltatime);
//
//};
//


// Essai

#pragma once

#include "Entity.h"

class PhysicalEntity : public Entity
{
protected:
    float mGravitySpeed = 0.0f; // Useless vu qu'on pourrait juste se servir ddu mVelcoiyt
    float mGravityAcceleration = 981.f;
    sf::Vector2f mVelocity = { 0.0f, 0.0f };

    void Update() override;

public:
    PhysicalEntity() = default;

    void SetGravityAcceleration(float gravity);
    void SetGravitySpeed(float speed);

    void ApplyImpulse(const sf::Vector2f& impulse);
    void ApplyImpulse(const float y, const float x = 0);
};