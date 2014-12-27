#include "map.hpp"

Map::Map () 
{
   sprite_map_ = new Sprite();
   image_map_ = new Image();
   
   Hauteur_ = new int;
   Largeur_ = new int;
   
   x_link_1 = new int;
   y_link_1 = new int;
   
   x_link_2 = new int;
   y_link_2 = new int;
   
   x_link_3 = new int;
   y_link_3 = new int;
   music_ = new Music();
}

Map::~Map()
{
   for (int x=0; x < *Hauteur_; x++) {
    delete[] Vector_map_[x];
   }
   delete[] Vector_map_;

   cout << "Vector_map deleted" << endl;

   delete sprite_map_;
   delete image_map_;
   
   delete x_link_1;
   delete y_link_1;
   delete x_link_2;
   delete y_link_2;
   delete x_link_3;
   delete y_link_3;
   delete Hauteur_;
   delete Largeur_;
   music_->Stop();
   delete music_;
   
}
 
void 
Map::map_create(int hauteur, int largeur) 
{ 
  // Allocation dynamique du tableau Bitmap
  
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
   link_map_1_ = new Map();
   link_map_2_ = new Map();
   link_map_3_ = new Map();
   
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

int * Map::get_Hauteur() {
   return Hauteur_;
}

int * Map::get_Largeur() {
   return Largeur_;
}


Image * Map::getImage() const {
   return image_map_;
} 


Sprite * Map::getSprite() const {
   return sprite_map_;
}

void Map::set_tpPoints(int x1, int y1, int x2, int y2, int x3, int y3) {
   *x_link_1 = x1;
   *y_link_1 = y1;
   
   *x_link_2 = x2;
   *y_link_2 = y2;
   
   *x_link_3 = x3;
   *y_link_3 = y3;
}

int ** Map::getVector() {
   return Vector_map_;

}

int Map::get_tpPoints(int pos) {
   switch (pos) {
   
      case 0 : {
         
         return *x_link_1 * 32;
         break;
         }
      case 1 : {
         return *y_link_1 * 32;
         break;
         }
      case 2 : {
         //linkmap1
         return *x_link_2 * 32;
         break;
         }
      case 3 : {
         //linkmap2
         return *y_link_2 * 32;
         break;
        } 
      case 4 : {
         return *x_link_3 * 32;
         break;
      }
      case 5 : {
         return *y_link_3 * 32;
         break;
      }
      default :
      return -1;
         break;
   }
}

Music* Map::getMusic() const {
   return music_;
}


void Map::setMusic(string s) {
   music_->OpenFromFile(s);
   music_->SetLoop(true);
}
