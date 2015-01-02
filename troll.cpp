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

#include "troll.hpp"


Troll::Troll(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(TROLL_X,TROLL_Y), 
			String("Troll"),
			TROLL_LIFE,
			TROLL_MANA, 
			TROLL_POWER,
			myMap,
			TROLL_DMG,
			TROLL_ATK_DELAY,
			TROLL_SPEED,
			ident,
			range,
			TROLL_XP, image1, image2, image3
			)
{	      setSpellDelay(1, TROLL_DELAY1);
         setSpellDelay(2, TROLL_DELAY2);
         setSpellDelay(3, TROLL_DELAY3);
         setSRange(1, TROLL_RANGE1);
         setSRange(2, TROLL_RANGE2);
         setSRange(3, TROLL_RANGE3);
         setDmg(1, TROLL_DMG1);
         setDmg(2, TROLL_DMG2);
         setDmg(3, TROLL_DMG3);
         setVSpell(1, TROLL_V2I1);
         setVSpell(2, TROLL_V2I2);
         setVSpell(3, TROLL_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, TROLL_MANA_COST1);
         setSManaCost(2, TROLL_MANA_COST2);
         setSManaCost(3, TROLL_MANA_COST3);
}


Troll::~Troll()
{}


