#pragma once
#include "SFML/Graphics.hpp"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "windows.h"

int game_status = 0;
int menu_status = 0;

using namespace sf;
using namespace std;
string number = "";
string color_str = "";
string name_str = "";
string number_bots_str = "";
string keymap_str = "";
ofstream Settings;
string PlayerNameDynamic;
string PlayerName;
Text PlayerNameInput;
string Number_of_enemiesDynamic;
string Number_of_enemies_t;
Text Number_of_enemiesInput;
void main_menu(RenderWindow& window);

bool exit(RenderWindow& window, Sprite& background)
{
	Texture are_u_sure, yes, no;
	are_u_sure.loadFromFile("imgs/are_u_sure.psd");
	yes.loadFromFile("imgs/yes.psd");
	no.loadFromFile("imgs/no.psd");
	Sprite sprite6(are_u_sure), sprite7(yes), sprite8(no);
	sprite6.setPosition(250, 150);
	sprite7.setPosition(250, 275);
	sprite8.setPosition(518, 273);
	
	bool is_exit=true;
	int choise=3;

	while (is_exit)
	{
		sprite7.setColor(Color::White);
		sprite8.setColor(Color::White);
		choise = 3;
		if (IntRect(250, 275, 230, 90).contains(Mouse::getPosition(window)))
		{
			sprite7.setColor(Color(105, 101, 110, 230));
			choise = 0;
		}
		if (IntRect(518, 273, 230, 90).contains(Mouse::getPosition(window)))
		{
			sprite8.setColor(Color(105, 101, 110, 230));
			choise = 1;
			
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (choise)
				{
				case 0:
					window.close();
					return false;
				case 1:
					is_exit = false;
					default:
					break;
				}
			}

		}
		window.draw(background);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.display();
	}
	return true;
}

