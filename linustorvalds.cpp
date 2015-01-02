#include "linustorvalds.hpp"


LinusTorvalds::LinusTorvalds(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3)
:Player( win,
			image, 
			Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), 
			String("Linus Torvalds"),
			LINUS_TORVALDS_LIFE,
			LINUS_TORVALDS_MANA, 
			LINUS_TORVALDS_POWER,
			myMap,
			LINUS_TORVALDS_DMG
			)
{        
         setSpellDelay(1, LINUS_TORVALDS_DELAY1);
         setSpellDelay(2, LINUS_TORVALDS_DELAY2);
         setSpellDelay(3, LINUS_TORVALDS_DELAY3);
         setSRange(1, LINUS_TORVALDS_RANGE1);
         setSRange(2, LINUS_TORVALDS_RANGE2);
         setSRange(3, LINUS_TORVALDS_RANGE3);
         setDmg(1, LINUS_TORVALDS_DMG1);
         setDmg(2, LINUS_TORVALDS_DMG2);
         setDmg(3, LINUS_TORVALDS_DMG3);
         setVSpell(1, LINUS_TORVALDS_V2I1);
         setVSpell(2, LINUS_TORVALDS_V2I2);
         setVSpell(3, LINUS_TORVALDS_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, LINUS_TORVALDS_MANA_COST1);
         setSManaCost(2, LINUS_TORVALDS_MANA_COST2);
         setSManaCost(3, LINUS_TORVALDS_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait1.png");
         setSpeed(LINUS_TORVALDS_SPEED);
}


LinusTorvalds::~LinusTorvalds()
{}


