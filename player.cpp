#include "player.hpp"


Player::Player(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name,
					int life, int mana, enum power power, Map *myMap, float att_dmg)
:LivingEntity(win,image,nbrOfAnim,myMap)
{
   // On construit le joueur
   
   setName(name);
   setLife(life);
   setLifeMax(life);
   setMana(mana);
   setManaMax(mana);
   setAttackDamage(att_dmg);
   
   portrait_ = new Image();
   sprt_ = new Sprite();
	play();
   movingSoundB_ = new SoundBuffer();
   movingSound_ = new Sound();
   setMovingSoundB("Musique/Move.ogg");
   movingSound_->SetPitch(2);
   movingSound_->SetVolume(60);
   movingSound_->SetLoop(true);
   
   projectileSoundB_ = new SoundBuffer;
   projectileSound_ = new Sound;
   setProjectileSoundB("Musique/Fireball.ogg");
   projectileSound_->SetPitch(2);
   projectileSound_->SetVolume(100);
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
   //Gère le déplacement ainsi que la gestion du son des pas.
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
	   getMovingSound()->Play();
	}
	if (compteur_deplacement == 0)
	{
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

