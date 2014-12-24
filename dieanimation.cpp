#ifndef DIE_ANIMATION_HPP
#define DIE_ANIMATION_HPP

#include "animation.hpp"
#include "entity.hpp"

class DieAnimation : public AnimationEffect
{
	public:

	DieAnimation(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Entity *entity);
	~DieAnimation();

	void play();
	void stop();
	void run ();

	bool isPlaying() const;

	virtual void setDefaultSprite();

	private:
	Entity *entity_;	
	const int numberOfEffect_;
	int  iAnim_;
	bool playing_;
	//Clock time_animation ;
	//float delay_animation = 0.001;
	

};

#endif
