#include "bot.hpp"

Bot::Bot(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name,
			int life, int mana, enum power power, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
,name_(name)
,life_(life)
,mana_(mana)
,power_(power)
{

}

Bot::~Bot()
{

}

void
Bot::move()
{
	//distribution(generateur);
}


