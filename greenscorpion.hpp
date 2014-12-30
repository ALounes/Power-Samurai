#ifndef GREENSCORPION_HPP
#define GREENSCORPION_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define GREENSCORPION_X 3
#define GREENSCORPION_Y 4
#define GREENSCORPION_LIFE 1000
#define GREENSCORPION_MANA  500
#define GREENSCORPION_POWER None
#define GREENSCORPION_DMG 100
#define GREENSCORPION_ATK_DELAY 5
#define GREENSCORPION_XP 10
#define GREENSCORPION_SPEED 1.5
#define GREENSCORPION_RANGE1 1
#define GREENSCORPION_RANGE2 2
#define GREENSCORPION_RANGE3 -1
#define GREENSCORPION_DELAY1 1
#define GREENSCORPION_DELAY2 7
#define GREENSCORPION_DELAY3 10
#define GREENSCORPION_DMG1 50
#define GREENSCORPION_DMG2 100
#define GREENSCORPION_DMG3 200
#define GREENSCORPION_V2I1 Vector2i(5,3)
#define GREENSCORPION_V2I2 Vector2i(5,5)
#define GREENSCORPION_V2I3 Vector2i(5,5)
#define GREENSCORPION_MANA_COST1 0
#define GREENSCORPION_MANA_COST2 0
#define GREENSCORPION_MANA_COST3 0

class Greenscorpion : public Bot
{
	public :

	Greenscorpion(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Greenscorpion();

	private:

};

#endif
