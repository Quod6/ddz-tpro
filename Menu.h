#pragma once
#include "SFML/Graphics.hpp"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "windows.h"


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
string PlayerNameDynamic = "";
string PlayerName = "";
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
int choise_map = 666;

void main_menu(RenderWindow& window, int amount);
bool is_pause(RenderWindow& window);

bool setup_multi2(RenderWindow& window, Sprite& background, int status);
void choose_mode(RenderWindow& window);
bool map_selection(RenderWindow& window, Sprite& background);
bool exit(RenderWindow& window, Sprite& background)
{
	Texture are_u_sure, yes, no;
	are_u_sure.loadFromFile("imgs/are_u_sure.psd");
	yes.loadFromFile("imgs/yes.psd");
	no.loadFromFile("imgs/no.psd");
	Sprite sprite_are_u_sure(are_u_sure), sprite_yes(yes), sprite_no(no);
	sprite_are_u_sure.setPosition(323, 222);
	sprite_yes.setPosition(323, 357);
	sprite_no.setPosition(620, 355);

	bool is_exit = true;
	int choise = 3;

	while (is_exit)
	{
		sprite_yes.setColor(Color::White);
		sprite_no.setColor(Color::White);
		choise = 3;
		if (IntRect(323, 357, 268, 85).contains(Mouse::getPosition(window)))
		{
			sprite_yes.setColor(Color(105, 101, 110, 230));
			choise = 0;
		}
		if (IntRect(620, 355, 268, 85).contains(Mouse::getPosition(window)))
		{
			sprite_no.setColor(Color(105, 101, 110, 230));
			choise = 1;

		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
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
		window.draw(sprite_are_u_sure);
		window.draw(sprite_yes);
		window.draw(sprite_no);
		window.display();
	}
	return true;
}

bool setup_single(RenderWindow& window, Sprite& background) {
	int choose_color = 1000;
	int choose_opponent = 1000;
	int choose_keymap = 1000;
	Texture arrows, blue, color, green, keymap, name, number_of_enemies, purple, red, save, wasd, zero, one, two, three, four, map;
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
	map.loadFromFile("imgs/map_selection.psd");
	Font shrift;
	shrift.loadFromFile("fonts/CyberwayRiders.ttf");
	PlayerNameInput.setFillColor(sf::Color(0, 0, 255));
	PlayerNameInput.setFont(shrift);
	PlayerNameInput.setCharacterSize(40);

	Sprite sprite_arrows(arrows), sprite_blue(blue), sprite_color(color), sprite_green(green), sprite_keymap(keymap), sprite_name(name), sprite_number_of_enemies(number_of_enemies), sprite_purple(purple), sprite_red(red), sprite_save(save), sprite_wasd(wasd), sprite_0(zero), sprite_1(one), sprite_2(two), sprite_3(three), sprite_4(four), sprite_map(map);
	sprite_arrows.setPosition(610, 380);
	sprite_blue.setPosition(280, 149);
	sprite_color.setPosition(94, 146);
	sprite_green.setPosition(450, 149);
	sprite_keymap.setPosition(94, 378);
	sprite_name.setPosition(94, 30);
	sprite_number_of_enemies.setPosition(94, 264);
	sprite_purple.setPosition(530, 149);
	sprite_red.setPosition(370, 149);
	sprite_save.setPosition(94, 630);
	sprite_wasd.setPosition(350, 380);
	sprite_0.setPosition(570, 266);
	sprite_1.setPosition(650, 266);
	sprite_2.setPosition(720, 266);
	sprite_3.setPosition(790, 266);
	sprite_4.setPosition(860, 266);
	sprite_map.setPosition(94, 500);
	bool is_setup = true;
	int choise = 666;
	while (is_setup)
	{
		choise = 666;
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
		sprite_map.setColor(Color::White);


		if (IntRect(94, 630, 188, 66).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;

		}
		if (IntRect(610, 380, 304, 59).contains(Mouse::getPosition(window)))
		{
			sprite_arrows.setColor(Color(105, 101, 110, 230));
			choise = 1;

		}
		if (IntRect(280, 149, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_blue.setColor(Color(105, 101, 110, 230));
			choise = 2;

		}

		if (IntRect(450, 149, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_green.setColor(Color(105, 101, 110, 230));
			choise = 3;

		}

		if (IntRect(94, 30, 538, 60).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}
		if (IntRect(530, 149, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_purple.setColor(Color(105, 101, 110, 230));
			choise = 5;

		}
		if (IntRect(370, 149, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_red.setColor(Color(105, 101, 110, 230));
			choise = 6;

		}
		if (IntRect(350, 380, 224, 59).contains(Mouse::getPosition(window)))
		{
			sprite_wasd.setColor(Color(105, 101, 110, 230));
			choise = 7;

		}
		if (IntRect(570, 266, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_0.setColor(Color(105, 101, 110, 230));
			choise = 8;

		}
		if (IntRect(650, 266, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_1.setColor(Color(105, 101, 110, 230));
			choise = 9;

		}
		if (IntRect(720, 266, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_2.setColor(Color(105, 101, 110, 230));
			choise = 10;

		}
		if (IntRect(790, 266, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_3.setColor(Color(105, 101, 110, 230));
			choise = 11;

		}
		if (IntRect(860, 266, 45, 45).contains(Mouse::getPosition(window)))
		{
			sprite_4.setColor(Color(105, 101, 110, 230));
			choise = 12;

		}

		if (IntRect(94, 500, 297, 61).contains(Mouse::getPosition(window)))
		{
			sprite_map.setColor(Color(105, 101, 110, 230));
			choise = 13;

		}




		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (choise)
				{
				case 0:

					is_setup = false;
					break;
				case 1:
					keymap_str = "arrows";
					choose_keymap = 1;

					break;
				case 2:
					color_str = "0";
					choose_color = 1;
					break;
				case 3:
					color_str = "2";
					choose_color = 2;
					break;
				case 4:
					goto L;
					break;
				case 5:
					color_str = "3";
					choose_color = 3;
					break;
				case 6:
					color_str = "1";
					choose_color = 4;
					break;
				case 7:
					keymap_str = "letters";
					choose_keymap = 2;
					break;
				case 8:
					number = "0";
					choose_opponent = 0;
					break;
				case 9:
					number = "1";
					choose_opponent = 1;
					break;
				case 10:
					number = "2";
					choose_opponent = 2;
					break;
				case 11:
					number = "3";
					choose_opponent = 3;
					break;
				case 12:
					number = "4";
					choose_opponent = 4;
					break;
				case 13:
					is_setup = map_selection(window, background);
					break;
				default:
					break;
				}


			}
		L:
			if (event.type == sf::Event::TextEntered) {
				PlayerNameInput.setPosition(250, 34);

				if ((event.text.unicode < 128)) {

					if (event.text.unicode == 8) {
						if (PlayerNameDynamic.length() != 0)
							PlayerNameDynamic.pop_back();
					}
					else if (event.text.unicode == 32) {
						PlayerNameDynamic += "_";
					}
					else {
						PlayerNameDynamic += static_cast<char>(event.text.unicode);
					}

					PlayerNameInput.setString(PlayerNameDynamic);

				}

			}




		}
		//оставляем затемнение при нажатии мышкой выбранной области
		if (choose_keymap == 1) {
			sprite_arrows.setColor(Color(105, 101, 110, 230));
		}
		if (choose_keymap == 2) {
			sprite_wasd.setColor(Color(105, 101, 110, 230));
		}
		if (choose_opponent == 0) {
			sprite_0.setColor(Color(105, 101, 110, 230));
		}
		if (choose_opponent == 1) {
			sprite_1.setColor(Color(105, 101, 110, 230));
		}
		if (choose_opponent == 2) {
			sprite_2.setColor(Color(105, 101, 110, 230));
		}
		if (choose_opponent == 3) {
			sprite_3.setColor(Color(105, 101, 110, 230));
		}
		if (choose_opponent == 4) {
			sprite_4.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 1) {
			sprite_blue.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 2) {
			sprite_green.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 3) {
			sprite_purple.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 4) {
			sprite_red.setColor(Color(105, 101, 110, 230));
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
		window.draw(sprite_map);
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

bool map_selection(RenderWindow& window, Sprite& background) {
	Texture map_1, map_2, map_3, map_1_text, map_2_text, map_3_text, save;
	int predv_choise = 666;
	int choise = 666;
	map_1.loadFromFile("imgs/map_1.psd");
	map_2.loadFromFile("imgs/map_2.psd");
	map_3.loadFromFile("imgs/map_3.psd");
	map_1_text.loadFromFile("imgs/map_1_text.psd");
	map_2_text.loadFromFile("imgs/map_2_text.psd");
	map_3_text.loadFromFile("imgs/map_3_text.psd");
	save.loadFromFile("imgs/save1.psd");
	Sprite sprite_map1(map_1), sprite_map2(map_2), sprite_map3(map_3), sprite_map1_text(map_1_text), sprite_map2_text(map_2_text), sprite_map3_text(map_3_text), sprite_save(save);
	bool is_setup = true;
	sprite_map1.setPosition(470, 110);
	sprite_map2.setPosition(470, 110);
	sprite_map3.setPosition(470, 110);
	sprite_map1_text.setPosition(60, 70);
	sprite_map2_text.setPosition(60, 220);
	sprite_map3_text.setPosition(60, 370);
	sprite_save.setPosition(90, 570);
	while (is_setup)
	{
		predv_choise = 666;
		sprite_map1.setColor(Color::White);
		sprite_map2.setColor(Color::White);
		sprite_map3.setColor(Color::White);
		sprite_map1_text.setColor(Color::White);
		sprite_map2_text.setColor(Color::White);
		sprite_map3_text.setColor(Color::White);
		sprite_save.setColor(Color::White);

		if (IntRect(60, 70, 351, 100).contains(Mouse::getPosition(window)))
		{
			sprite_map1_text.setColor(Color(105, 101, 110, 230));

			predv_choise = 0;

		}
		if (IntRect(60, 220, 351, 100).contains(Mouse::getPosition(window)))
		{
			sprite_map2_text.setColor(Color(105, 101, 110, 230));
			predv_choise = 1;

		}
		if (IntRect(60, 370, 351, 100).contains(Mouse::getPosition(window)))
		{
			sprite_map3_text.setColor(Color(105, 101, 110, 230));
			predv_choise = 2;

		}
		if (IntRect(90, 570, 278, 93).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			predv_choise = 3;

		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (predv_choise)
				{
				case 0:
					choise_map = 0;
					break;
				case 1:
					choise_map = 1;
					break;
				case 2:
					choise_map = 2;
					break;
				case 3:
					is_setup = false;
					break;
				}

			}



		}
		if (choise_map == 0) {
			sprite_map1_text.setColor(Color(105, 101, 110, 230));
		}
		if (choise_map == 1) {
			sprite_map2_text.setColor(Color(105, 101, 110, 230));
		}
		if (choise_map == 2) {
			sprite_map3_text.setColor(Color(105, 101, 110, 230));
		}

		window.draw(background);
		window.draw(sprite_map1_text);
		window.draw(sprite_map2_text);
		window.draw(sprite_map3_text);
		window.draw(sprite_save);

		if (choise_map == 0) {
			window.draw(sprite_map1);
		}
		if (choise_map == 1) {
			window.draw(sprite_map2);
		}
		if (choise_map == 2) {
			window.draw(sprite_map3);
		}
		if (predv_choise == 0) {
			window.draw(sprite_map1);
		}
		if (predv_choise == 1) {
			window.draw(sprite_map2);
		}
		if (predv_choise == 2) {
			window.draw(sprite_map3);
		}
		window.display();
	}
	return true;
}

bool setup_multi1(RenderWindow& window, Sprite& background) {
	int choose_color = 1000;
	int choose_keymap = 1000;
	int keymap_status = 0;
	Texture arrows, blue, color, keymap, name, number_of_enemies, red, save, wasd, first, map;
	arrows.loadFromFile("imgs/arrows.psd");
	blue.loadFromFile("imgs/blue.psd");
	color.loadFromFile("imgs/color.psd");

	keymap.loadFromFile("imgs/keymap.psd");
	name.loadFromFile("imgs/name.psd");
	map.loadFromFile("imgs/map_selection.psd");

	red.loadFromFile("imgs/red.psd");
	save.loadFromFile("imgs/save.psd");
	wasd.loadFromFile("imgs/wasd.psd");
	first.loadFromFile("imgs/1_player.psd");

	Font shrift;
	shrift.loadFromFile("fonts/CyberwayRiders.ttf");
	PlayerNameInput_1.setFillColor(sf::Color(0, 0, 255));
	PlayerNameInput_1.setFont(shrift);
	PlayerNameInput_1.setCharacterSize(40);

	Sprite sprite_arrows(arrows), sprite_blue(blue), sprite_color(color), sprite_keymap(keymap), sprite_name(name), sprite_red(red), sprite_save(save), sprite_wasd(wasd), sprite_first(first), sprite_map(map);
	sprite_arrows.setPosition(610, 330);
	sprite_blue.setPosition(280, 229);
	sprite_color.setPosition(94, 226);

	sprite_keymap.setPosition(94, 328);
	sprite_name.setPosition(94, 130);


	sprite_red.setPosition(370, 229);
	sprite_save.setPosition(94, 600);
	sprite_wasd.setPosition(350, 330);

	sprite_first.setPosition(94, 40);
	sprite_map.setPosition(94, 450);

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
		sprite_map.setColor(Color::White);

		if (IntRect(94, 600, 188, 66).contains(Mouse::getPosition(window)))
		{
			sprite_save.setColor(Color(105, 101, 110, 230));
			choise = 0;
		}
		if (IntRect(610, 330, 304, 59).contains(Mouse::getPosition(window)))
		{
			sprite_arrows.setColor(Color(105, 101, 110, 230));
			choise = 1;
		}
		if (IntRect(280, 229, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_blue.setColor(Color(105, 101, 110, 230));
			choise = 2;
		}
		if (IntRect(94, 130, 538, 60).contains(Mouse::getPosition(window)))
		{
			sprite_name.setColor(Color(105, 101, 110, 230));
			choise = 3;
		}

		if (IntRect(370, 229, 49, 49).contains(Mouse::getPosition(window)))
		{
			sprite_red.setColor(Color(105, 101, 110, 230));
			choise = 4;

		}
		if (IntRect(350, 330, 224, 59).contains(Mouse::getPosition(window)))
		{
			sprite_wasd.setColor(Color(105, 101, 110, 230));
			choise = 5;

		}
		if (IntRect(94, 450, 297, 61).contains(Mouse::getPosition(window)))
		{
			sprite_map.setColor(Color(105, 101, 110, 230));
			choise = 6;

		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (choise)
				{
				case 0:
					is_setup = setup_multi2(window, background, keymap_status);
					return true;
					break;
				case 1:
					keymap_str_1 = "arrows";
					choose_keymap = 1;
					keymap_status = 1;
					break;
				case 2:
					color_str_1 = "0";
					choose_color = 1;
					break;

				case 3:
					goto L;
					break;

				case 4:
					color_str_1 = "1";
					choose_color = 2;
					break;
				case 5:
					keymap_str_1 = "letters";
					choose_keymap = 2;
					keymap_status = 2;
					break;
				case 6:
					is_setup = map_selection(window, background);
					break;
				default:
					break;
				}

			}
		L:
			if (event.type == sf::Event::TextEntered) {
				PlayerNameInput_1.setPosition(250, 134);

				if (event.text.unicode < 128) {
					if (event.text.unicode == 8) {
						if (PlayerNameDynamic_1.length() != 0)
							PlayerNameDynamic_1.pop_back();
					}
					else if (event.text.unicode == 32) {
						PlayerNameDynamic_1 += "_";
					}
					else {
						PlayerNameDynamic_1 += static_cast<char>(event.text.unicode);
					}

					PlayerNameInput_1.setString(PlayerNameDynamic_1);

				}

			}




		}

		if (choose_color == 1) {
			sprite_blue.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 2) {
			sprite_red.setColor(Color(105, 101, 110, 230));
		}
		if (choose_keymap == 1) {
			sprite_arrows.setColor(Color(105, 101, 110, 230));
		}
		if (choose_keymap == 2) {
			sprite_wasd.setColor(Color(105, 101, 110, 230));
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
		window.draw(sprite_map);
		window.display();
	}
	return true;
}

bool setup_multi2(RenderWindow& window, Sprite& background, int keymap_status) {

	int choose_color = 1000;
	int choose_keymap = 1000;


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
					choose_keymap = 1;
					break;
				case 2:
					color_str_2 = "2";
					choose_color = 1;
					break;

				case 4:
					goto L;
					break;

				case 7:
					color_str_2 = "3";
					choose_color = 2;
					break;
				case 9:
					keymap_str_2 = "letters";
					choose_keymap = 2;
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
					else if (event.text.unicode == 32) {
						PlayerNameDynamic_2 += "_";
					}
					else {
						PlayerNameDynamic_2 += static_cast<char>(event.text.unicode);
					}

					PlayerNameInput_2.setString(PlayerNameDynamic_2);

				}

			}




		}
		if (choose_color == 1) {
			sprite_green.setColor(Color(105, 101, 110, 230));
		}
		if (choose_color == 2) {
			sprite_purple.setColor(Color(105, 101, 110, 230));
		}
		if (choose_keymap == 1) {
			sprite_arrows.setColor(Color(105, 101, 110, 230));
		}
		if (choose_keymap == 2) {
			sprite_wasd.setColor(Color(105, 101, 110, 230));
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


	int menu_status = 0;

	Texture background_start, begin, shesterenka, exit_texture;

	background_start.loadFromFile("imgs/bg.psd");
	begin.loadFromFile("imgs/begin.psd");
	shesterenka.loadFromFile("imgs/shesterenka.psd");
	exit_texture.loadFromFile("imgs/exit.psd");

	Sprite sprite_bg(background_start), sprite_begin(begin), sprite_shesterenka(shesterenka), sprite_exit(exit_texture);
	sprite_bg.setPosition(0, 0);

	sprite_begin.setPosition(100, 120);

	sprite_shesterenka.setPosition(240, 510);
	sprite_exit.setPosition(100, 298);


	bool is_menu = true;
	menu_status = 6;

	while (is_menu)
	{
		menu_status = 6;
		sprite_begin.setColor(Color::White);
		sprite_shesterenka.setColor(Color::White);
		sprite_exit.setColor(Color::White);
		if (IntRect(100, 120, 452, 92).contains(Mouse::getPosition(window)))
		{
			sprite_begin.setColor(Color(105, 101, 110, 230));
			menu_status = 1;
		}

		if (IntRect(260, 510, 165, 165).contains(Mouse::getPosition(window)))
		{
			sprite_shesterenka.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}

		if (IntRect(100, 298, 452, 92).contains(Mouse::getPosition(window)))
		{
			sprite_exit.setColor(Color(105, 101, 110, 230));
			menu_status = 3;
		}
		if (amount == 1) {
			Event event;
			while (window.pollEvent(event))
			{

				if (event.type == Event::Closed)

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
							Settings << "PLAYER_COLOR1 0" << endl;
							Settings << "PLAYER_COLOR2 2" << endl;
						}
						else {
							Settings << "PLAYER_COLOR1 " << color_str << endl;
							Settings << "PLAYER_COLOR2 1" << endl;

						}

						if (choise_map == 1) {
							Settings << "MAP_INDEX 1" << endl;
						}
						else if (choise_map == 2) {
							Settings << "MAP_INDEX 2" << endl;
						}
						else
							Settings << "MAP_INDEX 0" << endl;
						if (number == "") {
							Settings << "BOT_COUNT " << 0 << endl;
						}
						else {
							Settings << "BOT_COUNT " << number << endl;
						}
						Settings << "PLAYER_COUNT 1" << endl;
						if (keymap_str == "") {
							Settings << "CONTROL " << "letters" << endl;


						}
						else {
							Settings << "CONTROL1 " << keymap_str << endl;


						}

						if (PlayerNameDynamic == "") {
							Settings << "PLAYER1_NAME PLAYER_1" << endl;
							Settings << "PLAYER2_NAME PLAYER_2" << endl;

						}
						else {
							Settings << "PLAYER1_NAME " << PlayerNameDynamic << endl;
							Settings << "PLAYER2_NAME PLAYER_2" << endl;

						}
						Settings.close();
						is_menu = is_pause(window);
						break;
					case 2:
						is_menu = setup_single(window, sprite_bg);
						break;
					case 3:
						is_menu = exit(window, sprite_bg);
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

				if (event.type == Event::Closed)

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

						if (choise_map == 1) {
							Settings << "MAP_INDEX 1" << endl;
						}
						else if (choise_map == 2) {
							Settings << "MAP_INDEX 2" << endl;
						}
						else
							Settings << "MAP_INDEX 0" << endl;
						Settings << "BOT_COUNT 0" << endl;
						Settings << "PLAYER_COUNT 2" << endl;

						if (keymap_str_1 == "") {
							Settings << "CONTROL " << "letters" << endl;

						}
						else {
							Settings << "CONTROL " << keymap_str_1 << endl;
						}

						if (PlayerNameDynamic_1 == "") {
							Settings << "PLAYER1_NAME " << "PLAYER_1" << endl;
						}
						else {
							Settings << "PLAYER1_NAME " << PlayerNameDynamic_1 << endl;
						}

						if (PlayerNameDynamic_2 == "") {
							Settings << "PLAYER2_NAME " << "PLAYER_2" << endl;
						}
						else {
							Settings << "PLAYER2_NAME " << PlayerNameDynamic_2 << endl;
						}
						Settings.close();
						break;
					case 2:
						is_menu = setup_multi1(window, sprite_bg);
						break;
					case 3:
						is_menu = exit(window, sprite_bg);
						break;
					default:
						break;
					}
				}
			}
		}

		window.clear();
		window.draw(sprite_bg);
		window.draw(sprite_begin);
		window.draw(sprite_shesterenka);
		window.draw(sprite_exit);
		window.display();

	}

}

void choose_mode(RenderWindow& window) {
	int menu_status = 0;
	Texture background_start, single, multi;
	// очищаем наш файл
	Settings.open("Config.txt", std::ios::trunc);
	Settings.close();
	// загружаем картинки
	background_start.loadFromFile("imgs/bg.psd");
	single.loadFromFile("imgs/single_player.psd");
	multi.loadFromFile("imgs/multi_player.psd");
	Sprite sprite_bg(background_start), sprite_single(single), sprite_multi(multi);
	sprite_bg.setPosition(0, 0);
	sprite_single.setPosition(200, 200);
	sprite_multi.setPosition(200, 400);
	bool is_menu = true;
	menu_status = 6;
	while (is_menu)
	{
		sprite_single.setColor(Color::White);
		sprite_multi.setColor(Color::White);

		if (IntRect(200, 200, 580, 100).contains(Mouse::getPosition(window)))
		{
			sprite_single.setColor(Color(105, 101, 110, 230));
			menu_status = 1;
		}

		if (IntRect(200, 400, 580, 100).contains(Mouse::getPosition(window)))
		{
			sprite_multi.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}
		//обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// нажатие на крестик
				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (menu_status)
				{
				case 1:
					main_menu(window, 1);
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
		window.draw(sprite_bg);
		window.draw(sprite_single);
		window.draw(sprite_multi);
		window.display();
	}


}

bool is_pause(RenderWindow& window) {
	Texture pause, Continue, quit_to_menu, circle1, circle2, circle3, restart, background;
	pause.loadFromFile("imgs/pause.psd");
	Continue.loadFromFile("imgs/continue.psd");
	quit_to_menu.loadFromFile("imgs/quit_to_menu.psd");
	circle1.loadFromFile("imgs/circle.psd");
	circle2.loadFromFile("imgs/circle.psd");
	circle3.loadFromFile("imgs/circle.psd");
	restart.loadFromFile("imgs/restart.psd");
	background.loadFromFile("imgs/101.psd");

	Sprite sprite_pause(pause), sprite_continue(Continue), sprite_quit(quit_to_menu), sprite_circle1(circle1), sprite_circle2(circle2), sprite_circle3(circle3), sprite_restart(restart), sprite_back(background);
	sprite_back.setPosition(0, 0);
	sprite_pause.setPosition(500, 20);
	sprite_continue.setPosition(500, 200);
	sprite_restart.setPosition(500, 400);
	sprite_quit.setPosition(400, 600);
	sprite_circle1.setPosition(350, 200);
	sprite_circle2.setPosition(350, 400);
	sprite_circle3.setPosition(250, 600);
	int choise = 100;
	bool is_menu = true;
	int menu_status = 20;
	while (is_menu)
	{
		menu_status = 20;
		sprite_back.setColor(Color::White);
		sprite_pause.setColor(Color::White);
		sprite_continue.setColor(Color::White);
		sprite_quit.setColor(Color::White);
		sprite_restart.setColor(Color::White);
		sprite_circle1.setColor(Color::White);
		sprite_circle2.setColor(Color::White);
		sprite_circle3.setColor(Color::White);
		if (IntRect(500, 200, 350, 88).contains(Mouse::getPosition(window)))
		{
			sprite_continue.setColor(Color(105, 101, 110, 230));
			menu_status = 1;

		}
		if (IntRect(500, 400, 341, 87).contains(Mouse::getPosition(window)))
		{
			sprite_restart.setColor(Color(105, 101, 110, 230));
			menu_status = 2;
		}
		if (IntRect(400, 600, 467, 100).contains(Mouse::getPosition(window)))
		{
			sprite_quit.setColor(Color(105, 101, 110, 230));
			menu_status = 3;
		}

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				switch (menu_status)
				{
				case 1:


					choise = 1;
					return false;
					break;
				case 2:
					choise = 2;
					break;
				case 3:
					choise = 3;
					is_menu = false;
					break;
				default:
					break;
				}
			}
		}


		sprite_back.setColor(Color(192, 192, 192, 255));
		window.clear();
		window.draw(sprite_back);
		window.draw(sprite_pause);
		window.draw(sprite_continue);
		window.draw(sprite_quit);
		window.draw(sprite_restart);
		if (menu_status == 1) {
			window.draw(sprite_circle1);
		}
		if (menu_status == 2) {
			window.draw(sprite_circle2);
		}
		if (menu_status == 3) {
			window.draw(sprite_circle3);
		}
		if (choise == 1) {
			window.draw(sprite_circle1);
		}
		if (choise == 2) {
			window.draw(sprite_circle2);
		}
		if (choise == 3) {
			window.draw(sprite_circle3);
		}

		window.display();
	}
	return true;
}


