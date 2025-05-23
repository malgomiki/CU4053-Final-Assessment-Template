#include "Background.h"

Background::Background()
{
	//https://www.spriters-resource.com/mobile/dodonpachiunlimited/sheet/90196/
	bgTex.loadFromFile("gfx/bg.png");
	bgTex.setRepeated(true);
	setTexture(&bgTex);
	setSize(sf::Vector2f(512 * 1.5, 1024 * 1.5));
	setPosition(256, 0);
}

Background::~Background()
{
}

void Background::update(float dt)
{
	static float offsetY = 0.f;
	float scrollSpeed = -200.f;

	offsetY += scrollSpeed * dt;

	if (offsetY > bgTex.getSize().y) {
		offsetY -= bgTex.getSize().y;
	}
	setTextureRect(sf::IntRect(0, static_cast<int>(offsetY), 512, 1024));
}
