#ifndef ATHENA_HPP
#define ATHENA_HPP

#include "player.hpp"
#include "config.hpp"

#define ATHENA_X 3
#define ATHENA_Y 4
#define ATHENA_LIFE 2000
#define ATHENA_MANA  300
#define ATHENA_POWER None
#define ATHENA_DMG 100
#define ATHENA_ATK_DELAY 5
#define ATHENA_XP 10
#define ATHENA_SPEED 1.5
#define ATHENA_RANGE1 3
#define ATHENA_RANGE2 3
#define ATHENA_RANGE3 3
#define ATHENA_DELAY1 5
#define ATHENA_DELAY2 10
#define ATHENA_DELAY3 20
#define ATHENA_DMG1 100
#define ATHENA_DMG2 200
#define ATHENA_DMG3 500
#define ATHENA_V2I1 Vector2i(5,6)
#define ATHENA_V2I2 Vector2i(5,5)
#define ATHENA_V2I3 Vector2i(5,5)
#define ATHENA_MANA_COST1 30
#define ATHENA_MANA_COST2 100
#define ATHENA_MANA_COST3 300

class Athena : public Player
{
	public :

	Athena(RenderWindow *win, Image &image, Map *myMap,float att_dmg);
	~Athena();

	private:
	
	
};

#endif
