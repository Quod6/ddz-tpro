#include <iostream>
#include "Game.h"

int main()
{
	// Init random seed
	srand(static_cast<unsigned>(time(0)));
	
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
