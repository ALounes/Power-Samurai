#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "entity.hpp"
#define PROJECTILE_DIRECTION_DEFAULT 6
#define ID_PROJECTILE -10

class Projectile : public Entity
{
	public :

	Projectile(RenderWindow *win, Image* image,const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect, int ProjectileSpeed);
	~Projectile();

	void update();
	int getDirection() const;
	void setDirection(int direction) ;
	void preset();

	private:

	int direction_;
	int  iAnim_;
	const int numberOfEffect_;
};

#endif
