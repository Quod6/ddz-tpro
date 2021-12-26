#include "Laser.h"

// Init parser
void Laser::initParser()
{
	this->parser = nullptr;
	this->parser = new ConstParser();
	this->parser->parse("./config.txt");
}

// Init variables
void Laser::initVariables(Sprite * sprite, bool isPlayer, int playerIndex)
{
	this->playerIndex = playerIndex;
	this->oldPos = sprite->getPosition();
	Texture texture;
	this->oldAngle = sprite->getRotation();
	this->lines.clear();
	this->positions.clear();

	if (isPlayer)
	{
		this->textureV.loadFromFile("./source/imgs/laserV.png",
			IntRect(4 + 4 * this->parser->getPlayerColor(this->playerIndex), 0, 1280, 4));
		this->textureH.loadFromFile("./source/imgs/laserH.png",
			IntRect(0, 4 + 4 * this->parser->getPlayerColor(this->playerIndex), 4, 720));
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
			this->oldPos.y += 30;
			break;
		case 90:
			this->sprite.setTexture(this->textureH);
			this->oldPos.x -= 30;
			break;
		case 180:
			this->sprite.setTexture(this->textureV);
			this->oldPos.y -= 30;
			break;
		case 270:
			this->sprite.setTexture(this->textureH);
			this->oldPos.x += 30;
			break;
	}
}

// Constructor
Laser::Laser(Sprite * sprite, bool isPlayer, int playerIndex)
{
	this->initParser();
	this->initVariables(sprite, isPlayer, playerIndex);
}

Laser::~Laser()
{

}

// Get global bounds for collision
vector<FloatRect> Laser::getBounds()
{
	vector<FloatRect> bounds;
	bounds.clear();

	for (unsigned i = 0; i < this->lines.size(); i++)
		bounds.push_back(this->lines[i].getGlobalBounds());

	return bounds;
}

// Update
void Laser::update(Sprite * sprite)
{
	if (this->oldAngle == sprite->getRotation())
	{
		float dx, dy, ds;
		ds = sprite->getTexture()->getSize().y / 2 + 20;

		switch ((int)this->oldAngle)
		{
			case 0:
				dx = 0;
				dy = sprite->getPosition().y - this->oldPos.y + ds;
				break;
			case 90:
				dx = sprite->getPosition().x - this->oldPos.x - ds;
				dy = 0;
				break;
			case 180:
				dx = 0;
				dy = sprite->getPosition().y - this->oldPos.y - ds;
				break;
			case 270:
				dx = sprite->getPosition().x - this->oldPos.x + ds;
				dy = 0;
				break;
		}

		if (dx == 0)
		{
			if (dy < 0)
				this->sprite.setRotation(180.f);
			else
				this->sprite.setRotation(0.f);

			this->sprite.setTextureRect({4 + 4 * this->parser->getPlayerColor(this->playerIndex),
				0,
				4,
				(int)dy});
		}
		if (dy == 0)
		{
			if (dx < 0)
				this->sprite.setRotation(180.f);
			else
				this->sprite.setRotation(0.f);

			this->sprite.setTextureRect({0,
				4 + 4 * this->parser->getPlayerColor(this->playerIndex),
				(int)dx,
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

		switch ((int)this->oldAngle) {
			case 0:
				this->oldPos.y += 30;
				break;
			case 90:
				this->oldPos.x -= 30;
				break;
			case 180:
				this->oldPos.y -= 30;
				break;
			case 270:
				this->oldPos.x += 30;
				break;
		}
	}
}

// Render
void Laser::render(RenderTarget *target)
{
	for(unsigned i = 0; i < this->lines.size(); i++)
		target->draw(this->lines[i]);
}
