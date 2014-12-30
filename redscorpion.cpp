#include "redscorpion.hpp"


Redscorpion::Redscorpion(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(REDSCORPION_X,REDSCORPION_Y), 
			String("Redscorpion"),
			REDSCORPION_LIFE,
			REDSCORPION_MANA, 
			REDSCORPION_POWER,
			myMap,
			REDSCORPION_DMG,
			REDSCORPION_ATK_DELAY,
			REDSCORPION_SPEED,
			ident,
			range,
			REDSCORPION_XP, image1, image2, image3
			)
{	      setSpellDelay(1, REDSCORPION_DELAY1);
         setSpellDelay(2, REDSCORPION_DELAY2);
         setSpellDelay(3, REDSCORPION_DELAY3);
         setSRange(1, REDSCORPION_RANGE1);
         setSRange(2, REDSCORPION_RANGE2);
         setSRange(3, REDSCORPION_RANGE3);
         setDmg(1, REDSCORPION_DMG1);
         setDmg(2, REDSCORPION_DMG2);
         setDmg(3, REDSCORPION_DMG3);
         setVSpell(1, REDSCORPION_V2I1);
         setVSpell(2, REDSCORPION_V2I2);
         setVSpell(3, REDSCORPION_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, REDSCORPION_MANA_COST1);
         setSManaCost(2, REDSCORPION_MANA_COST2);
         setSManaCost(3, REDSCORPION_MANA_COST3);
}


Redscorpion::~Redscorpion()
{}


