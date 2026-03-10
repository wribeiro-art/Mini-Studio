#pragma once
#include "PhysicalEntity.h"

class PlayerController : public PhysicalEntity
{
private:


public:

	void MoveX(float dt, float stickXPos);

};