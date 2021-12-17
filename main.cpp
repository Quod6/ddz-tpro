#include "Libs.h"
#include "Game.h"

int main()
{
	// Init random seed
	srand(time(nullptr));

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
