#include "greenslime.hpp"


Greenslime::Greenslime(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
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
			GREENSLIME_XP
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
         setImgSpell(1, "Sprites/Sorts/Attack12.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, GREENSLIME_MANA_COST1);
         setSManaCost(2, GREENSLIME_MANA_COST2);
         setSManaCost(3, GREENSLIME_MANA_COST3);
}


Greenslime::~Greenslime()
{}


