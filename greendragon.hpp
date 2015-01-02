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
/*                  Fichier : GREENDRAGON.HPP                      */
/*=================================================================*/
/*******************************************************************/

#ifndef GREEN_DRAGON_HPP
#define GREEN_DRAGON_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define GREEN_DRAGON_X 3
#define GREEN_DRAGON_Y 4
#define GREEN_DRAGON_LIFE 7000
#define GREEN_DRAGON_MANA  500
#define GREEN_DRAGON_POWER None
#define GREEN_DRAGON_DMG 100
#define GREEN_DRAGON_ATK_DELAY 5
#define GREEN_DRAGON_XP 10
#define GREEN_DRAGON_SPEED 1.5
#define GREEN_DRAGON_RANGE1 1
#define GREEN_DRAGON_RANGE2 2
#define GREEN_DRAGON_RANGE3 4
#define GREEN_DRAGON_DELAY1 2
#define GREEN_DRAGON_DELAY2 4
#define GREEN_DRAGON_DELAY3 10
#define GREEN_DRAGON_DMG1 600
#define GREEN_DRAGON_DMG2 600
#define GREEN_DRAGON_DMG3 1400
#define GREEN_DRAGON_V2I1 Vector2i(5,3)
#define GREEN_DRAGON_V2I2 Vector2i(5,5)
#define GREEN_DRAGON_V2I3 Vector2i(5,5)
#define GREEN_DRAGON_MANA_COST1 0
#define GREEN_DRAGON_MANA_COST2 0
#define GREEN_DRAGON_MANA_COST3 0

class GreenDragon : public Bot
{
	public :

	GreenDragon(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3);

	~GreenDragon();

	private:

};

#endif
