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

#include "bjarnestroustrup.hpp"

BjarneStroustrup::BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3)
:Player( win,
			image, 
			Vector2i(BJARNE_STROUSTRUP_X,BJARNE_STROUSTRUP_Y), 
			String("Bjarne Stroustrup"),
			BJARNE_STROUSTRUP_LIFE,
			BJARNE_STROUSTRUP_MANA, 
			BJARNE_STROUSTRUP_POWER,
			myMap,
			BJARNE_STROUSTRUP_DMG
			)
{
         setSpellDelay(1, BJARNE_STROUSTRUP_DELAY1);
         setSpellDelay(2, BJARNE_STROUSTRUP_DELAY2);
         setSpellDelay(3, BJARNE_STROUSTRUP_DELAY3);
         setSRange(1, BJARNE_STROUSTRUP_RANGE1);
         setSRange(2, BJARNE_STROUSTRUP_RANGE2);
         setSRange(3, BJARNE_STROUSTRUP_RANGE3);
         setDmg(1, BJARNE_STROUSTRUP_DMG1);
         setDmg(2, BJARNE_STROUSTRUP_DMG2);
         setDmg(3, BJARNE_STROUSTRUP_DMG3);
         setVSpell(1, BJARNE_STROUSTRUP_V2I1);
         setVSpell(2, BJARNE_STROUSTRUP_V2I2);
         setVSpell(3, BJARNE_STROUSTRUP_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, BJARNE_STROUSTRUP_MANA_COST1);
         setSManaCost(2, BJARNE_STROUSTRUP_MANA_COST2);
         setSManaCost(3, BJARNE_STROUSTRUP_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait2.png");
         setSpeed(BJARNE_STROUSTRUP_SPEED);
}


BjarneStroustrup::~BjarneStroustrup() {}
