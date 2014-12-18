#include "projectile.hpp"

	
Projectile::Projectile(RenderWindow *win, Image* image, const Vector2i& nbrOfAnim, Entity *entity, Map *myMap)
:Entity(win,*image,nbrOfAnim,myMap)
,direction_(PROJECTILE_DIRECTION_DEFAULT)
{
	
	setPosition( entity->getPosition() );
}

Projectile::~Projectile()
{}

char 
Projectile::getDirection() const
{
	return direction_;
}

void
Projectile::setDirection(char direction) 
{
	direction_ = direction;
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
			runMove();
			moveDown();
			break;

		case LEFT:
			runMove();
			moveLeft();
			break;

		case RIGHT:
			runMove();
			moveRight();
			break;

		case UP:
			runMove();
			moveUp();
			break;

		case UPLEFT:
			runMove();
			moveUpLeft();
			break;

		case UPRIGHT:
			runMove();
			moveUpRight();
			break;

		case DOWNLEFT:
			runMove();
			moveDownLeft();
			break;

		case DOWNRIGHT:
			runMove();
			moveDownRight();
			break;
		
		default: // Cas -1 pas de mouvement
			break;
	}
}

