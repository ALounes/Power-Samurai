#include "game.hpp"

#define GAME_WIDTH  1024
#define GAME_HEIGHT 768

#define PLAYING_WIDTH 800
#define PLAYING_HEIGHT 600

#define VIEW_WIDTH 400
#define VIEW_HEIGHT 300



#define PLAYER_X_START 25
#define PLAYER_Y_START 23

#define MAP_1_HEIGHT 27
#define MAP_1_WIDTH 31

#define MAP_2_HEIGHT 47
#define MAP_2_WIDTH 47

#define MAP_3_HEIGHT 47
#define MAP_3_WIDTH 47

#define MAP_4_HEIGHT 47
#define MAP_4_WIDTH 47

#define MAP_5_HEIGHT 29
#define MAP_5_WIDTH 30

#define FRAMERATE 30

#define RATE_FIRE 0.5

#define REFRESH_ITEM 60
#define SPELL_RATE 3


Image effect_003;
Image effect_003e;

Vector2i anim(1,DOWN);
bool moving = false;


int pos_x ,pos_y;




enum direction direction_prec;

Game::Game ()
{
   cout << "CONSTRUCTEUR game()" << endl;
  mainMenu_ = new MainMenu;

  gameState_ = new GameState;
  *gameState_ = Uninitialized;
  
  
  // On crée une fenêtre et on la centre sur l'écran.
  mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Power Samurai!!!", Style::Close);
  mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

  map_1 = new Map();
  map_2 = new Map();
  map_3 = new Map();
  map_4 = new Map();
  map_5 = new Map();
  
   map_courante = new Map();
   player_choice = new p_choice;
   image_joueur = new Image;
   image_projectile = new Image();
   image_hp_item = new Image();
   image_mana_item = new Image();
  
   image_Armor1 = new Image();
   image_Devil1 = new Image();
	image_Dragon1 = new Image();
	image_Fantome1 = new Image();
	image_Fantome2 = new Image();
	image_Reaper1 = new Image();
	image_Squelette = new Image();
	image_Troll = new Image();
	//music_courante_ = new Music();
  
  cout << "game() terminé" << endl;
}


