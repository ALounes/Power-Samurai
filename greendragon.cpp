#include "greendragon.hpp"


GreenDragon::GreenDragon(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(GREEN_DRAGON_X,GREEN_DRAGON_Y), 
			String("GreenDragon"),
			GREEN_DRAGON_LIFE,
			GREEN_DRAGON_MANA, 
			GREEN_DRAGON_POWER,
			myMap,
			GREEN_DRAGON_DMG,
			GREEN_DRAGON_ATK_DELAY,
			GREEN_DRAGON_SPEED,
			ident,
			range,
			GREEN_DRAGON_XP
			)
{	
			spell_delay1 = GREEN_DRAGON_DELAY1;
			spell_delay2 = GREEN_DRAGON_DELAY2;
			spell_delay3 = GREEN_DRAGON_DELAY3;
			range1 = GREEN_DRAGON_RANGE1;
			range2 = GREEN_DRAGON_RANGE2;
			range3 = GREEN_DRAGON_RANGE3;
			dmg1 = GREEN_DRAGON_DMG1;
			dmg2 = GREEN_DRAGON_DMG2;
			dmg3 = GREEN_DRAGON_DMG3;
			v_spell1 = GREEN_DRAGON_V2I1;
			v_spell2 = GREEN_DRAGON_V2I2;
			v_spell3 = GREEN_DRAGON_V2I3;

         if (!Spell1->LoadFromFile("Sprites/Sorts/Attack101.png"))
		      cout << "erreur " << endl ;
         if (!Spell2->LoadFromFile("Sprites/Sorts/Special12.png"))
		      cout << "erreur " << endl ;
         if (!Spell3->LoadFromFile("Sprites/Sorts/Gun2.png"))
		      cout << "erreur " << endl ;
      
}


GreenDragon::~GreenDragon()
{}


