#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

const float scale = 1.5f;
const int windowWidth = 1280;
const int windowHeight = 720;

class Cycle
{
private:
	Vector3i position;
	Vector3i oldPos;
	bool isLaserActive;
	vector<Vector3i> moveGrid;

public:
	Cycle(vector<short> position)
	{
		this->position = {position[0], position[1], position[2]};
		switch (this->position.z) {
			case 0:
				oldPos = {position[0], position[1] + 30, position[2]};
				break;
			case 1:
				oldPos = {position[0] - 30, position[1], position[2]};
				break;
			case 2:
				oldPos = {position[0], position[1] - 30, position[2]};
				break;
			case 3:
				oldPos = {position[0] + 30, position[1], position[2]};
				break;
		}
		isLaserActive = false;
	}

private:
	void rotate(Sprite *cycleSprite)
	{
		switch (position.z) {
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
	bool checkCollision(Sprite *cycleSprite)
	{
		if (position.x - cycleSprite->getTexture()->getSize().y / 2 <= 0 ||
			position.x + cycleSprite->getTexture()->getSize().y / 2 >= windowWidth)
		{
			return false;
		}
		if (position.y - cycleSprite->getTexture()->getSize().y / 2 <= 0 ||
			position.y + cycleSprite->getTexture()->getSize().y / 2 >= windowHeight)
		{
			return false;
		}
		return true;
	}

	// Функция, "взрывающая" светоцикл в случае столкновения
	void destroy()
	{

	}

	void update()
	{
		switch (position.z) {
			case 0:
				position.y -= 5;
				break;
			case 1:
				position.x += 5;
				break;
			case 2:
				position.y += 5;
				break;
			case 3:
				position.x -= 5;
				break;
		}
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

		if (d1 == position.z || d2 == position.z) position.z = direction;
	}

	void changeLaserCondition()
	{
		isLaserActive = !isLaserActive;
	}

	void move(Sprite *cycleSprite)
	{
		if(checkCollision(cycleSprite))
		{
			update();
			rotate(cycleSprite);
			cycleSprite->setPosition(position.x, position.y);
		}
		else
		{
			destroy();
		}
	}

	void updateOldPos()
	{
		cout << "{" << oldPos.x << ", " << oldPos.y << ", " << oldPos.z << "} <- ";
		oldPos = position;
		cout << "{" << oldPos.x << ", " << oldPos.y << ", " << oldPos.z << "}" << endl;
	}

	Vector3i getPosition()
	{
		return this->position;
	}

	Vector3i getDeltaPos()
	{
		return {abs(position.x - oldPos.x),
				abs(position.y - oldPos.y),
				position.z - oldPos.z};
	}
};

int main()
{
	// Создаем окно размером 800 на 600 и частотой обновления 60 кадров в секунду
	RenderWindow window(VideoMode(windowWidth, windowHeight),
						"TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// Создаем фон
	Texture bgT;
	bgT.loadFromFile("./source/imgs/map.png");
	Sprite bgS(bgT);
	bgS.setOrigin(bgT.getSize().x / 2, bgT.getSize().y / 2);
	bgS.setPosition(windowWidth / 2, windowHeight / 2);
	bgS.setScale(1.2f, 1.2f);

	// Добавляем шрифты
	Font cyberwayFont;
	Font asherpunkFont;
	cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Создаем объекты игрока и действия
	Cycle player {{500, 500, 0}};
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
	plSprite.setPosition(500.f, 500.f);

	// Дополнительные переменные
	Vector3i plDeltaPos;

	// Перед основным циклом обновляем старые координаты, чтобы они стали начальной точкой
	player.updateOldPos();
	// Основной цикл
	while (window.isOpen())
	{
		// Берем позицию игрока в начале игрового цикла
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
		plDeltaPos = player.getDeltaPos();
		if (plDeltaPos.x >= 30 || plDeltaPos.y >= 30)
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.setDirection(0);
				player.updateOldPos();
			}
			else if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.setDirection(3);
				player.updateOldPos();
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.setDirection(2);
				player.updateOldPos();
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.setDirection(1);
				player.updateOldPos();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::F)) player.changeLaserCondition();

		player.move(&plSprite);

		// Очищаем окно и рисуем фон
		window.clear();
		window.draw(bgS);

		// Here is draw magick :)
		window.draw(plSprite);

		// Отображаем окно
		window.display();
	}

	return 0;
}
