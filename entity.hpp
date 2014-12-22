#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "animation.hpp"
#include "config.hpp"
#include "map.hpp"

#define ELEM_HEIGHT 32
#define ELEM_WIDTH 32

class Entity : public Animation
{
	public :

	enum direction {DOWN = 0, LEFT, RIGHT, UP, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT};

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

	float  getSpeed() const;
	void setSpeed(float speed);

	int* soclePosition() const;
	int* getSocle(int x, int y) const;
	
	int isMapChanged();
	void setMapChanged(int);
	int getId() const;
	void setId(int);
	
	bool getStuck() const;
	void setStuck(bool);
	
	

	private:
	
	bool moving_;
	float moveSpeed_;
	Map  *myMap_;
	
	int map_changed = 0;
	int id;
	bool is_stuck = false;
};

#endif
