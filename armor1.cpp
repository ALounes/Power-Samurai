/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*******************************************************************/


#include "armor1.hpp"

Armor1::Armor1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
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
			ARMOR1_XP, image1, image2, image3
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
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3); 
         
         setSManaCost(1, ARMOR1_MANA_COST1);
         setSManaCost(2, ARMOR1_MANA_COST2);
         setSManaCost(3, ARMOR1_MANA_COST3);    
}


Armor1::~Armor1()
{}


