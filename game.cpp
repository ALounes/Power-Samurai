#include "game.hpp"
#include "config.hpp"

#define GAME_WIDTH  1024
#define GAME_HEIGHT 768

#define PLAYING_WIDTH 800
#define PLAYING_HEIGHT 600

#define BASE_SPRITE 32
#define PLAYER_X_START 8
#define PLAYER_Y_START 25

#define MAP_1_HEIGHT 27
#define MAP_1_WIDTH 31

#define MAP_2_HEIGHT 47
#define MAP_2_WIDTH 47



Image image_linus;
Image perso;
Image plan;
Image effect_003;

Sprite sprite_perso;
//Image feux;
//Sprite sprite_feux;

//Player *joueur;

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
  mainWindow_ = new RenderWindow(VideoMode(GAME_WIDTH, GAME_HEIGHT), "Power Samurai!!!");
  mainWindow_->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

  map_1 = new Map();
  cout << "map_1 créé" << endl;
  map_2 = new Map();
  map_3 = new Map();
  map_4 = new Map();
  map_courante = new Map();
  player_choice = new int;
  image_joueur = new Image;
 
  
  
  cout << "game() terminé" << endl;
}


Game::~Game ()
{
  delete map_1;
    cout << "map 1 détruite" << endl;
  delete map_2;
  //delete map_3;
  //delete map_4;
  cout << "maps détruites" << endl;
  delete mainMenu_;
  delete gameState_;
  delete mainWindow_;
  delete player_choice;
  delete image_joueur;
  //delete joueur;
  
  //delete difficultyMenu_;
  //delete playersMenu_;
}
void Game::Map_Load(void)
{
  cout << "Map_load()" << endl;
  // Creation map 1
  
  map_1->map_create(MAP_1_HEIGHT,MAP_1_WIDTH);
  cout << "creation terminée()" << endl;
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
  
  cout << "static terminé() (3,1) = " << staticmap_1[3][1] << endl;
  
  for (int x = 0; x < MAP_1_HEIGHT; x++) {
    for (int y = 0; y < MAP_1_WIDTH; y++) {
      map_1->set_tableau(x, y, staticmap_1[x][y]);
    }
  }
  
  
  cout << "dynamique terminé()" << endl;
  
  cout << "dynamique(3,1) = " << map_1->getSocleMap(3,1) << endl; 
   
  map_1->image_map_->LoadFromFile("images/Maps/map.png");
  map_1->sprite_map_->SetImage(*(map_1->image_map_));
	
  map_1->set_links(map_2,NULL,NULL);
  map_1->set_tpPoints(45,23,0,0,0,0);
	
	// Creation map 2
  
  map_2->map_create(MAP_2_HEIGHT,MAP_2_WIDTH);
  int staticmap_2[MAP_2_HEIGHT][MAP_2_WIDTH] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,1,1,1,2,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,2,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,0,2,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,0,0},
  {0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
  {0,1,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0},
  {0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,2,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,2,1,0,1,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,1,0,0},
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,0,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0},
  {0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0},
  {0,1,1,1,0,2,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0},
  {0,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
  {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0},
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
  
   map_2->image_map_->LoadFromFile("images/Maps/ruines1.png");
	map_2->sprite_map_->SetImage(*(map_2->image_map_));
	
	map_2->set_links(NULL,map_1,NULL);
	map_2->set_tpPoints(0,0,8,14,0,0);
	
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
	cout << "mainMenu loaded" << endl;
	
	cout << "Début ShowMainMenu" << endl;
	MainMenu::MenuResult result = mainMenu_->Show(mainWindow_);
	cout << "result obtenu" << endl;
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
			*gameState_ = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Intermediate:
			*gameState_ = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Hard:
			*gameState_ = Game::ShowingMainMenu;

			break;
	default:    
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
	 
	 *player_choice = *(playersMenu_->getposition());
	 cout << "CHOIX JOUEUR : " << *player_choice << endl;
  mainWindow_->ShowMouseCursor(true);
  cout << "delete players terminé" << endl;
}

