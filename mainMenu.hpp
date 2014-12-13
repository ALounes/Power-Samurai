#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "stdafx.hpp"
#include <list>

class MainMenu
{

public:

  MainMenu ();
  ~MainMenu ();

	enum MenuResult { Nothing, Exit, Play, Difficulty, Players};	
	
	struct MenuItem
		{
		public:
			sf::Rect<int> rect;
			MenuResult action;
			sf::Sprite sprite;
		};
	
	void Load(sf::RenderWindow *window);
	MenuResult Show(sf::RenderWindow *window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow *window);
	MenuResult HandleClick(int x, int y);
	void HandleMove(int x, int y,sf::RenderWindow *window);
	
	std::list<MenuItem> *menuItems_;
	
	sf::Image *image_main_;
	sf::Image *image_play_;
	sf::Image *image_exit_;
	sf::Image *image_difficulty_;
	sf::Image *image_players_;
	
	sf::Sprite *sprite_main_all_; 
};

#endif 
