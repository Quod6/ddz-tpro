#include <random>
#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game
{
private:

public:
	// Constructor & destructor
	Game();
	virtual ~Game();

	// Functions
	void update();
	void render();
};
