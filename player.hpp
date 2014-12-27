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

	String getName() const;
	void setName(String name);
	
	int getLifeMax() const;
	int getManaMax() const;
	int getLife() const;
	int getMana() const;

	void setLife(int life);
	void setMana(int mana);
	void setLifeMax(int life);
	void setManaMax(int mana);
	void bonusLifeMax(int life);
	void bonusManaMax(int mana);

	void lifePenalty(int penalty);
	void lifeGain(int gain);
	void manaPenalty(int penalty);
	void manaGain(int gain);
	bool isAlive()  const;
	bool haveMana() const;
	
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
	
	void setAttackDamage(float);
	float getAttackDamage();
	//void createSpell1();
	//void createSpell2();
	//void createSpell3();
	
	int range1;
	int range2;
	int range3;
	int dmg1;
	int dmg2;
	int dmg3;
	int spell_delay1;
	int spell_delay2;
   int spell_delay3;
   Clock * timer1;
	Clock * timer2;
	Clock * timer3;
	
	Image* Spell1;
	Image* Spell2;
	Image* Spell3;
	
	Vector2i v_spell1;
	Vector2i v_spell2;
	Vector2i v_spell3;
	
	

	private:
	
	String name_;
	int life_;
	int mana_;
	int lifeMax_;
	int manaMax_;
	enum power power_;
	int current_direction;
	float attack_damage;
	int nb_Hp_Pot = 0;
	int nb_Mana_Pot = 0;
	

};

#endif
