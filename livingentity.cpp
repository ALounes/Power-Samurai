#include "livingentity.hpp"


LivingEntity::LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
{

}

LivingEntity::~LivingEntity()
{
//while (!spells.empty()) { delete spells.back(); spells.pop_back(); }
//while (!appliedeffects.empty()) { delete appliedeffects.back(); appliedeffects.pop_back(); }
cout << "DESTRUCTEUR LivingEntity()" << endl;
}
