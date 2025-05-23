#include "WinGame.h"
#include "framework/Menu.h"
#include "Player.h"

WinGame::WinGame(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;

	wgFont.loadFromFile("font/msgothic.ttc");
	
	wgScreenTex.loadFromFile("gfx/win.png");
	wgScreenSpr.setTexture(wgScreenTex);
	wgScreenSpr.setPosition(0, 0);

	wgText[0].setFont(wgFont);
	wgText[0].setFillColor(sf::Color::White);
	wgText[0].setCharacterSize(120);
	wgText[0].setString("You won!");
	wgText[0].setPosition(sf::Vector2f(400, 295));

	wgText[1].setFont(wgFont);
	wgText[1].setFillColor(sf::Color::White);
	wgText[1].setString("press esc to quit game\npress enter for credits");
	wgText[1].setPosition(sf::Vector2f(450, 460));
}

WinGame::~WinGame()
{
}

void WinGame::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::CREDITS);
	}
}

void WinGame::update(float dt)
{
}

void WinGame::render()
{
	window->draw(wgScreenSpr);
	for (int i = 0; i < 2; i++)
	{
		window->draw(wgText[i]);
	}
}
