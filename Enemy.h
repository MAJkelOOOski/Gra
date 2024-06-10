#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(sf::Texture&, sf::Vector2f position);
	virtual void Move(sf::Vector2f) override;
	virtual void Update(sf::Time); // delay
	void SetVelocity(sf::Vector2f force);
	sf::Vector2f GetVelocity();
	void draw(sf::RenderWindow&);
	void SetDelay(sf::Time t1);
	sf::Time GetDelay();
	
protected:
	sf::Sprite obj;
	sf::Vector2f velocity = sf::Vector2f(-15, 0);

private:
	sf::Time delay = sf::milliseconds(50);
};

