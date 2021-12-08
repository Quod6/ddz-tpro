// #include <random>
// #include <iostream>
// #include <vector>
// #include <string>
//
// #include <SFML/Graphics.hpp>

#include "Game.h"

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
						"TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// Добавляем шрифты
	Font cyberwayFont;
	Font asherpunkFont;
	cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Добавляем задний фон
	Field background(0, WINDOW_WIDTH, WINDOW_HEIGHT);

	// Основной цикл
	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed) window.close();
			if (evnt.type == Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (evnt.key.code == Keyboard::Escape) window.close();
			}
		}

		// Очищаем окно и рисуем фон
		window.clear();
		background.draw(&window);

		// Отображаем окно
		window.display();
	}

	return 0;
}
