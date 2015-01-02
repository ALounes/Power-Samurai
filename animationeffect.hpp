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
/*                Fichier : ANIMATIONEFFECT.HPP                    */
/*=================================================================*/
/*******************************************************************/

#ifndef ANIMATION_EFFECT_HPP
#define ANIMATION_EFFECT_HPP

#include <SFML/Graphics.hpp>
#include "animation.hpp"
#include "entity.hpp"

class AnimationEffect: public Animation
{
	public:

	AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim); 
	virtual ~AnimationEffect();

 	void play();      //L'animation est en cours
	void stop();      //L'animation est arrêtée.
	bool isPlaying() const; //Renvoie le status de l'animation

	virtual void loop();    //Permet de boucler l'animation
	virtual void run ();    //Utile pour les classes héritées

	void setDefaultSprite();

	void setAnim(int anim);
	int  incrementationAnim();
	int  getAnim() const;
	int  getNmbEffect() const;
	int getManaCost() const;
	void setManaCost(int);
	int getId() const;
	void setId(int);

	private:

	const int numberOfEffect_;
	int  iAnim_;
	bool playing_;
	int mana_cost_;      //Cout de l'animation
	int id_;
	
};

#endif
