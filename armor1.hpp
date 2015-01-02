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
/*                    Fichier : ARMOR1.HPP                         */
/*=================================================================*/
/*******************************************************************/

#ifndef ARMOR1_HPP
#define ARMOR1_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define ARMOR1_X 3
#define ARMOR1_Y 4
#define ARMOR1_LIFE 7000
#define ARMOR1_MANA 0
#define ARMOR1_POWER None
#define ARMOR1_DMG 0
#define ARMOR1_ATK_DELAY 0
#define ARMOR1_XP 10
#define ARMOR1_SPEED 1.5
#define ARMOR1_RANGE1 1
#define ARMOR1_RANGE2 3
#define ARMOR1_RANGE3 5
#define ARMOR1_DELAY1 1
#define ARMOR1_DELAY2 6
#define ARMOR1_DELAY3 10
#define ARMOR1_DMG1 700
#define ARMOR1_DMG2 1200
#define ARMOR1_DMG3 1700
#define ARMOR1_V2I1 Vector2i(5,3)
#define ARMOR1_V2I2 Vector2i(5,4)
#define ARMOR1_V2I3 Vector2i(5,6)
#define ARMOR1_MANA_COST1 0
#define ARMOR1_MANA_COST2 0
#define ARMOR1_MANA_COST3 0

class Armor1 : public Bot
{
	public :

	Armor1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~Armor1();

	private:

};

#endif
