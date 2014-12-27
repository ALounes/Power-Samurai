#include "bjarnestroustrup.hpp"

BjarneStroustrup::BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(BJARNE_STROUSTRUP_X,BJARNE_STROUSTRUP_Y), 
			String("Bjarne Stroustrup"),
			BJARNE_STROUSTRUP_LIFE,
			BJARNE_STROUSTRUP_MANA, 
			BJARNE_STROUSTRUP_POWER,
			myMap,
			att_dmg
			)
{
         spell_delay1 = BJARNE_STROUSTRUP_DELAY1;
			spell_delay2 = BJARNE_STROUSTRUP_DELAY2;
			spell_delay3 = BJARNE_STROUSTRUP_DELAY3;
			range1 = BJARNE_STROUSTRUP_RANGE1;
			range2 = BJARNE_STROUSTRUP_RANGE2;
			range3 = BJARNE_STROUSTRUP_RANGE3;
			dmg1 = BJARNE_STROUSTRUP_DMG1;
			dmg2 = BJARNE_STROUSTRUP_DMG2;
			dmg3 = BJARNE_STROUSTRUP_DMG3;
			v_spell1 = BJARNE_STROUSTRUP_V2I1;
			v_spell2 = BJARNE_STROUSTRUP_V2I2;
			v_spell3 = BJARNE_STROUSTRUP_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Special15.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Special12.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Gun2.png"))
		      cout << "erreur " << endl ;
      

}


BjarneStroustrup::~BjarneStroustrup() {}
