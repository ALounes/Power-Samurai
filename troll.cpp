#include "troll.hpp"


Troll::Troll(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(TROLL_X,TROLL_Y), 
			String("GreenDragon"),
			TROLL_LIFE,
			TROLL_MANA, 
			TROLL_POWER,
			myMap,
			TROLL_DMG,
			TROLL_ATK_DELAY,
			TROLL_SPEED,
			ident,
			range,
			TROLL_XP
			)
{	
			spell_delay1 = TROLL_DELAY1;
			spell_delay2 = TROLL_DELAY2;
			spell_delay3 = TROLL_DELAY3;
			range1 = TROLL_RANGE1;
			range2 = TROLL_RANGE2;
			range3 = TROLL_RANGE3;
			dmg1 = TROLL_DMG1;
			dmg2 = TROLL_DMG2;
			dmg3 = TROLL_DMG3;
			v_spell1 = TROLL_V2I1;
			v_spell2 = TROLL_V2I2;
			v_spell3 = TROLL_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Attack12.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Meteor.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Heal4.png"))
		      cout << "erreur " << endl ;
      
}


Troll::~Troll()
{}


