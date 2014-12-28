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
#define LINUS_TORVALDS_DMG 100
#define LINUS_TORVALDS_ATK_DELAY 5
#define LINUS_TORVALDS_XP 10
#define LINUS_TORVALDS_SPEED 1.5
#define LINUS_TORVALDS_RANGE1 3
#define LINUS_TORVALDS_RANGE2 3
#define LINUS_TORVALDS_RANGE3 3
#define LINUS_TORVALDS_DELAY1 5
#define LINUS_TORVALDS_DELAY2 10
#define LINUS_TORVALDS_DELAY3 20
#define LINUS_TORVALDS_DMG1 100
#define LINUS_TORVALDS_DMG2 300
#define LINUS_TORVALDS_DMG3 500
#define LINUS_TORVALDS_V2I1 Vector2i(5,6)
#define LINUS_TORVALDS_V2I2 Vector2i(5,5)
#define LINUS_TORVALDS_V2I3 Vector2i(5,5)
#define LINUS_TORVALDS_MANA_COST1 30
#define LINUS_TORVALDS_MANA_COST2 100
#define LINUS_TORVALDS_MANA_COST3 300

class LinusTorvalds : public Player
{
	public :

	LinusTorvalds(RenderWindow *win, Image &image, Map *myMap,float att_dmg);

	~LinusTorvalds();

	private:

};

#endif
