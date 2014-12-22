#include "projectile.hpp"

	
Projectile::Projectile(RenderWindow *win, Image* image, const Vector2i& nbrOfAnim, Entity *entity, int numberOfEffect)
:Entity(win,*image,nbrOfAnim,entity->getMap())
,direction_(PROJECTILE_DIRECTION_DEFAULT)
,iAnim_(0)
,numberOfEffect_(numberOfEffect)
{
	play();
	Vector2f posit(entity->getCenter().x - getAnimationWidth() / 2, entity->getCenter().y - getAnimationHeight() / 2);
	setPosition( posit );
	cout << "Animation largeur : "  << getAnimationWidth() << endl;
	//getSprite()->SetScale(0.4,0.4);
	
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
			break;

		case 7:

			//moveUpRight();
			break;

		case 3:

			//moveDownLeft();
			break;

		case 1:

			//moveDownRight();
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
			mySprite_->SetRotation(180);
			break;

		case 0:
			runMove();
			moveRight();
			break;

		case 6:
			runMove();
			moveUp();
			mySprite_->SetRotation(90);
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

