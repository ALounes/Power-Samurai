#include "alanturing.hpp"

AlanTuring::AlanTuring(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(ALAN_TURING_X,ALAN_TURING_Y), 
			String("Alan Turing"),
			ALAN_TURING_LIFE,
			ALAN_TURING_MANA, 
			ALAN_TURING_POWER,
			myMap,
			att_dmg
			)
{
         spell_delay1 = ALAN_TURING_DELAY1;
			spell_delay2 = ALAN_TURING_DELAY2;
			spell_delay3 = ALAN_TURING_DELAY3;
			range1 = ALAN_TURING_RANGE1;
			range2 = ALAN_TURING_RANGE2;
			range3 = ALAN_TURING_RANGE3;
			dmg1 = ALAN_TURING_DMG1;
			dmg2 = ALAN_TURING_DMG2;
			dmg3 = ALAN_TURING_DMG3;
			v_spell1 = ALAN_TURING_V2I1;
			v_spell2 = ALAN_TURING_V2I2;
			v_spell3 = ALAN_TURING_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Special15.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Special12.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Gun2.png"))
		      cout << "erreur " << endl ;
}


AlanTuring::~AlanTuring()
{}
