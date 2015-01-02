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
	
	list<MenuItem> *menuItems_;
	
	Image *image_main_;
	Image *image_play_;
	Image *image_exit_;
	Image *image_difficulty_;
	Image *image_players_;
	Image *image_help_;
	
	int on_button = 0;
	
	Music* music_;
	Clock *Mouse_Refresh;
	
	Sprite *sprite_main_all_; 
};

#endif 
