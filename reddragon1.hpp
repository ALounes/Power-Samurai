#ifndef REDDRAGON1_HPP
#define REDDRAGON1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define REDDRAGON1_X 3
#define REDDRAGON1_Y 4
#define REDDRAGON1_LIFE 1000
#define REDDRAGON1_MANA  500
#define REDDRAGON1_POWER None
#define REDDRAGON1_DMG 100
#define REDDRAGON1_ATK_DELAY 5
#define REDDRAGON1_XP 10
#define REDDRAGON1_SPEED 1.5
#define REDDRAGON1_RANGE1 1
#define REDDRAGON1_RANGE2 2
#define REDDRAGON1_RANGE3 -1
#define REDDRAGON1_DELAY1 1
#define REDDRAGON1_DELAY2 7
#define REDDRAGON1_DELAY3 10
#define REDDRAGON1_DMG1 50
#define REDDRAGON1_DMG2 100
#define REDDRAGON1_DMG3 200
#define REDDRAGON1_V2I1 Vector2i(5,3)
#define REDDRAGON1_V2I2 Vector2i(5,5)
#define REDDRAGON1_V2I3 Vector2i(5,5)
#define REDDRAGON1_MANA_COST1 0
#define REDDRAGON1_MANA_COST2 0
#define REDDRAGON1_MANA_COST3 0

class Reddragon1 : public Bot
{
	public :

	Reddragon1(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Reddragon1();

	private:

};

#endif
