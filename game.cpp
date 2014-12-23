#include "game.hpp"

#define GAME_WIDTH  1024
#define GAME_HEIGHT 768

#define PLAYING_WIDTH 800
#define PLAYING_HEIGHT 600

#define VIEW_WIDTH 400
#define VIEW_HEIGHT 300



#define PLAYER_X_START 8
#define PLAYER_Y_START 25

#define MAP_1_HEIGHT 27
#define MAP_1_WIDTH 31

#define MAP_2_HEIGHT 47
#define MAP_2_WIDTH 47

#define MAP_3_HEIGHT 47
#define MAP_3_WIDTH 47

#define FRAMERATE 30

#define RATE_FIRE 0.2




Image effect_003;

Vector2i anim(1,DOWN);
bool moving = false;


int pos_x ,pos_y;
SoundBuffer buffer_son;
Sound son;



enum direction direction_prec;

Game::Game ()
{
   cout << "CONSTRUCTEUR game()" << endl;
  mainMenu_ = new MainMenu;

  gameState_ = new GameState;
  *gameState_ = Uninitialized;
  
  
  // On crée une fenêtre et on la centre sur l'écran.
  mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Power Samurai!!!");
  mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

  map_1 = new Map();
  map_2 = new Map();
  map_3 = new Map();
  map_4 = new Map();
  map_courante = new Map();
  player_choice = new p_choice;
  image_joueur = new Image;
  image_bot_linus = new Image();
  image_bot_blonde = new Image();
  image_projectile = new Image();
  image_hp_item = new Image();
  image_mana_item = new Image();
  
  cout << "game() terminé" << endl;
}


