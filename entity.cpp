#include "entity.hpp"

Entity::Entity(RenderWindow *win, Image& image, const Vector2i& nbrOfAnim, Map *myMap)
: Animation(win,image,nbrOfAnim)
,moving_(false)
,myMap_(myMap)
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
		cout << " x et y : " << x << y << endl;

	int *socle = getSocle(y,x); // CAR HAUTEUR DU TABLEAU = X !!!
	int i = socle[1];
	int j = socle[3];
	cout << " socle x : " << x << " socle y : " << y << " socle map :" << myMap_->getSocleMap(i,j) << endl;
	//int i = getCenter().x / 32;
	//int j = getCenter().y / 32;
		

	if (!isMoving())
		return false;
	else if (myMap_->getSocleMap(i,j) == 0)
		return false;
	else 
		return true;

}

void 
Entity::moveUp()
{
	if(legalDeplacement(getCenter().x,getCenter().y - getSpeed())){
		mySprite_->Move(ZERO,-getSpeed());
		setAnimationY(UP);
	}
}

void 
Entity::moveDown()
{
	if(legalDeplacement(getCenter().x,getCenter().y + getSpeed())){
		mySprite_->Move(ZERO,getSpeed());
		setAnimationY(DOWN);
	}
}

void 
Entity::moveLeft()
{
	if(legalDeplacement(getCenter().x - getSpeed(),getCenter().y)){
		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	}
}

void 
Entity::moveRight()
{
	if(legalDeplacement(getCenter().x + getSpeed(),getCenter().y)){
		mySprite_->Move(getSpeed(),ZERO);
		setAnimationY(RIGHT);
	}
}


void 
Entity::moveUpRight()
{
	if(legalDeplacement(getCenter().x + getSpeed(),getCenter().y - getSpeed())){
		mySprite_->Move(getSpeed(),-getSpeed());
		setAnimationY(RIGHT);
	}
}

void 
Entity::moveDownRight()
{
	if(legalDeplacement(getCenter().x + getSpeed(),getCenter().y + getSpeed())){
		mySprite_->Move(getSpeed(),getSpeed());
		setAnimationY(RIGHT);
	}
}

void 
Entity::moveUpLeft()
{
	if(legalDeplacement(getCenter().x - getSpeed(),getCenter().y - getSpeed())){
		mySprite_->Move(-getSpeed(),-getSpeed());
		setAnimationY(LEFT);
	}
}

void 
Entity::moveDownLeft()
{
	if(legalDeplacement(getCenter().x - getSpeed(),getCenter().y + getSpeed())){
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

int* 
Entity::soclePosition() const
{
	int *tab = new int[4];
	Vector2f socle= getCenter();

	tab[0] = (socle.x - getAnimationWidth()/2) / getAnimationWidth();
	tab[1] = (socle.x + getAnimationWidth()/2) / getAnimationWidth();
	tab[2] = (socle.y - getAnimationHeight()/2) / getAnimationHeight();
	tab[3] = (socle.y + getAnimationHeight()/2) / getAnimationHeight();

	return tab;
}

int* 
Entity::getSocle(int x, int y) const
{	
	int *tab = new int[4];

	tab[0] = x / getAnimationWidth();
	tab[1] = x / getAnimationWidth();
	tab[2] = y / getAnimationHeight();
	tab[3] = y / getAnimationHeight();
	
	cout << " tab socle : "<< tab[0] << " " << tab[1] << " "  << tab[2] << " "  << tab[3] <<  endl;

	return tab;
}
