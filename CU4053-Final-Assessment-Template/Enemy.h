#pragma once
#include "framework/GameObject.h"
#include "Framework/Animation.h"
class Enemy : public GameObject
{
	sf::Texture enmTex;
	Animation enmMove;

	Animation* curEnmAni;

public:
	int enmHealth;
	float enmSpeed;

	Enemy();
	~Enemy();
	void update(float dt) override;
};

