#include <SFML/Graphics.hpp>
int game_status = 0;
int menu_status = 0;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1001, 595), "The Game!");

	// Создание и загрузка текстуры
		Texture background_start, begin,begin1, shesterenka, exit,are_u_sure,yes,no;
		//Загрузка текстур
		background_start.loadFromFile("imgs/bg.psd");
		begin1.loadFromFile("imgs/begin.psd");
		begin.loadFromFile("imgs/begin.psd");
		shesterenka.loadFromFile("imgs/shesterenka.psd");
		exit.loadFromFile("imgs/exit.psd");
		are_u_sure.loadFromFile("imgs/are_u_sure.psd");
		yes.loadFromFile("imgs/yes.psd");
		no.loadFromFile("imgs/no.psd");


	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		Sprite sprite1(background_start), sprite2(begin), sprite3(shesterenka), sprite4(exit),sprite6(are_u_sure), sprite7(yes), sprite8(no);
		sprite1.setPosition(0, 0);

		sprite2.setPosition(38, 90);

		sprite3.setPosition(160, 400);
		sprite4.setPosition(38, 250);
		sprite6.setPosition(250, 150);
		sprite7.setPosition(250, 275);
		sprite8.setPosition(518, 273);
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		Event e;
		int a;
		int b;
		//Отрисовка спрайта
		if (menu_status == 0) 
		{
			 a = 1;
			if (IntRect(38, 90, 430, 90).contains(Mouse::getPosition(window))&&(a==1)) 
			{
				sprite2.setColor(Color(105, 101, 110, 230));
				
			}
			if (IntRect(38, 250, 430, 90).contains(Mouse::getPosition(window)) && (a == 1))
			{
				sprite4.setColor(Color(105, 101, 110, 230));
				if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)) 
				{
					menu_status = 1;
				}
			}
			if (IntRect(160, 400, 165, 150).contains(Mouse::getPosition(window)) && (a == 1))
			{
				sprite3.setColor(Color(105, 101, 110, 230));
			}
			window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		
		}
		
		if (menu_status == 1)
		{
			a = 2;
			if (IntRect(250, 275, 230, 90).contains(Mouse::getPosition(window))&& (a==2))
			{
				sprite7.setColor(Color(105, 101, 110, 230));
				if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
				{
					window.close();
				}
			}
			if (IntRect(518, 273, 230, 90).contains(Mouse::getPosition(window)) && (a == 2))
			{
				sprite8.setColor(Color(105, 101, 110, 230));
				if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (a == 2))
				{
					menu_status = 0;
				}
			}
			
			window.draw(sprite1);
			window.draw(sprite6);
			window.draw(sprite7);
			window.draw(sprite8);
		}
		

		// Отрисовка окна
		
		window.display();
	}

	return 0;
}