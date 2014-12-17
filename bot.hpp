#ifndef BOT_HPP
#define BOT_HPP

//#include <random>
#include "config.hpp"
#include "entity.hpp"
#include "player.hpp"

using namespace std;

class Bot: public Entity
{
	public :
	
	Bot(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name,
		 int life, int mana, enum power power, Map *myMap);
		
	~Bot();

	void move();
	
	void SetRange(int range);
	int GetRange();
	void SetSpeed(int speed);
	int GetSpeed();
	
	Player * player_;

	private:
	
	String &name_;
	int    life_;
	int    mana_;
	enum power power_;
	
	int range_;
	int speed_;
	
	
	
	
	//uniform_int_distribution<int> distribution(random_minimum,random_maximum);
	//defalut_random_engine generateur;
};

#endif
