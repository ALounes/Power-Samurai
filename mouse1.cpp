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

#include "mouse1.hpp"


Mouse1::Mouse1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(MOUSE1_X,MOUSE1_Y), 
			String("Mouse1"),
			MOUSE1_LIFE,
			MOUSE1_MANA, 
			MOUSE1_POWER,
			myMap,
			MOUSE1_DMG,
			MOUSE1_ATK_DELAY,
			MOUSE1_SPEED,
			ident,
			range,
			MOUSE1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, MOUSE1_DELAY1);
         setSpellDelay(2, MOUSE1_DELAY2);
         setSpellDelay(3, MOUSE1_DELAY3);
         setSRange(1, MOUSE1_RANGE1);
         setSRange(2, MOUSE1_RANGE2);
         setSRange(3, MOUSE1_RANGE3);
         setDmg(1, MOUSE1_DMG1);
         setDmg(2, MOUSE1_DMG2);
         setDmg(3, MOUSE1_DMG3);
         setVSpell(1, MOUSE1_V2I1);
         setVSpell(2, MOUSE1_V2I2);
         setVSpell(3, MOUSE1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, MOUSE1_MANA_COST1);
         setSManaCost(2, MOUSE1_MANA_COST2);
         setSManaCost(3, MOUSE1_MANA_COST3);
}


Mouse1::~Mouse1()
{}


