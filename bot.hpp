#ifndef BOT_HPP
#define BOT_HPP

//#include <random>
#include "config.hpp"
#include "map.hpp"
#include "player.hpp"
#include "folowinganimation.hpp"
#include "livingentity.hpp"

#define DEFAULT_RANGE 10



using namespace std;

/*!
*\class Bot
*\brief Classe représentant les monstres
*
*La classe gère le déplacement des monstres à l'aide de l'algorithme A*
*/

class Bot: public LivingEntity
{
	public :
	
	/*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Bot
     *
     *  \param listSongs : liste initial des morceaux
     */
	
	Bot(RenderWindow *win, Image &image, const Vector2i nbrOfAnim, String name, int life, int mana, enum power power, Map *myMap, float att_dmg, float att_delay, float ResultDiff, int ident, int rangebot, int xp, Image* image1, Image* image2, Image* image3);
		
	virtual ~Bot();

   //Inutilisé
	void move();
	
	// Permet d'assigner et de récupérer la range de détection 
	void SetRange(int range);
	int GetRange() const;
	// Permet d'assigner et de récupérer la vitesse de déplacement
	void SetSpeed(int speed);
	int GetSpeed() const;
	
	
	// Permet d'assigner et de récupérer le pointeur sur le joueur de référence.
	void SetPlayer(Player * player);
	Player * GetPlayer() const;
	
	// Permet de récupérer le chemin entre le monstre et le joueur
	string GetPath() const ;
	

	// Permet d'assigner et de récupérer la range de détection du monstre
	void setRange(int);
	int getRange();
	
	// Permet d'assigner et de récupérer la distance entre le joueur et le monstre
	void setDistance(int);
	int getDistance();
	
	// Permet d'assigner et de récupérer l'xp 
	void setXp(int);
	int getXp() const;
	
	// Permet d'assigner et de récupérer le délai d'attaque
   void setAttackDelay(float);
	float getAttackDelay();
	
	// Permet d'assigner et de récupérer le champ in_pursuit. Une fois à "true". Il ne peut que passer de l'état false à true
	void inPursuit();
	bool getPursuit();
	
		// drawRect permet de construire la barre de vie des monstres et de la dessiner dans la fenêtre
	void drawRect();
	
	// Inspiré de l'algorithme A star (A*), retourne le plus court chemin, en prenant en compte les obstacles, sous la forme d'une chaîne de caractère représentant les directions à suivre.
	string pathFind( const int & xStart, const int & yStart, const int & xFinish, const int & yFinish, Map * map_);
	
	
	// Permet de mettre à jour le chemin du bot avec les coordonnées du bot et du joueur.
	void update_path(Map * map,Player * player);
	
	//follow_path gère la création des sorts suivant si la distance au joueur est plus petite que la distance de lancer du sort, ainsi que le déplacement du joueur suivant le chemin le plus court.
	void follow_path(Map *map, Player * player);
	
	//Met à jour le sprite suivant le déplacement.
	void update(); 
	
	Shape Rect ;
	
	Clock* getRefresh() const;
	
	
	private:
	
	string path;      /*!< Chemin entre le monstre et le joueur*/
	Player * player_; /*!< Pointeur sur le joueur de référence*/
	
	int range_ = DEFAULT_RANGE; /*!< Rayon de détection du Bot*/
	int speed_;/*!<Vitesse du bot*/
	int distance = 100; /*!< Donne la distance entre le joueur et le Bot*/

	float attack_delay;
	int xp_;          /*!< Xp que rapporte le Bot à sa mort.*/
	
	bool in_pursuit = false;   /*!< Etat du Bot. Une fois en poursuite, il poursuit le joueur jusqu'à sa mort ou celle du joueur.*/
	Clock * Timer_Refresh_;
	//uniform_int_distribution<int> distribution(random_minimum,random_maximum);
	//defalut_random_engine generateur;
};

#endif
