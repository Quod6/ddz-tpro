#include <fstream>
#include <string>

#include <SFML/Window/Keyboard.hpp>

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
	int PLAYER_COLOR1;
	int PLAYER_COLOR2;

	/*
		0 - map3.png
	*/
	int MAP_INDEX;

	/*
		letters - wasd
		arrows - up, left, down, right
	*/
	string CONTROL;

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
	int getPlayerColor(int playerIndex);
	int getMapIndex();
	int getPlayerCount();
	int getBotCount();
	string getControl();
};
