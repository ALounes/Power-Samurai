#include "entity.hpp"

Entity::Entity(RenderWindow *win, Image& image, Vector2i nbrOfAnim, int moveSpeed)
: Animation(win,image,nbrOfAnim)
, moveSpeed_(moveSpeed)
{
	// A FAIRE
}

Entity::~Entity() {}

void 
Entity::init()
{
	// A FAIRE 
}

void 
Entity::setSpeed(int speed)
{
	moveSpeed_ = speed;
}

int 
Entity::getSpeed() const
{
	return moveSpeed_;
}

bool 
Entity::legalDeplacement(int x, int y) const
{
	if((x > X_MAX_MAP)&&(x < X_MIN_MAP)&&(y > Y_MAX_MAP)&&(y < Y_MIN_MAP))
		return false;
	else 
		return true;
}

void 
Entity::moveUp()
{
	if(legalDeplacement(mySprite_->GetCenter().x,mySprite_->GetCenter().y - getSpeed())){
		mySprite_->Move(ZERO,-getSpeed());
		setAnimationY(UP);
	}
}

void 
Entity::moveDown()
{
	if(legalDeplacement(mySprite_->GetCenter().x,mySprite_->GetCenter().y + getSpeed())){
		mySprite_->Move(ZERO,getSpeed());
		setAnimationY(DOWN);
	}
}

void 
Entity::moveLeft()
{
	if(legalDeplacement(mySprite_->GetCenter().x - getSpeed(),mySprite_->GetCenter().y)){
		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	}
}

void 
Entity::moveRight()
{
	if(legalDeplacement(mySprite_->GetCenter().x + getSpeed(),mySprite_->GetCenter().y)){
		mySprite_->Move(getSpeed(),ZERO);
		setAnimationY(RIGHT);
	}
}


void 
Entity::moveUpRight()
{
	if(legalDeplacement(mySprite_->GetCenter().x + getSpeed(),mySprite_->GetCenter().y - getSpeed())){
		mySprite_->Move(getSpeed(),-getSpeed());
		setAnimationY(RIGHT);
	}
}

void 
Entity::moveDownRight()
{
	if(legalDeplacement(mySprite_->GetCenter().x + getSpeed(),mySprite_->GetCenter().y + getSpeed())){
		mySprite_->Move(getSpeed(),getSpeed());
		setAnimationY(RIGHT);
	}
}

void 
Entity::moveUpLeft()
{
	if(legalDeplacement(mySprite_->GetCenter().x - getSpeed(),mySprite_->GetCenter().y - getSpeed())){
		mySprite_->Move(-getSpeed(),-getSpeed());
		setAnimationY(LEFT);
	}
}

void 
Entity::moveDownLeft()
{
	if(legalDeplacement(mySprite_->GetCenter().x - getSpeed(),mySprite_->GetCenter().y + getSpeed())){
		mySprite_->Move(-getSpeed(),getSpeed());
		setAnimationY(LEFT);
	}
}

void 
Entity::setDefaultSprite()
{
	mySprite_->SetSubRect(IntRect(E_SPRITE_BEGIN_X,E_SPRITE_BEGIN_Y,E_SPRITE_END_X,E_SPRITE_END_Y));
}


