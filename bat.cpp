#include "bat.hpp"


Bat::Bat(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(BAT_X,BAT_Y), 
			String("Bat"),
			BAT_LIFE,
			BAT_MANA, 
			BAT_POWER,
			myMap,
			BAT_DMG,
			BAT_ATK_DELAY,
			BAT_SPEED,
			ident,
			range,
			BAT_XP
			)
{	      setSpellDelay(1, BAT_DELAY1);
         setSpellDelay(2, BAT_DELAY2);
         setSpellDelay(3, BAT_DELAY3);
         setSRange(1, BAT_RANGE1);
         setSRange(2, BAT_RANGE2);
         setSRange(3, BAT_RANGE3);
         setDmg(1, BAT_DMG1);
         setDmg(2, BAT_DMG2);
         setDmg(3, BAT_DMG3);
         setVSpell(1, BAT_V2I1);
         setVSpell(2, BAT_V2I2);
         setVSpell(3, BAT_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack12.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, BAT_MANA_COST1);
         setSManaCost(2, BAT_MANA_COST2);
         setSManaCost(3, BAT_MANA_COST3);
}


Bat::~Bat()
{}


