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

	void lifePenalty(int penalty);
	void lifeGain(int gain);
	void manaPenalty(int penalty);
	void manaGain(int gain);
	bool isAlive()  const;
	bool haveMana() const;
	
	void setAttackDamage(float);
	float getAttackDamage();
   
   list<AnimationEffect*> spells;
	list<AnimationEffect*> appliedeffects;
	
	
	
	private:
	
	String name_;
	int life_;
	int mana_;
	int lifeMax_;
	int manaMax_;
	enum power power_;
	float attack_damage;
	
	Clock * timer1_;
	Clock * timer2_;
	Clock * timer3_;
	
	float spell_delay1_;
	float spell_delay2_;
   float spell_delay3_;	
	
	
	int range1_;
	int range2_;
	int range3_;
	float dmg1_;
	float dmg2_;
	float dmg3_;
	Vector2i v_spell1_;
	Vector2i v_spell2_;
	Vector2i v_spell3_;
	float mana_cost1_;
	float mana_cost2_;
	float mana_cost3_;
	
	Image* Spell1_;
   Image* Spell2_;
	Image* Spell3_;
	
};

#endif
