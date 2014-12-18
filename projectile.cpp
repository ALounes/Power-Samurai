#include "projectile.hpp"

	
Projectile::Projectile(RenderWindow *win, Image* image, const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect)
:Entity(win,*image,nbrOfAnim,entity->getMap())
,direction_(PROJECTILE_DIRECTION_DEFAULT)
,iAnim_(0)
,numberOfEffect_(numberOfEffect)
{
	play();
	setPosition( entity->getPosition() );
	getSprite()->SetScale(0.4,0.4);
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
		if(iAnim_ < numberOfEffect_)
		{
			setAnimation(++iAnim_);
			draw();
		}
		else
		{
			iAnim_= 0;
		}	
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

