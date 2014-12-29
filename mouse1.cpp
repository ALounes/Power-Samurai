#include "mouse1.hpp"


Mouse1::Mouse1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(MOUSE1_X,MOUSE1_Y), 
			String("Mouse1"),
			MOUSE1_LIFE,
			MOUSE1_MANA, 
			MOUSE1_POWER,
			myMap,
			MOUSE1_DMG,
			MOUSE1_ATK_DELAY,
			MOUSE1_SPEED,
			ident,
			range,
			MOUSE1_XP
			)
{	      setSpellDelay(1, MOUSE1_DELAY1);
         setSpellDelay(2, MOUSE1_DELAY2);
         setSpellDelay(3, MOUSE1_DELAY3);
         setSRange(1, MOUSE1_RANGE1);
         setSRange(2, MOUSE1_RANGE2);
         setSRange(3, MOUSE1_RANGE3);
         setDmg(1, MOUSE1_DMG1);
         setDmg(2, MOUSE1_DMG2);
         setDmg(3, MOUSE1_DMG3);
         setVSpell(1, MOUSE1_V2I1);
         setVSpell(2, MOUSE1_V2I2);
         setVSpell(3, MOUSE1_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack8.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, MOUSE1_MANA_COST1);
         setSManaCost(2, MOUSE1_MANA_COST2);
         setSManaCost(3, MOUSE1_MANA_COST3);
}


Mouse1::~Mouse1()
{}


