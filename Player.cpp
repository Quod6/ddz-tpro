#include "Player.h"

// Private functions
// Init parser
void Player::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

// Init laser
void Player::initLaser()
{
	this->laser = nullptr;
	this->laser = new Laser(&this->sprite, isPlayer, this->playerIndex);
}

// Init next newPosition
void Player::initNewNextPos()
{
	int s = static_cast<int>(this->speed);
	int i;
	switch (static_cast<int>(this->position.z))
	{
		case 0:
			this->newPosition.x = this->position.x;
			this->newPosition.y = randInt(-2 * s, this->position.y - 2 * s);
			i = randInt(0, 1);
			if (i == 0) this->newPosition.z = 3;
			else this->newPosition.z = 1;
			break;
		case 1:
			this->newPosition.x = randInt(this->position.x + 2 * s,
				this->parser->getWindowWidth() + 2 * s);
			this->newPosition.y = this->position.y;
			i = randInt(0, 1);
			if (i == 0) this->newPosition.z = 0;
			else this->newPosition.z = 2;
			break;
		case 2:
			this->newPosition.x = this->position.x;
			this->newPosition.y = randInt(this->position.y + 2 * s,
				this->parser->getWindowHeight() + 2 * s);
			i = randInt(0, 1);
			if (i == 0) this->newPosition.z = 1;
			else this->newPosition.z = 3;
			break;
		case 3:
			this->newPosition.x = randInt(-2 * s, this->position.x - 2 * s);
			this->newPosition.y = this->position.y;
			i = randInt(0, 1);
			if (i == 0) this->newPosition.z = 2;
			else this->newPosition.z = 0;
			break;
	}
}

// Init variables
void Player::initVariables(bool isPlayer, int playerIndex, float x, float y, float z)
{
	this->playerIndex = playerIndex;
	if (isPlayer)
	{
		this->texture.loadFromFile("./source/imgs/cycles.png",
			IntRect(13 + 13 * this->parser->getPlayerColor(playerIndex), 0, 13, 25));
	}
	else
	{
		this->texture.loadFromFile("./source/imgs/cycles.png",
			IntRect(0, 0, 13, 25));
	}
	this->isPlayer = isPlayer;
	this->speed = this->parser->getSpeed();
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

// Init player sprite
void Player::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2,
							this->texture.getSize().y);
	this->sprite.setPosition(this->position.x, this->position.y);
	this->sprite.setScale(2.f, 2.f);
}

// Checking collisions with walls
bool Player::wallCollision()
{
	if (this->sprite.getPosition().x < 120)
		return true;
	if (this->sprite.getPosition().x > this->parser->getWindowWidth() - 120)
		return true;
	if (this->sprite.getPosition().y < 100)
		return true;
	if (this->sprite.getPosition().y > this->parser->getWindowHeight() - 70)
		return true;
	return false;
}

// Makes BOOM
void Player::destroy(float dt)
{
	int a = 0;
	int b = 0;
	cout << a / b << endl;
}


// change angle of sprite direction
void Player::setDirection()
{
	switch (static_cast<int>(this->position.z)) {
		case 0:
			this->sprite.setRotation(0.f);
			break;
		case 1:
			this->sprite.setRotation(90.f);
			break;
		case 2:
			this->sprite.setRotation(180.f);
			break;
		case 3:
			this->sprite.setRotation(270.f);
			break;
	}
}

void Player::move(float dt)
{
	if(!this->wallCollision() && !this->isCollided)
	{
		this->setDirection();
		switch (static_cast<int>(this->position.z))
		{
			case 0:
				this->position.y -= this->speed;
				break;
			case 1:
				this->position.x += this->speed;
				break;
			case 2:
				this->position.y += this->speed;
				break;
			case 3:
				this->position.x -= this->speed;
				break;
		}
		this->sprite.setPosition(this->position.x, this->position.y);
	}
	else
	{
		this->destroy(dt);
	}
}

// Changing rotation of sprite
void Player::rotate(short direction)
{
	// Directions:
	// 0 - up
	// 1 - right
	// 2 - down
	// 3 - left

	short d1 = (direction - 1) % 4;
	short d2 = (direction + 1) % 4;

	if (d1 < 0) d1 += 4;

	if (static_cast<int>(d1) == this->position.z ||
		static_cast<int>(d2) == this->position.z)
		this->position.z = static_cast<int>(direction);
}

// Constructor & destructor
Player::Player(bool isPlayer, int playerIndex, float x, float y, float z)
{
	this->initParser();
	this->initLaser();
	// x, y - start coordinates of sprite
	this->initVariables(isPlayer, playerIndex, x, y, z);
	this->initShape();
	if (!this->isPlayer) this->initNewNextPos();
}

Player::~Player()
{
	delete this->parser;
	delete this->laser;
}

FloatRect Player::getPlayerBounds()
{
	FloatRect bounds = this->sprite.getGlobalBounds();
	switch((int)this->sprite.getRotation())
	{
		case 0:
			bounds.height = bounds.height / 2;
			break;
		case 90:
			bounds.width = bounds.width / 2;
			bounds.left += bounds.width;
			break;
		case 180:
			bounds.height = bounds.height / 2;
			bounds.top += bounds.height;
			break;
		case 270:
			bounds.width = bounds.width / 2;
			break;
	}
	return bounds;
}

vector<FloatRect> Player::getLaserBounds()
{
	return this->laser->getBounds();
}

void Player::setCollided(bool value)
{
	this->isCollided = value;
}

// Public functions
void Player::updateInput(float dt)
{
	if (this->isPlayer)
	{
		// Keyboadr input
		if (this->parser->getControl() == "letters")
		{
			if(Keyboard::isKeyPressed(Keyboard::A))
				this->rotate(3);
			else if(Keyboard::isKeyPressed(Keyboard::W))
				this->rotate(0);
			else if(Keyboard::isKeyPressed(Keyboard::S))
				this->rotate(2);
			else if(Keyboard::isKeyPressed(Keyboard::D))
				this->rotate(1);
		}
		else
		{
			if(Keyboard::isKeyPressed(Keyboard::Left))
				this->rotate(3);
			else if(Keyboard::isKeyPressed(Keyboard::Up))
				this->rotate(0);
			else if(Keyboard::isKeyPressed(Keyboard::Down))
				this->rotate(2);
			else if(Keyboard::isKeyPressed(Keyboard::Right))
				this->rotate(1);
		}
	}
	else
	{
		if (this->position.x == this->newPosition.x &&
			this->position.y == this->newPosition.y)
		{
			this->rotate(this->newPosition.z);
			this->initNewNextPos();
		}
	}
	this->move(dt);
}

void Player::update(float dt)
{
	this->updateInput(dt);
	this->laser->update(&this->sprite);
}

void Player::render(RenderTarget *target)
{
	target->draw(this->sprite);
	this->laser->render(target);
}
