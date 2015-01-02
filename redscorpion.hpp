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

#ifndef REDSCORPION_HPP
#define REDSCORPION_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define REDSCORPION_X 3
#define REDSCORPION_Y 4
#define REDSCORPION_LIFE 2300
#define REDSCORPION_MANA  500
#define REDSCORPION_POWER None
#define REDSCORPION_DMG 100
#define REDSCORPION_ATK_DELAY 5
#define REDSCORPION_XP 10
#define REDSCORPION_SPEED 2.5
#define REDSCORPION_RANGE1 1
#define REDSCORPION_RANGE2 2
#define REDSCORPION_RANGE3 -1
#define REDSCORPION_DELAY1 1.5
#define REDSCORPION_DELAY2 6
#define REDSCORPION_DELAY3 10
#define REDSCORPION_DMG1 300
#define REDSCORPION_DMG2 600
#define REDSCORPION_DMG3 200
#define REDSCORPION_V2I1 Vector2i(5,3)
#define REDSCORPION_V2I2 Vector2i(5,5)
#define REDSCORPION_V2I3 Vector2i(5,6)
#define REDSCORPION_MANA_COST1 0
#define REDSCORPION_MANA_COST2 0
#define REDSCORPION_MANA_COST3 0

class Redscorpion : public Bot
{
	public :

	Redscorpion(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Redscorpion();

	private:

};

#endif
