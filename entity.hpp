#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "animation.hpp"
#include "config.hpp"

class Entity : public Animation
{
	public :

	enum direction {DOWN = 0, LEFT, RIGHT, UP};

	Entity(RenderWindow *win, Image& image, Vector2i nbrOfAnim);
	~Entity();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void moveUpLeft();
	void moveUpRight();
	void moveDownLeft();
	void moveDownRight();

	virtual bool legalDeplacement(int x, int y) const;
	virtual void setDefaultSprite();

	int  getSpeed() const;
	void setSpeed(int speed);

	private:
	int moveSpeed_;
};

#endif
