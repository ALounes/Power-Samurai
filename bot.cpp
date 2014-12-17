#include "bot.hpp"

Bot::Bot(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, String name,
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
	/*if (player_->getPosition())*/
	
}

void
Bot::SetRange(int range)
{
	range_ = range;
}

int Bot::GetRange() {
   return range_;
}
void Bot::SetSpeed(int speed) {
   speed_ = speed;
}

int Bot::GetSpeed() {
   return speed_;
}
