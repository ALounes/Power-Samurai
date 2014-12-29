#include "troll.hpp"


Troll::Troll(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(TROLL_X,TROLL_Y), 
			String("Troll"),
			TROLL_LIFE,
			TROLL_MANA, 
			TROLL_POWER,
			myMap,
			TROLL_DMG,
			TROLL_ATK_DELAY,
			TROLL_SPEED,
			ident,
			range,
			TROLL_XP
			)
{	      setSpellDelay(1, TROLL_DELAY1);
         setSpellDelay(2, TROLL_DELAY2);
         setSpellDelay(3, TROLL_DELAY3);
         setSRange(1, TROLL_RANGE1);
         setSRange(2, TROLL_RANGE2);
         setSRange(3, TROLL_RANGE3);
         setDmg(1, TROLL_DMG1);
         setDmg(2, TROLL_DMG2);
         setDmg(3, TROLL_DMG3);
         setVSpell(1, TROLL_V2I1);
         setVSpell(2, TROLL_V2I2);
         setVSpell(3, TROLL_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack7.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, TROLL_MANA_COST1);
         setSManaCost(2, TROLL_MANA_COST2);
         setSManaCost(3, TROLL_MANA_COST3);
}


Troll::~Troll()
{}


