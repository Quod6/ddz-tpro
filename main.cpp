#include "Libs.h"
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
		cout << "First update check" << endl;

		// Render
		game.render();
		cout << "First render check" << endl;
	}

	return 0;
}
