#include "athena.hpp"

Athena::Athena(RenderWindow *win, Image &image, Map *myMap,float att_dmg, Image* image1, Image* image2, Image* image3)
:Player( win,
			image, 
			Vector2i(ATHENA_X,ATHENA_Y), 
			String("Alan Turing"),
			ATHENA_LIFE,
			ATHENA_MANA, 
			ATHENA_POWER,
			myMap,
			att_dmg
			)
{
         setSpellDelay(1, ATHENA_DELAY1);
         setSpellDelay(2, ATHENA_DELAY2);
         setSpellDelay(3, ATHENA_DELAY3);
         setSRange(1, ATHENA_RANGE1);
         setSRange(2, ATHENA_RANGE2);
         setSRange(3, ATHENA_RANGE3);
         setDmg(1, ATHENA_DMG1);
         setDmg(2, ATHENA_DMG2);
         setDmg(3, ATHENA_DMG3);
         setVSpell(1, ATHENA_V2I1);
         setVSpell(2, ATHENA_V2I2);
         setVSpell(3, ATHENA_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, ATHENA_MANA_COST1);
         setSManaCost(2, ATHENA_MANA_COST2);
         setSManaCost(3, ATHENA_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait4.png");
}


Athena::~Athena()
{}
