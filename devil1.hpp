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
/*                     Fichier : DEVIL1.HPP                        */
/*=================================================================*/
/*******************************************************************/

#ifndef DEVIL1_HPP
#define DEVIL1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define DEVIL1_X 3
#define DEVIL1_Y 4
#define DEVIL1_LIFE 120000
#define DEVIL1_MANA  500
#define DEVIL1_POWER None
#define DEVIL1_DMG 100
#define DEVIL1_ATK_DELAY 5
#define DEVIL1_XP 10
#define DEVIL1_SPEED 1.5
#define DEVIL1_RANGE1 2
#define DEVIL1_RANGE2 4
#define DEVIL1_RANGE3 5
#define DEVIL1_DELAY1 2
#define DEVIL1_DELAY2 9
#define DEVIL1_DELAY3 16
#define DEVIL1_DMG1 1400
#define DEVIL1_DMG2 1900
#define DEVIL1_DMG3 4000
#define DEVIL1_V2I1 Vector2i(5,5)
#define DEVIL1_V2I2 Vector2i(5,5)
#define DEVIL1_V2I3 Vector2i(5,5)
#define DEVIL1_MANA_COST1 0
#define DEVIL1_MANA_COST2 0
#define DEVIL1_MANA_COST3 0

class Devil1 : public Bot
{
	public :

	Devil1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Devil1();

	private:

};

#endif
