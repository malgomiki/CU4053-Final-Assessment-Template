#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

//taking the L in a way i couldn't figure out the two mechanics i promised in that production document
//at least doing the assets was fun

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, sf::View* v, World* w, TileManager* tm)
{
	window = hwnd;
	input = in;
	gameState = gs;
	view = v;
	world = w;
	tileManager = tm;
	audioManager = new AudioManager();

	//audioManager->addSound("sfx/shoot.wav", "shooting");
	//audioManager->addSound("sfx/damage.wav", "enmdamage");
	audioManager->addSound("sfx/pldead.wav", "pldamage");

	ectFont.loadFromFile("font/msgothic.ttc");

	//adds in all these things
	world->AddGameObject(f22);
	world->AddGameObject(thing);
	f22.setInput(in);

	//the cool ui
	UItex.loadFromFile("gfx/StageUI.png");
	UI.setTexture(&UItex);
	UI.setSize(sf::Vector2f(1280, 720));
	UI.setPosition(0, 0);

	//ui text
	enmClearText[0].setFont(ectFont);
	//enmClearText[0].setCharacterSize();
	enmClearText[0].setFillColor(sf::Color::White);
	enmClearText[0].setOutlineColor(sf::Color::Black);
	enmClearText[0].setOutlineThickness(4.f);
	enmClearText[0].setString("Enemies\nDefeated:");
	enmClearText[0].setPosition(sf::Vector2f(1050, 35));

	enmClearText[1].setFont(ectFont);
	enmClearText[1].setFillColor(sf::Color::White);
	enmClearText[1].setOutlineColor(sf::Color::Black);
	enmClearText[1].setOutlineThickness(4.f);
	enmClearText[1].setPosition(sf::Vector2f(1050, 115));

}
Level::~Level()
{
	//Making pointers null
	window = nullptr;
	input = nullptr;
	gameState = nullptr;
	view = nullptr;
	world = nullptr;
	tileManager = nullptr;
	if (audioManager != nullptr) {
		delete audioManager;
		audioManager = nullptr;
	}
}

void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	//delete everything below this
	if (input->isKeyDown(sf::Keyboard::U))
	{
		input->setKeyUp(sf::Keyboard::U);
		gameState->setCurrentState(State::WIN);
	}
	if (input->isKeyDown(sf::Keyboard::I))
	{
		input->setKeyUp(sf::Keyboard::I);
		gameState->setCurrentState(State::END);
	}

	////replace with pause screen once done with everything else
	//if (input->isKeyDown(sf::Keyboard::Tab))
	//{
	//	input->setKeyUp(sf::Keyboard::Tab);
	//	gameState->setCurrentState(State::TILEEDITOR);
	//}
	f22.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	//int bltTimer = 15;
	//int enmSpawnTimer = 0;
	int enmClear = 0;

	//std::vector<Enemy> enemies;

	enmClearText[1].setString(std::to_string(enmClear));

	bg.update(dt);
	thing.update(dt);
	
	//top + bottom collision detection
	if (f22.getPosition().y <= 0)
		f22.setPosition(f22.getPosition().x, 0);
	if (f22.getPosition().y >= window->getSize().y - f22.getGlobalBounds().height)
		f22.setPosition(f22.getPosition().x, window->getSize().y - f22.getGlobalBounds().height);

	if (f22.CollisionWithTag("Enemy")) {
		audioManager->playSoundbyName("pldamage");
		f22.setPosition(1900, 1080);
		gameState->setCurrentState(State::END);
	}
}

// Render level
void Level::render()
{
	window->draw(bg);
	if (f22.isAlive()) {
		window->draw(f22);
	}
	window->draw(thing);
	window->draw(UI);
	for (int i = 0; i < 2; i++)
	{
		window->draw(enmClearText[i]);
	}
	if (gameState->getCurrentState() == State::LEVEL)
	{
		tileManager->render(false);
	}
}


void Level::adjustViewToWindowSize(unsigned int width, unsigned int height) 
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view->setSize(static_cast<float>(width), static_cast<float>(height));
	view->setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}