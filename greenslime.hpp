#ifndef GREENSLIME_HPP
#define GREENSLIME_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define GREENSLIME_X 3
#define GREENSLIME_Y 4
#define GREENSLIME_LIFE 1000
#define GREENSLIME_MANA  500
#define GREENSLIME_POWER None
#define GREENSLIME_DMG 100
#define GREENSLIME_ATK_DELAY 5
#define GREENSLIME_XP 10
#define GREENSLIME_SPEED 1.5
#define GREENSLIME_RANGE1 1
#define GREENSLIME_RANGE2 -1
#define GREENSLIME_RANGE3 -1
#define GREENSLIME_DELAY1 1
#define GREENSLIME_DELAY2 7
#define GREENSLIME_DELAY3 10
#define GREENSLIME_DMG1 50
#define GREENSLIME_DMG2 100
#define GREENSLIME_DMG3 200
#define GREENSLIME_V2I1 Vector2i(5,3)
#define GREENSLIME_V2I2 Vector2i(5,5)
#define GREENSLIME_V2I3 Vector2i(5,5)
#define GREENSLIME_MANA_COST1 0
#define GREENSLIME_MANA_COST2 0
#define GREENSLIME_MANA_COST3 0

class Greenslime : public Bot
{
	public :

	Greenslime(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Greenslime();

	private:

};

#endif
