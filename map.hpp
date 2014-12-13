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
	//void Free_Map();
	void set_links(Map *map_1, Map *map_2, Map *map_3);
	void set_image(Image img);
	void set_sprite(Sprite sprt);
	void set_tableau(int i, int j, int val);

   
   int getSocleMap(int i,int j) const;
   Map * getLink(int i) const;
   
   Image * getImage() const;  
   Sprite * getSprite() const;  
   
   Image *image_map_;
	Sprite *sprite_map_;  

private:

   

   int ** Vector_map_;

   Map * link_map_1_;
   Map * link_map_2_;
   Map * link_map_3_;


   int *Hauteur_;
   int *Largeur_;

   
};


#endif 
