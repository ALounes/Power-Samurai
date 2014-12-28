#ifndef TROLL_HPP
#define TROLL_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define TROLL_X 3
#define TROLL_Y 4
#define TROLL_LIFE 1000
#define TROLL_MANA  500
#define TROLL_POWER None
#define TROLL_DMG 100
#define TROLL_ATK_DELAY 5
#define TROLL_XP 10
#define TROLL_SPEED 1.5
#define TROLL_RANGE1 1
#define TROLL_RANGE2 2
#define TROLL_RANGE3 -1
#define TROLL_DELAY1 1
#define TROLL_DELAY2 7
#define TROLL_DELAY3 10
#define TROLL_DMG1 50
#define TROLL_DMG2 100
#define TROLL_DMG3 200
#define TROLL_V2I1 Vector2i(5,3)
#define TROLL_V2I2 Vector2i(5,5)
#define TROLL_V2I3 Vector2i(5,5)
#define TROLL_MANA_COST1 0
#define TROLL_MANA_COST2 0
#define TROLL_MANA_COST3 0

class Troll : public Bot
{
	public :

	Troll(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Troll();

	private:

};

#endif