Game::~Game ()
{

   delete map_1;
   delete map_2;
   delete map_3;
   delete map_4;
   delete map_5;
  
   delete mainMenu_;
   delete gameState_;
   delete mainWindow_;
   delete player_choice;
   delete image_joueur;
   delete image_projectile;
   delete image_hp_item;
   delete image_mana_item;
   delete image_Armor1;
   delete image_Devil1;
   delete image_Dragon1;
	delete image_Fantome1;
	delete image_Fantome2;
	delete image_Reaper1;
	delete image_Squelette;
	delete image_Troll;
	//delete music_courante_;
  
}
void Game::Map_Load(void)
{
  cout << "Map_load()" << endl;
  // Creation map 1
  
  map_1->map_create(MAP_1_HEIGHT,MAP_1_WIDTH);
  // Comme nous ne pouvons pas initialiser facilement de tableau dynamique, nous avons recours à un tableau statique
  int staticmap_1[MAP_1_HEIGHT][MAP_1_WIDTH] = 
{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,0,0,0,0,1,1,1,0,0,2,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,0,2,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0},
  {0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0},
  {0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0},
  {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  for (int x = 0; x < MAP_1_HEIGHT; x++) {
    for (int y = 0; y < MAP_1_WIDTH; y++) {
      map_1->set_tableau(x, y, staticmap_1[x][y]);
    }
  }
   
  map_1->image_map_->LoadFromFile("images/Maps/Entree.png");
  map_1->sprite_map_->SetImage(*(map_1->image_map_));
  
  // On link la carte 1 à la carte 2. Le passage de la carte 1 à la 2 se fait via les cases "2"
  map_1->set_links(map_2,NULL,map_5);
  // On rentre alors les coordonnées d'arrivées dans la nouvelle carte (45,23)
  map_1->set_tpPoints(45,23,0,0,1,8);
  
  map_1->setMusic("Musique/Dungeon6.ogg");
   
	
	// Creation map 2
  
  map_2->map_create(MAP_2_HEIGHT,MAP_2_WIDTH);
  int staticmap_2[MAP_2_HEIGHT][MAP_2_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,2,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,1,1,0,1,1,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,0},
  {0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0},
  {0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0},
  {0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,1,0,0},
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,0,1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0},
  {0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0},
  {0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0},
  {0,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,0,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };
  
  for (int x=0; x < MAP_2_HEIGHT; x++) {
    for (int y=0; y < MAP_2_WIDTH; y++) {

      map_2->set_tableau(x, y, staticmap_2[x][y]);
    }
  }
  
   map_2->image_map_->LoadFromFile("images/Maps/R1.png");
	map_2->sprite_map_->SetImage(*(map_2->image_map_));
	
	map_2->set_links(map_3,map_1,NULL);
	map_2->set_tpPoints(3,37,8,14,0,0);
	map_2->setMusic("Musique/Battle3.ogg");
	
	// MAP 3
	
	map_3->map_create(MAP_3_HEIGHT,MAP_3_WIDTH);
	int staticmap_3[MAP_3_HEIGHT][MAP_3_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,2,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0},
  {0,1,1,1,1,1,0,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0},
  {0,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0},
  {0,0,0,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,0,0}, 
  {0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,0,0},
  {0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0}, 
  {0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,0},
  {0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0}, 
  {0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0},
  {0,0,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0}, 
  {0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0},
  {0,0,0,0,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };
  
  
	
   for (int x=0; x < MAP_3_HEIGHT; x++) {
    for (int y=0; y < MAP_3_WIDTH; y++) {

      map_3->set_tableau(x, y, staticmap_3[x][y]);
    }
  }
  
   map_3->image_map_->LoadFromFile("images/Maps/R2.png");
	map_3->sprite_map_->SetImage(*(map_3->image_map_));
	
	map_3->set_links(map_2,map_4,NULL);
	map_3->set_tpPoints(3,37,41,27,0,0);
	
	//MAP 4
	map_4->map_create(MAP_4_HEIGHT,MAP_4_WIDTH);
	int staticmap_4[MAP_4_HEIGHT][MAP_4_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0},
  {0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0},
  {0,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0},
  {0,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0,0},
  {0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0},
  {0,0,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0},
  {0,0,0,1,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,0},
  {0,0,0,1,1,1,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,1,1,1,1,1,0},
  {0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,1,1,1,1,0},
  {0,0,0,1,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0},
  {0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0},
  {0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,1,0,0,1,0,1,0},
  {0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0},
  {0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0},
  {0,1,1,1,0,1,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0},
  {0,0,1,1,0,1,1,0,0,1,1,1,0,1,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,0},
  {0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,1,0,1,1,1,1,0},
  {0,1,1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
  {0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  
  };
	for (int x=0; x < MAP_4_HEIGHT; x++) {
    for (int y=0; y < MAP_4_WIDTH; y++) {

      map_4->set_tableau(x, y, staticmap_4[x][y]);
    }
  }
  
   map_4->image_map_->LoadFromFile("images/Maps/R3.png");
	map_4->sprite_map_->SetImage(*(map_4->image_map_));
	
	map_4->set_links(map_3,NULL,NULL);
	map_4->set_tpPoints(41,25,0,0,0,0);
	
	// MAP 5
	
	map_5->map_create(MAP_5_HEIGHT,MAP_5_WIDTH);
	
	int staticmap_5[MAP_5_HEIGHT][MAP_5_WIDTH] = 
{ {0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
  {0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},
  {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  };
  
  for (int x=0; x < MAP_5_HEIGHT; x++) {
    for (int y=0; y < MAP_5_WIDTH; y++) {

      map_5->set_tableau(x, y, staticmap_5[x][y]);
    }
  }
  
   map_5->image_map_->LoadFromFile("images/Maps/Depart.png");
	map_5->sprite_map_->SetImage(*(map_5->image_map_));
	
	map_5->set_links(map_1,NULL,NULL);
	map_5->set_tpPoints(25,8,0,0,0,0);
	map_5->setMusic("Musique/Airship.ogg");
	
	cout << "Map chargées" << endl;
	
}

void Game::Start(void)
{
	if(*gameState_ != Uninitialized) {
	   cout << "Bug, jeu déjà initialisé" << endl;
		return;
	}
	
	*gameState_ = Game::ShowingSplash;
	

	while(!IsExiting())
	{
		GameLoop();
	}
   
	mainWindow_->Close();
	cout << "fermeture effectuee" << endl;
}

bool Game::IsExiting()
{
	if(*gameState_ == Game::Exiting) 
		return true;
	else 
		return false;
}

void Game::GameLoop()
{
	switch(*gameState_)
	{
	  case Game::ShowingSplash:
			{
				ShowSplashScreen();
				break;
			}
		case Game::ShowingMainMenu:
			{
				ShowMainMenu();
				break;
			}
		case Game::ShowingDifficultyMenu:
			{
			  difficultyMenu_ = new DifficultyMenu();
			  difficultyMenu_->Load(mainWindow_);
			  ShowDifficultyMenu();
           delete difficultyMenu_;
           break;
			}
			
		case Game::ShowingPlayersMenu:
			{
			  playersMenu_ = new PlayersMenu();
			  playersMenu_->Load(mainWindow_);
			  ShowPlayersMenu();
           delete playersMenu_;
			  break;
			}
			
		case Game::Playing:
			{
            delete mainMenu_;
            delete mainWindow_;  
            // On détruit et on recrée une nouvelle fenêtre aux dimensions du jeu.
            
            mainWindow_ = new RenderWindow(VideoMode(PLAYING_WIDTH, PLAYING_HEIGHT), "     Kill them all, and get the BOSS", Style::Close);
            mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - PLAYING_WIDTH)/2, (VideoMode::GetDesktopMode().Height - PLAYING_HEIGHT)/2);
            mainWindow_->Clear();
            
            RunGame();
            
            delete mainWindow_;
            mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), "  Power Samurai!!!",Style::Close);
            mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);
            mainMenu_ = new MainMenu();
				break;
			}
			default :
			{
				break;
			}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen *splashScreen_ = new SplashScreen();
	splashScreen_->Show(mainWindow_);
	
	*gameState_ = Game::ShowingMainMenu;
	
	delete splashScreen_;
}

