#ifndef STATIC_ANIMATION_HPP
#define STATIC_ANIMATION_HPP

#include "animationeffect.hpp"
#include "entity.hpp"

class StaticAnimation : public AnimationEffect
{
	public:

	StaticAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Vector2f position);
	~StaticAnimation();

	void play();
	void loop();
	void stop();
	void run ();

	bool isPlaying() const;
	void setDefaultSprite();

	private:

	Vector2f position_;	

};

#endif
