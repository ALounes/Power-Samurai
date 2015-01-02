#ifndef LIVING_ENTITY_HPP
#define LIVING_ENTITY_HPP

#include "entity.hpp"
#include "animationeffect.hpp"
#include <list>

class LivingEntity : public Entity
{
	public :

	LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap);
	virtual ~LivingEntity();
	
	Clock * getTimer(int) const;
	void setTimer(int i, Clock* t);
	
	float getSpellDelay(int) const;
	void setSpellDelay(int i, float sd);
	
	Image* getImgSpell(int) const;
	void setImgSpell(int i, Image*);
	
	int getSRange(int) const;
	void setSRange(int i, int r);
	
	float getDmg(int) const;
	void setDmg(int i, float d);
	
	float getSManaCost(int) const;
	void setSManaCost(int i, float mc);
	
	Vector2i getVSpell(int) const;
	void setVSpell(int, Vector2i v);
	
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

   //Pour les gains/pertes de mana, on vérifie que l'on est bien dans les bornes.
	void lifePenalty(int penalty);
	void lifeGain(int gain);
	void manaPenalty(int penalty);
	void manaGain(int gain);
	bool isAlive()  const;
	bool haveMana() const;
	
	void setAttackDamage(float);
	float getAttackDamage();
   
   list<AnimationEffect*> spells;      //Sorts lancés par l'entité
	list<AnimationEffect*> appliedeffects; // Sorts appliqués à l'entité
	
	
	
	private:
	
	String name_;
	int life_;  //Vie de l'entité
	int mana_;  //Mana
	int lifeMax_;  //Vie Max
	int manaMax_;  //Mana Max
	enum power power_;
	float attack_damage; //Dégats
	
	Clock * timer1_;  //Timers associés aux sorts
	Clock * timer2_;
	Clock * timer3_;
	
	float spell_delay1_; //Cooldown des sorts
	float spell_delay2_;
   float spell_delay3_;	
	
	
	int range1_;      //Portée des sorts
	int range2_;
	int range3_;
	float dmg1_;     //Dégats des sorts
	float dmg2_;
	float dmg3_;
	Vector2i v_spell1_;  //Vecteurs du nombre de sous sprites dans les images
	Vector2i v_spell2_;
	Vector2i v_spell3_;
	float mana_cost1_;   //Cout en mana des sorts
	float mana_cost2_;
	float mana_cost3_;
	
	Image* Spell1_;   //Image du premier sort
   Image* Spell2_;   //Image du second sort
	Image* Spell3_;   //Image du troisième sort
	
};

#endif
