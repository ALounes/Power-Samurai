#ifndef ANIMATION_EFFECT_HPP
#define ANIMATION_EFFECT_HPP

#include "animation.hpp"
#include "entity.hpp"

class AnimationEffect: public Animation
{
	public:

	virtual void play() = 0;
	virtual void loop() = 0;
	virtual void stop() = 0;
	virtual void run () = 0;

	virtual bool isPlaying() const  = 0;

	virtual void setDefaultSprite() = 0;

	private:

	const int numberOfEffect_;
	int  iAnim_;
	bool playing_;
	
};

#endif
