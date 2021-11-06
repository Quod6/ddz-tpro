#include <SFML/Graphics.hpp>

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	sf::RenderWindow window(sf::VideoMode(800, 600), "TRON", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::Event evnt;

	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed) window.close();
			if (evnt.type == sf::Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (evnt.key.code == sf::Keyboard::Escape) window.close();
			}
		}

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.display();
	}

	return 0;
}
