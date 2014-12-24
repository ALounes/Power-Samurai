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

	void loop();
	void run ();

	private:

	Entity *entity_;	

};

#endif
