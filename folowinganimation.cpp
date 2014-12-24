#include "folowinganimation.hpp"


FolowingAnimation::FolowingAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Entity *entity)
	: AnimationEffect(win,image,nbrOfAnim)
	, entity_(entity)
{}

FolowingAnimation::
~FolowingAnimation() {}

void 
FolowingAnimation::run() 
{
	if(isPlaying())
	{
		setCenter( (entity_->getCenter()) );
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}	
		if(isPlaying() && (getAnim() == -1))
			stop();			
	}
}

void 
FolowingAnimation::loop() 
{
	if(isPlaying())
	{
		setCenter(entity_->getCenter());
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}				
	}
}
