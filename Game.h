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

	// BG of endGame
	Texture endGameTexture;
	Sprite endGameSprite;

	// Text of names and timer
	Text player1Name;
	Text player2Name;
	Text timeText;
	float seconds;

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
	void updateTimer(float dt);
	void renderText();

	// Global bounds of all entities
	void getBoundsOfEntities();

	// Global collision
	void checkGlobalCollision();

	// End game check
	bool checkGameResult();

public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	const bool isRunning() const;
	void gameResult(int isPl1Win);

	// Public functions
	RenderWindow* getGameWindow();
	Event * getGameEvent();
	void pollEvents();
	void update(float dt);
	void render();
};
