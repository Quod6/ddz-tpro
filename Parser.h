#include "Libs.h"

class Parser
{
private:
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	float SPEED;
	float MAX_SPEED;
	int PLAYER_COLOR;
	int MAP_INDEX;
	int PLAYER_COUNT;
	int BOT_COUNT;

public:
	Parser();

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
};
