#include "Player.h"

// Private functions
// Init parser
void Player::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

// Init variables
void Player::initVariables(float x, float y)
{
	this->texture.loadFromFile("./source/imgs/cycles.png",
					IntRect(13 + 13 * this->parser->getPlayerColor(), 0, 13, 25));
	this->speed = this->parser->getSpeed();
	this->position.x = x;
	this->position.y = y;
	this->position.z = 1.f;
}

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
	switch ((int)this->position.z) {
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

void Player::move()
{
	if(1 == 1)
	{
		this->setDirection();
		switch ((int)this->position.z)
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
		this->destroy();
	}
}

// Changing rotation of sprite
void Player::rotate(int direction)
{
	// Directions:
	// 0 - up
	// 1 - right
	// 2 - down
	// 3 - left

	short d1 = (direction - 1) % 4;
	short d2 = (direction + 1) % 4;

	if (d1 < 0) d1 += 4;

	if (d1 == this->position.z || d2 == this->position.z)
		this->position.z = direction;
}

// Makes BOOM
void Player::destroy()
{

}

// Constructor & destructor
Player::Player(float x, float y)
{
	this->initParser();

	// x, y - start coordinates of sprite
	this->initVariables(x, y);
	this->initShape();
}

Player::~Player()
{
	delete this->parser;
}

// Public functions
void Player::updateInput()
{
	// Keyboadr input
	if(Keyboard::isKeyPressed(Keyboard::A)) this->rotate(3);
	else if(Keyboard::isKeyPressed(Keyboard::W)) this->rotate(0);
	else if(Keyboard::isKeyPressed(Keyboard::S)) this->rotate(2);
	else if(Keyboard::isKeyPressed(Keyboard::D)) this->rotate(1);

	this->move();
}

void Player::update()
{
	this->updateInput();
}

void Player::render(RenderTarget *target)
{
	target->draw(this->sprite);
}
