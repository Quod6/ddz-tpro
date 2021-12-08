// #include <random>
// #include <iostream>
// #include <vector>
// #include <string>
//
// #include <SFML/Graphics.hpp>

#include "Game.h"

using namespace std;
using namespace sf;

int main()
{
	// Init Game engine
	Game game;

	// Main loop
	while (game.isRunning())
	{
		//Update
		game.update();
		
		// Render
		game.render();
	}

	return 0;
}
