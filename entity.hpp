#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "animation.hpp"
#include "config.hpp"
#include "map.hpp"
#include "animationeffect.hpp"
#include <list>


#define ELEM_HEIGHT 32
#define ELEM_WIDTH 32

class AnimationEffect;
class Entity : public Animation
{
	public :

	enum direction {DOWN = 0, LEFT, RIGHT, UP, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT};
	
	//enum direction {RIGHT = 0, DOWNRIGHT, DOWN, DOWNLEFT, LEFT, UPLEFT, UP, UPRIGHT};

	Entity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap);
	virtual ~Entity();

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
	
	map_number isMapChanged();
	void setMapChanged(map_number);
	int getId() const;
	void setId(int);
	
	bool getStuck() const;
	void setStuck(bool);
	

	private:
	
	bool moving_;
	float moveSpeed_;
	Map  *myMap_;
	
	map_number map_changed = NOCHANGE;
	int id_;
	bool is_stuck = false;
	
};

#endif
