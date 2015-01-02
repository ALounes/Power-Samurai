#include "game.hpp"

//Image effect_003;
//Image effect_003e;

Vector2i anim(1,DOWN);
bool moving = false;


int pos_x ,pos_y;


enum direction direction_prec;

Game::Game ()
{
	mainMenu_ = new MainMenu;
	

	gameState_ = new GameState;
	*gameState_ = Uninitialized;
  
  
  // On crée une fenêtre et on la centre sur l'écran.
	mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), 
											 "Power Samurai!!!", 
											 Style::Close);

	mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2,
									 (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

	map_1 = new Map();
	map_2 = new Map();
	map_3 = new Map();
	map_4 = new Map();
	map_5 = new Map();
  
   player_choice = new p_choice;
   image_joueur  = new Image;
   image_projectile = new Image();
   image_hp_item    = new Image();
   image_mana_item  = new Image();
  
	image_degats = new Image();
	image_Death = new Image();
	image_death_joueur = new Image();
	Timer_Victory = new  Clock();
	
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
   
	delete image_degats;
	delete image_Death;
	delete image_death_joueur;
	delete Timer_Victory;
  
}
void Game::Map_Load(void)
{
  // Creation map 1
  
  map_1->map_create(MAP_1_HEIGHT,MAP_1_WIDTH);

  /* Comme nous ne pouvons pas initialiser facilement de
	 tableau dynamique, nous avons recours à un tableau statique */

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

	for (int x = 0; x < MAP_1_HEIGHT; x++) 
	{
		for (int y = 0; y < MAP_1_WIDTH; y++) {
			map_1->set_tableau(x, y, staticmap_1[x][y]);
		}
	}
   
  map_1->image_map_->LoadFromFile("images/Maps/Entree.png");
  map_1->sprite_map_->SetImage(*(map_1->image_map_));
  
  /* On link la carte 1 à la carte 2. Le passage de 
		la carte 1 à la 2 se fait via les cases "2" */

  map_1->set_links(map_2,NULL,map_5);

  /* On rentre alors les coordonnées d'arrivées 
		dans la nouvelle carte (45,23) */

  map_1->set_tpPoints(45,23,0,0,1,8);
  
  map_1->setMusic("Musique/Dungeon6.ogg");
  map_1->setId(2);      // numéro de carte dans le jeu
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
	map_2->setId(3);
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
  
  
	
   for (int x=0; x < MAP_3_HEIGHT; x++) 
	{
		for (int y=0; y < MAP_3_WIDTH; y++) 
		{
		map_3->set_tableau(x, y, staticmap_3[x][y]);
		}
	}
  
   map_3->image_map_->LoadFromFile("images/Maps/R2.png");
	map_3->sprite_map_->SetImage(*(map_3->image_map_));
	
	map_3->set_links(map_2,map_4,NULL);
	map_3->set_tpPoints(3,37,41,27,0,0);
	map_3->setId(4);
	
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

	for (int x=0; x < MAP_4_HEIGHT; x++) 
	{
		for (int y=0; y < MAP_4_WIDTH; y++) 
		{
		map_4->set_tableau(x, y, staticmap_4[x][y]);
		}
	}
  
   map_4->image_map_->LoadFromFile("images/Maps/R3.png");
	map_4->sprite_map_->SetImage(*(map_4->image_map_));
	
	map_4->set_links(map_3,NULL,NULL);
	map_4->set_tpPoints(41,25,0,0,0,0);
	map_4->setId(5);
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
  
	for (int x=0; x < MAP_5_HEIGHT; x++) 
	{
		for (int y=0; y < MAP_5_WIDTH; y++) 
		{
			map_5->set_tableau(x, y, staticmap_5[x][y]);
		}
	}
  
   map_5->image_map_->LoadFromFile("images/Maps/Depart.png");
	map_5->sprite_map_->SetImage(*(map_5->image_map_));
	
	map_5->set_links(map_1,NULL,NULL);
	map_5->set_tpPoints(25,8,0,0,0,0);
	map_5->setMusic("Musique/Airship.ogg");
	map_5->setId(1);
}