void Game::ShowMainMenu()
{
   mainMenu_->Load(mainWindow_);
	MainMenu::MenuResult result = mainMenu_->Show(mainWindow_);
	switch(result)
	{
	case MainMenu::Exit:
			*gameState_ = Game::Exiting;
			cout << "result = Exit" << endl;
			
			break;
	case MainMenu::Play:
			*gameState_ = Game::Playing;
			break;
	case MainMenu::Difficulty:
			*gameState_ = Game::ShowingDifficultyMenu;
			
			break;
	case MainMenu::Players:
			*gameState_ = Game::ShowingPlayersMenu;
			break;
	default:
			break;	
	}
	
}

void Game::ShowDifficultyMenu()
{
  DifficultyMenu::DifficultyResult resultat = difficultyMenu_->Show(mainWindow_);

	switch(resultat)
	{
	case DifficultyMenu::Escape:
			*gameState_ = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Easy:
	      
	      ResultDifficulty = EASY_DIFFICULTY;          // Sauvegarde le niveau de difficulté
			*gameState_ = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Intermediate:
	      ResultDifficulty = INTERMEDIATE_DIFFICULTY;
			*gameState_ = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Hard:
	      ResultDifficulty = HARD_DIFFICULTY;
			*gameState_ = Game::ShowingMainMenu;

			break;
	default:    
	      ResultDifficulty = EASY_DIFFICULTY;
			break;	
	}
	
}

void Game::ShowPlayersMenu()
{
  mainWindow_->ShowMouseCursor(false);
  PlayersMenu::PlayersResult resultat = playersMenu_->Show(mainWindow_);
  
  while (resultat != PlayersMenu::Escape && resultat != PlayersMenu::Return) {
	  resultat = playersMenu_->Show(mainWindow_);
	}
	switch(resultat)
	 {
	 case PlayersMenu::Escape:
			*gameState_ = Game::ShowingMainMenu;	
			break;
	 case PlayersMenu::Return:
			*gameState_ = Game::ShowingMainMenu;			
			break;
	 default:    
			break;	
	 }
	 // Sauvegarde le choix du personnage
	 *player_choice = (p_choice) *(playersMenu_->getposition());

  mainWindow_->ShowMouseCursor(true);

}

