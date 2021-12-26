#include "ConstParser.h"

ConstParser::ConstParser()
{
	this->WINDOW_WIDTH = 1280;
	this->WINDOW_HEIGHT = 720;
	this->SPEED = 1.f;
	this->MAX_SPEED = 20.f;
	this->PLAYER_COLOR1 = 0;
	this->PLAYER_COLOR2 = 1;
	this->MAP_INDEX = 0;
	this->PLAYER_COUNT = 1;
	this->BOT_COUNT = 0;
	this->CONTROL = "letters";
}

void ConstParser::parse(string filepath)
{
	ifstream file(filepath);
	string str;
	string token;
	string value;
	size_t pos;

	while(getline(file,str))
	{
		value = str;
		pos = value.find(' ');
		token = value.substr(0, pos);
		value.erase(0, pos + 1);

		if (token == "//") continue;
		else if (token == "WINDOW_WIDTH") this->WINDOW_WIDTH = stoi(value);
		else if (token == "WINDOW_HEIGHT") this->WINDOW_HEIGHT = stoi(value);
		else if (token == "SPEED") this->SPEED = stof(value);
		else if (token == "MAX_SPEED") this->MAX_SPEED = stof(value);
		else if (token == "PLAYER_COLOR1") this->PLAYER_COLOR1 = stoi(value);
		else if (token == "PLAYER_COLOR2") this->PLAYER_COLOR2 = stoi(value);
		else if (token == "MAP_INDEX") this->MAP_INDEX = stoi(value);
		else if (token == "PLAYER_COUNT")
		{
			this->PLAYER_COUNT = stoi(value);
			if (this->PLAYER_COUNT > 2)
				this->PLAYER_COUNT = 2;
		}
		else if (token == "BOT_COUNT") this->BOT_COUNT = stoi(value);
		else if (token == "CONTROL") this->CONTROL = value;
	}
}

int ConstParser::getWindowWidth()
{
	return this->WINDOW_WIDTH;
}

int ConstParser::getWindowHeight()
{
	return this->WINDOW_HEIGHT;
}

float ConstParser::getSpeed()
{
	return this->SPEED;
}

float ConstParser::getMaxSpeed()
{
	return this->MAX_SPEED;
}

int ConstParser::getPlayerColor(int playerIndex)
{
	if (playerIndex == 0)
		return this->PLAYER_COLOR1;
	return this->PLAYER_COLOR2;
}

int ConstParser::getMapIndex()
{
	return this->MAP_INDEX;
}

int ConstParser::getPlayerCount()
{
	return this->PLAYER_COUNT;
}

int ConstParser::getBotCount()
{
	return this->BOT_COUNT;
}

string ConstParser::getControl()
{
	return this->CONTROL;
}