void Game::RunGame()
{
  mainWindow_->ShowMouseCursor(false);
	Event event;
	Clock time;
	Clock clock2;
	Vector2f position(mainWindow_->GetWidth()/2,mainWindow_->GetHeight()/2);
	Clock clock;
	Vector2i test_effect(5,8);

	// Test projectile
	Image *feux = new Image();
	Vector2i vfeux(4,4);
	if (!feux->LoadFromFile("sprite/feux.png"))
		cout << "erreur " << endl ;
	// FIN Test projectile
	

	
	if (!buffer_son.LoadFromFile("Musique/BinB.ogg"))
		cout << "erreur " << endl ;

	if (!effect_003.LoadFromFile("sprite/effect_010.png"))
		cout << "erreur " << endl ;

	son.SetBuffer(buffer_son);
	son.SetLoop(true);
 	//son.Play();	
 	
 	setPlayer(mainWindow_,image_joueur);
 	
 	Image image_bot;
	if(!image_bot.LoadFromFile("sprite/LinusTorvalds.png"))
		cout << "erreur " << endl ;
	Bot *bot = new Bot(mainWindow_,image_bot,Vector2i(LINUS_TORVALDS_X,LINUS_TORVALDS_Y), String("Linus Torvalds"), LINUS_TORVALDS_LIFE, LINUS_TORVALDS_MANA, LINUS_TORVALDS_POWER,map_courante);
	bot->setPosition(Vector2f(32*7,32*3));	
	bot->update_path(map_courante,joueur);
	entitys.push_front(bot);
   bot->play();
   /*int xStart = 7;
   int yStart = 3;
   int xFinish = 8;
   int yFinish = 25;*/
   
  // cout << "CHAINE CHEMIN" << bot->pathFind( xStart, yStart, xFinish, yFinish, map_courante) << endl;
   //cout << "CHAINE CHEMIN " << bot->GetPath() << endl;
   
   
	camera = new Camera(mainWindow_,joueur);
	view = new View();
	//camera->setCameraXY(BASE_SPRITE * MAP_1_WIDTH,BASE_SPRITE * MAP_1_HEIGHT);
	

	// ANIMATION EFFECT
	
	//AnimationEffect *effect = new AnimationEffect(mainWindow_,effect_003,test_effect,linus);
	//addEffect(effect);
	//effect->setPosition(Vector2f(300,300));


	// TEST PROJECTILE	
	Projectile projectile(mainWindow_,feux,vfeux,joueur,16);

   // Exécution de la boucle principale
   bool fin_de_boucle = false;
   const Input &input = mainWindow_->GetInput();
   while (mainWindow_->IsOpened() && !(fin_de_boucle) && *gameState_ == Playing)
   {
      mainWindow_->SetFramerateLimit(30);
      camera->setCameraXY(*(map_courante->get_Largeur()) * BASE_SPRITE,*(map_courante->get_Hauteur()) * BASE_SPRITE);
		mainWindow_->Draw(*(map_courante->sprite_map_));
			
      if (input.IsKeyDown(Key::Z) ||input.IsKeyDown(Key::Q) || input.IsKeyDown(Key::D) || input.IsKeyDown(Key::S) ) {
   
				joueur->soclePosition();
				joueur->actionKey(map_courante);
				map_courante = joueur->getMap();
				for(auto s : entitys){
		         
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

		view->SetHalfSize(400, 300);
      
      
		camera->run();	

		// TEST PROJECTILES
		//projectile.update();
		//projectile.draw();

		// Mise a jours des sprites et affichage
		displayEntity(clock);
	
   	//effect->run();

		// Affichage du contenu de la fenêtre à l'écran
		mainWindow_->Display();

		// Efface le contenu de la fenetre 
		mainWindow_->Clear();
   
   }
mainWindow_->ShowMouseCursor(true);
entitys.clear();
effects.clear();
delete view;
delete camera;
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
   case  Key::P :
      map_courante = map_courante->getLink(1);

		
		break;


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

   if (refresh && joueur->isPlaying()) {
      joueur->update();
   }
   joueur->draw();
      
	for(auto s : entitys){
		if(refresh ){
			s->update();
			//s->follow_path(map_courante, joueur);
		}
		s->draw();
	}

	if(refresh)
		time.Reset();
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


void Game::setPlayer(RenderWindow  * mainwin,Image * image) {
   entitys.clear();
   switch(*player_choice) {
      case 0 : 

      {
        if(!image_joueur->LoadFromFile("sprite/blonde.png"))

		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante);
        mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }
      
      case 1 : 
      {
        if(!image_joueur->LoadFromFile("sprite/fartas.png"))
		      cout << "erreur " << endl ; 
        joueur = new AlanTuring(mainwin,*image_joueur,map_courante);
        mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }
      
      case 2 : 
      {
        if(!image_joueur->LoadFromFile("sprite/gris.png"))
		      cout << "erreur " << endl ; 
        joueur = new BjarneStroustrup(mainwin,*image_joueur,map_courante);
        mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }
      
      case 3 : 

      {

        if(!image_joueur->LoadFromFile("sprite/LinusTorvalds.png"))

		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante);
        mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }
      
      default : 
      {
        if(!image_joueur->LoadFromFile("sprite/LinusTorvalds.png"))
		      cout << "erreur " << endl ; 
        joueur = new LinusTorvalds(mainwin,*image_joueur,map_courante);
        mainwin->Draw(*(joueur->getSprite()));
        joueur->setPosition(Vector2f(PLAYER_X_START*BASE_SPRITE ,PLAYER_Y_START*BASE_SPRITE));
        //entitys.push_front(joueur);
        break;
      }

   }
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



