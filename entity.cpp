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
Entity::setSpeed(float speed)
{
	moveSpeed_ = speed;
}

float 
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
Entity::legalDeplacement(int x, int y) 
{	
		//cout << " x et y : " << x << y << endl;

	int *socle = getSocle(y,x); // CAR HAUTEUR DU TABLEAU = X !!!
	int i = socle[0];
	int j = socle[2];

	//int i = getCenter().x / 32;
	//int j = getCenter().y / 32;
		
//myMap_->getSocleMap(i,j)
	if (!isMoving())
		return false;
	else {
	   switch ( myMap_->getSocleMap(i,j) ) {
	   
	      case 0 : 	         
	         return false;
	         break;

	      case 1 :
	         return true;
	         break;

	      case 2 :

	         //linkmap1
            if ( getMap()->getLink(1) ) 
				{	         
		         setPosition(Vector2f(getMap()->get_tpPoints(1),getMap()->get_tpPoints(0)));   //(Y, X)
		         setMap(getMap()->getLink(1));
	         }

	         return false;
	         break;

	      case 3 : 

	         //linkmap2
	         if ( getMap()->getLink(2) ) 
				{	       
	       		setPosition(Vector2f(getMap()->get_tpPoints(3),getMap()->get_tpPoints(2)));   //(Y, X)
	       		setMap(getMap()->getLink(2));
	         }
	         return false;
	         break;
	       
	      case 4 :
	         //linkmap3
	         if ( getMap()->getLink(3) ) 
				{
		         setPosition(Vector2f(getMap()->get_tpPoints(5),getMap()->get_tpPoints(4)));   //(Y, X)
		         setMap(getMap()->getLink(3));
	         }

	         return false;
	         break;

	      default :
		      return false;
	         break;	         
	   }
	}
	
	return true;
	/*if (myMap_->getSocleMap(i,j) == 0)
		return false;
	else 
		return true;*/

}

void 
Entity::moveUp()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y - getAnimationHeight()/3 - getSpeed()) &&  legalDeplacement(getCenter().x - getAnimationWidth()/3 ,getCenter().y - getAnimationHeight()/3 - getSpeed())){

		mySprite_->Move(ZERO,-getSpeed());
		setAnimationY(UP);
		//cout << "deplacement autorisé " << endl;
	}
	
}

void 
Entity::moveDown()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed()) && legalDeplacement(getCenter().x - getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed())){

		mySprite_->Move(ZERO,getSpeed());
		setAnimationY(DOWN);
	}
}

void 
Entity::moveLeft()
{
	if(legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3) && legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3)){

		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	}
}

void 
Entity::moveRight()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3 ) && legalDeplacement(getCenter().x  + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3 )){

		mySprite_->Move(getSpeed(),ZERO);
		setAnimationY(RIGHT);
	}
}


void 
Entity::moveUpRight()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3 - getSpeed()) && legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 + getSpeed() ,getCenter().y - getAnimationHeight()  / 3 - getSpeed()) && legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3 - getSpeed())){

		mySprite_->Move(getSpeed(),-getSpeed());
		setAnimationY(RIGHT);
	}
	else {
	   if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3) && legalDeplacement(getCenter().x  + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3)){ // RIGHT

		   mySprite_->Move(getSpeed(),ZERO);
		   setAnimationY(RIGHT);
	   }
	   else {
	      moveUp();
	   }
	}
}

void 
Entity::moveDownRight()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth() / 3 + getSpeed(),getCenter().y + getAnimationHeight() / 3 + getSpeed()) && legalDeplacement(getCenter().x - getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3 + getSpeed()) && legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3 + getSpeed())){

		mySprite_->Move(getSpeed(),getSpeed());
		setAnimationY(RIGHT);
	}
	else {
	   if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3 ) && legalDeplacement(getCenter().x  + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3)){ // RIGHT

		   mySprite_->Move(getSpeed(),ZERO);
		   setAnimationY(RIGHT);
	   }
	   else {
	      moveDown();
	   }
	}
}

void 
Entity::moveUpLeft()
{
	if(legalDeplacement(getCenter().x - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3 - getSpeed())  && legalDeplacement(getCenter().x - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3 - getSpeed()) && legalDeplacement(getCenter().x + getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3 - getSpeed())){
	//cout << "center X + speed: " << getCenter().x - getSpeed()<< "center Y + speed: " << getCenter().y + getSpeed() << endl;
		mySprite_->Move(-getSpeed(),-getSpeed());
		setAnimationY(LEFT);
	}
	else {
	   if(legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3 ) && legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3 )){
		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	   }
	   else {
	      moveUp();
	   }
	
	}
}

void 
Entity::moveDownLeft()
{
	if(legalDeplacement(getCenter().x - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3 + getSpeed())   && legalDeplacement(getCenter().x - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3 + getSpeed())  && legalDeplacement(getCenter().x + getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3 + getSpeed())){

		mySprite_->Move(-getSpeed(),getSpeed());
		setAnimationY(LEFT);
	}
	else {
	   if(legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3 ) && legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3 )){
		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	   }
	   else {
	      moveDown();
	   }
	
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
	Vector2f socle = getCenter();

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
	
	//cout << " tab socle : "<< tab[0] << " " << tab[1] << " "  << tab[2] << " "  << tab[3] <<  endl;

	return tab;
}


void Entity::setMap(Map * map) {
   myMap_ = map;
}

Map * Entity::getMap() const {
   return myMap_;
}
