#ifndef MAP_HPP
#define MAP_HPP

#include "config.hpp"
#include "stdafx.hpp"
#include <list>

#define PROJECTILE -10
#define BOT3 -3
#define BOT2 -2
#define BOT1 -1
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

class Bot;
class Item;

class Map
{
public:

   Map ();
   ~Map ();
  
   //Allocation dynamique du tableau Bitmap et initialisation de ses dimensions
	void map_create(int hauteur, int largeur);
   // On mémorise en pointeur sur Map les cartes avec lesquelles nous pouvons interagir depuis cette map.
   void set_links(Map *map_1, Map *map_2, Map *map_3);
   // On paramétre les coordonées d'arrivée lorsque l'on passe d'une carte à l'autre.
   void set_tpPoints(int x1, int y1, int x2, int y2, int x3, int y3);
	void set_image(Image img);
	void set_sprite(Sprite sprt);
	// Assigne la valeur "val" à la case (i,j)  du tableau
	void set_tableau(int i, int j, int val);

   int * get_Hauteur();
   int * get_Largeur();
   int ** getVector();
   
   Music* getMusic() const;
   void setMusic(string s);
   
   // Suivant la valeur de i, renvoie le pointeur sur la (i+1)eme Map.
   Map* getLink(int i) const;
   
   // 0 < pos < 5. pos renvoie la valeur des coordonnées de téléportations (Exemple : pos = 0 => x_link_1)
   int  get_tpPoints(int pos);
   
   Image*  getImage() const;  
   Sprite* getSprite() const;
   
   // Renvoie la valeur du socle aux coordonnées (x,y)
   int getSocleMap(int x,int y) const;
   
   void setId(int id);
   int getId() const;

   Image  *image_map_;
	Sprite *sprite_map_; 
	
	list<Bot*> Bot_list;
	list<Item*> Item_list;

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
   Music* music_;
   int id_;

   
};


#endif 
