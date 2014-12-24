#include "animationeffect.hpp"
int PIPI = 0;

AnimationEffect::AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Entity *entity)
: Animation(win,image,nbrOfAnim)
,entity_(entity)
,numberOfEffect_(nbrOfAnim.x * nbrOfAnim.y)
,iAnim_(-1)
,playing_(false)
{
	setDefaultSprite();
}

AnimationEffect::
~AnimationEffect() {}

void 
AnimationEffect::run() 
{
	if(playing_ )
	{
		setCenter(entity_->getCenter());
		if(iAnim_ < numberOfEffect_)
		{
			setAnimation(++iAnim_);
			draw();
		}
		else
		{
			iAnim_= -1;
		}	
		if(playing_ && (iAnim_ == -1))
			stop();			
	}
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
