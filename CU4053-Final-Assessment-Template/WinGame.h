#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Input.h"
#include "framework/BaseLevel.h"
#include "framework/GameState.h"
#include <string>
#include <iostream>
#include "Level.h"

class WinGame : public BaseLevel
{
public:
	WinGame(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~WinGame();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;

	sf::Font wgFont;
	sf::Text wgText[2];

	sf::Sprite wgScreenSpr;
	sf::Texture wgScreenTex;
};

