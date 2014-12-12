#include "bjarnestroustrup.hpp"

BjarneStroustrup::BjarneStroustrup(RenderWindow *win, Image &image)
:Player( win,
			image, 
			Vector2i(BJARNE_STROUSTRUP_X,BJARNE_STROUSTRUP_Y), 
			String("Bjarne Stroustrup"),
			BJARNE_STROUSTRUP_LIFE,
			BJARNE_STROUSTRUP_MANA, 
			BJARNE_STROUSTRUP_POWER
			)
{

}


BjarneStroustrup::~BjarneStroustrup() {}
