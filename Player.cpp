#include "Player.h"

// Private functions
// Init variables
void Player::initVariables()
{
	this->texture.loadFromFile("./source/imgs/cycles.png", IntRect(13, 0, 13, 25));
	this->speed = 3.f;
}

// Init player sprite
void Player::initShape(float x, float y)
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2,
							this->texture.getSize().y / 2);
	this->sprite.setPosition(x, y);
}

// change angle of sprite direction
void Player::setDirection()
{
	switch (this->position.z) {
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
		switch (this->position.z)
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
	// x, y - start coordinates of sprite

	this->initVariables();
	this->initShape(x, y);
}

Player::~Player()
{

}

// Public functions
void Player::updateInput()
{
	// Keyboadr input
	if(Keyboard::isKeyPressed(Keyboard::A)) this->rotate(3);
	if(Keyboard::isKeyPressed(Keyboard::W)) this->rotate(0);
	if(Keyboard::isKeyPressed(Keyboard::S)) this->rotate(2);
	if(Keyboard::isKeyPressed(Keyboard::D)) this->rotate(1);

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
