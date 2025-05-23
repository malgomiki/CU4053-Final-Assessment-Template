#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Input.h"
#include "framework/BaseLevel.h"
#include "framework/GameState.h"
#include <string>
#include <iostream>
#include "Level.h"

class Credits : public BaseLevel
{
public:
	Credits(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~Credits();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;

	sf::Font crFont;
	sf::Text crText[7];

	sf::Sprite crScreenSpr;
	sf::Texture crScreenTex;
};

