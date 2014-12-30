#ifndef GREENDRAGON1_HPP
#define GREENDRAGON1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define GREENDRAGON1_X 3
#define GREENDRAGON1_Y 4
#define GREENDRAGON1_LIFE 1000
#define GREENDRAGON1_MANA  500
#define GREENDRAGON1_POWER None
#define GREENDRAGON1_DMG 100
#define GREENDRAGON1_ATK_DELAY 5
#define GREENDRAGON1_XP 10
#define GREENDRAGON1_SPEED 1.5
#define GREENDRAGON1_RANGE1 1
#define GREENDRAGON1_RANGE2 2
#define GREENDRAGON1_RANGE3 -1
#define GREENDRAGON1_DELAY1 1
#define GREENDRAGON1_DELAY2 7
#define GREENDRAGON1_DELAY3 10
#define GREENDRAGON1_DMG1 50
#define GREENDRAGON1_DMG2 100
#define GREENDRAGON1_DMG3 200
#define GREENDRAGON1_V2I1 Vector2i(5,3)
#define GREENDRAGON1_V2I2 Vector2i(5,5)
#define GREENDRAGON1_V2I3 Vector2i(5,5)
#define GREENDRAGON1_MANA_COST1 0
#define GREENDRAGON1_MANA_COST2 0
#define GREENDRAGON1_MANA_COST3 0

class Greendragon1 : public Bot
{
	public :

	Greendragon1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Greendragon1();

	private:

};

#endif
