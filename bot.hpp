#ifndef BOT_HPP
#define BOT_HPP

//#include <random>
#include "config.hpp"
#include "entity.hpp"

using namespace std;

class Bot: public Entity
{
	public :
	
	Bot(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name,
		 int life, int mana, enum power power, Map *myMap);
	~Bot();

	void move();

	private:
	
	String &name_;
	int    life_;
	int    mana_;
	enum power power_;
	//uniform_int_distribution<int> distribution(random_minimum,random_maximum);
	//defalut_random_engine generateur;
};

#endif
