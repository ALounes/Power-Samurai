#ifndef POWERSAMURAI_HPP
#define POWERSAMURAI_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include "entity.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "animationeffect.hpp"
#include "linustorvalds.hpp"

using  namespace sf;
using  namespace std;

enum direction {DOWN,LEFT,RIGHT,UP};

class PowerSamurai
{
public:

	PowerSamurai();
	~PowerSamurai();

	void run ();

	void addEntity(Entity *entity);
	void removeEntity(Entity *entity);		
	void displayEntity(Clock &time);

	void addEffect(AnimationEffect *effect);
	void removeEffect(AnimationEffect *effect);		
	void displayEffect(Clock &time);

	void eventManagement(Event &event);
	void keyPressedManagement (sf::Key::Code keyPressed);
	void fire(enum direction dir);

private:
	RenderWindow *win_;
	list<Entity*> entitys;
	list<AnimationEffect*> effects;
};

#endif 
