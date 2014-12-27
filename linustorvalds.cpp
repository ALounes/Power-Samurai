#include "linustorvalds.hpp"


LinusTorvalds::LinusTorvalds(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), 
			String("Linus Torvalds"),
			LINUS_TORVALDS_LIFE,
			LINUS_TORVALDS_MANA, 
			LINUS_TORVALDS_POWER,
			myMap,
			att_dmg
			)
{
         spell_delay1 = LINUS_TORVALDS_DELAY1;
			spell_delay2 = LINUS_TORVALDS_DELAY2;
			spell_delay3 = LINUS_TORVALDS_DELAY3;
			range1 = LINUS_TORVALDS_RANGE1;
			range2 = LINUS_TORVALDS_RANGE2;
			range3 = LINUS_TORVALDS_RANGE3;
			dmg1 = LINUS_TORVALDS_DMG1;
			dmg2 = LINUS_TORVALDS_DMG2;
			dmg3 = LINUS_TORVALDS_DMG3;
			v_spell1 = LINUS_TORVALDS_V2I1;
			v_spell2 = LINUS_TORVALDS_V2I2;
			v_spell3 = LINUS_TORVALDS_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Special15.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Special12.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Gun2.png"))
		      cout << "erreur " << endl ;
}


LinusTorvalds::~LinusTorvalds()
{}


