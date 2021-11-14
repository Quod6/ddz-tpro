#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

const float SCALE = 1.5f;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const int SPEED = 3;

class Game
{
private:
	Texture bgT;
	Texture lgT;
	Sprite bgS;
	Sprite lgS;

public:
	Game(int windowWidth, int windowHeight, string bgPath, string logoPath)
	{
		bgT.loadFromFile(bgPath);
		bgS.setTexture(bgT);
		bgS.setOrigin(bgT.getSize().x / 2, bgT.getSize().y / 2);
		bgS.setPosition(windowWidth / 2, windowHeight / 2);
		bgS.setScale((float)windowWidth / bgT.getSize().x,
					 (float)windowHeight / bgT.getSize().y);

		lgT.loadFromFile(logoPath);
		lgS.setTexture(lgT);
		lgS.setOrigin(lgT.getSize().x / 2, lgT.getSize().y / 2);
		lgS.setPosition(windowWidth / 2, windowHeight / 5);
		lgS.setScale(windowWidth / 3.0 / lgT.getSize().x,
					 windowHeight / 4.0 / lgT.getSize().y);
	}

	void setTexture(Texture newTexture)
	{
		bgS.setTexture(newTexture);
	}

	Sprite getBG()
	{
		return bgS;
	}

	Sprite getLogo()
	{
		return lgS;
	}

};

class Cycle
{
private:
	Vector3i position;
	Vector3i oldPos;
	bool isLaserActive;
	int cycleSpeed;

public:
	Cycle(vector<short> position, int cycleSpeed)
	{
		this->cycleSpeed = cycleSpeed;
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

	bool collisionWalls(Sprite *cycleSprite)
	{
		if (position.x - cycleSprite->getTexture()->getSize().y / 2 <= 0 ||
			position.x + cycleSprite->getTexture()->getSize().y / 2 >= WINDOW_WIDTH)
		{
			return false;
		}
		if (position.y - cycleSprite->getTexture()->getSize().y / 2 <= 0 ||
			position.y + cycleSprite->getTexture()->getSize().y / 2 >= WINDOW_HEIGHT)
		{
			return false;
		}
		return true;
	}

	bool collisionLaser(Sprite *cycleSprite)
	{
		return true;
	}

	// Функция, проверяющая столкновение светоцикла с чем-либо
	bool checkCollision(Sprite *cycleSprite)
	{
		return collisionWalls(cycleSprite) & collisionLaser(cycleSprite);
	}

	// Функция, "взрывающая" светоцикл в случае столкновения
	void destroy()
	{

	}

	void update()
	{
		switch (position.z) {
			case 0:
				position.y -= cycleSpeed;
				break;
			case 1:
				position.x += cycleSpeed;
				break;
			case 2:
				position.y += cycleSpeed;
				break;
			case 3:
				position.x -= cycleSpeed;
				break;
		}
	}

	void makeLaser()
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
			if (isLaserActive)  makeLaser();
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
		oldPos = position;
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
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
						"TRON", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	// Создаем фон
	Game gm(WINDOW_WIDTH, WINDOW_HEIGHT, "./source/imgs/bg.png", "./source/imgs/logo2.png");

	// Добавляем шрифты
	Font cyberwayFont;
	Font asherpunkFont;
	cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Создаем объекты игрока и действия
	Cycle player {{500, 500, 0}, SPEED};
	Event evnt;

	// Создаем текстуру и спрайт игрока
	Texture plTexture;
	plTexture.loadFromFile("./source/imgs/cycles.png", IntRect(0, 0, 13, 25));
	plTexture.setSmooth(false);
	Sprite plSprite(plTexture);
	plSprite.setScale(SCALE, SCALE);
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
		window.draw(gm.getBG());
		window.draw(gm.getLogo());

		// Here is draw magick :)
		window.draw(plSprite);

		// Отображаем окно
		window.display();
	}

	return 0;
}
