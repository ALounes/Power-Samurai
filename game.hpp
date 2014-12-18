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


enum direction {DOWN,LEFT,RIGHT,UP};

class Game
{
public:

  	Game ();
  	~Game ();

   void Map_Load();
	void Start();

	void addEntity(Entity *entity);
	void removeEntity(Entity *entity);		
	void displayEntity(Clock &time);

	void addEffect(AnimationEffect *effect);
	void removeEffect(AnimationEffect *effect);		
	void displayEffect(Clock &time);

	void eventManagement(Event &event);
	void keyPressedManagement (Key::Code keyPressed);
	void launchingPause();
  
private:
	 bool IsExiting();
	 void GameLoop();
	
	 void ShowSplashScreen();
	 void ShowPlayersMenu();
	 void ShowDifficultyMenu();
	 void ShowMainMenu();
	 void RunGame();
	 void setPlayer(RenderWindow  * mainwin,Image * image_joueur);


  enum GameState { Uninitialized, ShowingSplash, Paused, 
					ShowingMainMenu, ShowingPlayersMenu, ShowingDifficultyMenu, Playing, Exiting };

	 GameState * gameState_;
   MainMenu * mainMenu_;
   DifficultyMenu * difficultyMenu_;
   PlayersMenu * playersMenu_;
	 list<Entity*> entitys;
	 list<AnimationEffect*> effects;
	 
	Player * joueur;
	Image * image_joueur;
	Camera * camera;
	int * player_choice;
	View * view;
   Map *map_1;
   Map *map_2;
   Map *map_3;
   Map *map_4;
   Map *map_courante;
	RenderWindow  * mainWindow_;
};


#endif 
