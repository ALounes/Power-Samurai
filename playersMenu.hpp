#ifndef PLAYERSMENU_HPP
#define PLAYERSMENU_HPP
#include "stdafx.hpp"
#include <list>

class PlayersMenu
{

public:


  

  PlayersMenu ();
  ~PlayersMenu ();

	enum PlayersResult {p1,p2,p3,p4,Nothing, Escape, Return};	
	
	struct PlayersItem
		{
		public:
			String texte;
			PlayersResult action;
			sf::Sprite sprite;
		};
	
	void Load(sf::RenderWindow *window);
	PlayersResult Show(sf::RenderWindow *window);

private:
	PlayersResult GetPlayersResponse(sf::RenderWindow *window);
	PlayersResult HandleKey(int position, sf::RenderWindow *window);
	
	std::list<PlayersItem> *playersItems_;
	
	sf::Image *image_p1_;
	sf::Image *image_p2_;
	sf::Image *image_p3_;
	sf::Image *image_p4_;
	sf::Image *image_arrow_;
	sf::Image *image_main_players_;
	
	sf::Sprite *sprite_main_players_;
	sf::Sprite *sprite_arrow_;
	
	int * position_fleche_;
	
};

#endif 
