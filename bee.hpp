#ifndef BEE_HPP
#define BEE_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define BEE_X 3
#define BEE_Y 4
#define BEE_LIFE 1000
#define BEE_MANA  500
#define BEE_POWER None
#define BEE_DMG 100
#define BEE_ATK_DELAY 5
#define BEE_XP 10
#define BEE_SPEED 1.5
#define BEE_RANGE1 1
#define BEE_RANGE2 -1
#define BEE_RANGE3 -1
#define BEE_DELAY1 1
#define BEE_DELAY2 7
#define BEE_DELAY3 10
#define BEE_DMG1 50
#define BEE_DMG2 100
#define BEE_DMG3 200
#define BEE_V2I1 Vector2i(5,3)
#define BEE_V2I2 Vector2i(5,5)
#define BEE_V2I3 Vector2i(5,5)
#define BEE_MANA_COST1 0
#define BEE_MANA_COST2 0
#define BEE_MANA_COST3 0

class Bee : public Bot
{
	public :

	Bee(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Bee();

	private:

};

#endif
