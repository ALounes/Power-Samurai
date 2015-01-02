#include "bee.hpp"


Bee::Bee(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(BEE_X,BEE_Y), 
			String("Bee"),
			BEE_LIFE,
			BEE_MANA, 
			BEE_POWER,
			myMap,
			BEE_DMG,
			BEE_ATK_DELAY,
			BEE_SPEED,
			ident,
			range,
			BEE_XP, image1, image2, image3
			)
{	      setSpellDelay(1, BEE_DELAY1);
         setSpellDelay(2, BEE_DELAY2);
         setSpellDelay(3, BEE_DELAY3);
         setSRange(1, BEE_RANGE1);
         setSRange(2, BEE_RANGE2);
         setSRange(3, BEE_RANGE3);
         setDmg(1, BEE_DMG1);
         setDmg(2, BEE_DMG2);
         setDmg(3, BEE_DMG3);
         setVSpell(1, BEE_V2I1);
         setVSpell(2, BEE_V2I2);
         setVSpell(3, BEE_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, BEE_MANA_COST1);
         setSManaCost(2, BEE_MANA_COST2);
         setSManaCost(3, BEE_MANA_COST3);
}


Bee::~Bee()
{}


