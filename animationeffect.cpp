#include "animationeffect.hpp"
int PIPI = 0;

AnimationEffect::AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim)
: Animation(win,image,nbrOfAnim)
{
	//setDefaultSprite();
}

AnimationEffect::
~AnimationEffect() {}

void 
AnimationEffect::play(Clock time, bool loop) 
{
	if (time.GetElapsedTime() > EFFECT_FPS_RATE) 
	{
		setAnimation( ++PIPI % 25);
		time.Reset();
		display();
	}
}

void 
AnimationEffect::stop() const
{	
	// A FAIRE
}


void 
AnimationEffect::setDefaultSprite()
{
	mySprite_->SetSubRect(IntRect(EFFECT_SPRITE_BEGIN_X, 
											EFFECT_SPRITE_BEGIN_Y,
											EFFECT_SPRITE_END_X, 
											EFFECT_SPRITE_END_Y ));
}
