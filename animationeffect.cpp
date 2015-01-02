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

#include "animationeffect.hpp"

AnimationEffect::AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim)
	: Animation(win,image,nbrOfAnim)
	, numberOfEffect_(nbrOfAnim.x * nbrOfAnim.y)
	, iAnim_(-1)
	, playing_(false)
{
	setDefaultSprite();
}

AnimationEffect::
~AnimationEffect() 
{}

void 
AnimationEffect::run() 
{}

void 
AnimationEffect::loop() 
{}

void 
AnimationEffect::setAnim(int anim)
{
	iAnim_ = anim;
}

int
AnimationEffect::incrementationAnim()
{
	return ++iAnim_; 
}

int  
AnimationEffect::getAnim() const
{
	return iAnim_ ;
}

int  
AnimationEffect::getNmbEffect() const
{
	return numberOfEffect_;
}

void 
AnimationEffect::stop() 
{	
	playing_ = false;
}

void 
AnimationEffect::play()
{	
	playing_ = true;
}

bool 
AnimationEffect::isPlaying() const
{
	return playing_;
}

void 
AnimationEffect::setDefaultSprite()
{
	mySprite_->SetSubRect(IntRect(EFFECT_SPRITE_BEGIN_X, 
											EFFECT_SPRITE_BEGIN_Y,
											EFFECT_SPRITE_END_X, 
											EFFECT_SPRITE_END_Y ));
}


int AnimationEffect::getManaCost() const {
   return mana_cost_;
}


void AnimationEffect::setManaCost(int mana_cost) {
   mana_cost_ = mana_cost;
}

int AnimationEffect::getId() const {
   return id_;
}

void AnimationEffect::setId(int id) {
   id_ = id;
}

