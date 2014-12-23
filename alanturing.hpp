#ifndef ALANTURING_HPP
#define ALANTURING_HPP

#include "player.hpp"
#include "config.hpp"

#define ALAN_TURING_X 3
#define ALAN_TURING_Y 4
#define ALAN_TURING_LIFE 2000
#define ALAN_TURING_MANA  300
#define ALAN_TURING_POWER None

class AlanTuring : public Player
{
	public :

	AlanTuring(RenderWindow *win, Image &image, Map *myMap,float att_dmg);
	~AlanTuring();

	private:
	
	
};

#endif
