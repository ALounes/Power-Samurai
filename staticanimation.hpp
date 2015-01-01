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


	void loop();      // Permet de faire tourner en boucle l'animation
	void run ();      // Permet de lancer l'animation

	private:

	Vector2f position_;	

};

#endif
