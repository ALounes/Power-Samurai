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

#ifndef LIFE_EFFECT_HPP
#define LIFE_EFFECT_HPP

#include "config.hpp"
#include "animationeffect.hpp"
#include "player.hpp"

#define LIFE_EFFECT_X 5
#define LIFE_EFFECT_Y 5
#define DEFAULT_NBR_EFFECT 3
 
class LifeEffect 
{
	public :

	LifeEffect(RenderWindow *win,Player *myPlayer);
	~LifeEffect();

	private:

	RenderWindow *win_;
	AnimationEffect animEffect_;
	Image  myImg_;
	Image  effectImg_;
	Sprite mySprite_;
	int nbrOfEfffect_;

};

#endif
