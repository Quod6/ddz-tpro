#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

const float scale = 3.f;

class Cycle
{
private:
	vector<short> position;
	bool isLaserActive;
	bool isPlayer;

public:
	Cycle(bool isPlayer, vector<short> position, string path, vector<int> coordinates)
	{
		this->position = {0, 0, 0};
		this->isPlayer = isPlayer;
		isLaserActive = false;
		// cycleTexture.loadFromFile(path, IntRect(coordinates[0], coordinates[1],
		// 	 									coordinates[2], coordinates[3]));
		// cycleTexture.setSmooth(false);
		// Sprite cycleSprite(cycleTexture);
	}

private:
	void rotate(Sprite *cycleSprite)
	{
		cout << position[2] << endl;
		switch (position[2]) {
			case 0:
				cycleSprite->setRotation(0.f);
				break;
			case 1:
				cycleSprite->setRotation(90.f);
				break;
			case 2:
				cycleSprite->setRotation(180.f);
				break;
			case 3:
				cycleSprite->setRotation(270.f);
				break;
		}
	}

	// Функция, проверяющая столкновение светоцикла со стенками
	bool checkCollision()
	{
		return true;
	}

	// Функция, "взрывающая" светоцикл в случае столкновения
	void destroy()
	{

	}

public:
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
				position[1] += 5;
				break;
			case 1:
				position[0] += 5;
				break;
			case 2:
				position[1] -= 5;
				break;
			case 3:
				position[0] -= 5;
				break;
		}
	}

	void move(Sprite *cycleSprite)
	{
		if(checkCollision())
		{
			rotate(cycleSprite);
			cout << position[0] << " " << position[1] << '\n';
			cycleSprite->setPosition(-position[0], -position[1]);
		}
		else
		{
			destroy();
		}
	}

	vector<short> getPosition()
	{
		return this->position;
	}
};

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	RenderWindow window(VideoMode(1000, 1000),
						"TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// Добавляем шрифты
	Font cyberwayFont;
	Font asherpunkFont;

	cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Добавляем текст
	Text cyberpunkText("Tron game", cyberwayFont, 50);

	// Создаем объекты игрока и действия
	Cycle player {true, {400, 300, 0}, "./source/imgs/cycles.png", {13, 0, 13, 25}};
	Event evnt;

	// Создаем текстуру и спрайт игрока
	Texture plTexture;
	plTexture.loadFromFile("./source/imgs/cycles.png", IntRect(13, 0, 13, 25));
	plTexture.setSmooth(false);
	Sprite plSprite(plTexture);
	plSprite.setScale(scale, scale);
	plSprite.setOrigin(plSprite.getTexture()->getSize().x / 2,
					   plSprite.getTexture()->getSize().y / 2);

	// Сдвинем спрайт игрока на цетр
	plSprite.setPosition(400.f, 300.f);

	// Основной цикл
	while (window.isOpen())
	{
		// Берем позицию игрока в начале игрового цикла
		vector<short> plOldPos = player.getPosition();
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
		player.move(&plSprite);


		// Очищаем окно
		window.clear();

		// Here is draw magick :)
		window.draw(cyberpunkText);
		window.draw(plSprite);

		// Отображаем окно
		window.display();
	}

	return 0;
}
