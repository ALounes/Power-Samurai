#ifndef STATIC_ANIMATION_HPP
#define STATIC_ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include "animationeffect.hpp"
#include "config.hpp"

class StaticAnimation : public AnimationEffect
{
	public:

	StaticAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Vector2f position);
	~StaticAnimation();


	void loop();
	void run ();

	private:

	Vector2f position_;	

};

#endif
