#ifndef NAGA_HPP
#define NAGA_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define NAGA_X 3
#define NAGA_Y 4
#define NAGA_LIFE 1000
#define NAGA_MANA  500
#define NAGA_POWER None
#define NAGA_DMG 100
#define NAGA_ATK_DELAY 5
#define NAGA_XP 10
#define NAGA_SPEED 1.5
#define NAGA_RANGE1 1
#define NAGA_RANGE2 -1
#define NAGA_RANGE3 -1
#define NAGA_DELAY1 2
#define NAGA_DELAY2 7
#define NAGA_DELAY3 10
#define NAGA_DMG1 300
#define NAGA_DMG2 100
#define NAGA_DMG3 200
#define NAGA_V2I1 Vector2i(5,3)
#define NAGA_V2I2 Vector2i(5,5)
#define NAGA_V2I3 Vector2i(5,5)
#define NAGA_MANA_COST1 0
#define NAGA_MANA_COST2 0
#define NAGA_MANA_COST3 0

class Naga : public Bot
{
	public :

	Naga(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Naga();

	private:

};

#endif
