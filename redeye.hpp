#ifndef REDEYE_HPP
#define REDEYE_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define REDEYE_X 3
#define REDEYE_Y 4
#define REDEYE_LIFE 1000
#define REDEYE_MANA  500
#define REDEYE_POWER None
#define REDEYE_DMG 100
#define REDEYE_ATK_DELAY 5
#define REDEYE_XP 10
#define REDEYE_SPEED 1.5
#define REDEYE_RANGE1 1
#define REDEYE_RANGE2 2
#define REDEYE_RANGE3 -1
#define REDEYE_DELAY1 1
#define REDEYE_DELAY2 7
#define REDEYE_DELAY3 10
#define REDEYE_DMG1 50
#define REDEYE_DMG2 100
#define REDEYE_DMG3 200
#define REDEYE_V2I1 Vector2i(5,3)
#define REDEYE_V2I2 Vector2i(5,5)
#define REDEYE_V2I3 Vector2i(5,5)
#define REDEYE_MANA_COST1 0
#define REDEYE_MANA_COST2 0
#define REDEYE_MANA_COST3 0

class Redeye : public Bot
{
	public :

	Redeye(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Redeye();

	private:

};

#endif
