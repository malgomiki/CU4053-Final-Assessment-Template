#pragma once
#include "framework/GameObject.h"
#include "framework/Animation.h"
#include "framework/World.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

class Player : public GameObject
{
	sf::Texture f22Tex;
	Animation f22Idle;
	Animation f22MLeft;
	Animation f22MRight;

	Animation* curF22Anim;

	//World* world;

	//std::vector<Bullet*> bullets;

public:
	int pLives;
	int pDmg;

	Player();
	~Player();
	void handleInput(float dt) override;	

	//void setWorld(World* world) { this->world = world; }

	//std::vector<Bullet*> getBullets() { return bullets; }
};

