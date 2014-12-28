#include "fantome2.hpp"

Fantome2::Fantome2(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot(win,
			image, 
			Vector2i(FANTOME2_X,FANTOME2_Y), 
			String("Armor"),
			FANTOME2_LIFE,
			FANTOME2_MANA, 
			FANTOME2_POWER,
			myMap,
			FANTOME2_DMG,
			FANTOME2_ATK_DELAY,
			FANTOME2_SPEED,
			ident,
			range,
			FANTOME2_XP
			)
{	      
			setSpellDelay(1, FANTOME2_DELAY1);
         setSpellDelay(2, FANTOME2_DELAY2);
         setSpellDelay(3, FANTOME2_DELAY3);
         setSRange(1, FANTOME2_RANGE1);
         setSRange(2, FANTOME2_RANGE2);
         setSRange(3, FANTOME2_RANGE3);
         setDmg(1, FANTOME2_DMG1);
         setDmg(2, FANTOME2_DMG2);
         setDmg(3, FANTOME2_DMG3);
         setVSpell(1, FANTOME2_V2I1);
         setVSpell(2, FANTOME2_V2I2);
         setVSpell(3, FANTOME2_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack1.png");
         setImgSpell(2, "Sprites/Sorts/Light1.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png"); 
         setSManaCost(1, FANTOME2_MANA_COST1);
         setSManaCost(2, FANTOME2_MANA_COST2);
         setSManaCost(3, FANTOME2_MANA_COST3);    
}


Fantome2::~Fantome2()
{}


