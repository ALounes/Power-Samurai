#ifndef LIVING_ENTITY_HPP
#define LIVING_ENTITY_HPP

#include "entity.hpp"
#include "animationeffect.hpp"
#include <list>

class LivingEntity : public Entity
{
	public :

	LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap);
	~LivingEntity();
	
   
   list<AnimationEffect*> spells;
	list<AnimationEffect*> appliedeffects;
	private:
	
};

#endif
