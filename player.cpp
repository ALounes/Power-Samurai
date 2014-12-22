#include "player.hpp"


Player::Player(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name,
					int life, int mana, enum power power, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
,name_(name)
,life_(life)
,mana_(mana)
,lifeMax_(PLAYER_LIFE_MAX)
,manaMax_(PLAYER_MANA_MAX)
,power_(power)
{
	play();
}

Player::~Player()
{

}

void
Player::actionKey(Map * map)
{  
   cout << "xperso : " << getPosition().x << "yperso :" << getPosition().y << endl;
	const sf::Input &input = win_->GetInput();
	int compteur_deplacement = 0;
	
	if ( input.IsKeyDown(Key::D)) {
	  compteur_deplacement +=1;
	}
	if ( input.IsKeyDown(Key::Q)) {
	  compteur_deplacement -=1;
	}
	if ( input.IsKeyDown(Key::S)) {
	  compteur_deplacement +=3;
	}
	if ( input.IsKeyDown(Key::Z)) {
	  compteur_deplacement -=3;
	}
	
	switch (compteur_deplacement) 
	{
	  case 1 :
	  {
		runMove();
		moveRight();
		current_direction = 0;
		  break;
	  }
	  case -1 :
	  {
		runMove();
		moveLeft();
		current_direction = 4;
		  break;
	  }
	  case 3 :
	  {
		runMove();
		moveDown();
		current_direction = 2;
		  break;
	  }
	  case -3 :
	  {
		runMove();
		moveUp();
		current_direction = 6;
		  break;
	  }
	  case 2 :
	  {
		runMove();
		moveDownLeft();
		current_direction = 4;
		  break;
	  }
	  case 4 :
	  {
		runMove();
		moveDownRight();
		current_direction = 0;
		  break;
	  }
	  case -2 :
	  {
		runMove();
		moveUpRight();
		current_direction = 0;
		  break;
	  }
	  case -4 :
	  {
		runMove();
		moveUpLeft();
		current_direction = 4;
		  break;
	  }
	  default :
	    break;
	}

}

void 
Player::update()
{
	if (isMoving())
	{
		updateSprite();
		animationRight();
		stopMove();
	}
}

String 
Player::getName() const
{
	return name_;
}

int 
Player::getLife() const
{
	return life_;
}

int 
Player::getMana() const
{
	return mana_;
}

void 
Player::setName(String name)
{
	name_ = name;
}

void 
Player::setLife(int life)
{
	life_ = life;
}

void 
Player::setMana(int mana)
{
	mana_ = mana;
}

void 
Player::lifePenalty(int penalty)
{
	life_ -= penalty;

	if(life_ < ZERO)
	{
		life_ = ZERO;
	}
}

void 
Player::lifeGain(int gain)
{
 	life_ += gain;

	if(life_ > lifeMax_)
	{
		life_ = lifeMax_;
	}
}

void 
Player::manaPenalty(int penalty)
{
	mana_ -= penalty;

	if(mana_ < ZERO)
	{
		mana_ = ZERO;
	}
}

void 
Player::manaGain(int gain)
{
 	mana_ += gain;

	if(mana_ > manaMax_)
	{
		mana_ = manaMax_;
	}
}

bool 
Player::isAlive() const
{
	return (life_ > ZERO);
}

bool 
Player::haveMana() const
{
	return (mana_ > ZERO);
}


int  
Player::getLifeMax() const
{
	return lifeMax_;
}

int  
Player::getManaMax() const
{
	return manaMax_;
}

void  
Player::setLifeMax(int life)
{
	lifeMax_ = life;
}

void  
Player::setManaMax(int mana)
{
	manaMax_ = mana;
}


void 
Player::bonusLifeMax(int life)
{
	lifeMax_ += life;
}

void 
Player::bonusManaMac(int mana)
{
	manaMax_ += mana;
}

int Player::getCurrentDirection() {
   return current_direction;
}

void Player::setCurrentDirection(int x) {
   current_direction = x;
}
