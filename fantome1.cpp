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

#include "fantome1.hpp"


Fantome1::Fantome1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(FANTOME1_X,FANTOME1_Y), 
			String("Fantome"),
			FANTOME1_LIFE,
			FANTOME1_MANA, 
			FANTOME1_POWER,
			myMap,
			FANTOME1_DMG,
			FANTOME1_ATK_DELAY,
			FANTOME1_SPEED,
			ident,
			range,
			FANTOME1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, FANTOME1_DELAY1);
         setSpellDelay(2, FANTOME1_DELAY2);
         setSpellDelay(3, FANTOME1_DELAY3);
         setSRange(1, FANTOME1_RANGE1);
         setSRange(2, FANTOME1_RANGE2);
         setSRange(3, FANTOME1_RANGE3);
         setDmg(1, FANTOME1_DMG1);
         setDmg(2, FANTOME1_DMG2);
         setDmg(3, FANTOME1_DMG3);
         setVSpell(1, FANTOME1_V2I1);
         setVSpell(2, FANTOME1_V2I2);
         setVSpell(3, FANTOME1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, FANTOME1_MANA_COST1);
         setSManaCost(2, FANTOME1_MANA_COST2);
         setSManaCost(3, FANTOME1_MANA_COST3);      
}


Fantome1::~Fantome1()
{}


