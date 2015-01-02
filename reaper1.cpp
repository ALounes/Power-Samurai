#include "reaper1.hpp"


Reaper1::Reaper1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(REAPER1_X,REAPER1_Y), 
			String("Reaper"),
			REAPER1_LIFE,
			REAPER1_MANA, 
			REAPER1_POWER,
			myMap,
			REAPER1_DMG,
			REAPER1_ATK_DELAY,
			REAPER1_SPEED,
			ident,
			range,
			REAPER1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, REAPER1_DELAY1);
         setSpellDelay(2, REAPER1_DELAY2);
         setSpellDelay(3, REAPER1_DELAY3);
         setSRange(1, REAPER1_RANGE1);
         setSRange(2, REAPER1_RANGE2);
         setSRange(3, REAPER1_RANGE3);
         setDmg(1, REAPER1_DMG1);
         setDmg(2, REAPER1_DMG2);
         setDmg(3, REAPER1_DMG3);
         setVSpell(1, REAPER1_V2I1);
         setVSpell(2, REAPER1_V2I2);
         setVSpell(3, REAPER1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, REAPER1_MANA_COST1);
         setSManaCost(2, REAPER1_MANA_COST2);
         setSManaCost(3, REAPER1_MANA_COST3);      
}


Reaper1::~Reaper1()
{}


