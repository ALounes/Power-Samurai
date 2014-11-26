#include "player.hpp"


Player::Player(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name,
					 int moveSpeed, int life, int mana, enum power power)
:Entity(win,image,nbrOfAnim,moveSpeed)
,name_(name)
,life_(life)
,mana_(mana)
,power_(power)
{

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

		if( input.IsKeyDown(Key::D))
			moveUpRight();
		else if( input.IsKeyDown(Key::Q))
			moveUpLeft();
		else
			moveUp();
		break;

	case sf::Key::S :

		if( input.IsKeyDown(Key::D))
			moveDownRight();
		else if( input.IsKeyDown(Key::Q))
			moveDownLeft();
		else
			moveDown();
		break;

	case sf::Key::Q :

		if( input.IsKeyDown(Key::Z))
			moveUpLeft();
		else if( input.IsKeyDown(Key::S))
			moveDownLeft();
		else
			moveLeft();
		break;

	case sf::Key::D :

		if( input.IsKeyDown(Key::Z))
			moveUpRight();
		else if( input.IsKeyDown(Key::S))
			moveDownRight();
		else
			moveRight();
		break;

	case sf::Key::Space :
		break;
	
	default: 
		break;
  }
	updateSprite();
	animationRight();
}


