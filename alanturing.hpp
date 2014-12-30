#ifndef ALANTURING_HPP
#define ALANTURING_HPP

#include "player.hpp"
#include "config.hpp"

#define ALAN_TURING_X 3
#define ALAN_TURING_Y 4
#define ALAN_TURING_LIFE 1000
#define ALAN_TURING_MANA  1000
#define ALAN_TURING_POWER None
#define ALAN_TURING_DMG 100
#define ALAN_TURING_ATK_DELAY 1
#define ALAN_TURING_XP 10
#define ALAN_TURING_SPEED 3.5
#define ALAN_TURING_RANGE1 4
#define ALAN_TURING_RANGE2 4
#define ALAN_TURING_RANGE3 4
#define ALAN_TURING_DELAY1 1
#define ALAN_TURING_DELAY2 4
#define ALAN_TURING_DELAY3 20
#define ALAN_TURING_DMG1 150
#define ALAN_TURING_DMG2 450
#define ALAN_TURING_DMG3 1000
#define ALAN_TURING_V2I1 Vector2i(5,6)
#define ALAN_TURING_V2I2 Vector2i(5,5)
#define ALAN_TURING_V2I3 Vector2i(5,5)
#define ALAN_TURING_MANA_COST1 30
#define ALAN_TURING_MANA_COST2 70
#define ALAN_TURING_MANA_COST3 200

class AlanTuring : public Player
{
	public :

	AlanTuring(RenderWindow *win, Image &image, Map *myMap,float att_dmg, Image* image1, Image* image2, Image* image3);
	~AlanTuring();

	private:
	
	
};

#endif
