#include "naga.hpp"


Naga::Naga(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(NAGA_X,NAGA_Y), 
			String("Naga"),
			NAGA_LIFE,
			NAGA_MANA, 
			NAGA_POWER,
			myMap,
			NAGA_DMG,
			NAGA_ATK_DELAY,
			NAGA_SPEED,
			ident,
			range,
			NAGA_XP
			)
{	      setSpellDelay(1, NAGA_DELAY1);
         setSpellDelay(2, NAGA_DELAY2);
         setSpellDelay(3, NAGA_DELAY3);
         setSRange(1, NAGA_RANGE1);
         setSRange(2, NAGA_RANGE2);
         setSRange(3, NAGA_RANGE3);
         setDmg(1, NAGA_DMG1);
         setDmg(2, NAGA_DMG2);
         setDmg(3, NAGA_DMG3);
         setVSpell(1, NAGA_V2I1);
         setVSpell(2, NAGA_V2I2);
         setVSpell(3, NAGA_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack12.png");
         setImgSpell(2, "Sprites/Sorts/Meteor.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png");
         setSManaCost(1, NAGA_MANA_COST1);
         setSManaCost(2, NAGA_MANA_COST2);
         setSManaCost(3, NAGA_MANA_COST3);
}


Naga::~Naga()
{}


