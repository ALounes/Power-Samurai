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

#ifndef MOUSE1_HPP
#define MOUSE1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define MOUSE1_X 3
#define MOUSE1_Y 4
#define MOUSE1_LIFE 1300
#define MOUSE1_MANA  500
#define MOUSE1_POWER None
#define MOUSE1_DMG 100
#define MOUSE1_ATK_DELAY 5
#define MOUSE1_XP 10
#define MOUSE1_SPEED 3
#define MOUSE1_RANGE1 1
#define MOUSE1_RANGE2 3
#define MOUSE1_RANGE3 -1
#define MOUSE1_DELAY1 0.5
#define MOUSE1_DELAY2 1.5
#define MOUSE1_DELAY3 10
#define MOUSE1_DMG1 70
#define MOUSE1_DMG2 150
#define MOUSE1_DMG3 300
#define MOUSE1_V2I1 Vector2i(5,3)
#define MOUSE1_V2I2 Vector2i(5,4)
#define MOUSE1_V2I3 Vector2i(5,5)
#define MOUSE1_MANA_COST1 0
#define MOUSE1_MANA_COST2 0
#define MOUSE1_MANA_COST3 0

class Mouse1 : public Bot
{
	public :

	Mouse1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Mouse1();

	private:

};

#endif