bool setup(RenderWindow& window, Sprite& background) {
	Texture arrows, blue, color, green, keymap, name, number_of_enemies, purple, red, save, wasd, zero, one, two,three, four;
	arrows.loadFromFile("imgs/arrows.psd");
	blue.loadFromFile("imgs/blue.psd");
	color.loadFromFile("imgs/color.psd");
	green.loadFromFile("imgs/green.psd");
	keymap.loadFromFile("imgs/keymap.psd");
	name.loadFromFile("imgs/name.psd");
	number_of_enemies.loadFromFile("imgs/number_of_enemies.psd");
	purple.loadFromFile("imgs/purple.psd");
	red.loadFromFile("imgs/red.psd");
	save.loadFromFile("imgs/save.psd");
	wasd.loadFromFile("imgs/wasd.psd");
	zero.loadFromFile("imgs/0.psd");
	one.loadFromFile("imgs/1.psd");
	two.loadFromFile("imgs/2.psd");
	three.loadFromFile("imgs/3.psd");
	four.loadFromFile("imgs/4.psd");
	Font shrift;
	shrift.loadFromFile("fonts/CyberwayRiders.ttf");
	PlayerNameInput.setFillColor(sf::Color(0,0,255));
	PlayerNameInput.setFont(shrift);
	PlayerNameInput.setCharacterSize(40);

	Sprite sprite_arrows(arrows), sprite_blue(blue), sprite_color(color), sprite_green(green), sprite_keymap(keymap), sprite_name(name), sprite_number_of_enemies(number_of_enemies), sprite_purple(purple), sprite_red(red), sprite_save(save), sprite_wasd(wasd), sprite_0(zero),sprite_1(one),sprite_2(two), sprite_3(three), sprite_4(four);
	sprite_arrows.setPosition(480, 264);
	sprite_blue.setPosition(198, 130);
	sprite_color.setPosition(64, 121);
	sprite_green.setPosition(340, 130);
	sprite_keymap.setPosition(64, 264);
	sprite_name.setPosition(64, 42);
	sprite_number_of_enemies.setPosition(64, 196);
	sprite_purple.setPosition(420, 130);
	sprite_red.setPosition(274, 130);
	sprite_save.setPosition(70, 510);
	sprite_wasd.setPosition(274, 264);
	sprite_0.setPosition(481, 200);
	sprite_1.setPosition(541, 200);
	sprite_2.setPosition(601, 200);
	sprite_3.setPosition(661, 200);
	sprite_4.setPosition(721, 200);
	bool is_setup = true;
	int choise = 666;
	while (is_setup)
	{
		int choise = 666;
		sprite_arrows.setColor(Color::White);
		sprite_blue.setColor(Color::White);
		sprite_color.setColor(Color::White);
		sprite_green.setColor(Color::White);
		sprite_keymap.setColor(Color::White);
		sprite_name.setColor(Color::White);
		sprite_purple.setColor(Color::White);
		sprite_red.setColor(Color::White);
		sprite_save.setColor(Color::White);
		sprite_wasd.setColor(Color::White);
		sprite_0.setColor(Color::White);
		sprite_1.setColor(Color::White);
		sprite_2.setColor(Color::White);
		sprite_3.setColor(Color::White);
		sprite_4.setColor(Color::White);



		if (IntRect(70, 510, 150, 50).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;

		}
		if (IntRect(480, 264, 250, 46).contains(Mouse::getPosition(window)))
		{
			sprite_arrows.setColor(Color(105, 101, 110, 230));
			choise = 1;

		}
		if (IntRect(198, 130, 34, 34).contains(Mouse::getPosition(window)))
		{
			sprite_blue.setColor(Color(105, 101, 110, 230));
			choise = 2;

		}

		if (IntRect(340, 130, 34, 34).contains(Mouse::getPosition(window)))
		{
			sprite_green.setColor(Color(105, 101, 110, 230));
			choise = 3;

		}

		if (IntRect(64, 42, 543, 55).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}
		if (IntRect(420, 130, 34, 34).contains(Mouse::getPosition(window)))
		{
			sprite_purple.setColor(Color(105, 101, 110, 230));
			choise = 6;

		}
		if (IntRect(274, 130, 34, 34).contains(Mouse::getPosition(window)))
		{
			sprite_red.setColor(Color(105, 101, 110, 230));
			choise = 7;

		}
		if (IntRect(274, 264, 184, 50).contains(Mouse::getPosition(window)))
		{
			sprite_wasd.setColor(Color(105, 101, 110, 230));
			choise = 9;

		}
		if (IntRect(481, 200, 48, 48).contains(Mouse::getPosition(window)))
		{
			sprite_0.setColor(Color(105, 101, 110, 230));
			choise = 10;

		}
		if (IntRect(541, 200, 48, 48).contains(Mouse::getPosition(window)))
		{
			sprite_1.setColor(Color(105, 101, 110, 230));
			choise = 11;

		}
		if (IntRect(601, 200, 48, 48).contains(Mouse::getPosition(window)))
		{
			sprite_2.setColor(Color(105, 101, 110, 230));
			choise = 12;

		}
		if (IntRect(661, 200, 48, 48).contains(Mouse::getPosition(window)))
		{
			sprite_3.setColor(Color(105, 101, 110, 230));
			choise = 13;

		}
		if (IntRect(721, 200, 48, 48).contains(Mouse::getPosition(window)))
		{
			sprite_4.setColor(Color(105, 101, 110, 230));
			choise = 14;

		}






		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (choise)
				{
				case 0:
					Settings.open("Config.txt", std::ios::trunc);
					if (color_str == "") {
						Settings <<"COLOR "<<0 << endl;
					}
					else {
						Settings <<"COLOR "<< color_str << endl;
					}
					if (keymap_str == "") {
						Settings << "CONTROL "<<"letters" << endl;
					}
					else { 
						Settings <<"CONTROL "<< keymap_str << endl; 
					}
					if (number == "") {
						Settings << "BOT_COUNT " << 0 << endl;
					}
					else {
						Settings << "BOT_COUNT " << number << endl;
					}
					if (PlayerNameDynamic == "") {
						Settings << "NAME " << "PLAYER" << endl;
					}
					else {
						Settings << "NAME " << PlayerNameDynamic << endl;
					}
					is_setup = false;
					Settings.close();
					break;
				case 1:
					keymap_str = "arrows";
					break;
				case 2:
					color_str = "0";
					break;
				case 3:
					color_str = "2";
					break;
				case 4:
					goto L;
					break;
				case 5:
					
					break;
				case 6:
					color_str = "3";
					break;
				case 7:
					color_str = "1";
					break;
				case 9:
					keymap_str = "letters";
					break;
				case 10:
					number = "0";
					break;
				case 11:
					number = "1";
					break;
				case 12:
					number = "2";
					break;
				case 13:
					number = "3";
					break;
				case 14:
					number = "4";
					break;
				default:
					break;
				}

			}
			L:
			if (event.type == sf::Event::TextEntered) {
				PlayerNameInput.setPosition(200, 44);
				
					if (event.text.unicode < 128) {
						if (event.text.unicode == 8) {
							if (PlayerNameDynamic.length() != 0)
								PlayerNameDynamic.pop_back();
						}
						else {
							PlayerNameDynamic += static_cast<char>(event.text.unicode);
						}

						PlayerNameInput.setString(PlayerNameDynamic);

					}
				
			}
			



		}

	
	window.draw(background);
	window.draw(sprite_arrows);
	window.draw(sprite_blue);
	window.draw(sprite_color);
	window.draw(sprite_green);
	window.draw(sprite_keymap);
	window.draw(sprite_name);
	window.draw(sprite_number_of_enemies);
	window.draw(sprite_purple);
	window.draw(sprite_red);
	window.draw(sprite_save);
	window.draw(sprite_wasd);
	window.draw(PlayerNameInput);
	window.draw(Number_of_enemiesInput);
	window.draw(sprite_0);
	window.draw(sprite_1);
	window.draw(sprite_2);
	window.draw(sprite_3);
	window.draw(sprite_4);
	window.display();
	}
	return true;
}

