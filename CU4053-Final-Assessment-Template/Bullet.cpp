#include "Bullet.h"

Bullet::Bullet()
{
	bltSpeed = 500.f;
	velocity.y = bltSpeed;
	
	bltTex.loadFromFile("gfx/bullet.png");
	setTexture(&bltTex);
	setSize(sf::Vector2f(9, 33));
	setCollisionBox(getPosition(), getSize());
	setTag("Bullet");
}

Bullet::~Bullet()
{
}
