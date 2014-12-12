#include "alanturing.hpp"

AlanTuring::AlanTuring(RenderWindow *win, Image &image)
:Player( win,
			image, 
			Vector2i(ALAN_TURING_X,ALAN_TURING_Y), 
			String("Alan Turing"),
			ALAN_TURING_LIFE,
			ALAN_TURING_MANA, 
			ALAN_TURING_POWER
			)
{}


AlanTuring::~AlanTuring()
{}
