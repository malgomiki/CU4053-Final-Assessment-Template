#include "Enemy.h"

Enemy::Enemy()
{
	enmHealth = 20;
	enmSpeed = -200.f;
	setTag("Enemy");

	enmTex.loadFromFile("gfx/enemysheet.png");
	setSize(sf::Vector2f(46 * 2, 28 * 2));
	setPosition(640, 220);
	setCollisionBox(getPosition(), getSize());
	setTexture(&enmTex);

	//enemy frame stuff
	enmMove.addFrame(sf::IntRect(0, 0, 46, 28));
	enmMove.addFrame(sf::IntRect(46, 0, 46, 28));
	enmMove.addFrame(sf::IntRect(92, 0, 46, 28));
	enmMove.setFrameSpeed(1.f / 5.f);

	//sets current animation to the move animation + sets the texture to it
	curEnmAni = &enmMove;
	setTextureRect(curEnmAni->getCurrentFrame());
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	curEnmAni->animate(dt);
	setTextureRect(curEnmAni->getCurrentFrame());
}
