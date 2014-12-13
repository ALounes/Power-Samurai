#include "map.hpp"

Map::Map () 
{
   cout << "Map()" << endl;
   sprite_map_ = new	sf::Sprite;
   image_map_ = new sf::Image;
   
   Hauteur_ = new int;
   Largeur_ = new int;
}

Map::~Map()
{
   for (int x=0; x < *Hauteur_; x++) {
    delete[] Vector_map_[x];
   }
   delete[] Vector_map_;

   delete sprite_map_;
   delete image_map_;
   delete link_map_1_;
   delete link_map_2_;
   delete link_map_3_;
}
 
void 
Map::map_create(int hauteur, int largeur) 
{ 
  // Allocation dynamique 
  
  *Hauteur_ = hauteur;
  *Largeur_ = largeur;
  
  Vector_map_ = new int * [hauteur];
  for (int x = 0; x < hauteur; x++) {
    Vector_map_[x] = new int [largeur];
  }

}

void 
Map::set_links(Map * map_1, Map * map_2, Map * map_3) 
{
   link_map_1_ = new Map;
   link_map_2_ = new Map;
   link_map_3_ = new Map;
   
   link_map_1_ = map_1;
   link_map_2_ = map_2;
   link_map_3_ = map_3;
}
 
int Map::getSocleMap(int x,int y) const {
return Vector_map_[x][y];
}

Map* Map::getLink(int i) const {
   switch (i) {
      case 1 :
         {
            return link_map_1_;
            break;
         }
      case 2 :
         {
            return link_map_2_;
            break;
         }
      case 3 :
         {
            return link_map_3_;
            break;
         }
      default :
            return NULL;
         break;
   }
   
}

void Map::set_image(Image img) {
    *image_map_ = img;
}

void Map::set_sprite(Sprite sprt) {
    *sprite_map_ = sprt;

}

void Map::set_tableau(int x, int y, int val) {
   Vector_map_[x][y] = val;

}

Image * Map::getImage() const {
   return image_map_;
} 


Sprite * Map::getSprite() const {
   return sprite_map_;
}
