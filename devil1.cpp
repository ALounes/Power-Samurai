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

#include "devil1.hpp"


Devil1::Devil1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(DEVIL1_X,DEVIL1_Y), 
			String("Devil1"),
			DEVIL1_LIFE,
			DEVIL1_MANA, 
			DEVIL1_POWER,
			myMap,
			DEVIL1_DMG,
			DEVIL1_ATK_DELAY,
			DEVIL1_SPEED,
			ident,
			range,
			DEVIL1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, DEVIL1_DELAY1);
         setSpellDelay(2, DEVIL1_DELAY2);
         setSpellDelay(3, DEVIL1_DELAY3);
         setSRange(1, DEVIL1_RANGE1);
         setSRange(2, DEVIL1_RANGE2);
         setSRange(3, DEVIL1_RANGE3);
         setDmg(1, DEVIL1_DMG1);
         setDmg(2, DEVIL1_DMG2);
         setDmg(3, DEVIL1_DMG3);
         setVSpell(1, DEVIL1_V2I1);
         setVSpell(2, DEVIL1_V2I2);
         setVSpell(3, DEVIL1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, DEVIL1_MANA_COST1);
         setSManaCost(2, DEVIL1_MANA_COST2);
         setSManaCost(3, DEVIL1_MANA_COST3);
}


Devil1::~Devil1()
{}


