#include "linustorvalds.hpp"


LinusTorvalds::LinusTorvalds(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), 
			String("Linus Torvalds"),
			LINUS_TORVALDS_LIFE,
			LINUS_TORVALDS_MANA, 
			LINUS_TORVALDS_POWER,
			myMap,
			att_dmg
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
         setImgSpell(1, "Sprites/Sorts/Light7.png");
         setImgSpell(2, "Sprites/Sorts/Special12.png");
         setImgSpell(3, "Sprites/Sorts/Gun2.png");
         setSManaCost(1, LINUS_TORVALDS_MANA_COST1);
         setSManaCost(2, LINUS_TORVALDS_MANA_COST2);
         setSManaCost(3, LINUS_TORVALDS_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait1.png");
}


LinusTorvalds::~LinusTorvalds()
{}


