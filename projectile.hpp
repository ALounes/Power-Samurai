#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "entity.hpp"
#define PROJECTILE_DIRECTION_DEFAULT 3

class Projectile : public Entity
{
	public :

	Projectile(RenderWindow *win, Image* image,const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect);
	~Projectile();

	void update();
	char getDirection() const;
	void setDirection(char direction) ;

	private:

	char direction_;
	int  iAnim_;
	const int numberOfEffect_;
};

#endif