void Game::RunGame()
{
   Timer_Projectile = new Clock();
   Timer_Spell = new Clock();
   Timer_Items = new Clock();
   mainWindow_->ShowMouseCursor(false);
	Event event;
	Clock time;
	Clock clock2;
	Vector2f position(mainWindow_->GetWidth()/2,mainWindow_->GetHeight()/2);
	Clock clock;
	
	map_courante = map_5;
	map_courante->getMusic()->Play();
	 	
 	// Suivant le résultat de PlayersMenu, on crée un personnage
 	setPlayer(mainWindow_);
 	
 	loadImages();
 	loadBot();
 	loadItem();
 	loadSpell();
	
	entitys = map_courante->Bot_list;
	items = map_courante->Item_list;
   
	camera = new Camera(mainWindow_,joueur);
	view = new View();

	// TEST STATUS BAR
	StatusBar statusbar(mainWindow_,joueur,camera);

	mainWindow_->Display();

   // Exécution de la boucle principale
   bool fin_de_boucle = false;
   const Input &input = mainWindow_->GetInput();
   while (mainWindow_->IsOpened() && !(fin_de_boucle) && *gameState_ == Playing)
   {
      effects = joueur->spells;
      mainWindow_->SetFramerateLimit(FRAMERATE);
      camera->setCameraXY(*(map_courante->get_Largeur()) * BASE_SPRITE,*(map_courante->get_Hauteur()) * BASE_SPRITE);
		mainWindow_->Draw(*(map_courante->sprite_map_));
			
      if (input.IsKeyDown(Key::Z) ||input.IsKeyDown(Key::Q) || input.IsKeyDown(Key::D) || input.IsKeyDown(Key::S)) {
   
				joueur->soclePosition();
				joueur->actionKey(map_courante);
				
				if (joueur->isMapChanged() != NOCHANGE) {
				   map_courante->getMusic()->Stop();
				   map_courante->Item_list = items;
				   map_courante->Bot_list = entitys;
				   map_courante = joueur->getMap();
				   joueur->setMapChanged(NOCHANGE);
				   entitys = map_courante->Bot_list;
				   items = map_courante->Item_list;
				   map_courante->getMusic()->Play();
				}

		}
		
		if ( input.IsKeyDown(Key::Space)) {
		   bool refresh = false;
	         if (Timer_Projectile->GetElapsedTime() > RATE_FIRE) 
	   	   refresh = true;

            if (refresh) {
        
                  Vector2i vfeux(4,4);

	               Projectile *projectile = new Projectile(mainWindow_,image_projectile ,vfeux,joueur,16,5);
	               projectile->setDirection( joueur->getCurrentDirection() );
	               projectile->preset();
		            projectiles.push_front(projectile);
		            Timer_Projectile->Reset();
		            joueur->getProjectileSound()->Play();
		         
		      }
      }
      
      if ( input.IsKeyDown(Key::E)) { 
            if ( joueur->timer1->GetElapsedTime() > joueur->spell_delay1 ) {
		         FolowingAnimation *effect1 = new FolowingAnimation(mainWindow_, *(joueur->Spell1), joueur->v_spell1, joueur);
               effect1->play();
               effect1->setId(1);
               effect1->setManaCost(30);               
               joueur->spells.push_front(effect1);              
            }
            
            for(auto s : joueur->spells){
               if (joueur->getMana() < s->getManaCost() || s->getId() != 1 || joueur->timer1->GetElapsedTime() <= joueur->spell_delay1)
               {
               }
               else {
                  joueur->manaPenalty(s->getManaCost());
                  for(auto s : entitys){
		               if(s->getDistance() < joueur->range1) {
		                  s->lifePenalty(joueur->dmg1);
	                     if (!s->isAlive())
	                     {
	                        entitys.remove(s);
	                        (map_courante->Bot_list).remove(s);
	                        delete s;
	                     }
		                  break; 
		               }
                  }
                  joueur->timer1->Reset();
               }
	         }
      }
      
      if ( input.IsKeyDown(Key::R)) { 
            if ( joueur->timer2->GetElapsedTime() > joueur->spell_delay2 ) {
		         FolowingAnimation *effect2 = new FolowingAnimation(mainWindow_, *(joueur->Spell2), joueur->v_spell2, joueur);
               effect2->play();
               effect2->setId(2);
               effect2->setManaCost(30);               
               joueur->spells.push_front(effect2);              
            }
            
            for(auto s : joueur->spells){
               if (joueur->getMana() < s->getManaCost() || s->getId() != 2 || joueur->timer2->GetElapsedTime() <= joueur->spell_delay2)
               {
               }
               else {
                  joueur->manaPenalty(s->getManaCost());
                  for(auto s : entitys){
		               if(s->getDistance() < joueur->range2) {
		                  s->lifePenalty(joueur->dmg2);
	                     if (!s->isAlive())
	                     {
	                        entitys.remove(s);
	                        (map_courante->Bot_list).remove(s);
	                        delete s;
	                     }
		                  break; 
		               }
                  }
                  joueur->timer2->Reset();
               }
	         }
      }
      
      if ( input.IsKeyDown(Key::T)) { 
            if ( joueur->timer3->GetElapsedTime() > joueur->spell_delay3 ) {
		         FolowingAnimation *effect3 = new FolowingAnimation(mainWindow_, *(joueur->Spell3), joueur->v_spell3, joueur);
               effect3->play();
               effect3->setId(3);
               effect3->setManaCost(30);               
               joueur->spells.push_front(effect3);              
            }
            
            for(auto s : joueur->spells){
               if (joueur->getMana() < s->getManaCost() || s->getId() != 3 || joueur->timer3->GetElapsedTime() <= joueur->spell_delay3)
               {
               }
               else {
                  joueur->manaPenalty(s->getManaCost());
                  for(auto s : entitys){
		               if(s->getDistance() < joueur->range3) {
		                  s->lifePenalty(joueur->dmg3);
	                     if (!s->isAlive())
	                     {
	                        entitys.remove(s);
	                        (map_courante->Bot_list).remove(s);
	                        delete s;
	                     }
		                  break; 
		               }
                  }
                  joueur->timer3->Reset();
               }
	         }
      }
      
      

      for(auto s : entitys){
         s->update_path(map_courante, joueur);
         s->setDistance( (s->GetPath()).size() );
         for (auto c : s->spells)
	      {
	         if(c->isPlaying()){
	         cout << ":( " << endl;
             c->run();
            }
            
            if (!c->isPlaying())
            {
               s->spells.remove(c); 
               delete c;
            }
            break;
	      }
         if (s->getDistance() > s->getRange() && !s->getPursuit())
         {  
            // Cas SURPLACE
         }
         else {
            s->inPursuit();
		      s->follow_path(map_courante, joueur);
		   }
	   }
	   
		while (mainWindow_->GetEvent(event) )
		{
		
			// Gestion des evenements 
		switch (event.Type)
		{
			case Event::Closed :
			   fin_de_boucle = true;
				*gameState_ = Game::ShowingMainMenu;
				break;


			case Event::KeyPressed :
				
				keyPressedManagement(event.Key.Code);

				break;

			default: 
				break;
		}
			
		}

		view->SetHalfSize(VIEW_WIDTH, VIEW_HEIGHT);
      
      
		camera->run();	

		// Mise a jour de la StatusBar et affichage
		
		statusbar.display();	
		
		// Mise a jours des sprites et affichage
		displayEntity(clock);
      //effect->run();
   	

		// Affichage du contenu de la fenêtre à l'écran
		mainWindow_->Display();

		// Efface le contenu de la fenetre 
		mainWindow_->Clear();
		joueur->getMovingSound()->Pause();
		if (!joueur->isAlive())
		{
		   map_courante->getMusic()->Stop();
		   cout << "Perso Mort" << endl;
		   launchingDeath();
		}
   
   }
   cout << "Sortie de boucle" << endl;
   mainWindow_->ShowMouseCursor(true);
   
joueur->getMovingSound()->Stop();
entitys = map_courante->Bot_list;
items = map_courante->Item_list;

while (!(map_1->Bot_list).empty()) { delete (map_1->Bot_list).back(); (map_1->Bot_list).pop_back(); }

while (!(map_2->Bot_list).empty()) { delete (map_2->Bot_list).back(); (map_2->Bot_list).pop_back(); }
while (!(map_3->Bot_list).empty()) { delete (map_3->Bot_list).back(); (map_3->Bot_list).pop_back(); }
while (!(map_4->Bot_list).empty()) { delete (map_4->Bot_list).back(); (map_4->Bot_list).pop_back(); }
while (!(map_5->Bot_list).empty()) { delete (map_5->Bot_list).back(); (map_5->Bot_list).pop_back(); }

entitys.clear();

while (!(map_1->Item_list).empty()) { delete (map_1->Item_list).back(); (map_1->Item_list).pop_back(); }
while (!(map_2->Item_list).empty()) { delete (map_2->Item_list).back(); (map_2->Item_list).pop_back(); }
while (!(map_3->Item_list).empty()) { delete (map_3->Item_list).back(); (map_3->Item_list).pop_back(); }
while (!(map_4->Item_list).empty()) { delete (map_4->Item_list).back(); (map_4->Item_list).pop_back(); }
while (!(map_5->Item_list).empty()) { delete (map_5->Item_list).back(); (map_5->Item_list).pop_back(); }


while (!effects.empty()) { delete effects.back(); effects.pop_back(); }


while (!projectiles.empty()) { delete projectiles.back(); projectiles.pop_back(); }

	delete view;

	delete camera;

	delete joueur;

	delete Timer_Projectile;

	delete Timer_Items;

   delete Timer_Spell;
}

