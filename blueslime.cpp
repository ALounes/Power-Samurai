#include "blueslime.hpp"


Blueslime::Blueslime(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(BLUESLIME_X,BLUESLIME_Y), 
			String("Blueslime"),
			BLUESLIME_LIFE,
			BLUESLIME_MANA, 
			BLUESLIME_POWER,
			myMap,
			BLUESLIME_DMG,
			BLUESLIME_ATK_DELAY,
			BLUESLIME_SPEED,
			ident,
			range,
			BLUESLIME_XP, image1, image2, image3
			)
{	      setSpellDelay(1, BLUESLIME_DELAY1);
         setSpellDelay(2, BLUESLIME_DELAY2);
         setSpellDelay(3, BLUESLIME_DELAY3);
         setSRange(1, BLUESLIME_RANGE1);
         setSRange(2, BLUESLIME_RANGE2);
         setSRange(3, BLUESLIME_RANGE3);
         setDmg(1, BLUESLIME_DMG1);
         setDmg(2, BLUESLIME_DMG2);
         setDmg(3, BLUESLIME_DMG3);
         setVSpell(1, BLUESLIME_V2I1);
         setVSpell(2, BLUESLIME_V2I2);
         setVSpell(3, BLUESLIME_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, BLUESLIME_MANA_COST1);
         setSManaCost(2, BLUESLIME_MANA_COST2);
         setSManaCost(3, BLUESLIME_MANA_COST3);
}


Blueslime::~Blueslime()
{}


