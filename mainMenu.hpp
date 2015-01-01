#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "stdafx.hpp"
#include <list>

class MainMenu
{

public:

  MainMenu ();
  ~MainMenu ();

	enum MenuResult { Nothing, Exit, Play, Difficulty, Players, Help};	
	
	struct MenuItem
		{
		public:
			Rect<int> rect;
			MenuResult action;
			Sprite sprite;
		};
	// Afficher l'image principale
	void Load(RenderWindow *window);
	MenuResult Show(RenderWindow *window);
	
	Music* getMusic() const;
   void setMusic(string s);

private:
	MenuResult GetMenuResponse(RenderWindow *window);
	MenuResult HandleClick(int x, int y);
	void HandleMove(int x, int y,RenderWindow *window);
	
	std::list<MenuItem> *menuItems_;
	
	sf::Image *image_main_;
	sf::Image *image_play_;
	sf::Image *image_exit_;
	sf::Image *image_difficulty_;
	sf::Image *image_players_;
	sf::Image *image_help_;
	
	int on_button = 0;
	
	Music* music_;
	
	sf::Sprite *sprite_main_all_; 
};

#endif 
