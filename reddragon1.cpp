#include "reddragon1.hpp"


Reddragon1::Reddragon1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(REDDRAGON1_X,REDDRAGON1_Y), 
			String("reddragon1"),
			REDDRAGON1_LIFE,
			REDDRAGON1_MANA, 
			REDDRAGON1_POWER,
			myMap,
			REDDRAGON1_DMG,
			REDDRAGON1_ATK_DELAY,
			REDDRAGON1_SPEED,
			ident,
			range,
			REDDRAGON1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, REDDRAGON1_DELAY1);
         setSpellDelay(2, REDDRAGON1_DELAY2);
         setSpellDelay(3, REDDRAGON1_DELAY3);
         setSRange(1, REDDRAGON1_RANGE1);
         setSRange(2, REDDRAGON1_RANGE2);
         setSRange(3, REDDRAGON1_RANGE3);
         setDmg(1, REDDRAGON1_DMG1);
         setDmg(2, REDDRAGON1_DMG2);
         setDmg(3, REDDRAGON1_DMG3);
         setVSpell(1, REDDRAGON1_V2I1);
         setVSpell(2, REDDRAGON1_V2I2);
         setVSpell(3, REDDRAGON1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, REDDRAGON1_MANA_COST1);
         setSManaCost(2, REDDRAGON1_MANA_COST2);
         setSManaCost(3, REDDRAGON1_MANA_COST3);
}


Reddragon1::~Reddragon1()
{}


