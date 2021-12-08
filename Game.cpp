#include "Game.h"

// Private functions
void Game::initVariables()
{
	// Init window
	this->window = nullptr;

	// Init fonts
	this->cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	this->asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Init sounds
	this->buffer.loadFromFile("./source/sounds/laser.ogg");
	this->sound.setBuffer(this->buffer);
	this->sound.setVolume(5.f);

	// Init music
	this->phonk.openFromFile("./source/sounds/phonk.ogg");

	// Init background
	this->bgTexture.loadFromFile("./source/imgs/map3.png");
	this->bgSprite.setTexture(this->bgTexture);
	this->bgSprite.setOrigin(this->bgTexture.getSize().x / 2,
							 this->bgTexture.getSize().y / 2);
	this->bgSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	this->bgSprite.setScale(WINDOW_WIDTH / this->bgTexture.getSize().x,
							WINDOW_HEIGHT / this->bgTexture.getSize().y);
}

void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
									"TRON", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(60);
}

// Constructor & destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->phonk.play();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

// Public functions
void Game::pollEvents()
{
	while(this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type) {
			case Event::Closed:
				this->window->close();
				break;
			case Event::KeyPressed:
				if(this->evnt.key.code == Keyboard::Escape) this->window->close();
				break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->sound.play();
}

void Game::render()
{
	// Clear old frame
	this->window->clear();

	// Draw game objects
	this->window->draw(this->bgSprite);

	// Display new frame
	this->window->display();
}