/*void
Game::eventManagement(Event &event)
{
	switch (event.Type)
	{
		case Event::Closed :
			mainWindow_->Close();
			break;

		case Event::KeyPressed :
			keyPressedManagement(event.Key.Code);
			break;

		default:
			break;
	}
}*/

void 
Game::keyPressedManagement (Key::Code keyPressed)
{

  switch (keyPressed) {
      case  Key::O : 
      { //HP
        joueur->consumeHpPot();
   
        break;
      }
   
      case  Key::P : 
      { //MANA
         joueur->consumeManaPot();
         
         break;
      }
  
      case  Key::Escape :
      {
         launchingPause();
		
	    	break;
	   }
      case  Key::Space : 
      {
		
		   break;
      }
      
		default: 
			break;
  }
	
}

void 
Game::addEntity(Bot *entity)
{
	entitys.push_back(entity);
}

void 
Game::removeEntity(Bot *entity)
{
	entitys.remove(entity);
}

void 
Game::displayEntity(Clock &time)
{
	bool refresh = false;

	if (time.GetElapsedTime() > ENTITY_FPS_RATE) 
		refresh = true;
		
	if (!joueur->isAlive())
	{
	   *gameState_ = ShowingMainMenu;
	   return;
	}
	
   // Gestion de l'affichage du joueur
   if (refresh && joueur->isPlaying()) {
      joueur->update();
   }
   joueur->draw();
   
   if(refresh)
		time.Reset();
     
   // Gestion de l'affichage des Bot 
   for(auto s : entitys){

	   if(refresh ){
		   s->update();
	   }
	   
	   s->draw();
   }
   // Gestion des effets
   for(auto s : effects){
      if(s->isPlaying()){
      s->run();
      }
   }
   //time.Reset();
   
   for(auto s : items){
      refresh = false;

	   if (s->getTimer()->GetElapsedTime() > REFRESH_ITEM ) 
		   refresh = true;
   
      if ( s->getIsShown()  && joueur->getCenter().x < s->getCenter().x + s->getAnimationWidth() && joueur->getCenter().x > s->getCenter().x - s->getAnimationWidth() && joueur->getCenter().y < s->getCenter().y + s->getAnimationHeight() && joueur->getCenter().y > s->getCenter().y - s->getAnimationHeight())
      {
            cout << "Contact item" << endl;
            s->setIsShown(false);
            s->resetTimer(); 
            if (s->getIt() == Item::HP)
            {
               cout << "add" << endl;
               joueur->increaseNbHpPot();
            }
            if (s->getIt() == Item::MANA)
            {
               joueur->increaseNbManaPot();
            }
            
            
      }
      if (s->getIsShown())
      {
         mainWindow_->Draw(*(s->mySprite_));
      }
      if (refresh) {
         s->setIsShown(true);
         s->resetTimer();
         
      }

   }

   
   for(auto s : projectiles){
      
	   if ( !s->getStuck())
	      {

	      s->update();
	      s->draw();
	   }
	   else {
	      projectiles.remove(s);
	      delete s;
		   break;
	   }
	   for(auto c : entitys){


         if ( s->getCenter().x < c->getCenter().x + c->getAnimationWidth() && s->getCenter().x > c->getCenter().x - c->getAnimationWidth() && s->getCenter().y < c->getCenter().y + c->getAnimationHeight() && s->getCenter().y > c->getCenter().y - c->getAnimationHeight())
         {
            
            cout << "Bot touché" << endl;
            // Pour éviter la triche, quand un monstre est touché par un projectile, il se met en poursuite, quelque soit sa distance.
            c->inPursuit();
            projectiles.remove(s);
	         delete s ;
	         c->lifePenalty(joueur->getAttackDamage());
	         if (!c->isAlive())
	         {
	            entitys.remove(c);
               (map_courante->Bot_list).remove(c);
					// TEST ANIMATION
					//Image *dieImage_  = new Image();
					//dieImage_->LoadFromFile("images/Sprite_bot/DieImage.png");
					//AnimationEffect *dieAnimation_ = new AnimationEffect(mainWindow_, *dieImage_, Vector2i(4,4),c);
					//dieAnimation_->play();
					//dieAnimation_->run();

			      delete c;
					
	         }
	         
		      return;
         }
      }
   }
}


