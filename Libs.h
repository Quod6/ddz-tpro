#pragma once

#include <random>
#include <vector>
#include <ctime>
#include <experimental/random>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ConstParser.h"

using namespace std;
using namespace sf;

int randInt(int min, int max)
{
	return experimental::randint(min, max);
}
