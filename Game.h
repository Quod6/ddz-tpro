#pragma once

#include "Libs.h"
#include "Player.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Game
{
private:
	// Variables
	// Main variables
	RenderWindow *window;
	Event evnt;
	bool endGame;

	// Fonts
	Font cyberwayFont;
	Font asherpunkFont;

	// All sounds
	SoundBuffer buffer;
	Sound sound;
	Music phonk;

	// Background
	Texture bgTexture;
	Sprite bgSprite;

	// Player
	Player player;

	//Functions
	// Private functions
	void initVariables();
	void initWindow();
public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	const bool isRunning() const;

	// Public functions
	void pollEvents();
	void update();
	void render();
};
