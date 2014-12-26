#ifndef ARMOR1_HPP
#define ARMOR1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define ARMOR1_X 3
#define ARMOR1_Y 4
#define ARMOR1_LIFE 1000
#define ARMOR1_MANA  500
#define ARMOR1_POWER None
#define ARMOR1_DMG 100
#define ARMOR1_ATK_DELAY 5
#define ARMOR1_XP 10
#define ARMOR1_SPEED 1.5
#define ARMOR1_RANGE1 1
#define ARMOR1_RANGE2 3
#define ARMOR1_RANGE3 -1
#define ARMOR1_DELAY1 1
#define ARMOR1_DELAY2 6
#define ARMOR1_DELAY3 10
#define ARMOR1_DMG1 50
#define ARMOR1_DMG2 100
#define ARMOR1_DMG3 200
#define ARMOR1_V2I1 Vector2i(5,3)
#define ARMOR1_V2I2 Vector2i(5,3)
#define ARMOR1_V2I3 Vector2i(5,5)

class Armor1 : public Bot
{
	public :

	Armor1(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Armor1();

	private:

};

#endif
