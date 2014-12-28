#include "greendragon1.hpp"


Greendragon1::Greendragon1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(GREENDRAGON1_X,GREENDRAGON1_Y), 
			String("Greendragon1"),
			GREENDRAGON1_LIFE,
			GREENDRAGON1_MANA, 
			GREENDRAGON1_POWER,
			myMap,
			GREENDRAGON1_DMG,
			GREENDRAGON1_ATK_DELAY,
			GREENDRAGON1_SPEED,
			ident,
			range,
			GREENDRAGON1_XP
			)
{	      setSpellDelay(1, GREENDRAGON1_DELAY1);
         setSpellDelay(2, GREENDRAGON1_DELAY2);
         setSpellDelay(3, GREENDRAGON1_DELAY3);
         setSRange(1, GREENDRAGON1_RANGE1);
         setSRange(2, GREENDRAGON1_RANGE2);
         setSRange(3, GREENDRAGON1_RANGE3);
         setDmg(1, GREENDRAGON1_DMG1);
         setDmg(2, GREENDRAGON1_DMG2);
         setDmg(3, GREENDRAGON1_DMG3);
         setVSpell(1, GREENDRAGON1_V2I1);
         setVSpell(2, GREENDRAGON1_V2I2);
         setVSpell(3, GREENDRAGON1_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack12.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, GREENDRAGON1_MANA_COST1);
         setSManaCost(2, GREENDRAGON1_MANA_COST2);
         setSManaCost(3, GREENDRAGON1_MANA_COST3);
}


Greendragon1::~Greendragon1()
{}


