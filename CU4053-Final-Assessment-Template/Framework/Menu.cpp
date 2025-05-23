#include "Menu.h"
#include "Utilities.h"
Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;
	audioManager = new AudioManager();

	audioManager->addMusic("bgm/menubgm.wav", "menu"); //"Arcade Title" from Ace Combat: Squadron Leader
	audioManager->playMusicbyName("menu");

	UIfont.loadFromFile("font/msgothic.ttc");

	menu_texture.loadFromFile("gfx/menu.png");
	menu_sprite.setTexture(menu_texture);
	
	//Scaling the sprite to fit any screen 
	auto bounds = menu_sprite.getLocalBounds();
	float originalWidth = bounds.width;
	float originalHeight = bounds.height;

	float scaleX = SCREEN_WIDTH / originalWidth;
	float scaleY = SCREEN_HEIGHT / originalHeight;

	// To maintain aspect ratio, use the smaller of the two scales
	float uniformScale = std::min(scaleX, scaleY);

	//fun ui text
	UIText[0].text.setFont(UIfont);
	UIText[0].text.setFillColor(sf::Color::White);
	UIText[0].text.setString("Play");
	UIText[0].text.setPosition(sf::Vector2f(461, 480));
	UIText[0].setCollisionBox(sf::FloatRect(600, 135, 35, 15));

	UIText[1].text.setFont(UIfont);
	UIText[1].text.setFillColor(sf::Color{ 0x99FFD5FF });
	UIText[1].text.setString("Exit");
	UIText[1].text.setPosition(sf::Vector2f(672, 480));
	UIText[1].setCollisionBox(sf::FloatRect(600, 165, 35, 15));

	selectedItem = 0;
}
Menu::~Menu()
{
}

void Menu::update(float dt)
{
	// Update the position of the text
	sf::Vector2u windowSize = window->getSize();

	//if this code was for the mouse position thing then i don't need it
	//UIText[0].text.setPosition(sf::Vector2f(windowSize.x / 2 - UIText[0].text.getGlobalBounds().width / 2, 120));
	//UIText[0].setCollisionBox(sf::FloatRect(windowSize.x / 2 - UIText[0].text.getGlobalBounds().width / 2, 135, 35, 15));

	//UIText[1].text.setPosition(windowSize.x / 2 - UIText[1].text.getGlobalBounds().width / 2, 150);
	//UIText[1].setCollisionBox(sf::FloatRect(windowSize.x / 2 - UIText[1].text.getGlobalBounds().width / 2, 165, 35, 15));


	//// Update mouse position
	//MousePos.x = input->getMouseX();
	//MousePos.y = input->getMouseY();

	//for (int i = 0; i < 2; i++) {
	//	if (Collision::checkBoundingBox(UIText[i].getCollisionBox(), MousePos)) {
	//		if (!mouseOverAnyItem) { // Only change if the mouse wasn't already over an item
	//			selectedItem = i;
	//			mouseOverAnyItem = true;
	//		}
	//	}
	//}

	updateVisualFeedback(); // Update visual feedback at the end to reflect any changes
}

void Menu::updateVisualFeedback()
{
	for (int i = 0; i < 2; i++) {
		if (i == selectedItem) {
			UIText[i].text.setFillColor(sf::Color::White); // Highlight selected item
		}
		else {
			UIText[i].text.setFillColor(sf::Color{ 0x99FFD5FF }); // Default color for non-selected items
		}
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem--;
		UIText[selectedItem].text.setFillColor(sf::Color{ 0x99FFD5FF });
	}
}
void Menu::MoveDown()
{
	if (selectedItem + 1 < 2)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem++;
		UIText[selectedItem].text.setFillColor(sf::Color{ 0x99FFD5FF });
	}

}
void Menu::handleInput(float dt)
{
	// Keyboard handling for menu navigation
	if (input->isKeyDown(sf::Keyboard::A)) {
		MoveUp();
		input->setKeyUp(sf::Keyboard::Left);
	}

	if (input->isKeyDown(sf::Keyboard::D)) {
		MoveDown();
		input->setKeyUp(sf::Keyboard::Right);
	}

	// Execute action for the current selected item
	if (input->isKeyDown(sf::Keyboard::Enter)) {
		switch (selectedItem) {
		case 0:
			audioManager->stopAllMusic();
			audioManager->addMusic("bgm/stagebgm.wav", "bgm1"); //"The Objective" from Ridge Racer Type 4
			audioManager->playMusicbyName("bgm1");
			gameState->setCurrentState(State::LEVEL);
			break;
		case 1:
			exit(0);
			break;
		}

		// Reset input states
		if (input->isKeyDown(sf::Keyboard::Enter)) {
			input->setKeyUp(sf::Keyboard::Enter);
		}
	}

}

void Menu::render()
{
	window->draw(menu_sprite);
	for (int i = 0; i < 2; i++)
	{
		window->draw(UIText[i].text);
	}

	//Uncomment so debug shapes for the menu text
	//for (int i = 0; i < 2; i++)
	//{
	//	window->draw(UIText[i].getDebugShape());
	//}

}