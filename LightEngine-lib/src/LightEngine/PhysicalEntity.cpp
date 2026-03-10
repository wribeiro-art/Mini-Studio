#include "PhysicalEntity.h"

void PhysicalEntity::SetGravityAcceleration(float gravity)
{
	mGravityAcceleration = gravity;
}

void PhysicalEntity::SetFrictionAir(float frictionAir)
{
    mFrictionAir = frictionAir;
}

void PhysicalEntity::ResetVelocity()
{
    mVelocity = { 0, 0 };
}

void PhysicalEntity::EnableGravity()
{
    ResetVelocity();
    mGravityOn = true;
}

void PhysicalEntity::DisableGravity()
{
    mGravityOn = false;
}

void PhysicalEntity::ApplyImpulse(const sf::Vector2f& impulse)
{
	mVelocity.y += impulse.y;  
	mVelocity.x += impulse.x;  
}

void PhysicalEntity::ApplyImpulse(const float y, const float x)
{
	ApplyImpulse({ x, y });
}

void PhysicalEntity::Update()
{
    float dt = GetDeltaTime();

    if (mGravityOn == false)
        return;

    mVelocity.y += mGravityAcceleration * dt;
    
    // Friction air. TODO ajouter friction sol

    mVelocity.x -= mVelocity.x * mFrictionAir * dt;

    sf::Vector2f pos = GetPosition(0.5f, 0.5f);

    pos.x += mVelocity.x * dt;
    pos.y += mVelocity.y * dt;
    
    SetPosition(pos.x, pos.y, 0.5f, 0.5f);

    Entity::Update();
}