#include <fstream>
#include <string>
#include <iostream>

#include <SFML/Window/Keyboard.hpp>

#include "enum_string.h"

using namespace std;

class ConstParser
{
private:
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	float SPEED;
	float MAX_SPEED;

	/*
		0 - blue
		1 - red
		2 - green
		3 - purple
	*/
	int PLAYER_COLOR;

	/*
		0 - map3.png
	*/
	int MAP_INDEX;

	/*
		enum Key from SFML/Keyboard.hpp
	*/
	sf::Keyboard::Key CONTROL_UP;
	sf::Keyboard::Key CONTROL_DOWN;
	sf::Keyboard::Key CONTROL_LEFT;
	sf::Keyboard::Key CONTROL_RIGHT;

	int PLAYER_COUNT;
	int BOT_COUNT;

public:
	ConstParser();

	// Parsing file
	void parse(string filepath);

	// Returning constants
	int getWindowWidth();
	int getWindowHeight();
	float getSpeed();
	float getMaxSpeed();
	int getPlayerColor();
	int getMapIndex();
	int getPlayerCount();
	int getBotCount();
	sf::Keyboard::Key getUp();
	sf::Keyboard::Key getDown();
	sf::Keyboard::Key getRight();
	sf::Keyboard::Key getLeft();
};
