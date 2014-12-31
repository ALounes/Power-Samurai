#ifndef LINUSTORVALDS_HPP
#define LINUSTORVALDS_HPP

#include "player.hpp"
#include "config.hpp"
//#include "folowinganimation.hpp"

#define LINUS_TORVALDS_X 3
#define LINUS_TORVALDS_Y 4
#define LINUS_TORVALDS_LIFE 1500
#define LINUS_TORVALDS_MANA  500
#define LINUS_TORVALDS_POWER None
#define LINUS_TORVALDS_DMG 200
#define LINUS_TORVALDS_ATK_DELAY 0.5
#define LINUS_TORVALDS_XP 10
#define LINUS_TORVALDS_SPEED 3
#define LINUS_TORVALDS_RANGE1 3
#define LINUS_TORVALDS_RANGE2 3
#define LINUS_TORVALDS_RANGE3 3
#define LINUS_TORVALDS_DELAY1 2
#define LINUS_TORVALDS_DELAY2 5
#define LINUS_TORVALDS_DELAY3 20
#define LINUS_TORVALDS_DMG1 100
#define LINUS_TORVALDS_DMG2 300
#define LINUS_TORVALDS_DMG3 500
#define LINUS_TORVALDS_V2I1 Vector2i(5,6)
#define LINUS_TORVALDS_V2I2 Vector2i(5,5)
#define LINUS_TORVALDS_V2I3 Vector2i(5,5)
#define LINUS_TORVALDS_MANA_COST1 30
#define LINUS_TORVALDS_MANA_COST2 60
#define LINUS_TORVALDS_MANA_COST3 100

class LinusTorvalds : public Player
{
	public :

	LinusTorvalds(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3);

	~LinusTorvalds();

	private:

};

#endif
