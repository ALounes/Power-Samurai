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

	int getSocleMap(int i,int j) const;
  
	Image *image_map;
	Sprite *sprite_map;
	

	int ** Vector_map;
      
   
   int getSocleMap(int i,int j) const;
   Map * getLink(int i) const;

private:

   Map * link_map_1;
   Map * link_map_2;
   Map * link_map_3;


   int *Hauteur;
   int *Largeur;

   
};


#endif 
