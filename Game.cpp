#include "Game.h"

// Private functions
void Game::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

void Game::initVariables()
{
	// Init window & main variables
	this->window = nullptr;
	this->endGame = false;
	this->seconds = 0.f;

	// Init fonts
	this->cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	this->asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Set fonts to text
	this->player1Name.setFont(this->cyberwayFont);
	this->player2Name.setFont(this->cyberwayFont);
	this->timeText.setFont(this->cyberwayFont);

	// Set size of text
	this->player1Name.setCharacterSize(50);
	this->player2Name.setCharacterSize(50);
	this->timeText.setCharacterSize(50);

	// Set color of text
	Color color;
	switch (this->parser->getPlayerColor(0))
	{
		case 0:
			color.r = 0;
			color.g = 0;
			color.b = 255;
			break;
		case 1:
			color.r = 255;
			color.g = 0;
			color.b = 0;
			break;
		case 2:
			color.r = 0;
			color.g = 255;
			color.b = 0;
			break;
		case 3:
			color.r = 255;
			color.g = 0;
			color.b = 255;
			break;
	}
	this->player1Name.setFillColor(color);
	switch (this->parser->getPlayerColor(1))
	{
		case 0:
			color.r = 0;
			color.g = 0;
			color.b = 255;
			break;
		case 1:
			color.r = 255;
			color.g = 0;
			color.b = 0;
			break;
		case 2:
			color.r = 0;
			color.g = 255;
			color.b = 0;
			break;
		case 3:
			color.r = 255;
			color.g = 0;
			color.b = 255;
			break;
	}
	this->player2Name.setFillColor(color);
	color.r = 248;
	color.g = 241;
	color.b = 62;
	this->timeText.setFillColor(color);

	// Set strings to text
	this->player1Name.setString(this->parser->getPlayerName(0));
	this->player2Name.setString(this->parser->getPlayerName(1));
	this->timeText.setString("Time: " + to_string((int)this->seconds));

	// Set position to text
	this->player1Name.setPosition(80, 10);
	this->player2Name.setPosition(1200 - (32 * this->parser->getPlayerName(1).size()), 10);
	this->timeText.setPosition(525, 10);

	// Init sounds
	this->buffer.loadFromFile("./source/sounds/laser.ogg");
	this->sound.setBuffer(this->buffer);
	this->sound.setVolume(5.f);

	// Init music
	this->phonk.openFromFile("./source/sounds/CYBERSITY.ogg");
	this->phonk.setVolume(20.f);

	// Init background

	switch(this->parser->getMapIndex())
	{
		case 0:
			this->bgTexture.loadFromFile("./source/imgs/map3.png");
			break;
		case 1:
			this->bgTexture.loadFromFile("./source/imgs/map4.png");
			break;
		case 2:
			this->bgTexture.loadFromFile("./source/imgs/map5.png");
			break;
		default:
			this->bgTexture.loadFromFile("./source/imgs/map3.png");
	}
	this->bgSprite.setTexture(this->bgTexture);
	this->bgSprite.setOrigin(this->bgTexture.getSize().x / 2,
							 this->bgTexture.getSize().y / 2);
	this->bgSprite.setPosition(
		this->parser->getWindowWidth() / 2,
		this->parser->getWindowHeight() / 2);
	this->bgSprite.setScale(
		this->parser->getWindowWidth() / this->bgTexture.getSize().x,
		this->parser->getWindowHeight() / this->bgTexture.getSize().y);

}

void Game::initPlayers()
{
	this->players.clear();

	this->players.push_back(new Player(true, 0, 250, 375));

	if (this->parser->getPlayerCount() == 2)
		this->players.push_back(new Player(true, 1, 1030, 375, 3));
}

void Game::initBots()
{
	this->bots.clear();
	switch (this->parser->getBotCount())
	{
		case 0:
			break;
		case 1:
			this->bots.push_back(new Player(false, -1, 1030, 375, 3));
			break;
		case 2:
			this->bots.push_back(new Player(false, -1, 1030, 300, 3));
			this->bots.push_back(new Player(false, -1, 1030, 450, 3));
			break;
		case 3:
			this->bots.push_back(new Player(false, -1, 1030, 300, 3));
			this->bots.push_back(new Player(false, -1, 1030, 450, 3));
			this->bots.push_back(new Player(false, -1, 800, 375, 3));
			break;
		case 4:
			this->bots.push_back(new Player(false, -1, 1030, 300, 3));
			this->bots.push_back(new Player(false, -1, 1030, 450, 3));
			this->bots.push_back(new Player(false, -1, 800, 350, 3));
			this->bots.push_back(new Player(false, -1, 800, 400, 3));
			break;
	}
}