void present(RenderWindow& window) {
	Texture start;
	start.loadFromFile("imgs/creators.psd");
	Sprite s(start);
	s.setPosition(0, 0);
	bool i = true;
	while (i) {
		s.setColor(Color::White);
		
		window.draw(s);
		window.display();
		Sleep(4000);
		i = false;
	}
	main_menu(window);
	
}



void main_menu(RenderWindow& window)
{
	int game_status = 0;
	int menu_status = 0;

	Texture background_start, begin, shesterenka, exit_texture;
	//Загрузка текстур
	background_start.loadFromFile("imgs/bg.psd");
	begin.loadFromFile("imgs/begin.psd");
	shesterenka.loadFromFile("imgs/shesterenka.psd");
	exit_texture.loadFromFile("imgs/exit.psd");

	Sprite sprite1(background_start), sprite2(begin), sprite3(shesterenka), sprite4(exit_texture);
	sprite1.setPosition(0, 0);

	sprite2.setPosition(38, 90);

	sprite3.setPosition(160, 400);
	sprite4.setPosition(38, 250);
	

	bool is_menu = true;
	menu_status = 6;

	while (is_menu)
	{
		menu_status = 6;
		sprite2.setColor(Color::White);
		sprite3.setColor(Color::White);
		sprite4.setColor(Color::White);
		if (IntRect(38, 90, 430, 90).contains(Mouse::getPosition(window)))
		{
			sprite2.setColor(Color(105, 101, 110, 230));
			menu_status = 1;
		}
		if (IntRect(38, 250, 430, 90).contains(Mouse::getPosition(window)))
		{
			sprite4.setColor(Color(105, 101, 110, 230));
			menu_status = 3;
		}
		if (IntRect(160, 400, 165, 150).contains(Mouse::getPosition(window)))
		{
			sprite3.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (menu_status)
				{
				case 1:
					break;
				case 2:
					is_menu = setup(window, sprite1);
					break;
				case 3:
					is_menu = exit(window,sprite1);
					break;
				default:
					break;
				}
			}
		}
		window.clear();
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.display();

	}

}

int main()
{
	RenderWindow window(VideoMode(1001, 595), "The Game!");
	present(window);
	return 0;
}
