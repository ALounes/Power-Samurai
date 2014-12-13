#include "animation.hpp"

Animation::Animation(RenderWindow *win, Image &image, const Vector2i& nbrOfAnim)
: win_(win)
, paused_(false)
, myImage_(image)
, numberOfAnim_(nbrOfAnim)
, animationFps_(DEFAULT_ANIM_FPS)
, anim_(1,0) 
{
	mySprite_ = new Sprite();
	mySprite_->SetImage(image); 

	sizeImage_.x    = image.GetWidth(); 
	sizeImage_.y    = image.GetHeight(); 
	sizeSprite_.x   = image.GetWidth()  / nbrOfAnim.x;
	sizeSprite_.y   = image.GetHeight() / nbrOfAnim.y;

	setDefaultSprite();
}

Animation::~Animation()
{
	 delete mySprite_;
}
 
Sprite* 
Animation::getSprite() const
{
	return mySprite_;
}

void
Animation::setAnimation(int i)
{
	int x ,y ;
 
	x = i % numberOfAnim_.x;
	y = i / numberOfAnim_.x;

	setAnimationX(x);
	setAnimationY(y);
	updateSprite();
}

void 
Animation::setImage(const string imageName)
{
	myImage_.LoadFromFile(imageName);
}


int  
Animation::getWidth () const
{
	return sizeImage_.x ;
}

int  
Animation::getHeight() const
{
	return sizeImage_.y;
}

int  
Animation::getAnimationWidth () const
{
	return sizeSprite_.x;
}

int  
Animation::getAnimationHeight() const
{
	return sizeSprite_.y;
}

Vector2f 
Animation::getCenter() const
{
	Vector2f new_position , position = getPosition();
	
	new_position.x = position.x + getAnimationWidth()  / 2; 
	new_position.y = position.y + getAnimationHeight() / 2;
	
	return new_position;
}

void 
Animation::setPosition(Vector2f position)
{
	mySprite_->SetPosition(position);
}

void 
Animation::setCenter(Vector2f position)
{
	Vector2f new_position;
	new_position.x = position.x - getAnimationWidth() / 2; 
	new_position.y = position.y - getAnimationHeight() / 2;
	
	mySprite_->SetPosition(new_position);
}


Vector2f 
Animation::getPosition() const
{
	return mySprite_->GetPosition();
}


void 
Animation::updateSprite()
{
	const int &x1 = anim_.x * sizeSprite_.x;
	const int &y1 = anim_.y * sizeSprite_.y;
	const int &x2 = x1 + sizeSprite_.x;
	const int &y2 = y1 + sizeSprite_.y;

	mySprite_->SetSubRect(IntRect(x1,y1,x2,y2));
}

void  
Animation::animationUp()
{
	if((anim_.y * sizeSprite_.y) > 0 )
		anim_.y--;
	else 
		anim_.y = (sizeImage_.y / sizeSprite_.y) - 1;
}

void  
Animation::animationDown()
{
	if( (anim_.y * sizeSprite_.y) < sizeImage_.y)
		anim_.y++;
	else 
		anim_.y = 0;
}

void  
Animation::animationLeft()
{
	if((anim_.x * sizeSprite_.x) > 0 )
		anim_.x--;
	else 
		anim_.x = (sizeImage_.x / sizeSprite_.x) - 1;
}

void  
Animation::animationRight()
{
	if((anim_.x * sizeSprite_.x) < sizeImage_.x - sizeSprite_.x)
		anim_.x++;
	else 
		anim_.x = 0;
}

void 
Animation::setAnimationX(int x)
{
	anim_.x = x;
}

void 
Animation::setAnimationY(int y)
{
	anim_.y = y;
}

int
Animation::getAnimationX() const
{
 	return anim_.x;
}

int 
Animation::getAnimationY() const
{
	return anim_.y;
}

void 
Animation::play()
{  
	paused_ = true;
}

void 
Animation::pause()
{
	paused_ = false;
}

bool
Animation::isPlaying() const
{
	return paused_;
}

void
Animation::SetAnimFps(int &fps)
{
	animationFps_ = fps;
}

int 
Animation::getAnimFps() const
{
	return animationFps_;
}

void 
Animation::display()
{
	win_->Draw(*mySprite_);
}

void 
Animation::setDefaultSprite()
{
	mySprite_->SetSubRect(IntRect(A_SPRITE_BEGIN_X,
											A_SPRITE_BEGIN_Y,		
											A_SPRITE_END_X,
											A_SPRITE_END_Y));
}


/***************************************************/
/***************************************************/
