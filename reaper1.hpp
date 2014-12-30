#ifndef REAPER1_HPP
#define REAPER1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define REAPER1_X 3
#define REAPER1_Y 4
#define REAPER1_LIFE 1000
#define REAPER1_MANA  500
#define REAPER1_POWER None
#define REAPER1_DMG 100
#define REAPER1_ATK_DELAY 5
#define REAPER1_XP 10
#define REAPER1_SPEED 2
#define REAPER1_RANGE1 1
#define REAPER1_RANGE2 2
#define REAPER1_RANGE3 -1
#define REAPER1_DELAY1 1
#define REAPER1_DELAY2 5
#define REAPER1_DELAY3 10
#define REAPER1_DMG1 50
#define REAPER1_DMG2 100
#define REAPER1_DMG3 200
#define REAPER1_V2I1 Vector2i(5,3)
#define REAPER1_V2I2 Vector2i(5,5)
#define REAPER1_V2I3 Vector2i(5,5)
#define REAPER1_MANA_COST1 0
#define REAPER1_MANA_COST2 0
#define REAPER1_MANA_COST3 0

class Reaper1 : public Bot
{
	public :

	Reaper1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Reaper1();

	private:

};

#endif