Game::~Game ()
{

  delete map_1;
  delete map_2;
  //delete map_3;
  //delete map_4;
  
  delete mainMenu_;
  delete gameState_;
  delete mainWindow_;
  delete player_choice;
  delete image_joueur;
  delete image_bot_linus;
  delete image_bot_blonde;
  delete image_projectile;
  delete image_hp_item;
  delete image_mana_item;
  
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
  {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,3,3,1,0,0,0,0,0,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,1,1,1,1,1,3,3,3,3,1,1,1,0,1,1,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,1,1,1,1,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  for (int x = 0; x < MAP_1_HEIGHT; x++) {
    for (int y = 0; y < MAP_1_WIDTH; y++) {
      map_1->set_tableau(x, y, staticmap_1[x][y]);
    }
  }
   
  map_1->image_map_->LoadFromFile("images/Maps/map.png");
  map_1->sprite_map_->SetImage(*(map_1->image_map_));
  
  // On link la carte 1 à la carte 2. Le passage de la carte 1 à la 2 se fait via les cases "2"
  map_1->set_links(map_2,NULL,NULL);
  // On rentre alors les coordonnées d'arrivées dans la nouvelle carte (45,23)
  map_1->set_tpPoints(45,23,0,0,0,0);
  
   
	
	// Creation map 2
  
  map_2->map_create(MAP_2_HEIGHT,MAP_2_WIDTH);
  int staticmap_2[MAP_2_HEIGHT][MAP_2_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,2,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0,0,0,1,1,0,1,1,0},
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
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0},
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
	map_2->set_tpPoints(4,36,8,14,0,0);
	// MAP 3
	
	map_3->map_create(MAP_3_HEIGHT,MAP_3_WIDTH);
	int staticmap_3[MAP_3_HEIGHT][MAP_3_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,2,1,1,0,1,1,1,1,1,1,0},
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
  {0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0}, 
  {0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,0,1,1,1,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0},
  {0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0},
  {0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0},
  {0,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,0}, 
  {0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0},
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
	
	map_3->set_links(map_2,NULL,NULL);
	map_3->set_tpPoints(3,37,0,0,0,0);
	
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
			  map_courante = map_1;
        cout << "Showingsplash" << endl;
				ShowSplashScreen();
				break;
			}
		case Game::ShowingMainMenu:
			{
			  cout << "MainMenu" << endl;
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
            
            mainWindow_ = new RenderWindow(VideoMode(PLAYING_WIDTH, PLAYING_HEIGHT), "     Kill them all, and get the BOSS");
            mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - PLAYING_WIDTH)/2, (VideoMode::GetDesktopMode().Height - PLAYING_HEIGHT)/2);
            mainWindow_->Clear();
            
            cout << "Rungame()" << endl;
            
            RunGame();
            
            delete mainWindow_;
           
            mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), "  Power Samurai!!!");
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
	  cout << "cas échap" << endl;
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
   Timer_Items = new Clock();
   mainWindow_->ShowMouseCursor(false);
	Event event;
	Clock time;
	Clock clock2;
	Vector2f position(mainWindow_->GetWidth()/2,mainWindow_->GetHeight()/2);
	Clock clock;
	//Vector2i test_effect(5,8);
	
	if (!buffer_son.LoadFromFile("Musique/BinB.ogg"))
		cout << "erreur " << endl ;

	if (!effect_003.LoadFromFile("sprite/effect_010.png"))
		cout << "erreur " << endl ;

	son.SetBuffer(buffer_son);
	son.SetLoop(true);
 	//son.Play();	
 	
 	// Suivant le résultat de PlayersMenu, on crée un personnage
 	setPlayer(mainWindow_);
 	
 	loadBot();
 	loadItem();
 	cout << "Bots chargés" << endl;
	
	entitys = map_courante->Bot_list;
	items = map_courante->Item_list;
	
	cout << "entitys initialisée" << endl;     
   
   
	camera = new Camera(mainWindow_,joueur);
	view = new View();

	mainWindow_->Display();

   // Exécution de la boucle principale
   bool fin_de_boucle = false;
   const Input &input = mainWindow_->GetInput();
   while (mainWindow_->IsOpened() && !(fin_de_boucle) && *gameState_ == Playing)
   {
      mainWindow_->SetFramerateLimit(FRAMERATE);
      camera->setCameraXY(*(map_courante->get_Largeur()) * BASE_SPRITE,*(map_courante->get_Hauteur()) * BASE_SPRITE);
		mainWindow_->Draw(*(map_courante->sprite_map_));
			
      if (input.IsKeyDown(Key::Z) ||input.IsKeyDown(Key::Q) || input.IsKeyDown(Key::D) || input.IsKeyDown(Key::S)) {
   
				joueur->soclePosition();
				joueur->actionKey(map_courante);
				
				if (joueur->isMapChanged() != NOCHANGE) {
				   map_courante->Item_list = items;
				   map_courante->Bot_list = entitys;
				   map_courante = joueur->getMap();
				   joueur->setMapChanged(NOCHANGE);
				   entitys = map_courante->Bot_list;
				   items = map_courante->Item_list;
				}

		}
		
		if ( input.IsKeyDown(Key::Space)) {
		   
		
		   bool refresh = false;

	         if (Timer_Projectile->GetElapsedTime() > RATE_FIRE) 
	   	   refresh = true;

            if (refresh) {
        
               Vector2i vfeux(4,4);
	            if (!image_projectile->LoadFromFile("sprite/feux2.png"))
		            cout << "erreur " << endl ;
	               Projectile *projectile = new Projectile(mainWindow_,image_projectile ,vfeux,joueur,16,5);
	               projectile->setDirection( joueur->getCurrentDirection() );
	               projectile->preset();
		            projectiles.push_front(projectile);
		            Timer_Projectile->Reset();
		         
		      }
      }
      
      if ( input.IsKeyDown(Key::E)) {
         for(auto s : effects){
            s->play();
	      }
      }

      for(auto s : entitys){
         s->update_path(map_courante, joueur);
         s->setDistance( (s->GetPath()).size() );
         
         if (s->getDistance() > s->getRange())
         {  
            // Cas SURPLACE
         }
         else {
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

		
		// Mise a jours des sprites et affichage
		displayEntity(clock);
      //effect->run();
   	

		// Affichage du contenu de la fenêtre à l'écran
		mainWindow_->Display();

		// Efface le contenu de la fenetre 
		mainWindow_->Clear();
   
   }
   cout << "Sortie de boucle" << endl;
   mainWindow_->ShowMouseCursor(true);

/*cout << "1" << endl;
for(auto s : entitys){
	entitys.remove(s);
   delete s ;
}
cout << "1" << endl;


for(auto s : (map_1->Bot_list)){
	(map_1->Bot_list).remove(s);
   delete s ;
}
for(auto s : (map_2->Bot_list)){
	(map_2->Bot_list).remove(s);
   delete s ;
}
for(auto s : (map_2->Bot_list)){
	(map_2->Bot_list).remove(s);
   delete s ;
}

for(auto s : effects){
	effects.remove(s);
   delete s ;
}

cout << "hihi" << endl;
for(auto s : projectiles){
	projectiles.remove(s);
   delete s ;
}*/
entitys.clear();
map_courante = map_1;
(map_1->Bot_list).clear();
(map_2->Bot_list).clear();
(map_3->Bot_list).clear();
effects.clear();
projectiles.clear();
delete view;
delete camera;
delete joueur;
delete Timer_Projectile;
delete Timer_Items;
}

void
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
}

