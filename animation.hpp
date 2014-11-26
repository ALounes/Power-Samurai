#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#define DEFAULT_ANIM_FPS 0.25

#include <SFML/Graphics.hpp>
#include "config.hpp"

using namespace sf;

class Animation 
{
	public :

	Animation(RenderWindow *win, Image& image, Vector2i nbrOfAnim);
	~Animation();

	int  getWidth () const;
	int  getHeight() const;
	int  getAnimationWidth () const;
	int  getAnimationHeight() const;
	
	void setPosition(Vector2f &position);
	
	void play();
	void pause();
	bool isPlaying();
	void SetAnimFps(int &fps);
	int  getAnimFps() const;
	void updateSprite();

	void animationUp();
	void animationDown();
	void animationLeft();
	void animationRight();

	void setAnimationX(int x);
	void setAnimationY(int y);
	int  getAnimationX() const;
	int  getAnimationY() const;

	virtual void setDefaultSprite();

	void display();

	protected:
	Sprite    *mySprite_;
	RenderWindow *win_;

	private:
	Image     &myImage_;
	Vector2i  sizeImage_; 
	Vector2i  sizeSprite_;
	Vector2i  &numberOfAnim_;

	int	  animationFps_;
	Vector2i  anim_;
	bool	  moving_;

};

#endif
