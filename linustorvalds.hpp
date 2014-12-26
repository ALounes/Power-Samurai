#ifndef LINUSTORVALDS_HPP
#define LINUSTORVALDS_HPP

#include "player.hpp"
#include "config.hpp"
//#include "folowinganimation.hpp"

#define LINUS_TORVALDS_X 3
#define LINUS_TORVALDS_Y 4
#define LINUS_TORVALDS_LIFE 1000
#define LINUS_TORVALDS_MANA  500
#define LINUS_TORVALDS_POWER None

class LinusTorvalds : public Player
{
	public :

	LinusTorvalds(RenderWindow *win, Image &image, Map *myMap,float att_dmg);

	~LinusTorvalds();

	private:

};

#endif
