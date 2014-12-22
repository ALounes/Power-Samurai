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
            is_stuck = true;
	         return false;
	         break;

	      case 1 :
            is_stuck = false;
	         return true;
	         break;

	      case 2 :

	         //linkmap1
            if ( getMap()->getLink(1) ) 
				{	         
		         setPosition(Vector2f(getMap()->get_tpPoints(1),getMap()->get_tpPoints(0)));   //(Y, X)
		         setMap(getMap()->getLink(1));
		         map_changed = 1;
		         cout << "map_changed (dans legal deplacement)" << map_changed << endl;
		         is_stuck = true;
		         return false;
	         }
            is_stuck = true;
	         return false;
	         break;

	      case 3 : 

	         //linkmap2
	         if ( getMap()->getLink(2) ) 
				{	       
	       		setPosition(Vector2f(getMap()->get_tpPoints(3),getMap()->get_tpPoints(2)));   //(Y, X)
	       		setMap(getMap()->getLink(2));
	       		map_changed = 2;
	       		is_stuck = true;
	       		return false;
	         }
	         is_stuck = true;
	         return false;
	         break;
	       
	      case 4 :
	         //linkmap3
	         if ( getMap()->getLink(3) ) 
				{
		         setPosition(Vector2f(getMap()->get_tpPoints(5),getMap()->get_tpPoints(4)));   //(Y, X)
		         setMap(getMap()->getLink(3));
		         map_changed = 3;
		         is_stuck = true;
		         return false;
	         }
            is_stuck = true;
	         return false;
	         break;

	      default :
            is_stuck = false;
		      return true;
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
Entity::moveUp() //Okay
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y - getAnimationHeight()/3 - getSpeed()) &&  legalDeplacement(getCenter().x - getAnimationWidth()/3 ,getCenter().y - getAnimationHeight()/3 - getSpeed())){
		mySprite_->Move(ZERO,-getSpeed());
		setAnimationY(UP);
		//cout << "deplacement autorisé " << endl;
	}
	else {
	   if(legalDeplacement(getCenter().x + getAnimationWidth()/3, getCenter().y - getAnimationHeight()/3 - getSpeed()) ){

		   mySprite_->Move(getSpeed(),ZERO);
		   setAnimationY(RIGHT); // Glisser à droite
	   }
	   else {
	       if(legalDeplacement(getCenter().x - getAnimationWidth()  / 3,getCenter().y - getAnimationHeight()  / 3 - getSpeed()) ){
	//cout << "center X + speed: " << getCenter().x - getSpeed()<< "center Y + speed: " << getCenter().y + getSpeed() << endl;
		      mySprite_->Move(-getSpeed(),ZERO);
		      setAnimationY(LEFT); // Glisser à gauche
	       }
	   }
	      
	
	
	}
	
}

void 
Entity::moveDown()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed()) && legalDeplacement(getCenter().x - getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed())){

		mySprite_->Move(ZERO,getSpeed());
		setAnimationY(DOWN);
	}
	else {
	   if(legalDeplacement(getCenter().x + getAnimationWidth()/3, getCenter().y + getAnimationHeight()/3 + getSpeed()) ){

		   mySprite_->Move(getSpeed(),ZERO);
		   setAnimationY(RIGHT); // Glisser à droite
	   }
	   else {
	       if(legalDeplacement(getCenter().x - getAnimationWidth()  / 3,getCenter().y + getAnimationHeight()  / 3 + getSpeed()) ){
	//cout << "center X + speed: " << getCenter().x - getSpeed()<< "center Y + speed: " << getCenter().y + getSpeed() << endl;
		      mySprite_->Move(-getSpeed(),ZERO);
		      setAnimationY(LEFT); // Glisser à gauche
	       }
	   }
	      
	
	
	}
}

