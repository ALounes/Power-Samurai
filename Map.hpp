#ifndef MAP_HPP
#define MAP_HPP

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
  
  void map_create(int,int);
	//void Free_Map();
	void set_links(Map * map_1, Map * map_2, Map * map_3);
  
  sf::Image *image_map;
	sf::Sprite *sprite_map;
	
	int ** Vector_map;
      
   Map * link_map_1;
   Map * link_map_2;
   Map * link_map_3;
   
private:

   int * Hauteur;
   int * Largeur;

   
};


#endif 
