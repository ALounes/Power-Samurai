#include "greenslime.hpp"


Greenslime::Greenslime(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(GREENSLIME_X,GREENSLIME_Y), 
			String("Greenslime"),
			GREENSLIME_LIFE,
			GREENSLIME_MANA, 
			GREENSLIME_POWER,
			myMap,
			GREENSLIME_DMG,
			GREENSLIME_ATK_DELAY,
			GREENSLIME_SPEED,
			ident,
			range,
			GREENSLIME_XP, image1, image2, image3
			)
{	      setSpellDelay(1, GREENSLIME_DELAY1);
         setSpellDelay(2, GREENSLIME_DELAY2);
         setSpellDelay(3, GREENSLIME_DELAY3);
         setSRange(1, GREENSLIME_RANGE1);
         setSRange(2, GREENSLIME_RANGE2);
         setSRange(3, GREENSLIME_RANGE3);
         setDmg(1, GREENSLIME_DMG1);
         setDmg(2, GREENSLIME_DMG2);
         setDmg(3, GREENSLIME_DMG3);
         setVSpell(1, GREENSLIME_V2I1);
         setVSpell(2, GREENSLIME_V2I2);
         setVSpell(3, GREENSLIME_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, GREENSLIME_MANA_COST1);
         setSManaCost(2, GREENSLIME_MANA_COST2);
         setSManaCost(3, GREENSLIME_MANA_COST3);
}


Greenslime::~Greenslime()
{}


