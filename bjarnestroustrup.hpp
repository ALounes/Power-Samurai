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
/*               Fichier : BJARNESTROUSTRUP.HPP                    */
/*=================================================================*/
/*******************************************************************/

#ifndef BJARNESTROUSTRUP_HPP
#define BJARNESTROUSTRUP_HPP

#include "player.hpp"
#include "config.hpp"

#define BJARNE_STROUSTRUP_X 3
#define BJARNE_STROUSTRUP_Y 4
#define BJARNE_STROUSTRUP_LIFE 2000
#define BJARNE_STROUSTRUP_MANA  500
#define BJARNE_STROUSTRUP_POWER None
#define BJARNE_STROUSTRUP_DMG 100
#define BJARNE_STROUSTRUP_ATK_DELAY 0.5
#define BJARNE_STROUSTRUP_XP 10
#define BJARNE_STROUSTRUP_SPEED 3
#define BJARNE_STROUSTRUP_RANGE1 3
#define BJARNE_STROUSTRUP_RANGE2 3
#define BJARNE_STROUSTRUP_RANGE3 3
#define BJARNE_STROUSTRUP_DELAY1 2
#define BJARNE_STROUSTRUP_DELAY2 5
#define BJARNE_STROUSTRUP_DELAY3 20
#define BJARNE_STROUSTRUP_DMG1 100
#define BJARNE_STROUSTRUP_DMG2 200
#define BJARNE_STROUSTRUP_DMG3 500
#define BJARNE_STROUSTRUP_V2I1 Vector2i(5,3)
#define BJARNE_STROUSTRUP_V2I2 Vector2i(5,6)
#define BJARNE_STROUSTRUP_V2I3 Vector2i(5,6)
#define BJARNE_STROUSTRUP_MANA_COST1 30
#define BJARNE_STROUSTRUP_MANA_COST2 60
#define BJARNE_STROUSTRUP_MANA_COST3 100

class BjarneStroustrup : public Player
{
	public :
	BjarneStroustrup(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3);
	~BjarneStroustrup();

	private:
	
};

#endif
