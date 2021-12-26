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
	vector<Player *> players;

	// Bots
	vector<Player *> bots;

	// Parser
	ConstParser *parser;

	// Global bounds of all entities
	vector<FloatRect> boundsOfEntities;

	// Global bounds of major entities
public:
	struct PlayerBounds
	{
		Player * player;
		FloatRect bounds;
	};
private:
	vector<PlayerBounds> boundsOfMajorEntities;

	//Functions
	// Private functions
	void initParser();
	void initVariables();
	void initPlayers();
	void initBots();
	void initWindow();

	// Global bounds of all entities
	void getBoundsOfEntities();

	// Global collision
	void checkGlobalCollision();

public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	const bool isRunning() const;

	// Public functions
	RenderWindow* getGameWindow();
	Event * getGameEvent();
	void pollEvents();
	void update(float dt);
	void render();
};
