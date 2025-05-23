#include "Player.h"

Player::Player()
{
	pLives = 1;
	pDmg = 4;

	f22Tex.loadFromFile("gfx/f22sheet.png");
	setSize(sf::Vector2f(34 * 2, 37 * 2));
	setPosition(606, 600);
	setTexture(&f22Tex);

	//idle
	f22Idle.addFrame(sf::IntRect(0, 0, 34, 37));
	f22Idle.addFrame(sf::IntRect(34, 0, 34, 37));
	f22Idle.addFrame(sf::IntRect(68, 0, 34, 37));
	f22Idle.addFrame(sf::IntRect(102, 0, 34, 37));
	f22Idle.addFrame(sf::IntRect(136, 0, 34, 37));
	f22Idle.addFrame(sf::IntRect(170, 0, 34, 37));
	f22Idle.setFrameSpeed(1.f / 15.f);

	//move left
	f22MLeft.addFrame(sf::IntRect(0, 37, 34, 37));
	f22MLeft.addFrame(sf::IntRect(34, 37, 34, 37));
	f22MLeft.addFrame(sf::IntRect(68, 37, 34, 37));
	f22MLeft.addFrame(sf::IntRect(102, 37, 34, 37));
	f22MLeft.setFrameSpeed(1.f / 15.f);

	//move right
	f22MRight.addFrame(sf::IntRect(0, 74, 34, 37));
	f22MRight.addFrame(sf::IntRect(34, 74, 34, 37));
	f22MRight.addFrame(sf::IntRect(68, 74, 34, 37));
	f22MRight.addFrame(sf::IntRect(102, 74, 34, 37));
	f22MRight.setFrameSpeed(1.f / 15.f);
	//literally couldve been easier to do isFlipped->(true) or whatever it was but i like being extra

	curF22Anim = &f22Idle;
	setTextureRect(curF22Anim->getCurrentFrame());
	setTag("Player");
}

Player::~Player()
{
	//is this ever used for anything
}

void Player::handleInput(float dt)
{
	velocity.x = 0.f;
	velocity.y = 0.f;
	curF22Anim->animate(dt); //putting this before the controls at the end actually makes the idle animation work
	setTextureRect(curF22Anim->getCurrentFrame());

	//player controls
	if (input->isKeyDown(sf::Keyboard::D)) {
		curF22Anim = &f22MRight;
		velocity = sf::Vector2f(100, 0);
		move(velocity * dt);
	}
	else {
		curF22Anim = &f22Idle; //somehow putting this here instead of at the end makes the right animation work, wonder why exactly
	} 
	if (input->isKeyDown(sf::Keyboard::A)) {
		curF22Anim = &f22MLeft;
		velocity = sf::Vector2f(-100, 0);
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::W)) {
		curF22Anim = &f22Idle;
		velocity = sf::Vector2f(0, -100);
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S)) {
		curF22Anim = &f22Idle;
		velocity = sf::Vector2f(0, 150);
		move(velocity * dt);
	}

	move(velocity * dt);
}
