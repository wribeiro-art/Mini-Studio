#pragma once

#include "Entity.h"

class PhysicalEntity : public Entity
{
protected:
    float mFrictionAir = 1.f; 
    float mGravityAcceleration = 9.81f;
    sf::Vector2f mVelocity = { 0.0f, 0.0f };

    bool mGravityOn = true;

    void Update() override;

public:
    PhysicalEntity() = default;

    void SetGravityAcceleration(float gravity);
    void SetFrictionAir(float frictionAir);

    void ResetVelocity();

    void EnableGravity();
    void DisableGravity();

    void ApplyImpulse(const sf::Vector2f& impulse);
    void ApplyImpulse(const float y, const float x = 0);

    virtual void Repulse(Entity* other) override;
};