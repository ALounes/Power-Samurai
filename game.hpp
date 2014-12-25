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
#include "camera.hpp"
#include "config.hpp"
#include "bjarnestroustrup.hpp"
#include "alanturing.hpp"
#include "projectile.hpp"
#include "item.hpp"
#include "statusbar.hpp"
#include "folowinganimation.hpp"

#define EASY_DIFFICULTY 1
#define INTERMEDIATE_DIFFICULTY 2 
#define HARD_DIFFICULTY 3



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
	void loadSpell();
	void loadImages();
  
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
};


#endif 
