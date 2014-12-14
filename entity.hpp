#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "animation.hpp"
#include "config.hpp"
#include "map.hpp"

class Entity : public Animation
{
	public :

	enum direction {DOWN = 0, LEFT, RIGHT, UP};

	Entity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap);
	~Entity();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void moveUpLeft();
	void moveUpRight();
	void moveDownLeft();
	void moveDownRight();

	virtual bool legalDeplacement(int x, int y);
	virtual void setDefaultSprite();
	virtual void update();

	virtual void play();
	virtual void pause();
	
	void setMap(Map * map);
   Map * getMap() const;
   
	void runMove();
	void stopMove();
	bool isMoving() const;

	int  getSpeed() const;
	void setSpeed(int speed);

	int* soclePosition() const;
	int* getSocle(int x, int y) const;

	private:
	
	bool moving_;
	int  moveSpeed_;
	Map  *myMap_;
};

#endif
