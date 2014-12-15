#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "entity.hpp"

class Projectile : Entity
{
	public :

	Projectile(RenderWindow *win, Image* image,const Vector2i& nbrOfAnim, Map *myMap);
	~Projectile();

	void update();
	char getDirection() const;

	private:

	char direction_;

};

#endif
