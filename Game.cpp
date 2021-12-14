#include "Game.h"

// Private functions
void Game::initVariables()
{
	// Init window & main variables
	this->window = nullptr;
	this->player = nullptr;
	this->endGame = false;

	// Init fonts
	this->cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	this->asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Init sounds
	this->buffer.loadFromFile("./source/sounds/laser.ogg");
	this->sound.setBuffer(this->buffer);
	this->sound.setVolume(5.f);

	// Init music
	this->phonk.openFromFile("./source/sounds/LVL-DEATH.ogg");
	this->phonk.setVolume(10.f);

	// Init background
	this->bgTexture.loadFromFile("./source/imgs/map3.png");
	this->bgSprite.setTexture(this->bgTexture);
	this->bgSprite.setOrigin(this->bgTexture.getSize().x / 2,
							 this->bgTexture.getSize().y / 2);
	this->bgSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	this->bgSprite.setScale(WINDOW_WIDTH / this->bgTexture.getSize().x,
							WINDOW_HEIGHT / this->bgTexture.getSize().y);

}

void Game::initPlayer()
{
	this->player = new Player(200.f, 200.f);
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
	this->initPlayer();
	this->initWindow();
	this->phonk.play();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
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

	this->player->update();
}

void Game::render()
{
	// Clear old frame
	this->window->clear();

	// Draw game objects
	this->window->draw(this->bgSprite);
	this->player->render(this->window);

	// Display new frame
	this->window->display();
}
