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
/*               Fichier : FOLWINGANIMATION.HPP                    */
/*=================================================================*/
/*******************************************************************/

#ifndef FOLOWING_ANIMATION_HPP
#define FOLOWING_ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include "animationeffect.hpp"
#include "entity.hpp"

class FolowingAnimation : public AnimationEffect
{
	public:

	FolowingAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Entity *entity);
	~FolowingAnimation();

	void loop();   //Boucle l'animation
	void run ();   //Gère le déroulement de l'animation et fait en sorte de bien suivre l'entité passée en paramètre

	private:

	Entity *entity_;	

};

#endif
