#pragma once
#include "PhysicalEntity.h"

class Entity;

class Player : public PhysicalEntity
{
private:
	
	float mSpeed;
	float mMaxSpeed;
	float mAcceleration;
	float mDecceleration;

	int mHealth;
	int mMaxHealth;

public:
	Player();

	void MoveX(float dt, float stickXPos);
	void OnCollision(Entity* collidedWith) override;
	void SetSpeed(float speed) { mSpeed = speed; }

	void TakeDamage(int damage);
	void Heal(int heal);
};