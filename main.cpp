#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;
using namespace sf;

const float SCALE = 1.5f;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const int SPEED = 3;
float TIME = 0.f;
int CURRENT_FRAME = 0;
Texture emptyTexture;

class Game
{
private:
	Texture bgT;
	Texture lgT;
	Sprite bgS;
	Sprite lgS;

public:
	Game(int windowWidth, int windowHeight, string bgPath, string logoPath, string emptyPath)
	{
		emptyTexture.loadFromFile(emptyPath);
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

class BotAI
{
private:

public:
	BotAI()
	{

	}

	void init()
	{

	}

	void move(Sprite *cycleSprite)
	{

	}
};

class Cycle
{
private:
	Vector3i position;
	Vector3i oldPos;
	bool isLaserActive;
	bool isPlayer;
	int cycleSpeed;
	BotAI AI;
	Texture destruction;


public:
	Cycle(bool isPlayer, vector<short> position, int cycleSpeed)
	{
		destruction.loadFromFile("./source/imgs/destruction.png");
		this->isPlayer = isPlayer;
		this->cycleSpeed = cycleSpeed;
		this->position = {position[0], position[1], position[2]};
		oldPos = {position[0], position[1], position[2]};
		isLaserActive = false;
		if (!isPlayer) AI.init();
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
		/*
		if (position.x - 13 * SCALE / 2 <= 0 ||
			position.x + 13 * SCALE >= WINDOW_WIDTH)
		{
			return false;
		}
		if (position.y - 13 * SCALE / 2 <= 0 ||
			position.y + 13 * SCALE / 2 >= WINDOW_HEIGHT)
		{
			return false;
		}
		return true;
		*/
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
	void destroy(Sprite *cycleSprite)
	{
		int drawingFrame = 0;
		if (drawingFrame == 7) return;
		if (CURRENT_FRAME == 0)
		{
			cycleSprite->setTexture(destruction);
			cycleSprite->setTextureRect(IntRect(0, 0, 192, 192));
			cycleSprite->setOrigin(96, 96);
		}
		drawingFrame = CURRENT_FRAME / 4;
		cycleSprite->setTextureRect(IntRect(192 * drawingFrame, 0, 192, 192));
		CURRENT_FRAME += TIME / 16;
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
		if (isPlayer)
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
				destroy(cycleSprite);
			}
		}
		else
		{
			AI.move(cycleSprite);
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
	Game gm(WINDOW_WIDTH, WINDOW_HEIGHT, "./source/imgs/map3.png",
			"./source/imgs/logo2.png", "./source/imgs/empty.png");

	// Добавляем шрифты
	Font cyberwayFont;
	Font asherpunkFont;
	cyberwayFont.loadFromFile("./source/fonts/CyberwayRiders.ttf");
	asherpunkFont.loadFromFile("./source/fonts/AsherPunk.ttf");

	// Создаем объекты игрока, бота и действия
	Cycle player {true, {500, 500, 0}, SPEED};
	Cycle bot {false, {700, 500, 0}, SPEED};
	Event evnt;

	// Создаем текстуру и спрайт игрока
	Texture plTexture;
	plTexture.loadFromFile("./source/imgs/cycles.png", IntRect(13, 0, 13, 25));
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
	// Создаем таймер, который будет отвечать за переключение анимаций
	Clock clock;
	// Основной цикл
	while (window.isOpen())
	{
		// Смотрим, сколько времени прошло и обновляем таймер
		TIME = clock.getElapsedTime().asMilliseconds();
		clock.restart();
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