void 
Entity::moveLeft()
{
	if(legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3) && legalDeplacement(getCenter().x  - getAnimationWidth()  / 3 - getSpeed(),getCenter().y - getAnimationHeight()  / 3)){

		mySprite_->Move(-getSpeed(),ZERO);
		setAnimationY(LEFT);
	}
	else {
	   if(legalDeplacement(getCenter().x - getAnimationWidth()/3 - getSpeed(), getCenter().y - getAnimationHeight()/3) ){

		   mySprite_->Move(ZERO,-getSpeed());
		   setAnimationY(UP); // Glisser en haut
	   }
	   else {
	       if(legalDeplacement(getCenter().x - getAnimationWidth()  / 3 - getSpeed(),getCenter().y + getAnimationHeight()  / 3) ){
	//cout << "center X + speed: " << getCenter().x - getSpeed()<< "center Y + speed: " << getCenter().y + getSpeed() << endl;
		      mySprite_->Move(ZERO,getSpeed());
		      setAnimationY(DOWN); // Glisser en bas
	       }
	   }
	      
	
	
	}
}

void 
Entity::moveRight()
{
	if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3 ) && legalDeplacement(getCenter().x  + getAnimationWidth()  / 3 + getSpeed(),getCenter().y - getAnimationHeight()  / 3 )){

		mySprite_->Move(getSpeed(),ZERO);
		setAnimationY(RIGHT);
	}
	else {
	   if(legalDeplacement(getCenter().x + getAnimationWidth()/3 + getSpeed(), getCenter().y - getAnimationHeight()/3) ){

		   mySprite_->Move(ZERO,-getSpeed());
		   setAnimationY(UP); // Glisser en haut
	   }
	   else {
	       if(legalDeplacement(getCenter().x + getAnimationWidth()  / 3 + getSpeed(),getCenter().y + getAnimationHeight()  / 3) ){
	//cout << "center X + speed: " << getCenter().x - getSpeed()<< "center Y + speed: " << getCenter().y + getSpeed() << endl;
		      mySprite_->Move(ZERO,getSpeed());
		      setAnimationY(DOWN); // Glisser en bas
	       }
	   }
	      
	
	
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
	      if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y - getAnimationHeight()/3 - getSpeed()) &&  legalDeplacement(getCenter().x - getAnimationWidth()/3 ,getCenter().y - getAnimationHeight()/3 - getSpeed())){

		   mySprite_->Move(ZERO,-getSpeed());
		   setAnimationY(UP);
		//cout << "deplacement autorisé " << endl;
	      }
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
	      if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed()) && legalDeplacement(getCenter().x - getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed())){

		      mySprite_->Move(ZERO,getSpeed());
		      setAnimationY(DOWN);
	      }
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
	      if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y - getAnimationHeight()/3 - getSpeed()) &&  legalDeplacement(getCenter().x - getAnimationWidth()/3 ,getCenter().y - getAnimationHeight()/3 - getSpeed())){

		      mySprite_->Move(ZERO,-getSpeed());
		      setAnimationY(UP);
		//cout << "deplacement autorisé " << endl;
	      }
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
	      if(legalDeplacement(getCenter().x + getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed()) && legalDeplacement(getCenter().x - getAnimationWidth()/3,getCenter().y + getAnimationHeight()  / 3 + getSpeed())){

		      mySprite_->Move(ZERO,getSpeed());
		      setAnimationY(DOWN);
	      }
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

	tab[0] = (socle.x - ELEM_WIDTH/2) / ELEM_WIDTH;
	tab[1] = (socle.x + ELEM_WIDTH/2) / ELEM_WIDTH;
	tab[2] = (socle.y - ELEM_HEIGHT/2) / ELEM_HEIGHT;
	tab[3] = (socle.y + ELEM_HEIGHT/2) / ELEM_HEIGHT;

	return tab;
}

int* 
Entity::getSocle(int x, int y) const
{	
	int *tab = new int[4];

	tab[0] = x / ELEM_WIDTH;
	tab[1] = x / ELEM_WIDTH;
	tab[2] = y / ELEM_HEIGHT;
	tab[3] = y / ELEM_HEIGHT;
	
	//cout << " tab socle : "<< tab[0] << " " << tab[1] << " "  << tab[2] << " "  << tab[3] <<  endl;

	return tab;
}


void Entity::setMap(Map * map) {
   myMap_ = map;
}

Map * Entity::getMap() const {
   return myMap_;
}

int Entity::isMapChanged() {
   return map_changed;
}  

void Entity::setMapChanged(int x) {
   map_changed = x;
}

int Entity::getId() const {
   return id;
}

void Entity::setId(int x) {
   id = x;
}

bool Entity::getStuck() const {
   return is_stuck;
}

void Entity::setStuck(bool b) {
   is_stuck = b;
}
