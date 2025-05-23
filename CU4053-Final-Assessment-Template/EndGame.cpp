#include "EndGame.h"
#include "framework/Menu.h"
#include "Player.h"

EndGame::EndGame(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;

	egFont.loadFromFile("font/msgothic.ttc");
	
	egScreenTex.loadFromFile("gfx/lose.png");
	egScreenSpr.setTexture(egScreenTex);
	egScreenSpr.setPosition(0, 0);
	
	egText[0].setFont(egFont);
	egText[0].setFillColor(sf::Color::White);
	egText[0].setCharacterSize(120);
	egText[0].setString("You died!");
	egText[0].setPosition(sf::Vector2f(350, 295));
	
	egText[1].setFont(egFont);
	egText[1].setFillColor(sf::Color::White);
	egText[1].setString("press esc to quit game");
	egText[1].setPosition(sf::Vector2f(450, 460));
}

EndGame::~EndGame()
{
}

void EndGame::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
}

void EndGame::update(float dt)
{
}

void EndGame::render()
{
	window->draw(egScreenSpr);
	for (int i = 0; i < 2; i++)
	{
		window->draw(egText[i]);
	}
}
