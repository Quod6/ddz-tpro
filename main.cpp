#include "Libs.h"
#include "Game.h"
#include "Menu.h"
int main()
{
	// Timer
	Clock clock;
	float TIME;

	// Init random seed
	reseed(time(0));

	RenderWindow * w = new RenderWindow(VideoMode(1280,720), "TRON",Style::Close | Style::Titlebar);
	choose_mode(*w);
	delete w;

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
