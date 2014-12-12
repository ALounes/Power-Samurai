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
			sf::Sprite *sprite;
		};
	
	void Load(sf::RenderWindow *window);
	PlayersResult Show(sf::RenderWindow *window);

private:
	PlayersResult GetPlayersResponse(sf::RenderWindow *window);
	PlayersResult HandleKey(int position, sf::RenderWindow *window);
	
	std::list<PlayersItem> *_playersItems;
	
	sf::Image *image_p1;
	sf::Image *image_p2;
	sf::Image *image_p3;
	sf::Image *image_p4;
	sf::Image *image_arrow;
	sf::Image *image_main_players;
	
	sf::Sprite *sprite_main_players;
	sf::Sprite *sprite_arrow;
	
	int * position_fleche;
	
};

#endif 
