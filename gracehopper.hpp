#ifndef GRACE_HOPPER_HPP
#define GRACE_HOPPER_HPP

#include "player.hpp"
#include "config.hpp"

#define GRACE_HOPPER_X 3
#define GRACE_HOPPER_Y 4
#define GRACE_HOPPER_LIFE 700
#define GRACE_HOPPER_MANA  1000
#define GRACE_HOPPER_POWER None
#define GRACE_HOPPER_DMG 120
#define GRACE_HOPPER_ATK_DELAY 1
#define GRACE_HOPPER_XP 10
#define GRACE_HOPPER_SPEED 3.5
#define GRACE_HOPPER_RANGE1 4
#define GRACE_HOPPER_RANGE2 4
#define GRACE_HOPPER_RANGE3 4
#define GRACE_HOPPER_DELAY1 0.5
#define GRACE_HOPPER_DELAY2 4
#define GRACE_HOPPER_DELAY3 20
#define GRACE_HOPPER_DMG1 350
#define GRACE_HOPPER_DMG2 600
#define GRACE_HOPPER_DMG3 1300
#define GRACE_HOPPER_V2I1 Vector2i(5,6)
#define GRACE_HOPPER_V2I2 Vector2i(5,3)
#define GRACE_HOPPER_V2I3 Vector2i(5,5)
#define GRACE_HOPPER_MANA_COST1 30
#define GRACE_HOPPER_MANA_COST2 70
#define GRACE_HOPPER_MANA_COST3 200

class GraceHopper : public Player
{
	public :

	GraceHopper(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3);
	~GraceHopper();

	private:
	
	
};

#endif
