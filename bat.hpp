#ifndef BAT_HPP
#define BAT_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define BAT_X 3
#define BAT_Y 4
#define BAT_LIFE 1000
#define BAT_MANA  500
#define BAT_POWER None
#define BAT_DMG 100
#define BAT_ATK_DELAY 5
#define BAT_XP 10
#define BAT_SPEED 1.5
#define BAT_RANGE1 1
#define BAT_RANGE2 2
#define BAT_RANGE3 -1
#define BAT_DELAY1 1
#define BAT_DELAY2 7
#define BAT_DELAY3 10
#define BAT_DMG1 50
#define BAT_DMG2 100
#define BAT_DMG3 200
#define BAT_V2I1 Vector2i(5,3)
#define BAT_V2I2 Vector2i(5,5)
#define BAT_V2I3 Vector2i(5,5)
#define BAT_MANA_COST1 0
#define BAT_MANA_COST2 0
#define BAT_MANA_COST3 0

class Bat : public Bot
{
	public :

	Bat(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Bat();

	private:

};

#endif
