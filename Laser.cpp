#include "Laser.h"

// Init parser
void Laser::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

// Init variables
void Laser::initVariables(Sprite * sprite, bool isPlayer)
{
	this->oldPos = sprite->getPosition();
	Texture texture;
	this->oldAngle = sprite->getRotation();
	this->lines.clear();
	this->positions.clear();
	this->sprites.clear();

	if (isPlayer)
	{
		this->textureV.loadFromFile("./source/imgs/laserV.png",
			IntRect(4 + 4 * this->parser->getPlayerColor(), 0, 1280, 4));
		this->textureH.loadFromFile("./source/imgs/laserH.png",
			IntRect(0, 4 + 4 * this->parser->getPlayerColor(), 4, 720));
	}
	else
	{
		this->textureV.loadFromFile("./source/imgs/laserV.png",
			IntRect(0, 0, 1280, 4));
		this->textureH.loadFromFile("./source/imgs/laserH.png",
			IntRect(0, 0, 4, 720));
	}

	switch ((int)sprite->getRotation()) {
		case 0:
			this->sprite.setTexture(this->textureV);
			break;
		case 90:
			this->sprite.setTexture(this->textureH);
			break;
		case 180:
			this->sprite.setTexture(this->textureV);
			break;
		case 270:
			this->sprite.setTexture(this->textureH);
			break;
	}
}

// Constructor
Laser::Laser(Sprite * sprite, bool isPlayer)
{
	this->initParser();
	this->initVariables(sprite, isPlayer);
}

Laser::~Laser()
{

}

// Update
void Laser::update(Sprite * sprite)
{
	if (this->oldAngle == sprite->getRotation())
	{
		float dx, dy;
		dx = sprite->getPosition().x - this->oldPos.x;
		dy = sprite->getPosition().y - this->oldPos.y;

		if (dx == 0)
		{
			if (dy < 0)
				this->sprite.setRotation(180.f);
			else
				this->sprite.setRotation(0.f);

			this->sprite.setTextureRect({4 + 4 * this->parser->getPlayerColor(),
				0,
				4,
				abs((int)dy)});
		}
		if (dy == 0)
		{
			if (dx < 0)
				this->sprite.setRotation(180.f);
			else
				this->sprite.setRotation(0.f);

			this->sprite.setTextureRect({0,
				4 + 4 * this->parser->getPlayerColor(),
				abs((int)dx),
				4});
		}

		this->sprite.setPosition(this->oldPos.x, this->oldPos.y);
		this->lines.push_back(this->sprite);
	}
	else
	{
		switch ((int)sprite->getRotation()) {
			case 0:
				this->sprite.setTexture(this->textureV);
				break;
			case 180:
				this->sprite.setTexture(this->textureV);
				break;
			case 270:
				this->sprite.setTexture(this->textureH);
				break;
			case 90:
				this->sprite.setTexture(this->textureH);
				break;
		}
		this->oldPos = sprite->getPosition();
		this->oldAngle = sprite->getRotation();
	}
}

// Render
void Laser::render(RenderTarget *target)
{
	for(unsigned i = 0; i < this->lines.size(); i++)
		target->draw(this->lines[i]);
	for(unsigned i = 0; i < this->sprites.size(); i++)
		target->draw(this->sprites[i]);
}
