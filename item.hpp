#ifndef HP_ITEM_HPP
#define HP_ITEM_HPP

#include "stdafx.hpp"
#include "map.hpp"
 
 
 
class Item 
{
   
   public :
   
   // Dans l'état actuel des choses, nous n'avons que deux sortes d'items, mais nous pouvons parfaitement en implémenter d'autres
   enum item_type {HP,MANA};
   
   Item(RenderWindow *win, Image* image, Map* map, int x, int y, Item::item_type it);
   ~Item();
	
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
	
	Clock * getTimer() const ;
   void resetTimer() ;
	
	
   Sprite *mySprite_;
   

   private :
   bool isShown = true;    // Un item est toujours présent. Seul son affichage diffère. Ce membre permet donc d'avoir le status de l'item
   int x_;        // Coordonées d'apparition de l'item
   int y_;
   item_type it_;    // Caractérisation de l'item (HP, MANA, etc)

   
   
   RenderWindow *window_;
   Image *image_;
   Map *map_ref;
   Clock *Timer_Item;      // Chaque item a un timer, permettant la réapparition de l'item après un certain temps.


};

#endif
