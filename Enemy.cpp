#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture& tekstura, sf::Vector2f position) 
	: Entity(sf::Vector2f(tekstura.getSize()))
{
	obj.setTexture(tekstura);
	obj.setPosition(position);
	SetHitboxPosition(position);
}

void Enemy::Move(sf::Vector2f force)
{
	obj.move(force);
	MoveHitbox(force);
}

void Enemy::Update(sf::Time d1)
{

	static sf::Time LastUpdate = sf::Time::Zero;
	if (d1 >= LastUpdate + delay)
	{
		LastUpdate = d1;
		Move(velocity);

	}
	
}

void Enemy::SetVelocity(sf::Vector2f force)
{
	velocity = force;
}

sf::Vector2f Enemy::GetVelocity()
{
	return velocity;
}

void Enemy::draw(sf::RenderWindow& handle)
{
	handle.draw(obj);
}

void Enemy::SetDelay(sf::Time t1)
{
	delay = t1;
}

sf::Time Enemy::GetDelay()
{
	return delay;
}
