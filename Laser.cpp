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
	this->oldAngle = sprite->getRotation();
	this->lines.clear();
	this->positions.clear();
	this->sprites.clear();

	if (isPlayer)
	{
		this->texture.loadFromFile("./source/imgs/laser.png",
			IntRect(1 + this->parser->getPlayerColor(), 0, 1, 4));
	}
	else
	{
		this->texture.loadFromFile("./source/imgs/laser.png",
			IntRect(0, 0, 1, 4));
	}

	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2,
		this->texture.getSize().y / 2);
	this->sprite.setScale(2.f, 2.f);
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
	if ((int)sprite->getRotation() != (int)this->oldAngle && this->sprites.size() != 0)
	{
		Sprite lineSprite;
		lineSprite.setTexture(this->texture);

		lineSprite.setScale((float)this->sprites.size(), 1.f);

		lineSprite.setOrigin(lineSprite.getScale().x / 2,
			lineSprite.getScale().y / 2);

		float x = 0;
		float y = 0;

		x = this->sprites[0].getPosition().x +
			this->sprites[this->sprites.size() - 1].getPosition().x;

		y = this->sprites[0].getPosition().y +
			this->sprites[this->sprites.size() - 1].getPosition().y;

		x = x / 2;
		y = y / 2;

		lineSprite.setPosition(x, y);

		lineSprite.setRotation(this->oldAngle);

		this->lines.push_back(lineSprite);
		this->sprites.clear();
		this->oldAngle = sprite->getRotation();
	}

	Vector3f cyclePos;
	switch((int)sprite->getRotation())
	{
		case 0:
			cyclePos.x = sprite->getPosition().x;
			cyclePos.y = sprite->getPosition().y +
						sprite->getTexture()->getSize().y / 2 +
						this->parser->getSpeed();
			cyclePos.z = 0;
			break;
		case 90:
			cyclePos.x = sprite->getPosition().x  -
						sprite->getTexture()->getSize().y / 2 -
						this->parser->getSpeed();
			cyclePos.y = sprite->getPosition().y;
			cyclePos.z = 1;
			break;
		case 180:
			cyclePos.x = sprite->getPosition().x;
			cyclePos.y = sprite->getPosition().y -
						sprite->getTexture()->getSize().y / 2 -
						this->parser->getSpeed();
			cyclePos.z = 2;
			break;
		case 270:
			cyclePos.x = sprite->getPosition().x  +
						sprite->getTexture()->getSize().y / 2 +
						this->parser->getSpeed();
			cyclePos.y = sprite->getPosition().y;
			cyclePos.z = 3;
			break;
	}
	this->positions.push_back(cyclePos);
	this->sprite.setPosition(cyclePos.x, cyclePos.y);
	this->sprite.setRotation(sprite->getRotation());
	this->sprites.push_back(this->sprite);
}

// Render
void Laser::render(RenderTarget *target)
{
	for(unsigned i = 0; i < this->lines.size(); i++)
		target->draw(this->lines[i]);
	for(unsigned i = 0; i < this->sprites.size(); i++)
		target->draw(this->sprites[i]);
}
