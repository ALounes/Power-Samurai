#ifndef HP_ITEM_HPP
#define HP_ITEM_HPP

#include "stdafx.hpp"
#include "map.hpp"
 
class Item 
{
   
   public :
   
   enum item_type {HP,MANA};
   
   Item(RenderWindow *win, Image* image, Map* map, int x, int y, Item::item_type it);
 
   /*void setLifeBonus(int);
	int getLifeBonus() const;*/
	
	void setMapRef(Map*);
	Map *getMapRef() const;
	
	void setX(int x);
	int getX() const;
	
	void setY(int y);
	int getY() const;
	
	void setIt(item_type y);
	item_type getIt() const;
	
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
   item_type it_;

   
   
   RenderWindow *window_;
   Image *image_;
   Map *map_ref;
   //Sprite *mySprite_;


};

#endif
