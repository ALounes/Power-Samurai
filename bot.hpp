#ifndef BOT_HPP
#define BOT_HPP

//#include <random>
#include "config.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "animationeffect.hpp"

#define DEFAULT_RANGE 10



using namespace std;



class Bot: public Entity
{
	public :
	
	Bot(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name, int life, int mana, enum power power, Map *myMap, float att_dmg, float att_delay, float ResultDiff, int ident, int rangebot, int xp);
		
	~Bot();

	void move();
	
	void SetRange(int range);
	int GetRange() const;
	void SetSpeed(int speed);
	int GetSpeed() const;
	
	void SetPlayer(Player * player);
	Player * GetPlayer() const;
	
	string GetPath() const ;
	
	string pathFind( const int & xStart, const int & yStart, const int & xFinish, const int & yFinish, Map * map_);
	
	void update_path(Map * map,Player * player);
	
	void follow_path(Map *map, Player * player);
	
	void update();
	
	void setRange(int);
	int getRange();
	
	void setDistance(int);
	int getDistance();
	
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
	
   void setAttackDelay(float);
	float getAttackDelay();
	
	void setAttackDamage(float);
	float getAttackDamage();
	
	void setXp(int);
	int getXp() const;

	private:
	
	string path;
	Player * player_;
	
	int range_ = DEFAULT_RANGE;
	int speed_;
	int distance;
	
	String &name_;
	int life_;
	int mana_;
	int lifeMax_;
	int manaMax_;
	enum power power_;
	int current_direction;
	float attack_damage_;
	
	float attack_delay;
	Clock * timer;
	int xp_;
	
	//uniform_int_distribution<int> distribution(random_minimum,random_maximum);
	//defalut_random_engine generateur;
};

#endif
