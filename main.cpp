#include <iostream>
#include "Game.h"

int main()
{
	// Init Game engine
	Game game(1);

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
