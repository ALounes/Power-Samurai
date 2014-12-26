#ifndef ANIMATION_EFFECT_HPP
#define ANIMATION_EFFECT_HPP

#include <SFML/Graphics.hpp>
#include "animation.hpp"
#include "entity.hpp"

class AnimationEffect: public Animation
{
	public:

	AnimationEffect(RenderWindow *win, Image& image, const Vector2i nbrOfAnim); 
	virtual ~AnimationEffect();

 	void play();
	void stop();
	bool isPlaying() const;

	virtual void loop();
	virtual void run ();

	void setDefaultSprite();

	void setAnim(int anim);
	int  incrementationAnim();
	int  getAnim() const;
	int  getNmbEffect() const;

	private:

	const int numberOfEffect_;
	int  iAnim_;
	bool playing_;
	
};

#endif
