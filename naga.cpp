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

#include "naga.hpp"


Naga::Naga(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(NAGA_X,NAGA_Y), 
			String("Naga"),
			NAGA_LIFE,
			NAGA_MANA, 
			NAGA_POWER,
			myMap,
			NAGA_DMG,
			NAGA_ATK_DELAY,
			NAGA_SPEED,
			ident,
			range,
			NAGA_XP, image1, image2, image3
			)
{	      setSpellDelay(1, NAGA_DELAY1);
         setSpellDelay(2, NAGA_DELAY2);
         setSpellDelay(3, NAGA_DELAY3);
         setSRange(1, NAGA_RANGE1);
         setSRange(2, NAGA_RANGE2);
         setSRange(3, NAGA_RANGE3);
         setDmg(1, NAGA_DMG1);
         setDmg(2, NAGA_DMG2);
         setDmg(3, NAGA_DMG3);
         setVSpell(1, NAGA_V2I1);
         setVSpell(2, NAGA_V2I2);
         setVSpell(3, NAGA_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, NAGA_MANA_COST1);
         setSManaCost(2, NAGA_MANA_COST2);
         setSManaCost(3, NAGA_MANA_COST3);
}


Naga::~Naga()
{}


