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
/*                   Fichier : FANTOME2.HPP                        */
/*=================================================================*/
/*******************************************************************/

#ifndef FANTOME2_HPP
#define FANTOME2_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define FANTOME2_X 3
#define FANTOME2_Y 4
#define FANTOME2_LIFE 2500
#define FANTOME2_MANA  500
#define FANTOME2_POWER None
#define FANTOME2_DMG 100
#define FANTOME2_ATK_DELAY 5
#define FANTOME2_XP 10
#define FANTOME2_SPEED 2
#define FANTOME2_RANGE1 1
#define FANTOME2_RANGE2 3
#define FANTOME2_RANGE3 -1
#define FANTOME2_DELAY1 1
#define FANTOME2_DELAY2 6
#define FANTOME2_DELAY3 10
#define FANTOME2_DMG1 250
#define FANTOME2_DMG2 500
#define FANTOME2_DMG3 200
#define FANTOME2_V2I1 Vector2i(5,5)
#define FANTOME2_V2I2 Vector2i(5,4)
#define FANTOME2_V2I3 Vector2i(5,5)
#define FANTOME2_MANA_COST1 0
#define FANTOME2_MANA_COST2 0
#define FANTOME2_MANA_COST3 0

class Fantome2 : public Bot
{
	public :

	Fantome2(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Fantome2();

	private:

};

#endif
