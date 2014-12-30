#ifndef ATHENA_HPP
#define ATHENA_HPP

#include "player.hpp"
#include "config.hpp"

#define ATHENA_X 3
#define ATHENA_Y 4
#define ATHENA_LIFE 1000
#define ATHENA_MANA  1000
#define ATHENA_POWER None
#define ATHENA_DMG 100
#define ATHENA_ATK_DELAY 1
#define ATHENA_XP 10
#define ATHENA_SPEED 3.5
#define ATHENA_RANGE1 4
#define ATHENA_RANGE2 4
#define ATHENA_RANGE3 4
#define ATHENA_DELAY1 1
#define ATHENA_DELAY2 4
#define ATHENA_DELAY3 20
#define ATHENA_DMG1 150
#define ATHENA_DMG2 450
#define ATHENA_DMG3 1000
#define ATHENA_V2I1 Vector2i(5,6)
#define ATHENA_V2I2 Vector2i(5,5)
#define ATHENA_V2I3 Vector2i(5,5)
#define ATHENA_MANA_COST1 30
#define ATHENA_MANA_COST2 70
#define ATHENA_MANA_COST3 200

class Athena : public Player
{
	public :

	Athena(RenderWindow *win, Image &image, Map *myMap,float att_dmg, Image* image1, Image* image2, Image* image3);
	~Athena();

	private:
	
	
};

#endif
