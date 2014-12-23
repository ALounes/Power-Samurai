#include <sstream>
#include <SFML/Graphics.hpp>
#include "statusbar.hpp"

StatusBar::StatusBar(RenderWindow *win, Player *player, Camera *camera)
	: win_(win)
	, player_(player)
	, camera_(camera)
{
	myImage_  = new Image();
	myImage_->LoadFromFile("images/StatusBar/StatusBar.png");

	mySprite_ = new Sprite();
	mySprite_->SetImage(*myImage_);

	persoSprite_ = new Sprite();

	myText_ = new String();	
	myText_->SetSize(25);
	myText_->SetStyle(sf::String::Bold);
	myText_->SetColor(sf::Color(0, 0, 0));
	myText_->SetFont(sf::Font::GetDefaultFont());
	myText_->SetPosition(10,win_->GetHeight()-23);
	myText_->SetText("02         02");	

	position_ = camera->getPosition();

	statuLife_ = Shape::Rectangle(0,
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
												MANA_BORDURE_COLOR);
}


StatusBar::~StatusBar()
{
	delete mySprite_;
	delete myImage_;
	delete myText_;
	delete persoSprite_;
}

void 
StatusBar::update()
{
	//statuLife_.SetScaleX(0.5);

	myText_->SetPosition  (TEXT_POSITION_X, TEXT_POSITION_Y);
	mySprite_->SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);

	statuLife_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuMana_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);
	statuLifeRed_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuManaRed_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);
}

void
StatusBar::display ()
{
   
   playLifeEffect(getPlayer());
   playManaEffect(getPlayer());
	update();

	win_->Draw(*mySprite_);
	
	win_->Draw(statuLife_);
	win_->Draw(statuMana_);
	win_->Draw(statuLifeRed_);
	win_->Draw(statuManaRed_);
	win_->Draw(*myText_);
}


void StatusBar::playLifeEffect(Player *player) {
   
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
	
}

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
StatusBar::setSprite(Sprite *sprite)
{
	mySprite_ = sprite;
}


void 
StatusBar::setImage(Image *image)
{
	myImage_ = image;
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


Sprite* 
StatusBar::getSprite() const
{
	return mySprite_;
}


Image*  
StatusBar::getImage()  const
{
	return myImage_;
}


