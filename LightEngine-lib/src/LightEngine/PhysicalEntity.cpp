#include "PhysicalEntity.h"

void PhysicalEntity::Fall(float deltatime)
{
	mGravitySpeed += GravityAcceleration * deltatime;
	mPosition.y += mGravitySpeed * deltatime;
}