void Game::initWindow()
{
	this->window = new RenderWindow(
		VideoMode(this->parser->getWindowWidth(), this->parser->getWindowHeight()),
		"TRON", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(180);
}

// Updating Timer text
void Game::updateTimer(float dt)
{
	this->seconds += dt / 1000;
	this->timeText.setString("Time: " + to_string((int)this->seconds));
}

// Rendering text of Names & Timer
void Game::renderText()
{
	this->window->draw(this->player1Name);
	if (this->parser->getPlayerCount() == 2)
		this->window->draw(this->player2Name);
	this->window->draw(this->timeText);
}

void Game::getBoundsOfEntities()
{
	this->boundsOfEntities.clear();
	this->boundsOfMajorEntities.clear();
	vector<FloatRect> bounds;
	PlayerBounds playerBounds;
	bounds.clear();


	for(unsigned i = 0; i < this->players.size(); i++)
	{
		this->boundsOfEntities.push_back(this->players[i]->getPlayerBounds());
		playerBounds.player = this->players[i];
		playerBounds.bounds = this->players[i]->getPlayerBounds();
		this->boundsOfMajorEntities.push_back(playerBounds);
		bounds = this->players[i]->getLaserBounds();
		for (unsigned j = 0; j < bounds.size(); j++)
			this->boundsOfEntities.push_back(bounds[j]);
	}
	bounds.clear();

	for(unsigned i = 0; i < this->bots.size(); i++)
	{
		this->boundsOfEntities.push_back(this->bots[i]->getPlayerBounds());
		playerBounds.player = this->bots[i];
		playerBounds.bounds = this->bots[i]->getPlayerBounds();
		this->boundsOfMajorEntities.push_back(playerBounds);
		bounds = this->bots[i]->getLaserBounds();
		for (unsigned j = 0; j < bounds.size(); j++)
			this->boundsOfEntities.push_back(bounds[j]);
	}
}

void Game::checkGlobalCollision()
{
	this->getBoundsOfEntities();
	for (unsigned i = 0; i < this->boundsOfMajorEntities.size(); i++)
	{
		for (unsigned j = 0; j < this->boundsOfEntities.size(); j++)
		{
			if (this->boundsOfMajorEntities[i].bounds == this->boundsOfEntities[j])
				continue;
			if (this->boundsOfMajorEntities[i].bounds.intersects(this->boundsOfEntities[j]))
				this->boundsOfMajorEntities[i].player->setCollided(true);
		}
	}
}

bool Game::checkGameResult()
{

		if (this->parser->getPlayerCount() == 1)
		{
			if (this->bots.size() != 0)
			{
				if (this->players[0]->getCollided())
				{
					this->gameResult(-1);
					return true;
				}

				bool isAllBotsDestroyed = true;
				for (unsigned i = 0; i < this->bots.size(); i++)
					isAllBotsDestroyed = isAllBotsDestroyed && this->bots[i]->getCollided();

				if (isAllBotsDestroyed)
				{
					this->gameResult(1);
					return true;
				}
			}
		}
		else
		{
			if (this->players[0]->getCollided() && !this->players[1]->getCollided())
			{
				this->gameResult(-1);
				return true;
			}
			else if (this->players[1]->getCollided() && this->players[0]->getCollided())
			{
				this->gameResult(0);
				return true;
			}
			else if (!this->players[0]->getCollided() && this->players[1]->getCollided())
			{
				this->gameResult(1);
				return true;
			}
			else return false;
		}

	return false;
}

void Game::gameResult(int isPl1Win)
{
	if (this->parser->getPlayerCount() == 1)
	{
		switch (isPl1Win)
		{
			case -1:
				this->endGameTexture.loadFromFile("./source/concept/lose.png");
				break;
			case 1:
				this->endGameTexture.loadFromFile("./source/concept/win.png");
				break;
		}
	}
	else
	{
		switch (isPl1Win)
		{
			case -1:
				this->endGameTexture.loadFromFile("./source/concept/1l2w.png");
				break;
			case 0:
				this->endGameTexture.loadFromFile("./source/concept/draw.png");
				break;
			case 1:
				this->endGameTexture.loadFromFile("./source/concept/1w2l.png");
				break;
		}
	}
	this->endGameSprite.setTexture(this->endGameTexture);
	this->endGameSprite.setScale(1280.f / this->endGameTexture.getSize().x,
		720.f / this->endGameTexture.getSize().y);
	this->endGameSprite.setPosition(0, 0);
}

// Constructor & destructor
Game::Game()
{
	this->initParser();
	this->initVariables();
	this->initPlayers();
	this->initBots();
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
RenderWindow* Game::getGameWindow()
{
	return this->window;
}

Event * Game::getGameEvent()
{
	return &this->evnt;
}

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

void Game::update(float dt)
{
	// this->pollEvents();
	this->checkGlobalCollision();

	this->endGame = checkGameResult();

	this->updateTimer(dt);

	for (unsigned i = 0; i < this->players.size(); i++)
		this->players[i]->update(dt);
	for (unsigned i = 0; i < this->bots.size(); i++)
		this->bots[i]->update(dt);
}

void Game::render()
{
	// Clear old frame
	this->window->clear();

	// Draw game objects
	this->window->draw(this->bgSprite);

	this->renderText();

	for (unsigned i = 0; i < this->players.size(); i++)
		this->players[i]->render(this->window);
	for (unsigned i = 0; i < this->bots.size(); i++)
		this->bots[i]->render(this->window);

	if (this->endGame)
		this->window->draw(this->endGameSprite);

	// Display new frame
	this->window->display();
}
