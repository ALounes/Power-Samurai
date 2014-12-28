#ifndef BJARNESTROUSTRUP_HPP
#define BJARNESTROUSTRUP_HPP

#include "player.hpp"
#include "config.hpp"

#define BJARNE_STROUSTRUP_X 3
#define BJARNE_STROUSTRUP_Y 4
#define BJARNE_STROUSTRUP_LIFE 2000
#define BJARNE_STROUSTRUP_MANA  300
#define BJARNE_STROUSTRUP_POWER None
#define BJARNE_STROUSTRUP_DMG 100
#define BJARNE_STROUSTRUP_ATK_DELAY 5
#define BJARNE_STROUSTRUP_XP 10
#define BJARNE_STROUSTRUP_SPEED 1.5
#define BJARNE_STROUSTRUP_RANGE1 2
#define BJARNE_STROUSTRUP_RANGE2 2
#define BJARNE_STROUSTRUP_RANGE3 2
#define BJARNE_STROUSTRUP_DELAY1 5
#define BJARNE_STROUSTRUP_DELAY2 10
#define BJARNE_STROUSTRUP_DELAY3 20
#define BJARNE_STROUSTRUP_DMG1 100
#define BJARNE_STROUSTRUP_DMG2 200
#define BJARNE_STROUSTRUP_DMG3 500
#define BJARNE_STROUSTRUP_V2I1 Vector2i(5,6)
#define BJARNE_STROUSTRUP_V2I2 Vector2i(5,5)
#define BJARNE_STROUSTRUP_V2I3 Vector2i(5,5)
#define BJARNE_STROUSTRUP_MANA_COST1 30
#define BJARNE_STROUSTRUP_MANA_COST2 100
#define BJARNE_STROUSTRUP_MANA_COST3 300

class BjarneStroustrup : public Player
{
	public :
	BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap,float att_dmg);
	~BjarneStroustrup();

	private:
	
};

#endif
