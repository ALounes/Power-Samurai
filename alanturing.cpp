#include "alanturing.hpp"

AlanTuring::AlanTuring(RenderWindow *win, Image &image, Map *myMap,float att_dmg)
:Player( win,
			image, 
			Vector2i(ALAN_TURING_X,ALAN_TURING_Y), 
			String("Alan Turing"),
			ALAN_TURING_LIFE,
			ALAN_TURING_MANA, 
			ALAN_TURING_POWER,
			myMap,
			att_dmg
			)
{
         setSpellDelay(1, ALAN_TURING_DELAY1);
         setSpellDelay(2, ALAN_TURING_DELAY2);
         setSpellDelay(3, ALAN_TURING_DELAY3);
         setSRange(1, ALAN_TURING_RANGE1);
         setSRange(2, ALAN_TURING_RANGE2);
         setSRange(3, ALAN_TURING_RANGE3);
         setDmg(1, ALAN_TURING_DMG1);
         setDmg(2, ALAN_TURING_DMG2);
         setDmg(3, ALAN_TURING_DMG3);
         setVSpell(1, ALAN_TURING_V2I1);
         setVSpell(2, ALAN_TURING_V2I2);
         setVSpell(3, ALAN_TURING_V2I3);
         setImgSpell(1, "Sprites/Sorts/Special15.png");
         setImgSpell(2, "Sprites/Sorts/Special12.png");
         setImgSpell(3, "Sprites/Sorts/Gun2.png");
         setSManaCost(1, ALAN_TURING_MANA_COST1);
         setSManaCost(2, ALAN_TURING_MANA_COST2);
         setSManaCost(3, ALAN_TURING_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait3.png");
         cout << " CONSTRUCTEUR AlanTuring()" << endl;
}


AlanTuring::~AlanTuring()
{}
