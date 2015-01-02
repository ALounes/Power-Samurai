#ifndef DIFFICULTYMENU_HPP
#define DIFFICULTYMENU_HPP
#include "stdafx.hpp"
#include <list>

class DifficultyMenu
{

public:

  DifficultyMenu (); // le constructeur charge aussi toutes les images nécessaire et initialise les boutons (Position, action, etc)
  ~DifficultyMenu ();
   //Chaque bouton a une action, du type DifficultyResult.
	enum DifficultyResult { Easy, Intermediate, Hard, Escape, Nothing};	
	
	//Structure permettant de rentrer les boutons du menu.
	struct DifficultyItem
		{
		public:
			sf::Rect<int> rect;
			DifficultyResult action;
			sf::Sprite sprite;
		};
   //Load affiche le Menu à l'écran	
	void Load(sf::RenderWindow *window);

   //Show appelle GetDifficultyResponse qui va analyser les actions sur l'écran, et en fonction de cela, afficher les sprites des boutons colorés, et si on clique sur l'un deux, de retourner l'action correspondant
	DifficultyResult Show(sf::RenderWindow *window);

private:
	DifficultyResult GetDifficultyResponse(sf::RenderWindow *window);
	DifficultyResult HandleClick(int x, int y);
	void HandleMove(int x, int y,sf::RenderWindow *window);
	std::list<DifficultyItem> *difficultyItems_;
	
	sf::Image *image_main_;
	sf::Image *image_easy_;
	sf::Image *image_intermediate_;
	sf::Image *image_hard_;
	
	sf::Sprite *sprite_main_difficulty_;
	Clock *Mouse_Refresh;
};

#endif 
