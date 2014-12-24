#include <sstream>
#include <SFML/Graphics.hpp>
#include "statusbar.hpp"

StatusBar::StatusBar(RenderWindow *win, Player *player, Camera *camera)
	: player_(player) 
	,win_(win)	
	,camera_(camera)
{
	StatusBar_  = new Image();
	StatusBar_->LoadFromFile("images/StatusBar/StatusBar.png");
	
	Life_ = new Image();
	Life_->LoadFromFile("images/StatusBar/HP_Bar.png");
	
	Mana_  = new Image();
	Mana_->LoadFromFile("images/StatusBar/Mana_bar.png");

   statuLife_.SetImage(*Life_);
   statuMana_.SetImage(*Mana_);
   statusBar_.SetImage(*StatusBar_);

   /*String *NamePlayer_;
	String *Level_;
	String *HP_Pot_Nb_;
	String *HP_Mana_Nb_;*/
	
	NamePlayer_ = new String();
	NamePlayer_->SetSize(25);
	NamePlayer_->SetStyle(11);
	NamePlayer_->SetColor(Color(0, 0, 0));
	NamePlayer_->SetFont(Font::GetDefaultFont());
	NamePlayer_->SetPosition(10,win_->GetHeight()-23);
   //String gne = player_->getName();
	*NamePlayer_ = player_->getName();	   


	position_ = camera->getPosition();

	/*statuLife_ = Shape::Rectangle(0,
										   0,
											118,
											12,
											LIFE_COLOR,
											LIFE_BORDURE,
											LIFE_BORDURE_COLOR); 

	statuMana_ = Shape::Rectangle(0,
										   0,
											118,
											12,
											MANA_COLOR,
											MANA_BORDURE,
											MANA_BORDURE_COLOR); 

	statuLifeRed_ = Shape::Rectangle(0,
										  		0,
												118,
												12,
												RED_COLOR,
												LIFE_BORDURE,
												LIFE_BORDURE_COLOR);

	statuManaRed_ = Shape::Rectangle(0,
										   	0,
												118,
												12,
												RED_COLOR,
												MANA_BORDURE,
												MANA_BORDURE_COLOR);*/
}


StatusBar::~StatusBar()
{
	
}

void 
StatusBar::update()
{
	//statuLife_.SetScaleX(0.5);

   NamePlayer_->SetPosition(TEXT_POSITION_X, TEXT_POSITION_Y);
	//myText_->SetPosition  (TEXT_POSITION_X, TEXT_POSITION_Y);
	statusBar_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);

	/*statuLife_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuMana_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);
	statuLifeRed_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuManaRed_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);*/
}

void
StatusBar::display ()
{
   
   //playLifeEffect(getPlayer());
   //playManaEffect(getPlayer());
	update();

	win_->Draw(statusBar_);
	win_->Draw(*NamePlayer_);
}


/*void StatusBar::playLifeEffect(Player *player) {
   
   statuLifeRed_ = Shape::Rectangle((int) 118 * ( (float) player->getLife() / (float) player->getLifeMax() ),
										  		0,
												118,
												12,
												RED_COLOR,
												LIFE_BORDURE,
												LIFE_BORDURE_COLOR);
}

void StatusBar::playManaEffect(Player *player) {
	statuManaRed_ = Shape::Rectangle((int) 118 * ( (float) player->getMana() / (float) player->getManaMax() ),
										   	0,
												118,
												12,
												RED_COLOR,
												MANA_BORDURE,
												MANA_BORDURE_COLOR);
	
}*/

void 
StatusBar::setPosition(Vector2f *position)
{
	position_->x = position->x;
	position_->y = position->y; 
}

void 
StatusBar::setPlayer(Player *player)
{
	player_ = player;
}

void 
StatusBar::setWindow(RenderWindow *win)
{
	win_ = win;
}


void 
StatusBar::setSprite(Sprite sprite)
{
	statusBar_ = sprite;
}


void 
StatusBar::setImage(Image *image)
{
	StatusBar_ = image;
}

Vector2f* 
StatusBar::getPosition() const
{
	return position_;
}


Player*
StatusBar::getPlayer() const
{
	return player_;
}


RenderWindow* 
StatusBar::getWindow() const
{
	return win_;
}


Sprite 
StatusBar::getSprite() const
{
	return statusBar_;
}


Image*  
StatusBar::getImage()  const
{
	return StatusBar_;
}


