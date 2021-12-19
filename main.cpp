#include "Libs.h"
#include "Game.h"

int main()
{
	// Timer
	Clock clock;
	float TIME;

	// Init random seed
	reseed(time(0));

	// Init Game engine
	Game game;

	// Main loop
	while (game.isRunning())
	{
		TIME = clock.getElapsedTime().asMilliseconds();

		//Update
		game.update(TIME);

		// Render
		game.render();
	}

	return 0;
}
