#include "projectile.hpp"

	
Projectile::Projectile(RenderWindow *win, Image* image, const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect, int ProjectileSpeed)
:Entity(win,*image,nbrOfAnim,entity->getMap())
,direction_(PROJECTILE_DIRECTION_DEFAULT)
,iAnim_(0)
,numberOfEffect_(numberOfEffect)
{
   setId(-10);
	play();
	Vector2f posit(entity->getCenter().x - getAnimationWidth() / 2, entity->getCenter().y - getAnimationHeight() / 2);
	setPosition( posit );	
	setSpeed(ProjectileSpeed);
}

Projectile::~Projectile()
{

}

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

void Projectile::preset() {
   int direction = getDirection();
	switch(direction)
	{
		case 2 :
			//runMove();
			//moveDown();
			mySprite_->SetRotation(270);
	      mySprite_->Move( getAnimationWidth(), getAnimationHeight());
			
			break;

		case 4:

			//moveLeft();
			mySprite_->SetRotation(180);
			mySprite_->Move( 0, getAnimationHeight());
			break;

		case 0:

			//moveRight();
			mySprite_->Move( getAnimationWidth(), 0);
			break;

		case 6:

			//moveUp();
			
			mySprite_->SetRotation(90);
			break;

		case 5:

			//moveUpLeft();
			mySprite_->Move( 0, getAnimationHeight());
			mySprite_->SetRotation(135);
			//mySprite_->Move( 0, getAnimationHeight());
			break;

		case 7:

			//moveUpRight();
			mySprite_->SetRotation(45);
			break;

		case 3:
         
			//moveDownLeft();
			mySprite_->Move( getAnimationWidth(), getAnimationHeight());
			mySprite_->SetRotation(225);
			break;

		case 1:

			//moveDownRight();
						mySprite_->Move( getAnimationWidth(), 0);
			mySprite_->SetRotation(315);
			break;
		
		default: // Cas -1 pas de mouvement
			break;
	}
   
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
			moveUp();
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
}


