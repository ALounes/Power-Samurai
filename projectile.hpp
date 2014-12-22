#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "entity.hpp"
#define PROJECTILE_DIRECTION_DEFAULT 6

class Projectile : public Entity
{
	public :

	Projectile(RenderWindow *win, Image* image,const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect);
	~Projectile();

	void update();
	int getDirection() const;
	void setDirection(int direction) ;

	private:

	int direction_;
	int  iAnim_;
	const int numberOfEffect_;
};

#endif
