/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*******************************************************************/

#include "item.hpp"

Item::Item(RenderWindow *win, Image* image, Map* map, int x, int y, Item::item_type it) :
   x_(x),
   y_(y),
   it_(it),
   window_(win),
   image_(image),
   map_ref(map)
 {
   mySprite_ = new Sprite();
	mySprite_->SetImage(*image_);
	mySprite_->SetPosition(BASE_SPRITE * x_, BASE_SPRITE * y_);
	Timer_Item = new Clock();
}

Item::~Item() {
   delete mySprite_;
   delete Timer_Item;
}

void 
Item::setMapRef(Map* map) 
{
   map_ref = map;
}
Map* 
Item::getMapRef() const 
{
   return map_ref;
}

Vector2f 
Item::getCenter() const
{
	Vector2f new_position , position = mySprite_->GetPosition();
	
	new_position.x = position.x + getAnimationWidth()  / 2; 
	new_position.y = position.y + getAnimationHeight() / 2;
	
	return new_position;
}

int 
Item::getAnimationWidth() const 
{
   return image_->GetWidth();
}

int 
Item::getAnimationHeight() const 
{
   return image_->GetHeight();
}

void 
Item::setIsShown(bool b) 
{
   isShown = b;
}

bool 
Item::getIsShown() const 
{
   return isShown;
}


void 
Item::setX(int x) 
{
   x_ = x;
}

int 
Item::getX() const 
{
   return x_;
}

void 
Item::setY(int y) 
{
   y_ = y;
}

int 
Item::getY() const 
{
   return y_;
}

void 
Item::setIt(Item::item_type y) 
{
   it_ = y;
}

Item::item_type 
Item::getIt() const 
{
   return it_;
}


Clock * 
Item::getTimer() const 
{
   return Timer_Item;
}

void 
Item::resetTimer() 
{
   Timer_Item->Reset();
}


