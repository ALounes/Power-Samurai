#include "entity.hpp"

Entity::Entity(RenderWindow *win, Image& image, const Vector2i& nbrOfAnim)
: Animation(win,image,nbrOfAnim)
,moving_(false)
{
	setDefaultSprite();
	setSpeed(DEFAULT_SPEED);
}

Entity::~Entity() {}

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

void 
Entity::runMove()
{
	moving_ = true;
}

void 
Entity::stopMove()
{
	moving_ = false;
}

bool 
Entity::isMoving() const
{
	return (moving_ && paused_);
}

void 
Entity::play()
{  
	paused_ = true;
}

void 
Entity::pause()
{
	paused_ = false;
	moving_ = false;
}

bool 
Entity::legalDeplacement(int x, int y) const
{
	if (!isMoving())
		return false;
	else if((x > X_MAX_MAP)&&(x < X_MIN_MAP)&&(y > Y_MAX_MAP)&&(y < Y_MIN_MAP))
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
	mySprite_->SetSubRect(IntRect(E_SPRITE_BEGIN_X,
											E_SPRITE_BEGIN_Y,
											E_SPRITE_END_X,
											E_SPRITE_END_Y));
}

void 
Entity::update()
{
		updateSprite();
}
