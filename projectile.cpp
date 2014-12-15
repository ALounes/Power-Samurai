#include "projectile.hpp"

	
Projectile::Projectile(RenderWindow *win, Image* image,const Vector2i& nbrOfAnim, Map *myMap)
:Entity(win,*image,nbrOfAnim,myMap)
,direction_(-1)
{

}

char 
Projectile::getDirection() const
{
	return direction_;
}

void 
Projectile::update()
{
	char direction = getDirection();

	if (isMoving())
	{
		updateSprite();
		animationRight();
		stopMove();
	}

	switch(direction)
	{
		case DOWN :
			moveDown();
			break;

		case LEFT:
			moveLeft();
			break;

		case RIGHT:
			moveRight();
			break;

		case UP:
			moveUp();
			break;

		case UPLEFT:
			moveUpLeft();
			break;

		case UPRIGHT:
			moveUpRight();
			break;

		case DOWNLEFT:
			moveDownLeft();
			break;

		case DOWNRIGHT:
			moveDownRight();
			break;
		
		default: // Cas -1 pas de mouvement
			break;
	}
}

