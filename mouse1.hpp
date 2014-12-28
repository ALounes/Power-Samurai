#ifndef MOUSE1_HPP
#define MOUSE1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define MOUSE1_X 3
#define MOUSE1_Y 4
#define MOUSE1_LIFE 1000
#define MOUSE1_MANA  500
#define MOUSE1_POWER None
#define MOUSE1_DMG 100
#define MOUSE1_ATK_DELAY 5
#define MOUSE1_XP 10
#define MOUSE1_SPEED 1.5
#define MOUSE1_RANGE1 1
#define MOUSE1_RANGE2 2
#define MOUSE1_RANGE3 -1
#define MOUSE1_DELAY1 1
#define MOUSE1_DELAY2 7
#define MOUSE1_DELAY3 10
#define MOUSE1_DMG1 50
#define MOUSE1_DMG2 100
#define MOUSE1_DMG3 200
#define MOUSE1_V2I1 Vector2i(5,3)
#define MOUSE1_V2I2 Vector2i(5,5)
#define MOUSE1_V2I3 Vector2i(5,5)
#define MOUSE1_MANA_COST1 0
#define MOUSE1_MANA_COST2 0
#define MOUSE1_MANA_COST3 0

class Mouse1 : public Bot
{
	public :

	Mouse1(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Mouse1();

	private:

};

#endif
