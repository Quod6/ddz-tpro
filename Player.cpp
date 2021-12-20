#include "Player.h"

// Private functions
// Init parser
void Player::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
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
void Player::initVariables(bool isPlayer, float x, float y, float z)
{
	if (isPlayer)
	{
		this->texture.loadFromFile("./source/imgs/cycles.png",
			IntRect(13 + 13 * this->parser->getPlayerColor(), 0, 13, 25));
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
/*
// Init laser
void Player::initLaser()
{
		this->laser = nullptr;
		this->laser = new Laser(this->position);
}
*/
// Init player sprite
void Player::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2,
							this->texture.getSize().y / 2);
	this->sprite.setPosition(this->position.x, this->position.y);
	this->sprite.setScale(2.f, 2.f);
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
	if(1 == 1)
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

// Makes BOOM
void Player::destroy(float dt)
{

}

// Makes laser
void Player::makeLaser()
{

}

// Constructor & destructor
Player::Player(bool isPlayer, float x, float y, float z)
{
	this->initParser();

	// x, y - start coordinates of sprite
	this->initVariables(isPlayer, x, y, z);
	this->initShape();
	// this->initLaser();
	if (!this->isPlayer) this->initNewNextPos();
}

Player::~Player()
{
	delete this->parser;
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
	this->makeLaser();
}

void Player::render(RenderTarget *target)
{
	target->draw(this->sprite);
}
