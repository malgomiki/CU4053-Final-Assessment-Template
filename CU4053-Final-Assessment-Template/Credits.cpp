#include "Credits.h"

Credits::Credits(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;

	crFont.loadFromFile("font/msgothic.ttc");

	crScreenTex.loadFromFile("gfx/win.png");
	crScreenSpr.setTexture(crScreenTex);
	crScreenSpr.setPosition(0, 0);

	crText[0].setFont(crFont);
	crText[0].setFillColor(sf::Color::White);
	crText[0].setString("Majority of Assets: malgomiki");
	crText[0].setPosition(sf::Vector2f(200, 80));

	crText[1].setFont(crFont);
	crText[1].setFillColor(sf::Color::White);
	crText[1].setString("Coding: malgomiki using 'Noob Engine'");
	crText[1].setPosition(sf::Vector2f(200, 160));

	crText[2].setFont(crFont);
	crText[2].setFillColor(sf::Color{ 0x1E1E21FF });
	crText[2].setCharacterSize(12);
	crText[2].setString("(or as i like to call it: 'Cosmopolitan Engine')");
	crText[2].setPosition(sf::Vector2f(200, 200));

	crText[3].setFont(crFont);
	crText[3].setFillColor(sf::Color::White);
	crText[3].setString("Stage Background: 'Level 1' from DoDonPachi: Unlimited");
	crText[3].setPosition(sf::Vector2f(200, 240));

	crText[4].setFont(crFont);
	crText[4].setFillColor(sf::Color::White);
	crText[4].setString("Menu BGM: 'Arcade Title' from Ace Combat: Squadron Leader"); //was it that or just ace combat 5: the unsung war in terms of game titles (because the latter was used outside of europe)
	crText[4].setPosition(sf::Vector2f(200, 320));

	crText[5].setFont(crFont);
	crText[5].setFillColor(sf::Color::White);
	crText[5].setString("Stage BGM: 'The Objective' from Ridge Racer Type 4");
	crText[5].setPosition(sf::Vector2f(200, 400));

	crText[6].setFont(crFont);
	crText[6].setFillColor(sf::Color::White);
	crText[6].setString("press esc to quit game");
	crText[6].setPosition(sf::Vector2f(460, 600));
}

Credits::~Credits()
{
}

void Credits::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
}

void Credits::update(float dt)
{
}

void Credits::render()
{
	window->draw(crScreenSpr);
	for (int i = 0; i < 7; i++)
	{
		window->draw(crText[i]);
	}

}


