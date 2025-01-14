#include "Player.h"

Player::Player(sf::Texture &tekstura, sf::Vector2f pos)
	: Entity(sf::Vector2f(tekstura.getSize()))
{
	obj.setTexture(tekstura);
	obj.setPosition(pos);
	SetHitboxPosition(pos);
}

void Player::Move(sf::Vector2f force)
{
	obj.setPosition(obj.getPosition() + force);
	SetHitboxPosition(GetHitboxPosition());
}

void Player::draw(sf::RenderWindow& handle)
{
	handle.draw(obj);
}

sf::Sprite Player::GetSprite()
{
	return obj;
}

void Player::Control(sf::Event event)
{
	obj.setOrigin(sf::Vector2f((obj.getTexture()->getSize().x)/2
		,(obj.getTexture()->getSize().y)/2));
	float step = 50;
	if(event.type == sf::Event::KeyPressed)
	switch(event.key.code)
	{
		case sf::Keyboard::Key::A:
		case sf::Keyboard::Key::Left:
			{
			sf::Vector2f force(-step, 0);
			Move(force);
			obj.setRotation(180);
			}
		break;

		case sf::Keyboard::Key::D:
		case sf::Keyboard::Key::Right:
		{
			sf::Vector2f force(step, 0);
			Move(force);
			obj.setRotation(0);
		}
		break;

		case sf::Keyboard::Key::W:
		case sf::Keyboard::Key::Up:
		{
			sf::Vector2f force(0, -step);
			Move(force);
			obj.setRotation(-90);
		}
		break;

		case sf::Keyboard::Key::S:
		case sf::Keyboard::Key::Down:
		{
			sf::Vector2f force(0, step);
			Move(force);
			obj.setRotation(90);
		}
		break;

		default:
			break;
	}
}

void Player::ResizeHitbox(sf::Vector2f size)
{
	SetSizeHitbox(size);
	sf::Vector2f NewPos(obj.getPosition().x + (obj.getTexture() -> getSize().x - size.x)/2, obj.getPosition().y + (obj.getTexture()->getSize().y - size.y)/2);
	SetHitboxPosition(NewPos);
}