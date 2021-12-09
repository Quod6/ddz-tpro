#include <random>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Game
{
private:
	// Variables
	// Main variables
	RenderWindow *window;
	Event evnt;

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
	Texture plTexture;
	Sprite plSprite;

	// Bots
	Texture botsTexture;
	vector<Sprite> botsSprites;

	//Functions
	// Private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initBots(int count);
public:
	// Constructor & destructor
	Game(int count);
	virtual ~Game();

	const bool isRunning() const;

	// Public functions
	void pollEvents();
	void update();
	void render();
};
