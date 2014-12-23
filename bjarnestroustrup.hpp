#ifndef BJARNESTROUSTRUP_HPP
#define BJARNESTROUSTRUP_HPP

#include "player.hpp"
#include "config.hpp"

#define BJARNE_STROUSTRUP_X 3
#define BJARNE_STROUSTRUP_Y 4
#define BJARNE_STROUSTRUP_LIFE 2000
#define BJARNE_STROUSTRUP_MANA  300
#define BJARNE_STROUSTRUP_POWER None

class BjarneStroustrup : public Player
{
	public :
	BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap,float att_dmg);
	~BjarneStroustrup();

	private:
	
};

#endif
