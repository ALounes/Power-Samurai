#include "player.hpp"


Player::Player(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name,
					int life, int mana, enum power power, Map *myMap, float att_dmg)
:LivingEntity(win,image,nbrOfAnim,myMap)
/*,name_(name)
,life_(life)
,mana_(mana)
,lifeMax_(life)
,manaMax_(mana)
,attack_damage(att_dmg)*/
{

   setName(name);
   setLife(life);
   setLifeMax(life);
   setMana(mana);
   setManaMax(mana);
   setAttackDamage(att_dmg);
   portrait_ = new Image();
   sprt_ = new Sprite();
	play();
   movingSoundB_ = new SoundBuffer;
   movingSound_ = new Sound;
   setMovingSoundB("Musique/Move.ogg");
   movingSound_->SetPitch(2);
   movingSound_->SetVolume(60);
   movingSound_->SetLoop(true);
   
   projectileSoundB_ = new SoundBuffer;
   projectileSound_ = new Sound;
   setProjectileSoundB("Musique/Blow7.ogg");
   projectileSound_->SetPitch(2);
   projectileSound_->SetVolume(60);
   projectileSound_->SetLoop(false);
}

Player::~Player()
{
	delete movingSoundB_;
   delete movingSound_;
   delete projectileSoundB_;
   delete projectileSound_;
   delete portrait_;
   delete sprt_;
   cout << "DESTRUCTEUR Player()" << endl;
}

void
Player::actionKey(Map * map)
{  
	const sf::Input &input = win_->GetInput();
	int compteur_deplacement = 0;
	
	if ( input.IsKeyDown(Key::D)) 
	{
	  compteur_deplacement +=1;
	}
	if ( input.IsKeyDown(Key::Q)) 
	{
	  compteur_deplacement -=1;
	}
	if ( input.IsKeyDown(Key::S)) 
	{
	  compteur_deplacement +=3;
	}
	if ( input.IsKeyDown(Key::Z)) 
	{
	  compteur_deplacement -=3;
	}
	
	switch (compteur_deplacement) 
	{
		case 1 :
			runMove();
			moveRight();
			current_direction = 0;
			break;

		case -1 :
			runMove();
			moveLeft();
			current_direction = 4;
			break;

		case 3 :
		runMove();
		moveDown();
		current_direction = 2;
		  break;

		case -3 :
			runMove();
			moveUp();
			current_direction = 6;
			break;

		case 2 :
			runMove();
			moveDownLeft();
			current_direction = 3;
			break;

		case 4 :
			runMove();
			moveDownRight();
			break;

		case -2 :
			runMove();
			moveUpRight();
			current_direction = 7;
			break;

		case -4 :
			runMove();
			moveUpLeft();
			current_direction = 5;
			break;

		default :
			break;
	}

	if (compteur_deplacement != 0 && 
		(getMovingSound()->GetStatus() == Sound::Stopped || 
		 getMovingSound()->GetStatus() == Sound::Paused) )
	{
	   cout << "SON joué" << endl;
	   getMovingSound()->Play();
	}
	if (compteur_deplacement == 0)
	{
	   cout<< "Pause" << endl;
	   getMovingSound()->Pause();
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

/*String 
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
Player::bonusManaMax(int mana)
{
	manaMax_ += mana;
}



void Player::setAttackDamage(float ad) 
{
   attack_damage = ad;
}

float Player::getAttackDamage() 
{
   return attack_damage;
}*/


int Player::getCurrentDirection() 
{
   return current_direction;
}

void Player::setCurrentDirection(int x) 
{
   current_direction = x;
}

int Player::getNbHP() const 
{
   return nb_Hp_Pot;
}

void Player::setNbHP(int h) 
{
   nb_Hp_Pot = h;
}
	
int Player::getNbMANA() const 
{
   return nb_Mana_Pot;
}

void Player::setNbMANA(int m) 
{
   nb_Mana_Pot = m;
}

void Player::increaseNbHpPot() 
{
   if (nb_Hp_Pot >= MAX_HP_POT)
   {
      nb_Hp_Pot = MAX_HP_POT;
   }
   else 
      ++nb_Hp_Pot;
}

void Player::increaseNbManaPot() 
{
   if (nb_Mana_Pot >= MAX_MANA_POT)
   {
      nb_Mana_Pot = MAX_MANA_POT;
   }
   else 
      ++nb_Mana_Pot;
}

void Player::consumeHpPot() 
{
   if (nb_Hp_Pot <= 0)
   {
      nb_Hp_Pot = 0;
   }
   else 
	{
      if (getLife() != getLifeMax())
      {
         --nb_Hp_Pot;
         lifeGain( (int) (HP_POT_PERCENTAGE * getLifeMax()) );
      }
      else 
		{
         // Ne rien faire, pas besoin de gaspiller de potions
      }
   }
}

void Player::consumeManaPot() 
{
   if (nb_Mana_Pot <= 0)
   {
      nb_Mana_Pot = 0;
   }
   else 
	{
      if (getMana() != getManaMax())
      {
			--nb_Mana_Pot;
			manaGain( (int) (MANA_POT_PERCENTAGE * getManaMax()) );
      }
      else 
		{
			// Ne rien faire, pas besoin de gaspiller de potions
      }
   }
}


SoundBuffer* Player::getMovingSoundB() const 
{ 
   return movingSoundB_;
}

void Player::setMovingSoundB(string s) 
{
	if (!movingSoundB_->LoadFromFile(s))
		cout << "erreur " << endl ;

   movingSound_->SetBuffer(*movingSoundB_);

}

Sound * Player::getMovingSound() const 
{
   return movingSound_;
}

SoundBuffer* Player::getProjectileSoundB() const 
{ 
   return projectileSoundB_;
}

void Player::setProjectileSoundB(string s)
{
	if (!projectileSoundB_->LoadFromFile(s))
		cout << "erreur " << endl ;

   projectileSound_->SetBuffer(*projectileSoundB_);
}

Sound * Player::getProjectileSound() const 
{
   return projectileSound_;
}
   
Sprite* Player::getSpritePortrait() const 
{
   return sprt_;
}

void Player::setImgSpritePortrait(string s) 
{
   if (!portrait_->LoadFromFile(s))
		      cout << "erreur " << endl ;

   sprt_->SetImage(*portrait_);
}
   
bool Player::getIsDamaged() const {
   return isDamaged_;
}
void Player::setIsDamaged(bool b) {
   isDamaged_ = b;
}

