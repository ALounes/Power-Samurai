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

int 
Projectile::getDirection() const
{
	return direction_;
}

void
Projectile::setDirection(int direction) 
{
	direction_ = direction;
}

void 
Projectile::update()
{
	int direction = getDirection();
	
   //cout << "direction : " << direction << endl;
	switch(direction)
	{
		case 2 :
			runMove();
			moveDown();
			break;

		case 4:
			runMove();
			moveLeft();
			break;

		case 0:
			runMove();
			moveRight();
			break;

		case 6:
			runMove();
			//cout << "Move" << endl;
			cout << "x1 :" << getCenter().x << endl;
			cout << "y1 :" << getCenter().y << endl;
			moveUp();
			cout << "cas 6" << endl;
			cout << "x2 :" << getCenter().x << endl;
			cout << "y2 :" << getCenter().y << endl;
			break;

		case 5:
			runMove();
			moveUpLeft();
			break;

		case 7:
			runMove();
			moveUpRight();
			break;

		case 3:
			runMove();
			moveDownLeft();
			break;

		case 1:
			runMove();
			moveDownRight();
			break;
		
		default: // Cas -1 pas de mouvement
			break;
	}
	
	if (isMoving())
	{
		if(iAnim_ < numberOfEffect_)
		{
			setAnimation(++iAnim_);
			//draw();
		}
		else
		{
			iAnim_= 0;
		}	
		stopMove();
	}
	
	cout << "x3 :" << getCenter().x << endl;
	cout << "y3 :" << getCenter().y << endl;
}

