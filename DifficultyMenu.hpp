#ifndef DIFFICULTYMENU_HPP
#define DIFFICULTYMENU_HPP
#include "stdafx.hpp"
#include <list>

class DifficultyMenu
{

public:

  DifficultyMenu ();
  ~DifficultyMenu ();

	enum DifficultyResult { Easy, Intermediate, Hard, Escape, Nothing};	
	
	struct DifficultyItem
		{
		public:
			sf::Rect<int> rect;
			DifficultyResult action;
			sf::Sprite *sprite;
		};
	
	void Load(sf::RenderWindow *window);
	DifficultyResult Show(sf::RenderWindow *window);

private:
	DifficultyResult GetDifficultyResponse(sf::RenderWindow *window);
	DifficultyResult HandleClick(int x, int y);
	void HandleMove(int x, int y,sf::RenderWindow *window);
	std::list<DifficultyItem> *_difficultyItems;
	
	sf::Image *image_main;
	sf::Image *image_easy;
	sf::Image *image_intermediate;
	sf::Image *image_hard;
	
	sf::Sprite *sprite_main_difficulty;
	
};

#endif 
