#include "player.hpp"


Player::Player(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name,
					int life, int mana, enum power power)
:Entity(win,image,nbrOfAnim)
,name_(name)
,life_(life)
,mana_(mana)
,power_(power)
{
	play();
}

Player::~Player()
{

}

void
Player::move(Key::Code keyPressed)
{
	const sf::Input &input = win_->GetInput();

	switch (keyPressed) 
	{
	case sf::Key::Z :
		runMove();
		if( input.IsKeyDown(Key::D))
			moveUpRight();
		else if( input.IsKeyDown(Key::Q))
			moveUpLeft();
		else
			moveUp();
		break;

	case sf::Key::S :
		runMove();
		if( input.IsKeyDown(Key::D))
			moveDownRight();
		else if( input.IsKeyDown(Key::Q))
			moveDownLeft();
		else
			moveDown();
		break;

	case sf::Key::Q :
		runMove();
		if( input.IsKeyDown(Key::Z))
			moveUpLeft();
		else if( input.IsKeyDown(Key::S))
			moveDownLeft();
		else
			moveLeft();
		break;

	case sf::Key::D :
		runMove();
		if( input.IsKeyDown(Key::Z))
			moveUpRight();
		else if( input.IsKeyDown(Key::S))
			moveDownRight();
		else
			moveRight();
		break;

	case sf::Key::Space :
		// A FAIRE 
		break;

	case sf::Key::Escape :
		if(isPlaying())
			pause();
		else
			play();
		break;

	default: 
		break;
  }
}

void 
Player::update()
{
	if (isMoving())
	{
		updateSprite();
		animationRight();
		stopMove();
	}
}

String 
Player::getName() const
{
	return name_;
}

int 
Player::getLife() const
{
	return life_;
}

int 
Player::getMana() const
{
	return mana_;
}

void 
Player::setName(String name)
{
	name_ = name;
}

void 
Player::setLife(int life)
{
	life_ = life;
}

void 
Player::setMana(int mana)
{
	mana_ = mana;
}

