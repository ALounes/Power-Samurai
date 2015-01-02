#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <list>
#include <sstream>
#include <string>
#include <time.h> 
#include "stdafx.hpp"
#include "mainMenu.hpp"
#include "splashScreen.hpp"
#include "difficultyMenu.hpp"
#include "playersMenu.hpp"
#include "map.hpp"
#include "entity.hpp"
#include "bot.hpp"
#include "player.hpp"
#include "images_animation.hpp"
#include "animationeffect.hpp"
#include "linustorvalds.hpp"
#include "bjarnestroustrup.hpp"
#include "alanturing.hpp"
#include "gracehopper.hpp"
#include "camera.hpp"
#include "config.hpp"
#include "projectile.hpp"
#include "item.hpp"
#include "statusbar.hpp"
#include "folowinganimation.hpp"
#include "staticanimation.hpp"
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
#include "devil1.hpp"



#define EASY_DIFFICULTY 0.5
#define INTERMEDIATE_DIFFICULTY 1
#define HARD_DIFFICULTY 1.5

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

#define PERCENTAGE_UPGRADE 0.005 / ResultDifficulty
#define PERCENTAGE_REGENERATION 0.005 / ResultDifficulty
#define DROP_CHANCE 2*100

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

	void addEntity(Bot *entity);        //Ajoute/supprime un bot à la liste de monstres
	void removeEntity(Bot *entity);		
	void displayEntity(Clock &time);    // Gère l'affichage des entités

	void addEffect(AnimationEffect *effect);     // Ajoute/supprime/affiche les effets
	void removeEffect(AnimationEffect *effect);		
	void displayEffect(Clock &time);

	void eventManagement(Event &event);          // Gère les événements sur la fenêtre
	void keyPressedManagement (Key::Code keyPressed);  // Gère la gestion de l'appui des touches
	void launchingPause();                             // Lance la pause. Elle a été implémenté pour mettre en pause tout le jeu à l'aide d'une boucle while
	void loadBot(int);                           // Charge les monstres
	void loadItem();                          // Charge les items
	void loadHP(int coordx, int coordy, Map *map);     // Permet d'ajouter une potion de vie sur une map
	void loadMana(int coordx, int coordy, Map *map);   // Permet d'ajouter une potion de mana sur une map
	
	void launchBloodEffect(LivingEntity * e);    // Lance une animation de sang
	void launchDeathEffect(LivingEntity * e);    // Lance une animation de mort d'un monstre
	
	void launchingDeath();     // Gère la mort du joueur
	void launchingVictory();   // Gère la victoire
	void upgrade();            // Chaque fois qu'un monstre meurt, on améliore le personnage
	
	void loadDragon(Map *map, int id, int range, int coordx, int coordy);      // Construction des monstres
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
   void loadDevil(Map *map, int id, int range, int coordx, int coordy);
   void loadNaga(Map *map, int id, int range, int coordx, int coordy);
   void loadReddragon1(Map *map, int id, int range, int coordx, int coordy);
   void loadRedeye(Map *map, int id, int range, int coordx, int coordy);
   void loadRedscorpion(Map *map, int id, int range, int coordx, int coordy);
   
   void launchStartDialogue(string s, int coordx, int coordy);             // Gère l'affichage d'un dialogue
   
   void randomDrop(int x, int y);         // Gère le drop d'items lorsqu'un monstre meurt
  
private:

   // Le jeu a plusieurs états. Chaque Menu en a un, puis nous avons un état Pause, Playing, et Exiting. Suivant cet état, on lance différentes fonction

	bool IsExiting();    // Permet de signaler que le jeu doit quitter.
	void GameLoop();     // Boucle de jeu 
	
	void ShowSplashScreen();   // Lance le SplashScreen
	void ShowPlayersMenu();    // Lance le Menu de choix du perso
	void ShowDifficultyMenu(); // Lance le Menu de difficultés
	void ShowMainMenu();       // Lance le Menu principal
	void RunGame();            // Lance le jeu
	void setPlayer(RenderWindow  * mainwin);  // Permet de sauvegarder le choix du perso 
	void setDifficulty();                     // Permet de sauvegarder le choix de difficulté


   enum GameState { Uninitialized, ShowingSplash, Paused, 
					ShowingMainMenu, ShowingPlayersMenu, ShowingDifficultyMenu, Playing, Exiting };


	GameState *gameState_;     // Variable de status de jeu
   MainMenu  *mainMenu_;
   DifficultyMenu *difficultyMenu_;
   PlayersMenu    *playersMenu_;
   
	list<Bot*> entitys;              // Liste des bots
	list<AnimationEffect*> effects;  // Liste des Animations dynamiques
	list<StaticAnimation*> static_effects; // Liste des Animations statiques
	list<Projectile*> projectiles;      // Liste des projectiles
	list<Item*> items;                  // Liste des items
	
	Images all_images;                  // Classe contenant toutes les images
	 
	Player *joueur;
	Image  *image_joueur;
	Image  *image_death_joueur;
	
	RenderWindow  *mainWindow_;
	Camera *camera;
	View   * view;
	 
	p_choice *player_choice;            // Enregistre la position de la flèche dans le playersMenu, permettant d'ensuite construire le personnage
	float ResultDifficulty = EASY_DIFFICULTY; // Enregistre la difficulté
	
   Map    *map_1;
   Map    *map_2;
   Map    *map_3;
   Map    *map_4;
   Map    *map_5;
   Map    *map_courante;
  
   Clock * Timer_Projectile;	
   Clock * Timer_Items;
   Clock * Timer_Spell;
   Clock * Timer_Victory;
	
	bool game_victory = false;
	
};


#endif 