void 
Game::addEffect(AnimationEffect *effect)
{
	effects.push_back(effect);
}

void 
Game::removeEffect(AnimationEffect *effect)
{
	effects.remove(effect);
}

void 
Game::displayEffect(Clock &time)
{
	// a faire
}


void Game::setPlayer(RenderWindow  * mainwin) {
   entitys.clear();
   switch(*player_choice) {
      case P1 : 

      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P1.png"))
		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante,100);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P2 : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P2.png"))
		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante,200);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P3 : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P3.png"))
		      cout << "erreur " << endl ; 
        joueur = new BjarneStroustrup(mainwin,*image_joueur,map_courante,300);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P4 : 

      {

        if(!image_joueur->LoadFromFile("Sprites/Personnages/P4.png"))

		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,250);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      default : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P1.png"))
		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,150);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }

   }
   joueur->setId(0);
}


void Game::launchingPause() {
   bool Ispause = true;
   
   Shape grey_screen   = Shape::Rectangle(0,0,PLAYING_WIDTH,PLAYING_HEIGHT,Color(0,0,0));
   grey_screen.SetPosition(camera->position_->x - PLAYING_WIDTH /2, camera->position_->y - PLAYING_HEIGHT /2);
   
	String texte = String ("               Le jeu est en pause.\n\n(P) : Continuer    (Q) : Menu principal", Font::GetDefaultFont(), 40.f);

	texte.SetPosition( camera->position_->x - 320, camera->position_->y - 100);
	texte.SetStyle(11);
	texte.SetColor(Color::White);

   mainWindow_->Draw(grey_screen);
   mainWindow_->Draw(texte);
   mainWindow_->Display();
   while (Ispause == true) {

     Event event2;
     
     while (mainWindow_->GetEvent(event2))
		{
			// Gestion des evenements 
		switch (event2.Type)
		{
			case Event::KeyPressed :
     
            switch (event2.Key.Code) {
               case  Key::Escape :
                  Ispause = false;
		            break;
               case  Key::P :
                  Ispause = false;
		
	               break; 
               case  Key::Q :
                  *gameState_ = ShowingMainMenu;
                  Ispause = false;
		
	        	      break;
	            default :
	               break;
	         }
	         
	         break;
	      default :
	         break;
	   }
    }
   }
}