void Game::Start(void)
{
   // On lance la boucle de jeu
	if(*gameState_ != Uninitialized) 
	{
	   cout << "Bug, jeu déjà initialisé" << endl;
		return;
	}
	
	*gameState_ = Game::ShowingSplash;
	// Si le gamestate est égal à Exiting, on quitte et on ferme la fenêtre. Le jeu est terminé
	while(!IsExiting())
	{
		GameLoop();
	}
   
	mainWindow_->Close();
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
   // Suivant le résultat de GameState, on lance la fonction correspondante
	switch(*gameState_)
	{
	  case Game::ShowingSplash:
			{
				ShowSplashScreen();
				break;
			}
		case Game::ShowingMainMenu:
			{
            mainMenu_->getMusic()->Play();
            ShowMainMenu();
	         if (*gameState_ == Game::Exiting || *gameState_ == Game::Playing)
	         {
	            mainMenu_->getMusic()->Pause();
	         }
	         
				
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
            
            mainWindow_ = new RenderWindow(VideoMode(PLAYING_WIDTH,
														 PLAYING_HEIGHT), 
														 "     Kill them all, and get the BOSS",
														 Style::Close);

            mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - PLAYING_WIDTH)/2,
												 (VideoMode::GetDesktopMode().Height - PLAYING_HEIGHT)/2);

            mainWindow_->Clear();
            
            RunGame();
            
            delete mainWindow_;
            mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT),
														 "  Power Samurai!!!",Style::Close);

            mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2,
												 (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

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
	Music music_;
	music_.OpenFromFile("Musique/SplashScreen.ogg");
   music_.SetLoop(true);
   music_.Play();
	splashScreen_->Show(mainWindow_);
	music_.Stop();
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
	case MainMenu::Help: {
	      Image img_help;
         Sprite s_help;
         if(!img_help.LoadFromFile("images/MainMenu/Instructions.png"))
            cout << "erreur " << endl ;
         s_help.SetImage(img_help);
 
         mainWindow_->Draw(s_help);
         mainWindow_->Display();
         int Ishelp = true;
	      while (Ishelp == true) 
	      {
           Event event2;
           
           while (mainWindow_->GetEvent(event2))
		     {
			      // Gestion des evenements 
		         switch (event2.Type)
		         {
			         case Event::KeyPressed :
				         Ishelp = false;
	                  break;
	                  
	               default :
	                  break;
	            }
           }
        }
        *gameState_ = Game::ShowingMainMenu;
		  break;
   }
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
	Clock clock_regen;
	Vector2f position(mainWindow_->GetWidth()/2,mainWindow_->GetHeight()/2);
	Clock clock;
	
	map_courante = map_5;
	map_courante->getMusic()->Play();
	 	
 	// Suivant le résultat de PlayersMenu, on crée un personnage
 	setPlayer(mainWindow_);
 	
 	//loadImagesAnimation();
 	
 	loadImages();
 	loadBot();
 	loadItem();
 	//loadSpell();
	
	entitys = map_courante->Bot_list;
	items = map_courante->Item_list;
   
	camera = new Camera(mainWindow_,joueur);
	view = new View();

	// TEST STATUS BAR
	StatusBar statusbar(mainWindow_,joueur,camera);

	mainWindow_->Display();

   // Exécution de la boucle principale
   bool fin_de_boucle = false;
   int lancer_dialogue = 0;  // 0 : non traité
   
   const Input &input = mainWindow_->GetInput();
   
   while (mainWindow_->IsOpened() && !(fin_de_boucle) && *gameState_ == Playing)
   {
      
      if (clock_regen.GetElapsedTime() >= 1)
      {  // Regen de la vie et de la mana du joueur
         joueur->lifeGain( PERCENTAGE_REGENERATION * joueur->getLifeMax());
         joueur->manaGain( PERCENTAGE_REGENERATION * joueur->getManaMax());
         clock_regen.Reset();
      }
      
      // On actualise les sorts en cours ainsi que la caméra
      effects = joueur->spells;
      mainWindow_->SetFramerateLimit(FRAMERATE);
      camera->setCameraXY(*(map_courante->get_Largeur()) * BASE_SPRITE,
								  *(map_courante->get_Hauteur()) * BASE_SPRITE);
		mainWindow_->Draw(*(map_courante->sprite_map_));
			
		// Gestion des déplancements	
      if (input.IsKeyDown(Key::Z) ||
			 input.IsKeyDown(Key::Q) || 
			 input.IsKeyDown(Key::D) || 
			 input.IsKeyDown(Key::S)) 
		{   
			joueur->soclePosition();
			joueur->actionKey(map_courante);
				
			if (joueur->isMapChanged() != NOCHANGE) 
			{  // Gestion du changement de carte
			   
			   map_courante->getMusic()->Stop();
			   map_courante->Item_list = items;
			   map_courante->Bot_list = entitys;
			   map_courante = joueur->getMap();
			   joueur->setMapChanged(NOCHANGE);
			   entitys = map_courante->Bot_list;
			   items = map_courante->Item_list;
			   map_courante->getMusic()->Play();
			   
			   if (map_courante->getId() == 5)
			   {
			      //mainWindow_->Draw(*(map_courante->sprite_map_));
			      //displayEntity(clock);	
		         //statusbar.display();
		         //mainWindow_->Display();
			      lancer_dialogue = 4;
			   }
			}

		}
		
		if ( input.IsKeyDown(Key::Space)) 
		{ // Gestion des projectiles
		   bool refresh = false;
			if (Timer_Projectile->GetElapsedTime() > RATE_FIRE) 
			refresh = true;

			if (refresh) 
			{        
				Vector2i vfeux(4,4);
				Projectile *projectile = new Projectile(mainWindow_,
																	 image_projectile ,
																	 vfeux,
																	 joueur,
																	 16,
																	 05);

				projectile->setDirection( joueur->getCurrentDirection() );
				projectile->preset();
				projectiles.push_front(projectile);
				Timer_Projectile->Reset();
				joueur->getProjectileSound()->Play();		         
			}
      }
      
		if ( input.IsKeyDown(Key::E)) 
		{ // Gestion du sort 1
			if ( joueur->getTimer(1)->GetElapsedTime() > joueur->getSpellDelay(1) ) 
			{
				FolowingAnimation *effect1 = new FolowingAnimation(mainWindow_,
																				 *(joueur->getImgSpell(1)), 
																					joueur->getVSpell(1),
																					joueur);

            effect1->setSoundB("Musique/Blow7.ogg");
            effect1->getSound()->SetLoop(false);
	         effect1->getSound()->Play();
				effect1->play();
				effect1->setId(1);
				effect1->setManaCost(joueur->getSManaCost(1));               
				joueur->spells.push_front(effect1);              
			}
            
			for(auto s : joueur->spells)
			{
				if (joueur->getMana() <
					 s->getManaCost()  || 
					 s->getId() != 1   || 
					 joueur->getTimer(1)->GetElapsedTime() <= 
					 joueur->getSpellDelay(1))
				{
				}
				else 
				{
					joueur->manaPenalty(s->getManaCost());
					for(auto s : entitys)
					{
						if(s->getDistance() < joueur->getSRange(1)) 
						{
							s->lifePenalty(joueur->getDmg(1));
							launchBloodEffect(s);
							if (!s->isAlive())
							{
							   if (s->getId() == -30 )// Boss final)
							   {
							      game_victory = true;
							      Timer_Victory->Reset();
							   }
							   else {
							      launchDeathEffect(s);
							      upgrade();
								   randomDrop(s->getCenter().x, s->getCenter().y);
								}
								entitys.remove(s);
								(map_courante->Bot_list).remove(s);
								delete s;
								break;
							}
		                   
		               }
                  }
                  joueur->getTimer(1)->Reset();
               }
	         }
      }
      
		if ( input.IsKeyDown(Key::R)) 
		{ // Gestion du sort 2
			if (joueur->getTimer(2)->GetElapsedTime() >
				joueur->getSpellDelay(2) ) 
			{
				FolowingAnimation *effect2 = new FolowingAnimation(mainWindow_,
																				 *(joueur->getImgSpell(2)), 
																					joueur->getVSpell(2), 
																					joueur);
            effect2->setSoundB("Musique/Magic6.ogg");
            effect2->getSound()->SetLoop(false);
	         effect2->getSound()->Play();
				effect2->play();
				effect2->setId(2);
				effect2->setManaCost(joueur->getSManaCost(2));               
				joueur->spells.push_front(effect2);              
			}
            
			for(auto s : joueur->spells)
			{
				if (joueur->getMana() < 
					 s->getManaCost()  || 
					 s->getId() != 2   || 
					 joueur->getTimer(2)->GetElapsedTime() <= 
					 joueur->getSpellDelay(2))
				{
				}
				else {
					joueur->manaPenalty(s->getManaCost());
					for(auto s : entitys){
						if(s->getDistance() < joueur->getSRange(2)) 
						{
							s->lifePenalty(joueur->getDmg(2));
							launchBloodEffect(s);
							if (!s->isAlive())
							{  
							   if (s->getId() == -30 )// Boss final)
							   {
							      game_victory = true;
							      Timer_Victory->Reset();
							   }
							   else {
							      launchDeathEffect(s);
							      upgrade();
								   randomDrop(s->getCenter().x, s->getCenter().y);
								}
								entitys.remove(s);
								(map_courante->Bot_list).remove(s);
								delete s;
							   break;
							  /* if (s->getId() == -30 )// Boss final)
							   {
							      game_victory = true;
							      Timer_Victory->Reset();
							   }
							   launchDeathEffect(s);
							   upgrade();
								entitys.remove(s);
								(map_courante->Bot_list).remove(s);
								randomDrop(s->getCenter().x, s->getCenter().y);
								delete s;
								break; */
							}
		                  
		               }
                  }
                  joueur->getTimer(2)->Reset();
               }
	         }
      }
      
      if ( input.IsKeyDown(Key::T)) { // Gestion du sort 3
			if (joueur->getTimer(3)->GetElapsedTime() > 
				 joueur->getSpellDelay(3) ) 
			{
			   
	         FolowingAnimation *effect3 = new FolowingAnimation(mainWindow_, 
																				 *(joueur->getImgSpell(3)),
																				  joueur->getVSpell(3), 
																				  joueur);
            effect3->setSoundB("Musique/Thunder7.ogg");
            effect3->getSound()->SetLoop(false);
	         effect3->getSound()->Play();
				effect3->play();
				effect3->setId(3);
				effect3->setManaCost(joueur->getSManaCost(3));               
				joueur->spells.push_front(effect3);   
			}
            
			for(auto s : joueur->spells){
				if (joueur->getMana() < 
					 s->getManaCost()  || 
					 s->getId() != 3   || 
					 joueur->getTimer(3)->GetElapsedTime() <= 
					 joueur->getSpellDelay(3))
				{
				}
				else 
				{
					joueur->manaPenalty(s->getManaCost());
					for(auto s : entitys)
					{
						if(s->getDistance() < joueur->getSRange(3)) 
						{
							s->lifePenalty(joueur->getDmg(3));
							launchBloodEffect(s);
							if (!s->isAlive())
							{
							   if (s->getId() == -30 )// Boss final)
							   {
							      game_victory = true;
							      Timer_Victory->Reset();
							   }
							   else {
							      launchDeathEffect(s);
							      upgrade();
								   randomDrop(s->getCenter().x, s->getCenter().y);
								}
								entitys.remove(s);
								(map_courante->Bot_list).remove(s);
								delete s;
								break;
							}
							 
						}
					}
					joueur->getTimer(3)->Reset();
				}
			}
		}
      
		for(auto s : entitys)
		{  // Actualise le chemin des monstres
			//s->update_path(map_courante, joueur);
			// Actualise la distance entre les monstres et le joueur
			//s->setDistance( (s->GetPath()).size() );
         
			if (s->getDistance() > s->getRange() && !s->getPursuit())
			{  
			   if (s->getRefresh()->GetElapsedTime() > 0.2)
			   {
			      s->update_path(map_courante, joueur);
			      s->setDistance( (s->GetPath()).size() );
			      s->getRefresh()->Reset();
			   }
            // Cas surplace. Si le monstre est trop loin et non en poursuite, il ne bouge pas
			}
			else {
			   s->update_path(map_courante, joueur);
			   s->setDistance( (s->GetPath()).size() );
			   // On passe en poursuite et on lance le déplacement du monstre
			   if (!s->getPursuit())
			   {
			      s->getTimer(1)->Reset();
			      s->getTimer(2)->Reset();
			      s->getTimer(3)->Reset();
			   }
			   
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
      
      // Gestion de la caméra
		view->SetHalfSize(VIEW_WIDTH, VIEW_HEIGHT);
		camera->run();			
		// Mise a jours des sprites et affichage
		displayEntity(clock);
		// Mise a jour et affichage de la StatusBar		
		statusbar.display();
		// Affichage du contenu de la fenêtre à l'écran
		mainWindow_->Display();
      // Gestion du dialogue d'introduction
      if (lancer_dialogue == 4)
      {   
          launchStartDialogue("JE SENS SA PRESENCE... TUE CE DEMON !!",0,0);
          lancer_dialogue = -1;
      }   
      
      /*
      if (lancer_dialogue == 3)
      {
         launchStartDialogue("TUE CETTE CREATURE MALEFIQUE, ET RETABLIT LA PAIX !", 0, 0);
         //lancer_dialogue = 4;
      }
      if (lancer_dialogue == 2)
      {
         //string Intro = joueur->getName();
         launchStartDialogue("LES TENEBRES ONT ENVAHIT LE ROYAUME D'OBLIVION.\n\n   APRES AVOIR SEME LA TERREUR DANS LE ROYAUME,\nLE DEMON USURPATEUR A FAIT UNE HALTE DANS CES\nCONTREES.\n   IL SE REPAIT MAINTENANT DES AMES DECHUES DANS\nLE DONJON DE LA LICHE...", 0, 0);
         //launchStartDialogue("BONJOUR, MON AMI.\nTOUT VA BIEN?", 0, 0);
         lancer_dialogue = 3;
      }
      
      if (lancer_dialogue == 1)
      {
         //string Intro = joueur->getName();
         launchStartDialogue("BONJOUR, VAILLANT GUERRIER.", 0, 0);
         //launchStartDialogue("BONJOUR, MON AMI.\nTOUT VA BIEN?", 0, 0);
         lancer_dialogue = 2;
      }
      if (lancer_dialogue == 0)
      {
         lancer_dialogue = 1;
      }*/
      
      joueur->getMovingSound()->Pause();
      if (game_victory)    // Gestion de la victoire
      {  // On a tué le boss Final
         map_courante->getMusic()->Stop();
         mainWindow_->Clear();
         mainWindow_->Draw(*(map_courante->sprite_map_));
         joueur->update();
         joueur->draw(); 
         mainWindow_->Display();
         while (Timer_Victory->GetElapsedTime() < 1)
         {
            
         }
         launchingVictory();         
      }
      			
		if (!joueur->isAlive())
		{  // Gestion de la mort du personnage
		   map_courante->getMusic()->Stop();
		   
		   Clock death_timer;
		   Vector2i eff = Vector2i(3,10);
	      StaticAnimation *mort = new StaticAnimation(mainWindow_, *image_death_joueur, eff, joueur->getCenter());
	      mort->play();		      
         int i = 0;
         while (mort->isPlaying())
         {
          if (i == 25) // Permet de faire durer plus longtemps le dernier frame de l'image
          {
             while (death_timer.GetElapsedTime() < 3)
             {
                // Ne rien faire
             }
             death_timer.Reset();            
          }
          mainWindow_->Clear();
          mainWindow_->Draw(*(map_courante->sprite_map_));
          mort->run();  
          ++i;
          mainWindow_->Display(); 
         }
		   delete mort;
		   launchingDeath(); // Lance l'écran de Gameover
		}
		
		mainWindow_->Clear();
		
		
   
   }
   // Gestion de la destruction de tous les éléments construit pendant le jeu
   mainWindow_->Clear();
   mainWindow_->ShowMouseCursor(true);		
	joueur->getMovingSound()->Stop();
	entitys = map_courante->Bot_list;
	items = map_courante->Item_list;
   game_victory = false;
   map_1->getMusic()->Stop();
   map_2->getMusic()->Stop();
   map_3->getMusic()->Stop();
   map_4->getMusic()->Stop();
   map_5->getMusic()->Stop();
   
	while (!(map_1->Bot_list).empty()) 
	{ 
		delete (map_1->Bot_list).back(); 
		(map_1->Bot_list).pop_back(); 
	}

	while (!(map_2->Bot_list).empty()) 
	{ 
		delete (map_2->Bot_list).back(); 
		(map_2->Bot_list).pop_back(); 
	}

	while (!(map_3->Bot_list).empty()) 
	{ 
		delete (map_3->Bot_list).back(); 
		(map_3->Bot_list).pop_back(); 
	}

	while (!(map_4->Bot_list).empty()) 
	{ 
		delete (map_4->Bot_list).back(); 
		(map_4->Bot_list).pop_back(); 
	}

	while (!(map_5->Bot_list).empty()) 
	{ 
		delete (map_5->Bot_list).back(); 
		(map_5->Bot_list).pop_back(); 
	}

	entitys.clear();
	effects.clear();
	items.clear();
	static_effects.clear();
	projectiles.clear();

	while (!(map_1->Item_list).empty()) 
	{ 
		delete (map_1->Item_list).back(); 
		(map_1->Item_list).pop_back(); 
	}

	while (!(map_2->Item_list).empty()) 
	{
	 	delete (map_2->Item_list).back(); 
		(map_2->Item_list).pop_back(); 
	}

	while (!(map_3->Item_list).empty()) 
	{ 
		delete (map_3->Item_list).back(); 
		(map_3->Item_list).pop_back(); 
	}

	while (!(map_4->Item_list).empty()) 
	{ 
		delete (map_4->Item_list).back(); 
		(map_4->Item_list).pop_back(); 
	}

	while (!(map_5->Item_list).empty()) 
	{ 
		delete (map_5->Item_list).back(); 
		(map_5->Item_list).pop_back(); 
	}

	while (!effects.empty()) 
	{ 
		delete effects.back(); 
		effects.pop_back(); 
	}
	while (!static_effects.empty()) 
	{ 
		delete static_effects.back(); 
		static_effects.pop_back(); 
	}

	while (!projectiles.empty())
	{ 
		delete projectiles.back(); 
		projectiles.pop_back(); 
	}

	delete view;
	delete camera;
	delete joueur;
	delete Timer_Projectile;
	delete Timer_Items;
   delete Timer_Spell;
}

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
{  // Gestion de l'affichage des entités
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
   if (joueur->getIsDamaged())
   {
      launchBloodEffect(joueur);
      joueur->setIsDamaged(false);
   }
   
   if(refresh)
		time.Reset();
     
   // Gestion de l'affichage des Bot ainsi que de leurs sorts
   for(auto s : entitys){

	   if(refresh ){
		   s->update();
	   }
	   s->draw();
	   s->drawRect();
	   for (auto c : s->spells)
	      {
	         if(c->isPlaying()){
             c->run();
            }
            
            if (!c->isPlaying())
            {
               s->spells.remove(c); 
               delete c;
               break;
            }
	      }
	   
	   
   }
   // Gestion des effets
   /*for(auto s : effects){

      if(s->isPlaying()){
      s->run();
      }
      else {
         effects.remove(s);
         delete s;
         break;
      }
   }*/
   
   // Gestion des sorts du joueur
   for(auto s : joueur->spells){

      if(s->isPlaying()){
      s->run();
      }
      else {
         joueur->spells.remove(s);
         delete s;
         break;
      }
   }
   // Gestion des effets statiques 
   for(auto s : static_effects){

      if(s->isPlaying()){
      s->run();
      }
      else {
         static_effects.remove(s);
         delete s;
         break;
      }
   }

   // Gestion des items   
   for(auto s : items){
      refresh = false;

	   if (s->getTimer()->GetElapsedTime() > REFRESH_ITEM ) 
		   refresh = true;
   
      if ( s->getIsShown()  && joueur->getCenter().x < s->getCenter().x + s->getAnimationWidth() && joueur->getCenter().x > s->getCenter().x - s->getAnimationWidth() && joueur->getCenter().y < s->getCenter().y + s->getAnimationHeight() && joueur->getCenter().y > s->getCenter().y - s->getAnimationHeight())
      {
            // le joueur rentre en contact avec l'item alors qu'il est en état affiché. On ajoute alors l'item à l'inventaire
            s->setIsShown(false);
            s->resetTimer(); 
            // Suivant l'identifiant de l'item, on l'ajoute
            if (s->getIt() == Item::HP)
            {
               joueur->increaseNbHpPot();
            }
            if (s->getIt() == Item::MANA)
            {
               joueur->increaseNbManaPot();
            }          
      }
      if (s->getIsShown())
      {
         // Si l'item est en état "Affiché", on le dessine sur la fenêtre
         mainWindow_->Draw(*(s->mySprite_));
      }
      if (refresh) {
         s->setIsShown(true);
         s->resetTimer();
         
      }

   }

   // Gestion des projectiles
   for(auto s : projectiles){
      
	   if ( !s->getStuck())
		{  // Si le projectile n'est pas coincé, il avance
			s->update();
			s->draw();
		}
	   else 
		{  // Sinon, il est détruit
	      projectiles.remove(s);
	      delete s;
		   break;
	   }
	   
	   for(auto c : entitys)
		{  // Si le projectile rentre en collision avec un monstre, on lui applique les dégats, on lance les animations de dégats, et on supprime le projectile.
			if ( s->getCenter().x < 
				c->getCenter().x   + 
				c->getAnimationWidth() && 
				s->getCenter().x > 
				c->getCenter().x - 
				c->getAnimationWidth() && 
				s->getCenter().y < 
				c->getCenter().y + 
				c->getAnimationHeight() && 
				s->getCenter().y > 
				c->getCenter().y - 
				c->getAnimationHeight())
         {
            launchBloodEffect(c);
            // Pour éviter la triche, quand un monstre est touché par un projectile, il se met en poursuite, quelque soit sa distance.
            c->inPursuit();
            projectiles.remove(s);
	         delete s ;
	         c->lifePenalty(joueur->getAttackDamage());
	         if (!c->isAlive())
	         {  // Si on tue le monstre, alors on lance l'animation de mort, on lance un random drop, et on supprime le monstre
	            upgrade();
	            if (c->getId() == -30 )// Boss final)
				   {
				      game_victory = true;
				      Timer_Victory->Reset();
				   }
				   else {
				      launchDeathEffect(c);
				      upgrade();
					   randomDrop(c->getCenter().x, c->getCenter().y);
					}
					entitys.remove(c);
					(map_courante->Bot_list).remove(c);
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


void Game::setPlayer(RenderWindow  * mainwin) 
{
   //entitys.clear();
   // Suivant le choix, on construit un personnage
   switch(*player_choice) 
	{
      case P1 : 

      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P1.png"))
		      cout << "erreur " << endl ; 
		  if(!image_death_joueur->LoadFromFile("Sprites/Personnages/Damage1.png"))
		      cout << "erreur " << endl ;
        
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,all_images.image_Special15,all_images.image_Special12,all_images.image_Gun2);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P2 : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P2.png"))
		      cout << "erreur " << endl ;
		  if(!image_death_joueur->LoadFromFile("Sprites/Personnages/Damage2.png"))
		      cout << "erreur " << endl ; 
        joueur = new BjarneStroustrup(mainwin,*image_joueur,map_courante,all_images.image_Heal5,all_images.image_Heal3,all_images.image_Light7);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P3 : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P3.png"))
		      cout << "erreur " << endl ; 
        if(!image_death_joueur->LoadFromFile("Sprites/Personnages/Damage3.png"))
		      cout << "erreur " << endl ;
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante,all_images.image_Wind1,all_images.image_Fire3,all_images.image_Gun1);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      case P4 : 

      {

        if(!image_joueur->LoadFromFile("Sprites/Personnages/P4.png"))
		      cout << "erreur " << endl ; 
		  if(!image_death_joueur->LoadFromFile("Sprites/Personnages/Damage1.png"))
		      cout << "erreur " << endl ;
        joueur = new Athena(mainwin,*image_joueur,map_courante,all_images.image_Special17,all_images.image_Special2,all_images.image_Special14);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }
      
      default : 
      {
        if(!image_joueur->LoadFromFile("Sprites/Personnages/P1.png"))
		      cout << "erreur " << endl ; 
		  if(!image_death_joueur->LoadFromFile("Sprites/Personnages/Damage1.png"))
		      cout << "erreur " << endl ;
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante,all_images.image_Special15,all_images.image_Special12,all_images.image_Gun2);
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        break;
      }

   }
   joueur->setId(0);
}


void Game::launchingPause() 
{  // On lance la pause. La seule chose qui permet de la quitter sont la touche Q et Echap (revient au menu principal), et la touche P (qui permet de continuer le jeu)
   bool Ispause = true;
   Shape grey_screen   = Shape::Rectangle(0,
														0,
														PLAYING_WIDTH,
														PLAYING_HEIGHT,
														Color(0,0,0));

   grey_screen.SetPosition(camera->position_->x - PLAYING_WIDTH  /2,
								   camera->position_->y - PLAYING_HEIGHT /2);
   
	String texte = String ("               Le jeu est en pause.\n\n(P) : Continuer    (Q) : Menu principal",
								  Font::GetDefaultFont(), 40.f);

	texte.SetPosition(camera->position_->x - 320, 
							camera->position_->y - 100);

	texte.SetStyle(11);
	texte.SetColor(Color::White);

   mainWindow_->Draw(grey_screen);
   mainWindow_->Draw(texte);
   mainWindow_->Display();
	while (Ispause == true) 
	{
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

void Game::launchingDeath() 
{
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
	   texte = String (to_string (18 - (int) death_timer.GetElapsedTime() ),
										   Font::GetDefaultFont(), 40.f);
      texte.SetStyle(11);
	   texte.SetColor(Color::White);
	   texte.SetPosition(camera->position_->x - 30,
							   camera->position_->y + PLAYING_HEIGHT /4);
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
}

void Game::loadBot() {

   // MAP 1

   loadMouse1(map_1, -1, 4, 28, 18);
   loadMouse1(map_1, -1, 7, 10, 4);
   loadMouse1(map_1, -1, 3, 13, 14);
   
   loadRedeye(map_1, -1, 3, 12, 19); 
   loadRedeye(map_1, -1, 4, 6, 8);
   loadRedeye(map_1, -1, 4, 21, 16);
   
   loadGreenscorpion(map_1, -1, 3, 6, 18);
   loadGreenscorpion(map_1, -1, 5, 10, 8);
   loadGreenscorpion(map_1, -1, 3, 14, 17);
   
   loadFantome1(map_1,-1, 6, 2, 13);
   loadFantome1(map_1,-1, 5, 21, 9);
   loadFantome1(map_1,-1, 7, 21, 5);
   for(auto c : map_1->Bot_list)
   {
      c->setDmg(1,c->getDmg(1) * ResultDifficulty);
      c->setDmg(2,c->getDmg(2) * ResultDifficulty);
      c->setDmg(3,c->getDmg(3) * ResultDifficulty);
   }
  // MAP 2
  //loadFantome1(map_2,-1, 7, 21, 5);
  loadBat(map_2,-1,2, 21, 37);
  loadBat(map_2,-1,4, 6, 24);
  loadBat(map_2,-1,4, 19, 32);
  loadBat(map_2,-1,5, 27, 23);
  loadBat(map_2,-1,2, 10, 14);
  loadBat(map_2,-1,4, 9, 9);
  loadBat(map_2,-1,5, 13, 4);
  loadBat(map_2,-1,4, 20, 4);
  loadBat(map_2,-1,2, 34, 5);
  loadBat(map_2,-1,3, 34, 23);
  loadBat(map_2,-1,3, 30, 35);
  loadBat(map_2,-1,3, 41, 29);
  loadBat(map_2,-1,3, 37, 7);
  loadGreendragon1(map_2,-1,2,16,40);
  loadGreendragon1(map_2,-1,3,4,39);
  loadGreendragon1(map_2,-1,4,26,32);
  loadGreendragon1(map_2,-1,7,15,23);
  loadGreendragon1(map_2,-1,3,3,18);
  loadGreendragon1(map_2,-1,3,3,9);
  loadGreendragon1(map_2,-1,4,15,15);
  loadGreendragon1(map_2,-1,5,26,10);
  loadGreendragon1(map_2,-1,2,32,11);
  loadGreendragon1(map_2,-1,5,37,28);
  loadGreendragon1(map_2,-1,6,45,39);
  loadGreendragon1(map_2,-1,2,45,24);
  loadGreendragon1(map_2,-1,3,43,16);
  loadFantome2(map_2,-1,5,17,38);
  loadFantome2(map_2,-1,3,5,34);
  loadFantome2(map_2,-1,3,11,30);
  loadFantome2(map_2,-1,2,24,26);
  loadFantome2(map_2,-1,4,7,17);
  loadFantome2(map_2,-1,3,2,4);
  loadFantome2(map_2,-1,3,14,8);
  loadFantome2(map_2,-1,3,30,13);
  loadFantome2(map_2,-1,4,29,4);
  loadFantome2(map_2,-1,5,32,30);
  loadFantome2(map_2,-1,4,34,40);
  loadFantome2(map_2,-1,2,42,34);
  loadFantome2(map_2,-1,4,45,6);
  loadRedscorpion(map_2,-1,2,9,40);
  loadRedscorpion(map_2,-1,4,6,29);
  loadRedscorpion(map_2,-1,3,16,31);
  loadRedscorpion(map_2,-1,5,11,23);
  loadRedscorpion(map_2,-1,5,8,4);
  loadRedscorpion(map_2,-1,4,19,10);
  loadRedscorpion(map_2,-1,3,34,17);
  loadRedscorpion(map_2,-1,2,25,4);
  loadRedscorpion(map_2,-1,5,38,34);
  loadRedscorpion(map_2,-1,2,29,40);
  loadRedscorpion(map_2,-1,2,41,24);
  loadRedscorpion(map_2,-1,2,40,11);
  
  
  
  for(auto c : map_2->Bot_list)
   {
      c->setDmg(1,c->getDmg(1) * ResultDifficulty);
      c->setDmg(2,c->getDmg(2) * ResultDifficulty);
      c->setDmg(3,c->getDmg(3) * ResultDifficulty);
   }
   
  // MAP 3
  
  
  for(auto c : map_3->Bot_list)
   {
      c->setDmg(1,c->getDmg(1) * ResultDifficulty);
      c->setDmg(2,c->getDmg(2) * ResultDifficulty);
      c->setDmg(3,c->getDmg(3) * ResultDifficulty);
   }
   
  // MAP 4
  
  
  for(auto c : map_4->Bot_list)
   {
      c->setDmg(1,c->getDmg(1) * ResultDifficulty);
      c->setDmg(2,c->getDmg(2) * ResultDifficulty);
      c->setDmg(3,c->getDmg(3) * ResultDifficulty);
   }
  // MAP 5

  loadBee(map_5, -5, 8, 25, 16);
  loadBee(map_5, -5, 9, 3, 6);
  loadBlueslime(map_5, -30, 2, 11, 22);
  loadBlueslime(map_5, -30, 5, 10, 9);
  loadBlueslime(map_5, -30, 5, 25, 7);
  loadGreenslime(map_5, -2, 3, 20, 5);
  loadGreenslime(map_5, -2, 5, 16, 11);

  loadNaga(map_5, -3, 3, 8, 3);
  loadNaga(map_5, -3, 6, 18, 17);
  loadNaga(map_5, -3, 2, 3, 21);
  loadNaga(map_5, -3, 5, 2, 9);
  
  for(auto c : map_5->Bot_list)
   {
      c->setDmg(1,c->getDmg(1) * ResultDifficulty);
      c->setDmg(2,c->getDmg(2) * ResultDifficulty);
      c->setDmg(3,c->getDmg(3) * ResultDifficulty);
   }

}


void Game::loadItem() {
   // MAP 5
   loadHP(28,17, map_5);
   loadHP(17,26, map_5);
   loadHP(9,8, map_5);
   
   loadMana(27,5, map_5);
   loadMana(3,9, map_5);
   
   // MAP 1
   loadHP(29,17, map_1);
   loadHP(11,10, map_1);
   loadHP(4,14, map_1);
   loadHP(29,5, map_1);
   loadMana(19,11, map_1);
   loadMana(4,15, map_1);
   
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

void Game::launchBloodEffect(LivingEntity * e) { 
   Vector2i blood_effect(8,3);        
   FolowingAnimation *effect = new FolowingAnimation(mainWindow_, *image_degats, blood_effect, e);
   effect->setSoundB("Musique/Blood_Squirt.ogg");
   effect->getSound()->SetLoop(false);
	effect->getSound()->Play();
   effect->play();            
	e->spells.push_front(effect);
} 

void Game::launchDeathEffect(LivingEntity * e) { 	
   Vector2i eff = Vector2i(5,5);
	StaticAnimation *ble = new StaticAnimation(mainWindow_, *image_Death, eff, e->getCenter());
   ble->setSoundB("Musique/Death.ogg");
	ble->getSound()->SetLoop(false);
	ble->getSound()->Play();
	ble->play();
	static_effects.push_front(ble);
} 

void Game::loadImages() 
{
   if (!image_Death->LoadFromFile("Sprites/Sorts/Death1.png"))
		      cout << "erreur " << endl ;
		      
   if (!image_degats->LoadFromFile("Sprites/Sorts/Blood2.png"))
		      cout << "erreur " << endl ;
		      
   if (!image_hp_item->LoadFromFile("Sprites/Items/hp.png"))
		      cout << "erreur " << endl ;

	if (!image_mana_item->LoadFromFile("Sprites/Items/mana.png"))
		      cout << "erreur " << endl ;	
   
   if (!image_projectile->LoadFromFile("Sprites/Projectiles/Fire1.png"))
		      cout << "erreur " << endl ;     
}
     
     
     
void Game::loadHP(int coordx, int coordy, Map *map) 
{
   Item *hp = new Item(mainWindow_,
							  image_hp_item,map,
							  coordx, 
							  coordy,
							  Item::HP);

	(map->Item_list).push_front(hp);
}

void Game::loadMana(int coordx, int coordy, Map *map) 
{
   Item *mana = new Item(mainWindow_,
								 image_mana_item,
								 map,
								 coordx,
								 coordy,
								 Item::MANA);

	(map->Item_list).push_front(mana);
}

void Game::loadDragon(Map *map, int id, int range, int coordx, int coordy) 
{ 
	GreenDragon *bot = new GreenDragon(mainWindow_,
												  *(all_images.image_Dragon1),
												  map,
												  id,
												  range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::loadTroll(Map *map, int id, int range, int coordx, int coordy) 
{
   Troll *bot = new Troll(mainWindow_,
								  *(all_images.image_Troll),
								  map,
								  id,
								  range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadArmor1(Map *map, int id, int range, int coordx, int coordy) 
{
   Armor1 *bot = new Armor1(mainWindow_,
									 *(all_images.image_Armor1),
									 map,
									 id,
									 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadReaper1(Map *map, int id, int range, int coordx, int coordy) 
{
   Reaper1 *bot = new Reaper1(mainWindow_,
										*(all_images.image_Reaper1),
										map,
										id,
										range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadFantome1(Map *map, int id, int range, int coordx, int coordy) 
{
   Fantome1 *bot = new Fantome1(mainWindow_,
										  *(all_images.image_Fantome1),
										  map,
										  id,
										  range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadFantome2(Map *map, int id, int range, int coordx, int coordy) 
{
   Fantome2 *bot = new Fantome2(mainWindow_,
										  *(all_images.image_Fantome2),
										  map,
										  id,
										  range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadSquelette(Map *map, int id, int range, int coordx, int coordy) 
{
   Squelette *bot = new Squelette(mainWindow_,
											 *(all_images.image_Squelette),
											 map,
											 id,
											 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadBat(Map *map, int id, int range, int coordx, int coordy) 
	{
   Bat *bot = new Bat(mainWindow_,
							 *(all_images.image_Bat),
							 map,
							 id,
							 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadBee(Map *map, int id, int range, int coordx, int coordy) 
{
   Bee *bot = new Bee(mainWindow_,
							 *(all_images.image_Bee),
							 map,
							 id,
							 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadBlueslime(Map *map, int id, int range, int coordx, int coordy) 
{
   Blueslime *bot = new Blueslime(mainWindow_,
											 *(all_images.image_Blueslime),
											 map,
											 id,
											 range, all_images.image_Attack1, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}
void Game::loadGreendragon1(Map *map, int id, int range, int coordx, int coordy) {
   Greendragon1 *bot = new Greendragon1(mainWindow_,
													 *(all_images.image_Greendragon1),
													 map,
													 id,
													 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadGreenscorpion(Map *map, int id, int range, int coordx, int coordy) 
{
   Greenscorpion *bot = new Greenscorpion(mainWindow_,
														*(all_images.image_Greenscorpion),
														map,
														id,
														range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadGreenslime(Map *map, int id, int range, int coordx, int coordy) 
{
   Greenslime *bot = new Greenslime(mainWindow_,
												*(all_images.image_Greenslime),
												map,
												id,
												range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);
	
   bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

   (map->Bot_list).push_front(bot);
}

void Game::loadMouse1(Map *map, int id, int range, int coordx, int coordy) 
{
	Mouse1 *bot = new Mouse1(mainWindow_,
									 *(all_images.image_Mouse1),
									 map,
									 id,
									 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::loadNaga(Map *map, int id, int range, int coordx, int coordy) 
{
	Naga *bot = new Naga(mainWindow_,
								*(all_images.image_Naga),
								map,
								id,
								range, all_images.image_Attack7, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::loadReddragon1(Map *map, int id, int range, int coordx, int coordy) 
{
	Reddragon1 *bot = new Reddragon1(mainWindow_,
												*(all_images.image_Reddragon1),
												map,
												id,
												range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::loadRedeye(Map *map, int id, int range, int coordx, int coordy) 
{
	Redeye *bot = new Redeye(mainWindow_,
									 *(all_images.image_Redeye),
									 map,
									 id,
									 range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::loadRedscorpion(Map *map, int id, int range, int coordx, int coordy) 
{
	Redscorpion *bot = new Redscorpion(mainWindow_,
												  *(all_images.image_Redscorpion),
												  map,
												  id,
												  range, all_images.image_Attack2, all_images.image_Special12, all_images.image_Gun2);

	bot->setPosition(Vector2f(BASE_SPRITE*coordx,BASE_SPRITE*coordy));

	(map->Bot_list).push_front(bot);
}

void Game::launchStartDialogue(string s, int coordx, int coordy) {

     // On affiche lettre par lettre pour donner un effet dynamique, et on actualise le background noir suivant le nombre de lignes 
     int offset_X = 0;
     int offset_Y = 1;
     String * pop = new String();
     Clock timer_dialogue;
     
     Shape Rect =  Shape::Rectangle(0, 0, PLAYING_WIDTH, 50, Color::Black);
     Rect.SetPosition(camera->getPosition()->x - PLAYING_WIDTH /2, camera->getPosition()->y - PLAYING_HEIGHT /2);
     mainWindow_->Draw(Rect);
     
     Font Police;
     if (!Police.LoadFromFile("Fonts/perso.ttf"))
	      cout << "erreur" << endl;
   
    
    for (int i = 0; i <(int) s.size(); ++i)
    {
      while (timer_dialogue.GetElapsedTime() < 0.1) {
      } 
      timer_dialogue.Reset();
      if ((s[i] == '\n'))
      {
         if (s[i-1] == '.')
         {
            while (timer_dialogue.GetElapsedTime() < 1) {
            }
         }
         else {
            // Pas de timer quand mise à la ligne, sauf après un point
         }
         offset_X = 0;
          
         timer_dialogue.Reset();
         Shape Rect =  Shape::Rectangle(0, 50 + 30*(offset_Y - 1), PLAYING_WIDTH, 50 + 30*(offset_Y), Color::Black);
         Rect.SetPosition(camera->getPosition()->x - PLAYING_WIDTH /2, camera->getPosition()->y - PLAYING_HEIGHT /2);
         mainWindow_->Draw(Rect);
         ++offset_Y;
      }
      else {
         string iLetter(1,s[i]);
         pop->SetText(iLetter);
         pop->SetSize(20);
         pop->SetStyle(11);
         pop->SetColor(Color::White);
         pop->SetFont(Police);
         pop->SetPosition(camera->getPosition()->x - 400 + 15*offset_X + coordx, camera->getPosition()->y - 300 + 30* offset_Y + coordy);
         mainWindow_->Draw(*pop);
         mainWindow_->Display();
         ++offset_X;
      }

      
   }
   while (timer_dialogue.GetElapsedTime() < 3) {
   } 

   
}

void Game::upgrade() {
   joueur->bonusLifeMax( PERCENTAGE_UPGRADE * joueur->getLifeMax());
   joueur->bonusManaMax( PERCENTAGE_UPGRADE * joueur->getManaMax());
   
   joueur->setDmg(1,joueur->getDmg(1) * (1 + PERCENTAGE_UPGRADE));
   joueur->setDmg(2,joueur->getDmg(2) * (1 + PERCENTAGE_UPGRADE));
   joueur->setDmg(3,joueur->getDmg(3) * (1 + PERCENTAGE_UPGRADE));
   joueur->setAttackDamage(joueur->getAttackDamage() * (1 + PERCENTAGE_UPGRADE));
   
	joueur->setSManaCost(1, joueur->getSManaCost(1) * (1 + PERCENTAGE_UPGRADE));
	joueur->setSManaCost(2, joueur->getSManaCost(2) * (1 + PERCENTAGE_UPGRADE));
	joueur->setSManaCost(3, joueur->getSManaCost(3) * (1 + PERCENTAGE_UPGRADE));
}

void Game::randomDrop(int x, int y) {
   // Gère la gestion des drops, suivant la difficulté
   int i = rand() % (int)(DROP_CHANCE + (ResultDifficulty - EASY_DIFFICULTY) * 200) + 1;
   int j = rand() % 100 + 1;
   
 
   if (i <= 100) {
      if (j <= 50)
      {
         loadHP(x/BASE_SPRITE,y/BASE_SPRITE, map_courante);
      }
      else {
         loadMana(x/BASE_SPRITE,y/BASE_SPRITE, map_courante);
      }
      items = map_courante->Item_list;
   }
}


void Game::launchingVictory() 
{
   Clock Wait_For;
   Image img_victory;
   Sprite s_victory;
   Timer_Victory->Reset();
   Music victory;
   
   if(!victory.OpenFromFile("Musique/Victoire.ogg"))
      cout << "erreur " << endl ;
   victory.Play();
   
   if(!img_victory.LoadFromFile("images/Victory/victory.png"))
      cout << "erreur " << endl ;
   s_victory.SetImage(img_victory);
   s_victory.SetPosition( camera->position_->x - PLAYING_WIDTH/2, camera->position_->y - PLAYING_HEIGHT/2 + 40);
   while (Timer_Victory->GetElapsedTime() < 3)
   {
            
   }
   Wait_For.Reset();
   
   while (Wait_For.GetElapsedTime() < 1)
   {
      mainWindow_->Draw(s_victory);
      mainWindow_->Display();
   }
   String text_ ;
	text_.SetText(" Press [Esc] to exit to MainMenu");	 
	text_.SetSize(20);
	text_.SetStyle(11);
	text_.SetColor(Color::White);
	text_.SetFont(Font::GetDefaultFont());
	text_.SetPosition( camera->position_->x - PLAYING_WIDTH/2, camera->position_->y - PLAYING_HEIGHT/2);
	mainWindow_->Draw(text_);
	mainWindow_->Display();
	bool inboucle = true;
	Event event2;
   while ( (mainWindow_->GetEvent(event2) || Wait_For.GetElapsedTime() < 60) && inboucle == true)
   {     
	   switch (event2.Type)
	   {
		   case Event::KeyPressed : {
     
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
         }
         default :
            break;
      }
   }
   victory.Stop(); 
   mainWindow_->Clear();
   *gameState_ = ShowingMainMenu;
   
}
