#ifndef GREEN_DRAGON_HPP
#define GREEN_DRAGON_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define GREEN_DRAGON_X 3
#define GREEN_DRAGON_Y 4
#define GREEN_DRAGON_LIFE 1000
#define GREEN_DRAGON_MANA  500
#define GREEN_DRAGON_POWER None
#define GREEN_DRAGON_DMG 100
#define GREEN_DRAGON_ATK_DELAY 5
#define GREEN_DRAGON_XP 10
#define GREEN_DRAGON_SPEED 1.5
#define GREEN_DRAGON_RANGE1 1
#define GREEN_DRAGON_RANGE2 2
#define GREEN_DRAGON_RANGE3 -1
#define GREEN_DRAGON_DELAY1 1
#define GREEN_DRAGON_DELAY2 7
#define GREEN_DRAGON_DELAY3 10
#define GREEN_DRAGON_DMG1 50
#define GREEN_DRAGON_DMG2 100
#define GREEN_DRAGON_DMG3 200
#define GREEN_DRAGON_V2I1 Vector2i(5,3)
#define GREEN_DRAGON_V2I2 Vector2i(5,5)
#define GREEN_DRAGON_V2I3 Vector2i(5,5)
#define GREEN_DRAGON_MANA_COST1 0
#define GREEN_DRAGON_MANA_COST2 0
#define GREEN_DRAGON_MANA_COST3 0

class GreenDragon : public Bot
{
	public :

	GreenDragon(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~GreenDragon();

	private:

};

#endif
