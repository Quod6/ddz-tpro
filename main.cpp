#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Cycle
{
private:
	vector<short> position;
	bool isLaserActive;
	bool isPlayer;

public:
	Cycle(bool isPlayer, vector<short> position)
	{
		this->position = {0, 0, 0};
		this->isPlayer = isPlayer;
		isLaserActive = false;
	}

	void setDirection(int direction)
	{
		// Directions:
		// 0 - up
		// 1 - right
		// 2 - down
		// 3 - left
		
		short d1 = (direction - 1) % 4;
		short d2 = (direction + 1) % 4;

		if (d1 < 0) d1 += 4;

		if (d1 == position[2] || d2 == position[2]) position[2] = direction;
	}

	void changeLaserCondition()
	{
		isLaserActive = !isLaserActive;
	}

	void update()
	{
		switch (position[2]) {
			case 0:
				position[1] += 10;
				break;
			case 1:
				position[0] += 10;
				break;
			case 2:
				position[1] -= 10;
				break;
			case 3:
				position[0] -= 10;
				break;
		}
	}
};

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	RenderWindow window(VideoMode(800, 600),
						"TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// Добаваляем текстуры
	Texture map;
	map.loadFromFile("./source/imgs/map.png");

	// Создаем объекты игрока и действия
	Cycle player {true, {0, 0, 0}};
	Event evnt;

	// Основной цикл
	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed) window.close();
			if (evnt.type == Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (evnt.key.code == Keyboard::Escape) window.close();
			}
		}

		// Here is move magick :)
		if (Keyboard::isKeyPressed(Keyboard::W)) player.setDirection(0);
		if (Keyboard::isKeyPressed(Keyboard::A)) player.setDirection(3);
		if (Keyboard::isKeyPressed(Keyboard::S)) player.setDirection(2);
		if (Keyboard::isKeyPressed(Keyboard::D)) player.setDirection(1);

		if (Keyboard::isKeyPressed(Keyboard::F)) player.changeLaserCondition();

		player.update();

		// Очищаем окно
		window.clear();
		// Here is draw magick :)
			// <-
		// Отображаем окно
		window.display();
	}

	return 0;
}
