#ifndef ALANTURING_HPP
#define ALANTURING_HPP

#include "player.hpp"
#include "config.hpp"

#define ALAN_TURING_X 3
#define ALAN_TURING_Y 4
#define ALAN_TURING_LIFE 2000
#define ALAN_TURING_MANA  300
#define ALAN_TURING_POWER None
#define ALAN_TURING_DMG 100
#define ALAN_TURING_ATK_DELAY 5
#define ALAN_TURING_XP 10
#define ALAN_TURING_SPEED 1.5
#define ALAN_TURING_RANGE1 3
#define ALAN_TURING_RANGE2 3
#define ALAN_TURING_RANGE3 3
#define ALAN_TURING_DELAY1 5
#define ALAN_TURING_DELAY2 10
#define ALAN_TURING_DELAY3 20
#define ALAN_TURING_DMG1 100
#define ALAN_TURING_DMG2 200
#define ALAN_TURING_DMG3 500
#define ALAN_TURING_V2I1 Vector2i(5,6)
#define ALAN_TURING_V2I2 Vector2i(5,5)
#define ALAN_TURING_V2I3 Vector2i(5,5)
#define ALAN_TURING_MANA_COST1 30
#define ALAN_TURING_MANA_COST2 100
#define ALAN_TURING_MANA_COST3 300

class AlanTuring : public Player
{
	public :

	AlanTuring(RenderWindow *win, Image &image, Map *myMap,float att_dmg, Image* image1, Image* image2, Image* image3);
	~AlanTuring();

	private:
	
	
};

#endif
