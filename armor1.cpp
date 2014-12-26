#include "armor1.hpp"


Armor1::Armor1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(ARMOR1_X,ARMOR1_Y), 
			String("Armor"),
			ARMOR1_LIFE,
			ARMOR1_MANA, 
			ARMOR1_POWER,
			myMap,
			ARMOR1_DMG,
			ARMOR1_ATK_DELAY,
			ARMOR1_SPEED,
			ident,
			range,
			ARMOR1_XP
			)
{	
			spell_delay1 = ARMOR1_DELAY1;
			spell_delay2 = ARMOR1_DELAY2;
			spell_delay3 = ARMOR1_DELAY3;
			range1 = ARMOR1_RANGE1;
			range2 = ARMOR1_RANGE2;
			range3 = ARMOR1_RANGE3;
			dmg1 = ARMOR1_DMG1;
			dmg2 = ARMOR1_DMG2;
			dmg3 = ARMOR1_DMG3;
			v_spell1 = ARMOR1_V2I1;
			v_spell2 = ARMOR1_V2I2;
			v_spell3 = ARMOR1_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Attack1.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Light1.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Heal4.png"))
		      cout << "erreur " << endl ;
      
}


Armor1::~Armor1()
{}


