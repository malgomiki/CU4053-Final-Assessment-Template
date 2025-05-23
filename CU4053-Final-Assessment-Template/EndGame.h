#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Input.h"
#include "framework/BaseLevel.h"
#include "framework/GameState.h"
#include <string>
#include <iostream>
#include "Level.h"

class EndGame : public BaseLevel
{
public:
	EndGame(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~EndGame();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;

	sf::Font egFont;
	sf::Text egText[2];

	sf::Sprite egScreenSpr;
	sf::Texture egScreenTex;
};

