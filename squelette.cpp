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

#include "squelette.hpp"

Squelette::Squelette(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(SQUELETTE_X,SQUELETTE_Y), 
			String("Armor"),
			SQUELETTE_LIFE,
			SQUELETTE_MANA, 
			SQUELETTE_POWER,
			myMap,
			SQUELETTE_DMG,
			SQUELETTE_ATK_DELAY,
			SQUELETTE_SPEED,
			ident,
			range,
			SQUELETTE_XP, image1, image2, image3
			)
{	      setSpellDelay(1, SQUELETTE_DELAY1);
         setSpellDelay(2, SQUELETTE_DELAY2);
         setSpellDelay(3, SQUELETTE_DELAY3);
         setSRange(1, SQUELETTE_RANGE1);
         setSRange(2, SQUELETTE_RANGE2);
         setSRange(3, SQUELETTE_RANGE3);
         setDmg(1, SQUELETTE_DMG1);
         setDmg(2, SQUELETTE_DMG2);
         setDmg(3, SQUELETTE_DMG3);
         setVSpell(1, SQUELETTE_V2I1);
         setVSpell(2, SQUELETTE_V2I2);
         setVSpell(3, SQUELETTE_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3); 
         setSManaCost(1, SQUELETTE_MANA_COST1);
         setSManaCost(2, SQUELETTE_MANA_COST2);
         setSManaCost(3, SQUELETTE_MANA_COST3);    
}


Squelette::~Squelette()
{}


