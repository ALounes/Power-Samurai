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
	void keyPressedManagement (sf::Key::Code keyPressed);
	void fire(enum direction dir);
	void launchingPause();
  
   
	

private:
	 bool IsExiting();
	 void GameLoop();
	
	 void ShowSplashScreen();
	 void ShowPlayersMenu();
	 void ShowDifficultyMenu();
	 void ShowMainMenu();
	 void RunGame();

	enum GameState { Uninitialized, ShowingSplash, Paused, 
					ShowingMainMenu, ShowingPlayersMenu, ShowingDifficultyMenu, Playing, Exiting };

	GameState * _gameState;
   MainMenu * _mainMenu;
   DifficultyMenu * _difficultyMenu;
   PlayersMenu * _playersMenu;
   
	list<Entity*> entitys;
	list<AnimationEffect*> effects;
   
   Map * _map_1;
   Map * _map_2;
   Map * _map_3;
   Map * _map_4;
   
   Map *_map_courante;
	
	 sf::RenderWindow  * _mainWindow;
};


#endif 
