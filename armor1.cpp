#include "armor1.hpp"

Armor1::Armor1(RenderWindow *win, Image &image, Map *myMap, int ident, int range)
:Bot( win,
			image, 
			Vector2i(ARMOR1_X,ARMOR1_Y), 
			String("Armor"),
			ARMOR1_LIFE,
			ARMOR1_MANA, 
			ARMOR1_POWER,
			myMap,
			ARMOR1_DMG,
			ARMOR1_ATK_DELAY,
			ARMOR1_SPEED,
			ident,
			range,
			ARMOR1_XP
			)
{	      setSpellDelay(1, ARMOR1_DELAY1);
         setSpellDelay(2, ARMOR1_DELAY2);
         setSpellDelay(3, ARMOR1_DELAY3);
         setSRange(1, ARMOR1_RANGE1);
         setSRange(2, ARMOR1_RANGE2);
         setSRange(3, ARMOR1_RANGE3);
         setDmg(1, ARMOR1_DMG1);
         setDmg(2, ARMOR1_DMG2);
         setDmg(3, ARMOR1_DMG3);
         setVSpell(1, ARMOR1_V2I1);
         setVSpell(2, ARMOR1_V2I2);
         setVSpell(3, ARMOR1_V2I3);
         setImgSpell(1, "Sprites/Sorts/Attack1.png");
         setImgSpell(2, "Sprites/Sorts/Light1.png");
         setImgSpell(3, "Sprites/Sorts/Heal4.png"); 
         setSManaCost(1, ARMOR1_MANA_COST1);
         setSManaCost(2, ARMOR1_MANA_COST2);
         setSManaCost(3, ARMOR1_MANA_COST3);    
}


Armor1::~Armor1()
{}


