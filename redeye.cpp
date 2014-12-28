#include "redeye.hpp"


Redeye::Redeye(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
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
			REDEYE_XP
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
         setImgSpell(1, "Sprites/Sorts/Attack12.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, REDEYE_MANA_COST1);
         setSManaCost(2, REDEYE_MANA_COST2);
         setSManaCost(3, REDEYE_MANA_COST3);
}


Redeye::~Redeye()
{}


