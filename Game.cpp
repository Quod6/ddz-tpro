#include "Game.h"

// Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	this->asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");
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
}

void Game::render()
{
	this->window->clear();

	// Draw game objects

	this->window->display();
}
