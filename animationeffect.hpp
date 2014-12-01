#ifndef ANIMATION_EFFECT_HPP
#define ANIMATION_EFFECT_HPP

#include "animation.hpp"

class AnimationEffect: public Animation
{
	public:

	AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim);
	~AnimationEffect();

	void play(bool loop);
	void stop() const;

	virtual void setDefaultSprite();

	private:

	const int numberOfEffect_;
	int iAnim_;

};

#endif
