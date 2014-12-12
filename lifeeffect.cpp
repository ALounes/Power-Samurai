#include "lifeeffect.hpp"

LifeEffect::LifeEffect(RenderWindow *win,Player *myPlayer)
:win_(win)
,nbrOfEfffect_(DEFAULT_NBR_EFFECT)
{
	if(!myImg_.LoadFromFile("sprite/Life.png"))
		cout << "erreur de chargement image" << endl ;

	if(!effectImg_.LoadFromFile("sprite/LifeEffect.png"))
		cout << "erreur de chargement image" << endl ;

	animEffect_ = new AnimationEffect(win, effectImg_, Vector2i(LIFE_EFFECT_X,LIFE_EFFECT_Y));

	mySprite_.SetImage(myImg_);
}

LifeEffect::~LifeEffect() 
{
	delete animEffect_;
}
