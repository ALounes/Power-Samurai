#ifndef BLUESLIME_HPP
#define BLUESLIME_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define BLUESLIME_X 3
#define BLUESLIME_Y 4
#define BLUESLIME_LIFE 1000
#define BLUESLIME_MANA  500
#define BLUESLIME_POWER None
#define BLUESLIME_DMG 100
#define BLUESLIME_ATK_DELAY 5
#define BLUESLIME_XP 10
#define BLUESLIME_SPEED 1.5
#define BLUESLIME_RANGE1 1
#define BLUESLIME_RANGE2 2
#define BLUESLIME_RANGE3 -1
#define BLUESLIME_DELAY1 1
#define BLUESLIME_DELAY2 7
#define BLUESLIME_DELAY3 10
#define BLUESLIME_DMG1 1000
#define BLUESLIME_DMG2 100
#define BLUESLIME_DMG3 200
#define BLUESLIME_V2I1 Vector2i(5,3)
#define BLUESLIME_V2I2 Vector2i(5,5)
#define BLUESLIME_V2I3 Vector2i(5,5)
#define BLUESLIME_MANA_COST1 0
#define BLUESLIME_MANA_COST2 0
#define BLUESLIME_MANA_COST3 0

class Blueslime : public Bot
{
	public :

	Blueslime(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Blueslime();

	private:

};

#endif
