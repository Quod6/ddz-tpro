#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Game
{
private:

public:

};

class Player
{
private:
	vector<short> position;
	bool isLaserWorking = false;

public:
	void changeDirection(int axis, int direction)
	{

	}
};

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	RenderWindow window(VideoMode(800, 600), "TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	Texture map;
	map.loadFromFile("source/ings/map.png");

	Event evnt;

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

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.display();
	}

	return 0;
}
