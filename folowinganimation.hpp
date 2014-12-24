#ifndef FOLOWING_ANIMATION_HPP
#define FOLOWING_ANIMATION_HPP

#include "animationeffect.hpp"
#include "entity.hpp"

class FolowingAnimation : public AnimationEffect
{
	public:

	FolowingAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Entity *entity);
	~FolowingAnimation();

	void play();
	void loop();
	void stop();
	void run ();

	bool isPlaying() const;
	void setDefaultSprite();

	private:

	Entity *entity_;	

};

#endif
