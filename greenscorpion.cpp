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

#include "greenscorpion.hpp"


Greenscorpion::Greenscorpion(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(GREENSCORPION_X,GREENSCORPION_Y), 
			String("Greenscorpion"),
			GREENSCORPION_LIFE,
			GREENSCORPION_MANA, 
			GREENSCORPION_POWER,
			myMap,
			GREENSCORPION_DMG,
			GREENSCORPION_ATK_DELAY,
			GREENSCORPION_SPEED,
			ident,
			range,
			GREENSCORPION_XP, image1, image2, image3
			)
{	      setSpellDelay(1, GREENSCORPION_DELAY1);
         setSpellDelay(2, GREENSCORPION_DELAY2);
         setSpellDelay(3, GREENSCORPION_DELAY3);
         setSRange(1, GREENSCORPION_RANGE1);
         setSRange(2, GREENSCORPION_RANGE2);
         setSRange(3, GREENSCORPION_RANGE3);
         setDmg(1, GREENSCORPION_DMG1);
         setDmg(2, GREENSCORPION_DMG2);
         setDmg(3, GREENSCORPION_DMG3);
         setVSpell(1, GREENSCORPION_V2I1);
         setVSpell(2, GREENSCORPION_V2I2);
         setVSpell(3, GREENSCORPION_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, GREENSCORPION_MANA_COST1);
         setSManaCost(2, GREENSCORPION_MANA_COST2);
         setSManaCost(3, GREENSCORPION_MANA_COST3);
}


Greenscorpion::~Greenscorpion()
{}


