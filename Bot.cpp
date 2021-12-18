#include "Bot.h"

// Private functions
// Init parser
void Bot::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

// Init next newPosition
void Bot::initNewNextPos()
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
void Bot::initVariables(float x, float y, float z)
{
	this->texture.loadFromFile("./source/imgs/cycles.png",
					IntRect(0, 0, 13, 25));
	this->speed = this->parser->getSpeed();
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;

	this->initNewNextPos();
}

// Init player sprite
void Bot::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2,
							this->texture.getSize().y / 2);
	this->sprite.setPosition(this->position.x, this->position.y);
	this->sprite.setScale(2.f, 2.f);
}

// change angle of sprite direction
void Bot::setDirection()
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

void Bot::move()
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
		this->destroy();
	}
}

// Changing rotation of sprite
void Bot::rotate(short direction)
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
void Bot::destroy()
{

}

// Constructor & destructor
Bot::Bot(float x, float y, float z)
{
	this->initParser();

	// x, y - start coordinates of sprite
	this->initVariables(x, y, z);
	this->initShape();
}

Bot::~Bot()
{
	delete this->parser;
}

// Public functions
void Bot::updateInput()
{
	if (this->position.x == this->newPosition.x && this->position.y == this->newPosition.y)
	{
		this->rotate(this->newPosition.z);
		this->initNewNextPos();
	}

	this->move();
}

void Bot::update()
{
	this->updateInput();
}

void Bot::render(RenderTarget *target)
{
	target->draw(this->sprite);
}
