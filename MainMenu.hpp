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
			sf::Sprite * sprite;
		};
	
	void Load(sf::RenderWindow *window);
	MenuResult Show(sf::RenderWindow *window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow *window);
	MenuResult HandleClick(int x, int y);
	void HandleMove(int x, int y,sf::RenderWindow *window);
	
	std::list<MenuItem> *_menuItems;
	
	sf::Image *image_main;
	sf::Image *image_play;
	sf::Image *image_exit;
	sf::Image *image_difficulty;
	sf::Image *image_players;
	
	sf::Sprite *sprite_main_all; 
};

#endif 