void 
Game::keyPressedManagement (Key::Code keyPressed)
{

  switch (keyPressed) {
   case  Key::Escape :
      launchingPause();
		
	 	break;
   case  Key::Space : {
   
		
		break;
   }
   case  Key::E : {
      Vector2i test_effect(5,8);
      if (!effect_003.LoadFromFile("sprite/effect_010.png"))
		   cout << "erreur " << endl ;
      AnimationEffect *effect = new AnimationEffect(mainWindow_,effect_003,test_effect,joueur);
	   addEffect(effect);
	   
	   for(auto s : entitys){
		   if(s->getDistance() < 3) {
		      cout << "Dégats dans ta face" << endl;
		      
		      s->lifePenalty(400);
	         if (!s->isAlive())
	         {
	            entitys.remove(s);
	            delete s;
	         }
		      break;
		      
		   }
      }
	   
	   
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
   
	refresh = false;

	if (Timer_Items->GetElapsedTime() > 5) 
		refresh = true;
   
   for(auto s : items){
      if ( s->getIsShown()  && joueur->getCenter().x < s->getCenter().x + s->getAnimationWidth() && joueur->getCenter().x > s->getCenter().x - s->getAnimationWidth() && joueur->getCenter().y < s->getCenter().y + s->getAnimationHeight() && joueur->getCenter().y > s->getCenter().y - s->getAnimationHeight())
      {
            cout << "Contact item" << endl;
            s->setIsShown(false); 
      }
      if (s->getIsShown())
      {
         mainWindow_->Draw(*(s->mySprite_));
      }
      if (refresh) {
         s->setIsShown(true);
         
      }

   }
   if (refresh) {
         Timer_Items->Reset();
         
      }

   
   for(auto s : projectiles){
      
	   if ( !s->getStuck())
	      {

	      s->update();
	      s->draw();
	   }
	   else {
	      projectiles.remove(s);
	      delete s ;
		   break;
	   }
	   for(auto c : entitys){


         if ( s->getCenter().x < c->getCenter().x + c->getAnimationWidth() && s->getCenter().x > c->getCenter().x - c->getAnimationWidth() && s->getCenter().y < c->getCenter().y + c->getAnimationHeight() && s->getCenter().y > c->getCenter().y - c->getAnimationHeight())
         {
            
            cout << "Bot touché" << endl;
            projectiles.remove(s);
	         delete s ;
	         c->lifePenalty(joueur->getAttackDamage());
	         if (!c->isAlive())
	         {
	            entitys.remove(c);
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
        if(!image_joueur->LoadFromFile("sprite/blonde.png"))

		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante,100);
        //mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }
      
      case P2 : 
      {
        if(!image_joueur->LoadFromFile("sprite/fartas.png"))
		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante,200);
        //mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P3 : 
      {
        if(!image_joueur->LoadFromFile("sprite/gris.png"))
		      cout << "erreur " << endl ; 
        joueur = new BjarneStroustrup(mainwin,*image_joueur,map_courante,300);
        //mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P4 : 

      {

        if(!image_joueur->LoadFromFile("sprite/LinusTorvalds.png"))

		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,250);
        //mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      default : 
      {
        if(!image_joueur->LoadFromFile("sprite/LinusTorvalds.png"))
		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,150);
        //mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }

   }
   joueur->setId(0);
}


void Game::launchingPause() {
   bool Ispause = true;
   
   Shape grey_screen   = Shape::Rectangle(0,0,GAME_WIDTH,GAME_HEIGHT,Color(0,0,0));
   grey_screen.SetPosition(camera->position_->x - 600, camera->position_->y - 400);
   
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

void Game::loadBot() {

   // MAP 1

      // BOT 1
      
      
	if(!image_bot_linus->LoadFromFile("sprite/LinusTorvalds.png"))
		cout << "erreur " << endl ;
	Bot *bot = new Bot(mainWindow_,*image_bot_linus,Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), String("Linus Torvalds"), LINUS_TORVALDS_LIFE, LINUS_TORVALDS_MANA, LINUS_TORVALDS_POWER,map_1,100,0.5,ResultDifficulty * 1, -1,10);
	bot->setPosition(Vector2f(BASE_SPRITE*7,BASE_SPRITE*3));	
	bot->update_path(map_courante,joueur);	
  (map_1->Bot_list).push_front(bot);
  
      
  
      // BOT 2
	if(!image_bot_blonde->LoadFromFile("sprite/blonde.png"))
		cout << "erreur " << endl ;
	Bot *bot2 = new Bot(mainWindow_,*image_bot_blonde,Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), String("Linus Torvalds"), LINUS_TORVALDS_LIFE, LINUS_TORVALDS_MANA, LINUS_TORVALDS_POWER,map_1,100,0.5,ResultDifficulty * 2,-2,10);
	bot2->setPosition(Vector2f(BASE_SPRITE*20,BASE_SPRITE*20));	
	bot2->update_path(map_courante,joueur);
  (map_1->Bot_list).push_front(bot2);
  
  // MAP 2
  
	Bot *bot3 = new Bot(mainWindow_,*image_bot_linus,Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), String("Linus Torvalds"), LINUS_TORVALDS_LIFE, LINUS_TORVALDS_MANA, LINUS_TORVALDS_POWER,map_2,100,0.5,ResultDifficulty * 1,-1,10);
	bot3->setPosition(Vector2f(BASE_SPRITE*7,BASE_SPRITE*3));	
	bot3->update_path(map_courante,joueur);
  (map_2->Bot_list).push_front(bot3);
  

}


void Game::loadItem() {

   if(!image_hp_item->LoadFromFile("sprite/hp.png"))
		   cout << "erreur " << endl ;
	Item *hp1 = new Item(mainWindow_,image_hp_item,map_1, 7, 3);
     (map_1->Item_list).push_front(hp1);
     
     
   if(!image_mana_item->LoadFromFile("sprite/mana.png"))
		   cout << "erreur " << endl ;
	Item *mana1 = new Item(mainWindow_,image_mana_item,map_1, 9, 3);
     (map_1->Item_list).push_front(mana1);
     
}     
     
     
