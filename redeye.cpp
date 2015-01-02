#include "redeye.hpp"


Redeye::Redeye(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(REDEYE_X,REDEYE_Y), 
			String("Redeye"),
			REDEYE_LIFE,
			REDEYE_MANA, 
			REDEYE_POWER,
			myMap,
			REDEYE_DMG,
			REDEYE_ATK_DELAY,
			REDEYE_SPEED,
			ident,
			range,
			REDEYE_XP, image1, image2, image3
			)
{	      setSpellDelay(1, REDEYE_DELAY1);
         setSpellDelay(2, REDEYE_DELAY2);
         setSpellDelay(3, REDEYE_DELAY3);
         setSRange(1, REDEYE_RANGE1);
         setSRange(2, REDEYE_RANGE2);
         setSRange(3, REDEYE_RANGE3);
         setDmg(1, REDEYE_DMG1);
         setDmg(2, REDEYE_DMG2);
         setDmg(3, REDEYE_DMG3);
         setVSpell(1, REDEYE_V2I1);
         setVSpell(2, REDEYE_V2I2);
         setVSpell(3, REDEYE_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, REDEYE_MANA_COST1);
         setSManaCost(2, REDEYE_MANA_COST2);
         setSManaCost(3, REDEYE_MANA_COST3);
}


Redeye::~Redeye()
{}


