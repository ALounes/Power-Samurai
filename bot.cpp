#include "bot.hpp"

Bot::Bot(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name,
			int life, int mana, enum power power)
:Entity(win,image,nbrOfAnim)
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


