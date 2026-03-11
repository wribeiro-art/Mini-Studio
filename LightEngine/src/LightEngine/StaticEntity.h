#pragma once

#include "Entity.h"

class StaticEntity : public Entity
{
protected:
	void Update() override; // Chais pas quoi mettre

public:
	StaticEntity() = default;
};