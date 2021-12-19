#include "Libs.h"
#include "Player.h"
#include "Bot.h"

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
	Player *player;

	// Bots
	vector<Bot *> bots;

	// Parser
	ConstParser *parser;

	//Functions
	// Private functions
	void initParser();
	void initVariables();
	void initPlayer();
	void initBots();
	void initWindow();
public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	const bool isRunning() const;

	// Public functions
	void pollEvents();
	void update(float dt);
	void render();
};
