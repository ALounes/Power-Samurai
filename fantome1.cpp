#include "fantome1.hpp"


Fantome1::Fantome1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(FANTOME1_X,FANTOME1_Y), 
			String("Fantome"),
			FANTOME1_LIFE,
			FANTOME1_MANA, 
			FANTOME1_POWER,
			myMap,
			FANTOME1_DMG,
			FANTOME1_ATK_DELAY,
			FANTOME1_SPEED,
			ident,
			range,
			FANTOME1_XP
			)
{	      setSpellDelay(1, FANTOME1_DELAY1);
         setSpellDelay(2, FANTOME1_DELAY2);
         setSpellDelay(3, FANTOME1_DELAY3);
         setSRange(1, FANTOME1_RANGE1);
         setSRange(2, FANTOME1_RANGE2);
         setSRange(3, FANTOME1_RANGE3);
         setDmg(1, FANTOME1_DMG1);
         setDmg(2, FANTOME1_DMG2);
         setDmg(3, FANTOME1_DMG3);
         setVSpell(1, FANTOME1_V2I1);
         setVSpell(2, FANTOME1_V2I2);
         setVSpell(3, FANTOME1_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack3.png");
         setImgSpell(2, "Sprites/Sorts/Special14.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, FANTOME1_MANA_COST1);
         setSManaCost(2, FANTOME1_MANA_COST2);
         setSManaCost(3, FANTOME1_MANA_COST3);      
}


Fantome1::~Fantome1()
{}


