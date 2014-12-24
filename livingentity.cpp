#include "livingentity.hpp"


LivingEntity::LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
{

}

LivingEntity::~LivingEntity()
{}
