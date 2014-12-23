#ifndef HP_ITEM_HPP
#define HP_ITEM_HPP

#include "stdafx.hpp"
#include "map.hpp"
 
class Item 
{
   
   public :
   
   Item(RenderWindow *win, Image* image, Map* map, int x, int y);

   void setLifeBonus(int);
	int getLifeBonus() const;
	
	void setMapRef(Map*);
	Map *getMapRef() const;
	
	void setX(int x);
	int getX() const;
	
	void setY(int y);
	int getY() const;
	
	void setIsShown(bool);
	bool getIsShown() const;
	
	int getAnimationWidth() const ;

   int getAnimationHeight() const ;
	
	Vector2f getCenter() const;
	
	
   Sprite *mySprite_;
   

   private :
   bool isShown = true;
   int x_;
   int y_;

   int life_;
   
   RenderWindow *window_;
   Image *image_;
   Map *map_ref;
   //Sprite *mySprite_;


};

#endif
