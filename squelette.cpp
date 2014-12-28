#include "squelette.hpp"

Squelette::Squelette(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(SQUELETTE_X,SQUELETTE_Y), 
			String("Armor"),
			SQUELETTE_LIFE,
			SQUELETTE_MANA, 
			SQUELETTE_POWER,
			myMap,
			SQUELETTE_DMG,
			SQUELETTE_ATK_DELAY,
			SQUELETTE_SPEED,
			ident,
			range,
			SQUELETTE_XP
			)
{	      setSpellDelay(1, SQUELETTE_DELAY1);
         setSpellDelay(2, SQUELETTE_DELAY2);
         setSpellDelay(3, SQUELETTE_DELAY3);
         setSRange(1, SQUELETTE_RANGE1);
         setSRange(2, SQUELETTE_RANGE2);
         setSRange(3, SQUELETTE_RANGE3);
         setDmg(1, SQUELETTE_DMG1);
         setDmg(2, SQUELETTE_DMG2);
         setDmg(3, SQUELETTE_DMG3);
         setVSpell(1, SQUELETTE_V2I1);
         setVSpell(2, SQUELETTE_V2I2);
         setVSpell(3, SQUELETTE_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack1.png");
         setImgSpell(2, "Sprites/Sorts/Light1.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png"); 
         setSManaCost(1, SQUELETTE_MANA_COST1);
         setSManaCost(2, SQUELETTE_MANA_COST2);
         setSManaCost(3, SQUELETTE_MANA_COST3);    
}


Squelette::~Squelette()
{}


