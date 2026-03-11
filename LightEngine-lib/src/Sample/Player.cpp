#include <iostream>
#include "Player.h"

#include "StaticEntity.h"

Player::Player()
{
	mSpeed = 0;
	mMaxSpeed = 1000;
	mAcceleration = 100.f;
	mDecceleration = 75.f;

	mMaxHealth = 10;
	mHealth = mMaxHealth;
}

void Player::MoveX(float dt, float direction)
{
	sf::Vector2f position = { GetPosition().x, GetPosition().y };

	mSpeed += mAcceleration * dt;
	if (mSpeed >= mMaxSpeed)
		mSpeed = mMaxSpeed;

	position.x += mSpeed * dt * direction;

	SetPosition(position.x, position.y);

	//std::cout << "x pos " << position.x << std::endl;
	//std::cout << "speed " << mSpeed << std::endl;
	//std::cout << "accel " << mAcceleration << std::endl;

}

void Player::OnCollision(Entity* collidedWith)
{


	if (collidedWith->IsTag(1) || collidedWith->IsTag(4))
		return;

	if (collidedWith->IsTag(2)) //ennemi -> logique ennemi
	{
		
	}

}

void Player::Dash(float DirX, float DirY)
{
	ResetVelocity();
	ApplyImpulse(DirY, DirX);
}

void Player::TakeDamage(int damage)
{
	mHealth -= damage;
}

void Player::Heal(int heal)
{
	mHealth += heal;
}
