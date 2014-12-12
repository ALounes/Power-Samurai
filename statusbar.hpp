#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "config.hpp"

class StatusBar
{
public:
	StatusBar(RenderWindow *win, Entity *entity);
	~StatusBar();  

	void display () const;
	void playLifeEffect(Entity *entity);
	void playManaEffect(Entity *entity);
  
private:
	RenderWindow *win_;
	Entity *entity_;
	Sprite mySprite_;
	Image  myImage_;
	Shape statu_bar;
};	

#endif 
