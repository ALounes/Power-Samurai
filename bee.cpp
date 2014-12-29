#include "bee.hpp"


Bee::Bee(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
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
			BEE_XP
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
         setImgSpell(1, "Sprites/Sorts/Attack5.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, BEE_MANA_COST1);
         setSManaCost(2, BEE_MANA_COST2);
         setSManaCost(3, BEE_MANA_COST3);
}


Bee::~Bee()
{}


