#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "livingentity.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"


#define HP_POT_PERCENTAGE 0.4
#define MANA_POT_PERCENTAGE 0.4
#define MAX_HP_POT 5
#define MAX_MANA_POT 5

class Player : public LivingEntity
{
	public :
	
	Player(RenderWindow *win, Image &image,const Vector2i nbrOfAnim, String name,
					int life, int mana, enum power power, Map *myMap, float att_dmg);
	~Player();

	void actionKey(Map * map);
	
	int getNbHP() const;
	void setNbHP(int);
	
	int getNbMANA() const;
	void setNbMANA(int);
	
	void increaseNbHpPot();
	void increaseNbManaPot();
	void consumeHpPot();
	void consumeManaPot();
	
	void update();
	
	int getCurrentDirection();
	void setCurrentDirection(int);
	
	
	
	SoundBuffer * getMovingSoundB() const;
	void setMovingSoundB(string s);
	Sound * getMovingSound() const;
	
	SoundBuffer * getProjectileSoundB() const;
	void setProjectileSoundB(string s);
	Sound * getProjectileSound() const;
	
	Sprite* getSpritePortrait() const;
	void setImgSpritePortrait(string s);
	
	bool getIsDamaged() const;
	void setIsDamaged(bool);
	
	private:
	
	int current_direction;
	int nb_Hp_Pot = 0;
	int nb_Mana_Pot = 0;
	
	bool isDamaged_ = false;
	
	Image* portrait_;
	Sprite* sprt_;
	
	SoundBuffer * movingSoundB_;
	Sound * movingSound_;
	
	SoundBuffer * projectileSoundB_;
	Sound * projectileSound_;
	
};

#endif
