#pragma once
#include "SFML/Graphics.hpp"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "windows.h"

int menu_status = 0;

using namespace sf;
using namespace std;



string color_str_1 = "";
string name_str_1 = "";
string keymap_str_1 = "";
string color_str_2 = "";
string name_str_2 = "";
string keymap_str_2 = "";
string number = "";
string color_str = "";
string name_str = "";
string number_bots_str = "";
string keymap_str = "";
ofstream Settings;
string PlayerNameDynamic="";
string PlayerName="";
Text PlayerNameInput;
string Number_of_enemiesDynamic = "";
Text Number_of_enemiesInput;
string PlayerNameDynamic_1 = "";
string PlayerName_1 = "";
Text PlayerNameInput_1;
string Number_of_enemiesDynamic_1 = "";
Text Number_of_enemiesInput_1;
string PlayerNameDynamic_2 = "";
string PlayerName_2 = "";
Text PlayerNameInput_2;
string Number_of_enemiesDynamic_2 = "";

Text Number_of_enemiesInput_2;



void main_menu(RenderWindow& window, int amount);
bool setup_multi2(RenderWindow& window, Sprite& background, int status);
void choose_mode(RenderWindow& window);
bool exit(RenderWindow& window, Sprite& background)
{
	Texture are_u_sure, yes, no;
	are_u_sure.loadFromFile("imgs/are_u_sure.psd");
	yes.loadFromFile("imgs/yes.psd");
	no.loadFromFile("imgs/no.psd");
	Sprite sprite6(are_u_sure), sprite7(yes), sprite8(no);
	sprite6.setPosition(323, 222);
	sprite7.setPosition(323, 357);
	sprite8.setPosition(620, 355);
	
	bool is_exit=true;
	int choise=3;

	while (is_exit)
	{
		sprite7.setColor(Color::White);
		sprite8.setColor(Color::White);
		choise = 3;
		if (IntRect(323, 357, 268, 85).contains(Mouse::getPosition(window)))
		{
			sprite7.setColor(Color(105, 101, 110, 230));
			choise = 0;
		}
		if (IntRect(620, 355, 268, 85).contains(Mouse::getPosition(window)))
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

bool setup_single(RenderWindow& window, Sprite& background) {
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
	sprite_arrows.setPosition(610, 440);
	sprite_blue.setPosition(280, 209);
	sprite_color.setPosition(94, 206);
	sprite_green.setPosition(450, 209);
	sprite_keymap.setPosition(94, 438);
	sprite_name.setPosition(94, 90);
	sprite_number_of_enemies.setPosition(94, 324);
	sprite_purple.setPosition(530, 209);
	sprite_red.setPosition(370, 209);
	sprite_save.setPosition(94, 600);
	sprite_wasd.setPosition(350, 440);
	sprite_0.setPosition(570, 326);
	sprite_1.setPosition(650, 326);
	sprite_2.setPosition(720, 326);
	sprite_3.setPosition(790, 326);
	sprite_4.setPosition(860, 326);
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



		if (IntRect(94, 600, 188, 66).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;

		}
		if (IntRect(610, 440, 304, 59).contains(Mouse::getPosition(window)))
		{
			sprite_arrows.setColor(Color(105, 101, 110, 230));
			choise = 1;

		}
		if (IntRect(280, 209, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_blue.setColor(Color(105, 101, 110, 230));
			choise = 2;

		}

		if (IntRect(450, 209, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_green.setColor(Color(105, 101, 110, 230));
			choise = 3;

		}

		if (IntRect(94, 90, 538, 60).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}
		if (IntRect(530, 209, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_purple.setColor(Color(105, 101, 110, 230));
			choise = 6;

		}
		if (IntRect(370, 209, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_red.setColor(Color(105, 101, 110, 230));
			choise = 7;

		}
		if (IntRect(350, 440, 224, 59).contains(Mouse::getPosition(window)))
		{
			sprite_wasd.setColor(Color(105, 101, 110, 230));
			choise = 9;

		}
		if (IntRect(570, 326, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_0.setColor(Color(105, 101, 110, 230));
			choise = 10;

		}
		if (IntRect(650, 326, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_1.setColor(Color(105, 101, 110, 230));
			choise = 11;

		}
		if (IntRect(720, 326, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_2.setColor(Color(105, 101, 110, 230));
			choise = 12;

		}
		if (IntRect(790, 326, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_3.setColor(Color(105, 101, 110, 230));
			choise = 13;

		}
		if (IntRect(860, 326, 45, 45).contains(Mouse::getPosition(window)))
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
				PlayerNameInput.setPosition(250, 94);
				
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
	choose_mode(window);
	
}



bool setup_multi1(RenderWindow& window, Sprite& background) {
	ofstream Settings;
	


	
	int keymap_status = 0;
	Texture arrows, blue, color, keymap, name, number_of_enemies, red, save, wasd,  first;
	arrows.loadFromFile("imgs/arrows.psd");
	blue.loadFromFile("imgs/blue.psd");
	color.loadFromFile("imgs/color.psd");
	
	keymap.loadFromFile("imgs/keymap.psd");
	name.loadFromFile("imgs/name.psd");
	
	
	red.loadFromFile("imgs/red.psd");
	save.loadFromFile("imgs/save.psd");
	wasd.loadFromFile("imgs/wasd.psd");
	first.loadFromFile("imgs/1_player.psd");
	
	Font shrift;
	shrift.loadFromFile("fonts/CyberwayRiders.ttf");
	PlayerNameInput_1.setFillColor(sf::Color(0, 0, 255));
	PlayerNameInput_1.setFont(shrift);
	PlayerNameInput_1.setCharacterSize(40);

	Sprite sprite_arrows(arrows), sprite_blue(blue), sprite_color(color), sprite_keymap(keymap), sprite_name(name),  sprite_red(red), sprite_save(save), sprite_wasd(wasd), sprite_first(first);
	sprite_arrows.setPosition(610, 440);
	sprite_blue.setPosition(280, 309);
	sprite_color.setPosition(94, 306);
	
	sprite_keymap.setPosition(94, 438);
	sprite_name.setPosition(94, 190);
	
	
	sprite_red.setPosition(370, 309);
	sprite_save.setPosition(94, 600);
	sprite_wasd.setPosition(350, 440);
	
	sprite_first.setPosition(94, 60);
	
	bool is_setup = true;
	int choise = 666;
	while (is_setup)
	{
	    choise = 666;
		sprite_arrows.setColor(Color::White);
		sprite_blue.setColor(Color::White);
		sprite_color.setColor(Color::White);
		
		sprite_keymap.setColor(Color::White);
		sprite_name.setColor(Color::White);
		
		sprite_red.setColor(Color::White);
		sprite_save.setColor(Color::White);
		sprite_wasd.setColor(Color::White);
		
		sprite_first.setColor(Color::White);


		if (IntRect(94, 600, 188, 66).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;

		}
		if (IntRect(610, 440, 304, 59).contains(Mouse::getPosition(window)))
		{
			sprite_arrows.setColor(Color(105, 101, 110, 230));
			choise = 1;

		}
		if (IntRect(280, 309, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_blue.setColor(Color(105, 101, 110, 230));
			choise = 2;

		}

		

		if (IntRect(94, 190, 538, 60).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}
		
		if (IntRect(370, 309, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_red.setColor(Color(105, 101, 110, 230));
			choise = 7;

		}
		if (IntRect(350, 440, 224, 59).contains(Mouse::getPosition(window)))
		{
			sprite_wasd.setColor(Color(105, 101, 110, 230));
			choise = 9;

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
					
					is_setup = false;
					Settings.close();
					is_setup = setup_multi2(window, background, keymap_status);
					return true;
					break;
				case 1:
					keymap_str_1 = "arrows";
					keymap_status = 1;
					break;
				case 2:
					color_str_1 = "0";
					break;
				
				case 4:
					goto L;
					break;
				
				case 7:
					color_str_1 = "1";
					break;
				case 9:
					keymap_str_1 = "letters";
					keymap_status = 2;
					break;
				
				default:
					break;
				}

			}
		L:
			if (event.type == sf::Event::TextEntered) {
				PlayerNameInput_1.setPosition(250, 194);

				if (event.text.unicode < 128) {
					if (event.text.unicode == 8) {
						if (PlayerNameDynamic_1.length() != 0)
							PlayerNameDynamic_1.pop_back();
					}
					else {
						PlayerNameDynamic_1 += static_cast<char>(event.text.unicode);
					}

					PlayerNameInput_1.setString(PlayerNameDynamic_1);

				}

			}




		}


		window.draw(background);
		window.draw(sprite_arrows);
		window.draw(sprite_blue);
		window.draw(sprite_color);
		
		window.draw(sprite_keymap);
		window.draw(sprite_name);
		window.draw(sprite_first);
		
		window.draw(sprite_red);
		window.draw(sprite_save);
		window.draw(sprite_wasd);
		window.draw(PlayerNameInput_1);
		window.draw(Number_of_enemiesInput_1);
		window.display();
	}
	return true;
}

bool setup_multi2(RenderWindow& window, Sprite& background,int keymap_status) {
	ofstream Settings;
	
	

	Texture arrows, purple, color, keymap, name, number_of_enemies, green, save, wasd, second;
	arrows.loadFromFile("imgs/arrows.psd");
	green.loadFromFile("imgs/green.psd");
	color.loadFromFile("imgs/color.psd");

	keymap.loadFromFile("imgs/keymap.psd");
	name.loadFromFile("imgs/name.psd");


	purple.loadFromFile("imgs/purple.psd");
	save.loadFromFile("imgs/save.psd");
	wasd.loadFromFile("imgs/wasd.psd");
	second.loadFromFile("imgs/2_player.psd");

	Font shrift;
	shrift.loadFromFile("fonts/CyberwayRiders.ttf");
	PlayerNameInput_2.setFillColor(sf::Color(0, 0, 255));
	PlayerNameInput_2.setFont(shrift);
	PlayerNameInput_2.setCharacterSize(40);

	Sprite sprite_arrows(arrows), sprite_green(green), sprite_color(color), sprite_keymap(keymap), sprite_name(name), sprite_purple(purple), sprite_save(save), sprite_wasd(wasd), sprite_second(second);
	sprite_arrows.setPosition(610, 440);
	sprite_green.setPosition(280, 309);
	sprite_color.setPosition(94, 306);

	sprite_keymap.setPosition(94, 438);
	sprite_name.setPosition(94, 190);


	sprite_purple.setPosition(370, 309);
	sprite_save.setPosition(94, 600);
	sprite_wasd.setPosition(350, 440);

	sprite_second.setPosition(94, 60);

	bool is_setup = true;
	int choise = 666;
	while (is_setup)
	{
		choise = 666;
		sprite_arrows.setColor(Color::White);
		sprite_green.setColor(Color::White);
		sprite_color.setColor(Color::White);

		sprite_keymap.setColor(Color::White);
		sprite_name.setColor(Color::White);

		sprite_purple.setColor(Color::White);
		sprite_save.setColor(Color::White);
		sprite_wasd.setColor(Color::White);

		sprite_second.setColor(Color::White);


		if (IntRect(94, 600, 188, 66).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;

		}
		if (keymap_status == 1) {
			sprite_arrows.setColor(Color(105, 101, 110, 230));
		}
		else {
			if (IntRect(610, 440, 304, 59).contains(Mouse::getPosition(window)))
			{
				sprite_arrows.setColor(Color(105, 101, 110, 230));
				choise = 1;

			}
		}
		if (IntRect(280, 309, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_green.setColor(Color(105, 101, 110, 230));
			choise = 2;

		}



		if (IntRect(94, 190, 538, 60).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}

		if (IntRect(370, 309, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_purple.setColor(Color(105, 101, 110, 230));
			choise = 7;

		}
		if (keymap_status == 2) {
			sprite_wasd.setColor(Color(105, 101, 110, 230));
		}
		else {
			if (IntRect(350, 440, 224, 59).contains(Mouse::getPosition(window)))
			{
				sprite_wasd.setColor(Color(105, 101, 110, 230));
				choise = 9;

			}
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
					Settings.open("Config.txt", std::ios::app);
					
					is_setup = false;
					Settings.close();
					
					break;
				case 1:
					keymap_str_2 = "arrows";
					break;
				case 2:
					color_str_2 = "2";
					break;

				case 4:
					goto L;
					break;

				case 7:
					color_str_2 = "3";
					break;
				case 9:
					keymap_str_2 = "letters";
					break;

				default:
					break;
				}

			}
		L:
			if (event.type == sf::Event::TextEntered) {
				PlayerNameInput_2.setPosition(250, 194);

				if (event.text.unicode < 128) {
					if (event.text.unicode == 8) {
						if (PlayerNameDynamic_2.length() != 0)
							PlayerNameDynamic_2.pop_back();
					}
					else {
						PlayerNameDynamic_2 += static_cast<char>(event.text.unicode);
					}

					PlayerNameInput_2.setString(PlayerNameDynamic_2);

				}

			}




		}


		window.draw(background);
		window.draw(sprite_arrows);
		window.draw(sprite_green);
		window.draw(sprite_color);

		window.draw(sprite_keymap);
		window.draw(sprite_name);
		window.draw(sprite_second);


		window.draw(sprite_purple);
		window.draw(sprite_save);
		window.draw(sprite_wasd);
		window.draw(PlayerNameInput_2);
		window.draw(Number_of_enemiesInput_2);
		window.display();
	}
	return true;
}


void main_menu(RenderWindow& window, int amount)
{
	ofstream Settings;
	int game_status = 0;
	int menu_status = 0;

	Texture background_start, begin, shesterenka, exit_texture;
	//«агрузка текстур
	background_start.loadFromFile("imgs/bg.psd");
	begin.loadFromFile("imgs/begin.psd");
	shesterenka.loadFromFile("imgs/shesterenka.psd");
	exit_texture.loadFromFile("imgs/exit.psd");

	Sprite sprite1(background_start), sprite2(begin), sprite3(shesterenka), sprite4(exit_texture);
	sprite1.setPosition(0, 0);

	sprite2.setPosition(100, 120);

	sprite3.setPosition(240, 510);
	sprite4.setPosition(100, 298);
	

	bool is_menu = true;
	menu_status = 6;

	while (is_menu)
	{
		menu_status = 6;
		sprite2.setColor(Color::White);
		sprite3.setColor(Color::White);
		sprite4.setColor(Color::White);
		if (IntRect(100, 120, 452, 92).contains(Mouse::getPosition(window)))
		{
			sprite2.setColor(Color(105, 101, 110, 230));
			menu_status = 1;
		}
		if (IntRect(100, 298, 452, 92).contains(Mouse::getPosition(window)))
		{
			sprite4.setColor(Color(105, 101, 110, 230));
			menu_status = 3;
		}
		if (IntRect(260, 510, 165, 165).contains(Mouse::getPosition(window)))
		{
			sprite3.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}
		if (amount == 1) {
			Event event;
			while (window.pollEvent(event))
			{
				// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
				if (event.type == Event::Closed)
					// тогда закрываем его
					window.close();
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					switch (menu_status)
					{
					case 1:
						Settings.open("Config.txt", std::ios::app);
						Settings << "WINDOW_WIDTH 1280" << endl;
						Settings << "WINDOW_HEIGHT 720" << endl;
						Settings << "SPEED 1" << endl;
						Settings << "MAX_SPEED 20" << endl;

						if (color_str == "") {
							Settings << "PLAYER_COLOR1 " << 0 << endl;
							Settings << "PLAYER_COLOR2 " << "LOREM_IPSUM" << endl;
						}
						else {
							Settings << "PLAYER_COLOR1 " << color_str << endl;
							Settings << "PLAYER_COLOR2 " << "LOREM_IPSUM" << endl;

						}
						Settings << "MAP 1" << endl;
						if (number == "") {
							Settings << "BOT_COUNT " << 0 << endl;
						}
						else {
							Settings << "BOT_COUNT " << number << endl;
						}
						Settings << "PLAYER_COUNT 1" << endl;
						if (keymap_str == "") {
							Settings << "CONTROL1 " << "letters" << endl;
							Settings << "CONTROL2 " << "LOREM_IPSUM" << endl;

						}
						else {
							Settings << "CONTROL1 " << keymap_str << endl;
							Settings << "CONTROL2 " << "LOREM_IPSUM" << endl;

						}
						
						if (PlayerNameDynamic == "") {
							Settings << "NAME_1 " << "PLAYER" << endl;
							Settings << "NAME_2 " << "LOREM_IPSUM" << endl;

						}
						else {
							Settings << "NAME_1 " << PlayerNameDynamic << endl;
							Settings << "NAME_2 " << "LOREM_IPSUM" << endl;

						}
						
						
						
						Settings.close();
						break;
					case 2:
						is_menu = setup_single(window, sprite1);
						break;
					case 3:
						is_menu = exit(window, sprite1);
						break;
					default:
						break;
					}
				}
			}
		}

		if (amount == 2) {
			Event event;
			while (window.pollEvent(event))
			{
				// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
				if (event.type == Event::Closed)
					// тогда закрываем его
					window.close();
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
				{
					switch (menu_status)
					{
					case 1:
						Settings.open("Config.txt", std::ios::app);
						Settings << "WINDOW_WIDTH 1280" << endl;
						Settings << "WINDOW_HEIGHT 720" << endl;
						Settings << "SPEED 1" << endl;
						Settings << "MAX_SPEED 20" << endl;
						if (color_str_1 == "") {
							Settings << "PLAYER_COLOR1 " << 0 << endl;
						}
						else {
							Settings << "PLAYER_COLOR1 " << color_str_1 << endl;
						}
						if (color_str_2 == "") {
							Settings << "PLAYER_COLOR2 " << 2 << endl;
						}
						else {
							Settings << "PLAYER_COLOR2 " << color_str_2 << endl;
						}
						Settings << "MAP 1" << endl;
						Settings << "BOT_COUNT 0" << endl;
						Settings << "PLAYER_COUNT 2" << endl;

						if (keymap_str_1 == "") {
							Settings << "CONTROL_1 " << "letters" << endl;
							Settings << "CONTROL_2 " << "arrows" << endl;
						}
						else {
							Settings << "CONTROL_1 " << keymap_str_1 << endl;
						}
						if (keymap_str_1 == "letters") {
							Settings << "CONTROL_2 " << "arrows" << endl;
						}
						if (keymap_str_1 == "arrows") {
							Settings << "CONTROL_2 " << "letters" << endl;
						}
						if (PlayerNameDynamic_1 == "") {
							Settings << "NAME_1 " << "PLAYER_1" << endl;
						}
						else {
							Settings << "NAME_1 " << PlayerNameDynamic_1 << endl;
						}
						
						if (PlayerNameDynamic_2 == "") {
							Settings << "NAME_2 " << "PLAYER_2" << endl;
						}
						else {
							Settings << "NAME_2 " << PlayerNameDynamic_2 << endl;
						}
						
						
						Settings.close();
						break;
					case 2:
						is_menu = setup_multi1(window, sprite1);
						break;
					case 3:
						is_menu = exit(window, sprite1);
						break;
					default:
						break;
					}
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

void choose_mode(RenderWindow& window) {
	Texture background_start, single, multi;
	ofstream Settings, Settings1;
	Settings1.open("Config.txt", std::ios::trunc);
	Settings1.close();
	background_start.loadFromFile("imgs/bg.psd");
	single.loadFromFile("imgs/single_player.psd");
	multi.loadFromFile("imgs/multi_player.psd");
	Sprite sprite1(background_start), sprite2(single), sprite3(multi);
	sprite1.setPosition(0, 0);
	sprite2.setPosition(200, 200);
	sprite3.setPosition(200, 400);
	bool is_menu = true;
	menu_status = 6;
	while (is_menu)
	{
		sprite2.setColor(Color::White);
		sprite3.setColor(Color::White);

		if (IntRect(200, 200, 580, 100).contains(Mouse::getPosition(window)))
		{
			sprite2.setColor(Color(105, 101, 110, 230));
			menu_status = 1;
		}

		if (IntRect(200, 400, 580, 100).contains(Mouse::getPosition(window)))
		{
			sprite3.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (menu_status)
				{
				case 1:
					main_menu(window,1);
					
					break;
				case 2:
					main_menu(window, 2);
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
		window.display();
	}


}

int main()
{
	RenderWindow window(VideoMode(1280, 720), "TRON");
	choose_mode(window);
	return 0;
}
