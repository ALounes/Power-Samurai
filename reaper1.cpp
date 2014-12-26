#include "reaper1.hpp"


Reaper1::Reaper1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(REAPER1_X,REAPER1_Y), 
			String("Reaper"),
			REAPER1_LIFE,
			REAPER1_MANA, 
			REAPER1_POWER,
			myMap,
			REAPER1_DMG,
			REAPER1_ATK_DELAY,
			REAPER1_SPEED,
			ident,
			range,
			REAPER1_XP
			)
{	
			spell_delay1 = REAPER1_DELAY1;
			spell_delay2 = REAPER1_DELAY2;
			spell_delay3 = REAPER1_DELAY3;
			range1 = REAPER1_RANGE1;
			range2 = REAPER1_RANGE2;
			range3 = REAPER1_RANGE3;
			dmg1 = REAPER1_DMG1;
			dmg2 = REAPER1_DMG2;
			dmg3 = REAPER1_DMG3;
			v_spell1 = REAPER1_V2I1;
			v_spell2 = REAPER1_V2I2;
			v_spell3 = REAPER1_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Attack2.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Special14.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Heal4.png"))
		      cout << "erreur " << endl ;
      
}


Reaper1::~Reaper1()
{}


