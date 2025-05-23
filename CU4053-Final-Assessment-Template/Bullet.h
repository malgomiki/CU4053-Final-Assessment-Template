#pragma once
#include "framework/GameObject.h"
class Bullet : public GameObject
{ 
	float bltSpeed;
	sf::Texture bltTex;

public:
	Bullet();
	~Bullet();

};

