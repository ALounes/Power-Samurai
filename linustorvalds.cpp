#include "linustorvalds.hpp"

LinusTorvalds::LinusTorvalds(RenderWindow *win, Image &image, Map *myMap)
:Player( win,
			image, 
			Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), 
			String("Linus Torvalds"),
			LINUS_TORVALDS_LIFE,
			LINUS_TORVALDS_MANA, 
			LINUS_TORVALDS_POWER,
			myMap
			)
{
	//setImage(string("sprite/LinusTorvalds.png"));
}


LinusTorvalds::~LinusTorvalds()
{}


