#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"
#include "stdafx.hpp"

#define DECOR 0 
#define VIDE 1
#define LINK_MAP_1 2 
#define LINK_MAP_2 3
#define LINK_MAP_3 4
#define ITEM_HP 10
#define ITEM_MANA 11
#define WEAPON_1 20
#define WEAPON_2 21
#define WEAPON_3 22

class Map
{
public:

   Map ();
   ~Map ();
  
	 void map_create(int hauteur, int largeur);
	 void set_links(Map *map_1, Map *map_2, Map *map_3);
	 void set_tpPoints(int x1, int y1, int x2, int y2, int x3, int y3);
	 void set_image(Image img);
	 void set_sprite(Sprite sprt);
	 void set_tableau(int i, int j, int val);

   int * get_Hauteur();
   int * get_Largeur();
   Map* getLink(int i) const;
   int  get_tpPoints(int pos);
   Image*  getImage() const;  
   Sprite* getSprite() const;
   int getSocleMap(int x,int y) const;
   int ** getVector();

   Image  *image_map_;
	 Sprite *sprite_map_;  

private:

   

   int ** Vector_map_;

   Map * link_map_1_;
   Map * link_map_2_;
   Map * link_map_3_;
   
   int * x_link_1;
   int * y_link_1;
   
   int * x_link_2;
   int * y_link_2;
   
   int * x_link_3;
   int * y_link_3;


   int *Hauteur_;
   int *Largeur_;

   
};


#endif 
