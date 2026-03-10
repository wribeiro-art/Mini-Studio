#include "PhysicalEntity.h"
#include <iostream>

//void PhysicalEntity::Fall(float deltatime)
//{
//	mGravitySpeed += GravityAcceleration * deltatime;
//	mPosition.y += mGravitySpeed * deltatime;
//}

void PhysicalEntity::SetGravityAcceleration(float gravity)
{
	mGravityAcceleration = gravity;
}

void PhysicalEntity::SetGravitySpeed(float speed)
{
	mGravitySpeed = speed;
}

void PhysicalEntity::ApplyImpulse(const sf::Vector2f& impulse)
{
	mGravitySpeed += impulse.y;  
	mVelocity.x += impulse.x; // Pas nécessaire   
}

void PhysicalEntity::ApplyImpulse(const float y, const float x)
{
	ApplyImpulse({ x, y });
}

void PhysicalEntity::Update()
{
    float dt = GetDeltaTime();

   // std::cout << "x " << mVelocity.x << std::endl;
  // std::cout << "y " << mGravitySpeed << std::endl;

    mGravitySpeed += mGravityAcceleration * dt;

    sf::Vector2f pos = GetPosition(0.5f, 0.5f);

    pos.x += mVelocity.x * dt;
    pos.y += mGravitySpeed * dt;
    
    SetPosition(pos.x, pos.y, 0.5f, 0.5f);

    Entity::Update();

}