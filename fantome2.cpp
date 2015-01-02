#include "fantome2.hpp"

Fantome2::Fantome2(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
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
			FANTOME2_XP, image1, image2, image3
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
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, FANTOME2_MANA_COST1);
         setSManaCost(2, FANTOME2_MANA_COST2);
         setSManaCost(3, FANTOME2_MANA_COST3);    
}


Fantome2::~Fantome2()
{}


