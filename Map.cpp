#include "Map.hpp"

Map::Map () 
{
   cout << "Map()" << endl;
   sprite_map = new	sf::Sprite;
   image_map = new sf::Image;
   
   Hauteur = new int;
   Largeur = new int;
}

Map::~Map()
{
   for (int i=0; i < *Hauteur; i++) {
    delete[] Vector_map[i];
   }
   delete[] Vector_map;

   delete sprite_map;
   delete image_map;
   delete link_map_1;
   delete link_map_2;
   delete link_map_3;
}
 
void Map::map_create(int hauteur, int largeur) {

 
  // Allocation dynamique 
  
  *Hauteur = hauteur;
  *Largeur = largeur;
  
  Vector_map = new int * [hauteur];
  for (int i = 0; i < hauteur; i++) {
    Vector_map[i] = new int [largeur];
  }

}

void Map::set_links(Map * map_1, Map * map_2, Map * map_3) {

   link_map_1 = new Map;
   link_map_2 = new Map;
   link_map_3 = new Map;
   
   link_map_1 = map_1;
   link_map_2 = map_2;
   link_map_3 = map_3;
}
 
/*void Free_Map(){
 
  
}*/
