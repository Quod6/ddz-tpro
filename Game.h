#include <random>
#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Game
{
private:
	// Variables
	RenderWindow *window;
	Event evnt;
	Font cyberwayFont;
	Font asherpunkFont;

	// Private functions
	void initVariables();
	void initWindow();
public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	const bool isRunning() const;

	// Functions
	void pollEvents();
	void update();
	void render();
};
