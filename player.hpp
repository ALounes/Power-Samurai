#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "config.hpp"

class Player : public Entity
{
	public :
	
	Player(RenderWindow *win, Image &image,const Vector2i nbrOfAnim, String name,
					int life, int mana, enum power power, Map *myMap);
	~Player();

	void actionKey(Map * map);

	String getName() const;
	int getLifeMax() const;
	int getManaMax() const;
	int getLife() const;
	int getMana() const;

	void setName(String name);
	void setLife(int life);
	void setMana(int mana);
	void setLifeMax(int life);
	void setManaMax(int mana);
	void bonusLifeMax(int life);
	void bonusManaMac(int mana);

	void lifePenalty(int penalty);
	void lifeGain(int gain);
	void manaPenalty(int penalty);
	void manaGain(int gain);
	bool isAlive()  const;
	bool haveMana() const;
	
	void update();

	private:
	
	String &name_;
	int life_;
	int mana_;
	int lifeMax_;
	int manaMax_;
	enum power power_;

};

#endif
