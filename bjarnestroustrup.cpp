#include "bjarnestroustrup.hpp"

BjarneStroustrup::BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(BJARNE_STROUSTRUP_X,BJARNE_STROUSTRUP_Y), 
			String("Bjarne Stroustrup"),
			BJARNE_STROUSTRUP_LIFE,
			BJARNE_STROUSTRUP_MANA, 
			BJARNE_STROUSTRUP_POWER,
			myMap,
			att_dmg
			)
{
         setSpellDelay(1, BJARNE_STROUSTRUP_DELAY1);
         setSpellDelay(2, BJARNE_STROUSTRUP_DELAY2);
         setSpellDelay(3, BJARNE_STROUSTRUP_DELAY3);
         setSRange(1, BJARNE_STROUSTRUP_RANGE1);
         setSRange(2, BJARNE_STROUSTRUP_RANGE2);
         setSRange(3, BJARNE_STROUSTRUP_RANGE3);
         setDmg(1, BJARNE_STROUSTRUP_DMG1);
         setDmg(2, BJARNE_STROUSTRUP_DMG2);
         setDmg(3, BJARNE_STROUSTRUP_DMG3);
         setVSpell(1, BJARNE_STROUSTRUP_V2I1);
         setVSpell(2, BJARNE_STROUSTRUP_V2I2);
         setVSpell(3, BJARNE_STROUSTRUP_V2I3);
         setImgSpell(1, "Sprites/Sorts/Special15.png");
         setImgSpell(2, "Sprites/Sorts/Special12.png");
         setImgSpell(3, "Sprites/Sorts/Gun2.png");
         setSManaCost(1, BJARNE_STROUSTRUP_MANA_COST1);
         setSManaCost(2, BJARNE_STROUSTRUP_MANA_COST2);
         setSManaCost(3, BJARNE_STROUSTRUP_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait2.png");
}


BjarneStroustrup::~BjarneStroustrup() {}
