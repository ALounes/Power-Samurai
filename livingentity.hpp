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
	
	int getSpellDelay(int) const;
	void setSpellDelay(int i, int sd);
	
	Image* getImgSpell(int) const;
	void setImgSpell(int i, string s);
	
	int getSRange(int) const;
	void setSRange(int i, int r);
	
	int getDmg(int) const;
	void setDmg(int i, int d);
	
	int getSManaCost(int) const;
	void setSManaCost(int i, int mc);
	
	Vector2i getVSpell(int) const;
	void setVSpell(int, Vector2i v);
   
   list<AnimationEffect*> spells;
	list<AnimationEffect*> appliedeffects;
	
	
	
	private:
	
	Clock * timer1_;
	Clock * timer2_;
	Clock * timer3_;
	
	int spell_delay1_;
	int spell_delay2_;
   int spell_delay3_;	
	
	
	int range1_;
	int range2_;
	int range3_;
	int dmg1_;
	int dmg2_;
	int dmg3_;
	Vector2i v_spell1_;
	Vector2i v_spell2_;
	Vector2i v_spell3_;
	int mana_cost1_;
	int mana_cost2_;
	int mana_cost3_;
	
	Image* Spell1_;
   Image* Spell2_;
	Image* Spell3_;
	
};

#endif
