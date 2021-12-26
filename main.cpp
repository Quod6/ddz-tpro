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
	Menu:
	RenderWindow * w = new RenderWindow(VideoMode(1280,720), "TRON",Style::Close | Style::Titlebar);
	choose_mode(*w);
	delete w;

	// Init Game engine
	Restart:
	Game game;
	int pauseResult = 4;
	// Main loop
	while (game.isRunning())
	{
		TIME = clock.getElapsedTime().asMilliseconds();

		// Poll event cycle
		while(game.getGameWindow()->pollEvent(*game.getGameEvent()))
		{
			switch (game.getGameEvent()->type) {
				case Event::Closed:
					game.getGameWindow()->close();
					break;
				case Event::KeyPressed:
					if(game.getGameEvent()->key.code == Keyboard::Escape)
					{
						pauseResult = is_pause(*game.getGameWindow());
						switch (pauseResult)
						{
							case 1:
								break;
							case 2:
								goto Restart;
							case 3:
								goto Menu;
						}
					}

					break;
			}
		}

		fstream f;
		f.open("./config.txt", ios::in);
		int file_size;
		f.seekg(0, ios::end);
		file_size = f.tellg();
		if (file_size == 0)
			return 0;

		//Update
		game.update(TIME);

		// Render
		game.render();
	}

	return 0;
}
