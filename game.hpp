#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <list>
#include "stdafx.hpp"
#include "mainMenu.hpp"
#include "splashScreen.hpp"
#include "difficultyMenu.hpp"
#include "playersMenu.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "animationeffect.hpp"
#include "linustorvalds.hpp"
#include "bjarnestroustrup.hpp"
#include "alanturing.hpp"
#include "athena.hpp"
#include "camera.hpp"
#include "config.hpp"
#include "projectile.hpp"
#include "item.hpp"
#include "statusbar.hpp"
#include "folowinganimation.hpp"
#include "greendragon.hpp"
#include "troll.hpp"
#include "armor1.hpp"
#include "reaper1.hpp"
#include "fantome1.hpp"
#include "fantome2.hpp"
#include "squelette.hpp"
#include "bat.hpp"
#include "bee.hpp"
#include "blueslime.hpp"
#include "greendragon1.hpp"
#include "greenscorpion.hpp"
#include "greenslime.hpp"
#include "mouse1.hpp"
#include "naga.hpp"
#include "reddragon1.hpp"
#include "redeye.hpp"
#include "redscorpion.hpp"



#define EASY_DIFFICULTY 1
#define INTERMEDIATE_DIFFICULTY 2 
#define HARD_DIFFICULTY 3

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

enum direction {DOWN,LEFT,RIGHT,UP};
enum p_choice {P1,P2,P3,P4};

class Game
{
public:

  	Game ();
  	~Game ();
   
   //Charger et initialiser les cartes. 
   void Map_Load();
	void Start();

	void addEntity(Bot *entity);
	void removeEntity(Bot *entity);		
	void displayEntity(Clock &time);

	void addEffect(AnimationEffect *effect);
	void removeEffect(AnimationEffect *effect);		
	void displayEffect(Clock &time);

	void eventManagement(Event &event);
	void keyPressedManagement (Key::Code keyPressed);
	void launchingPause();
	void loadBot();
	void loadItem();
	void loadHP(int coordx, int coordy, Map *map);
	void loadMana(int coordx, int coordy, Map *map);
	void loadSpell();
	void loadImages();
	void launchingDeath();
	void loadDragon(Map *map, int id, int range, int coordx, int coordy);
	void loadTroll(Map *map, int id, int range, int coordx, int coordy);
	void loadArmor1(Map *map, int id, int range, int coordx, int coordy);
	void loadReaper1(Map *map, int id, int range, int coordx, int coordy);
   void loadFantome1(Map *map, int id, int range, int coordx, int coordy);
   void loadFantome2(Map *map, int id, int range, int coordx, int coordy);
   void loadSquelette(Map *map, int id, int range, int coordx, int coordy);
   
   void loadBat(Map *map, int id, int range, int coordx, int coordy);
   void loadBee(Map *map, int id, int range, int coordx, int coordy);
   void loadBlueslime(Map *map, int id, int range, int coordx, int coordy);
   void loadGreendragon1(Map *map, int id, int range, int coordx, int coordy);
   void loadGreenscorpion(Map *map, int id, int range, int coordx, int coordy);
   void loadGreenslime(Map *map, int id, int range, int coordx, int coordy);
   
   void loadMouse1(Map *map, int id, int range, int coordx, int coordy);
   void loadNaga(Map *map, int id, int range, int coordx, int coordy);
   void loadReddragon1(Map *map, int id, int range, int coordx, int coordy);
   void loadRedeye(Map *map, int id, int range, int coordx, int coordy);
   void loadRedscorpion(Map *map, int id, int range, int coordx, int coordy);
   
   
  
private:

	bool IsExiting();
	void GameLoop();
	
	void ShowSplashScreen();
	void ShowPlayersMenu();
	void ShowDifficultyMenu();
	void ShowMainMenu();
	void RunGame();
	void setPlayer(RenderWindow  * mainwin);
	void setDifficulty();


   enum GameState { Uninitialized, ShowingSplash, Paused, 
					ShowingMainMenu, ShowingPlayersMenu, ShowingDifficultyMenu, Playing, Exiting };

	GameState *gameState_;
   MainMenu  *mainMenu_;
   DifficultyMenu *difficultyMenu_;
   PlayersMenu    *playersMenu_;
   
	list<Bot*> entitys;
	list<AnimationEffect*> effects;
	list<Projectile*> projectiles;
	list<Item*> items;
	 
	Player *joueur;
	Image  *image_joueur;
	
	RenderWindow  *mainWindow_;
	Camera *camera;
	View   * view;
	 
	p_choice *player_choice;
	float ResultDifficulty = EASY_DIFFICULTY;
	
   Map    *map_1;
   Map    *map_2;
   Map    *map_3;
   Map    *map_4;
   Map    *map_5;
   Map    *map_courante;
   
   //Music *music_courante_;
  
   Clock * Timer_Projectile;	
   Clock * Timer_Items;
   Clock * Timer_Spell;
	

	Image *image_projectile;
	Image *image_hp_item;
	Image *image_mana_item;
	
	Image *image_Armor1;
	Image *image_Devil1;
	Image *image_Dragon1;
	Image *image_Fantome1;
	Image *image_Fantome2;
	Image *image_Reaper1;
	Image *image_Squelette;
	Image *image_Troll;
	
	Image *image_Bat;
	Image *image_Bee;
	Image *image_Blueslime;
	Image *image_Greendragon1;
	Image *image_Greenscorpion;
	Image *image_Greenslime;
	Image *image_Mouse1;
	Image *image_Naga;
	
	Image *image_Reddragon1;
	Image *image_Redeye;
	Image *image_Redscorpion;
};


#endif 