void Game::launchingDeath() {
   Clock death_timer;
   Image game_over;
   Sprite s_over;
   String texte;
  
   Music gameover;
   if(!gameover.OpenFromFile("Musique/Gameover2.ogg"))
      cout << "erreur " << endl ;
   gameover.Play();
   
   if(!game_over.LoadFromFile("images/Gameover/Gameover.png"))
      cout << "erreur " << endl ;
   s_over.SetImage(game_over);
   s_over.SetPosition( camera->position_->x - PLAYING_WIDTH/2, camera->position_->y - PLAYING_HEIGHT/2);
   
   mainWindow_->Clear();
   
   Event event2;
   bool inboucle = true;
     
     while ((mainWindow_->GetEvent(event2) || death_timer.GetElapsedTime() <= 18) && inboucle == true)
		{
	   texte = String (to_string (18 - (int) death_timer.GetElapsedTime() ), Font::GetDefaultFont(), 40.f);
      texte.SetStyle(11);
	   texte.SetColor(Color::White);
	   texte.SetPosition(camera->position_->x - 30, camera->position_->y + PLAYING_HEIGHT /4);
      mainWindow_->Draw(s_over);
      mainWindow_->Draw(texte);
      mainWindow_->Display(); 
		switch (event2.Type)
		{
			case Event::KeyPressed :
     
            switch (event2.Key.Code) {
               case  Key::Escape : {
                  *gameState_ = ShowingMainMenu;
                  inboucle = false;
		            break;
               }
	            default :
	               break;
	         }
	         
	         break;
	      default :
	         break;
	   }
    }
   gameover.Stop();
   
   //while () {
      
   //}
   
   
}

void Game::loadBot() {

   // MAP 1

  loadReaper1(map_1, -1, 10, 7, 3);

  loadTroll(map_1, -1, 20, 20,20);
  
  // MAP 2
  
  // MAP 5
  loadArmor1(map_5, -5, 10, 2, 5);
  loadArmor1(map_5, -5, 3, 20, 8);
  
  loadDragon(map_5, -1, 10, 6, 24);
   
  loadTroll(map_5, -2, 10, 12,17);
  loadTroll(map_5, -3, 9, 25,15);
  loadTroll(map_5, -4, 8, 10,9);
}


