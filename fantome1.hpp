#ifndef FANTOME1_HPP
#define FANTOME1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define FANTOME1_X 3
#define FANTOME1_Y 4
#define FANTOME1_LIFE 2500
#define FANTOME1_MANA  500
#define FANTOME1_POWER None
#define FANTOME1_DMG 100
#define FANTOME1_ATK_DELAY 5
#define FANTOME1_XP 10
#define FANTOME1_SPEED 2.5
#define FANTOME1_RANGE1 1
#define FANTOME1_RANGE2 2
#define FANTOME1_RANGE3 -1
#define FANTOME1_DELAY1 3
#define FANTOME1_DELAY2 8
#define FANTOME1_DELAY3 10
#define FANTOME1_DMG1 250
#define FANTOME1_DMG2 400
#define FANTOME1_DMG3 200
#define FANTOME1_V2I1 Vector2i(5,3)
#define FANTOME1_V2I2 Vector2i(5,5)
#define FANTOME1_V2I3 Vector2i(5,5)
#define FANTOME1_MANA_COST1 0
#define FANTOME1_MANA_COST2 0
#define FANTOME1_MANA_COST3 0

class Fantome1 : public Bot
{
	public :

	Fantome1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Fantome1();

	private:

};

#endif
