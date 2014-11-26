#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "config.hpp"

class Player : public Entity
{
	public :
	
	Player(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name, int moveSpeed, int life, int mana, enum power power);
	~Player();

	void move(Key::Code keyPressed);

	private:
	
	String &name_;
	int    life_;
	int    mana_;
	enum power power_;
};

#endif