void Game::loadItem() {
   // MAP 5
   loadHP(28,17, map_5);
   loadHP(17,26, map_5);
   loadHP(9,8, map_5);
   loadMana(27,4, map_5);
   loadMana(3,9, map_5);
   
   // MAP 1
   loadHP(7,3, map_1);
   loadMana(9,3, map_1);
   
   // MAP 2   
   loadHP(2,24, map_2);
   loadHP(10,3, map_2);
   loadHP(40,24, map_2);
   loadMana(6,14, map_2);
   loadMana(30,25, map_2);
   loadMana(29,40, map_2);  
   
   // MAP 3
   loadHP(21,35, map_3);
   loadHP(10,3, map_3);
   loadHP(24,3, map_3);
   loadHP(20,19, map_3);
   
   loadMana(45,24, map_3);
   loadMana(22,3, map_3);
   loadMana(22,9, map_3);
   
   // MAP 4
   loadHP(21,27, map_4);
   loadHP(11,3, map_4);
   loadHP(1,20, map_4);
   loadHP(1,35, map_4);
   loadHP(40,28, map_4);
   loadHP(37,3, map_4);
   
   loadMana(25,27, map_4);
   loadMana(1,21, map_4);
   loadMana(15,29, map_4);
   loadMana(44,24, map_4);
   loadMana(39,3, map_4);
   loadMana(31,3, map_4);
}    

void Game::loadSpell() {
         Vector2i test_effect(5,6);
         if (!effect_003.LoadFromFile("Sprites/Sorts/Special15.png"))
		      cout << "erreur " << endl ;
		   FolowingAnimation *effect = new FolowingAnimation(mainWindow_, effect_003, test_effect, joueur);
		   effect->setManaCost(30);
} 

void Game::loadImages() {
   if (!image_hp_item->LoadFromFile("Sprites/Items/hp.png"))
		      cout << "erreur " << endl ;
	if (!image_mana_item->LoadFromFile("Sprites/Items/mana.png"))
		      cout << "erreur " << endl ;	      
   if (!image_Armor1->LoadFromFile("Sprites/Ennemis/Armor1.png"))
		      cout << "erreur " << endl ;      
   if (!image_Devil1->LoadFromFile("Sprites/Ennemis/Devil1.png"))
		      cout << "erreur " << endl ;	      
   if (!image_Dragon1->LoadFromFile("Sprites/Ennemis/Dragon1.png"))
		      cout << "erreur " << endl ;
   if (!image_Fantome1->LoadFromFile("Sprites/Ennemis/Fantome1.png"))
		      cout << "erreur " << endl ;
   if (!image_Reaper1->LoadFromFile("Sprites/Ennemis/Reaper1.png"))
		      cout << "erreur " << endl ;
   if (!image_Squelette->LoadFromFile("Sprites/Ennemis/Squelette.png"))
		      cout << "erreur " << endl ;	      
   if (!image_Troll->LoadFromFile("Sprites/Ennemis/Troll.png"))
		      cout << "erreur " << endl ;
   if (!image_Fantome2->LoadFromFile("Sprites/Ennemis/Fantome2.png"))
		      cout << "erreur " << endl ;
   if (!image_projectile->LoadFromFile("Sprites/Projectiles/Fire1.png"))
		      cout << "erreur " << endl ;
}
     
     
     
void Game::loadHP(int coordx, int coordy, Map *map) {
   Item *hp = new Item(mainWindow_,image_hp_item,map, coordx, coordy, Item::HP);
     (map->Item_list).push_front(hp);
}

void Game::loadMana(int coordx, int coordy, Map *map) {
   Item *mana = new Item(mainWindow_,image_mana_item,map, coordx, coordy, Item::MANA);
     (map->Item_list).push_front(mana);
}

void Game::loadDragon(Map *map, int id, int range, int coordx, int coordy) { 
   GreenDragon *bot = new GreenDragon(mainWindow_,*image_Dragon1,map,id,range);
   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));
   (map->Bot_list).push_front(bot);
}

void Game::loadTroll(Map *map, int id, int range, int coordx, int coordy) {
   Troll *bot = new Troll(mainWindow_,*image_Troll,map,id,range);
   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));
   (map->Bot_list).push_front(bot);
}

void Game::loadArmor1(Map *map, int id, int range, int coordx, int coordy) {
   Armor1 *bot = new Armor1(mainWindow_,*image_Armor1,map,id,range);
   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));
   (map->Bot_list).push_front(bot);
}

void Game::loadReaper1(Map *map, int id, int range, int coordx, int coordy) {
   Reaper1 *bot = new Reaper1(mainWindow_,*image_Reaper1,map,id,range);
   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));
   (map->Bot_list).push_front(bot);
}
