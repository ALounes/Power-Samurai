#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#define DEFAULT_ANIM_FPS 0.25

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Animation 
{
	public :

	Animation(RenderWindow *win, Image& image,const Vector2i &nbrOfAnim);
	~Animation();

	void setImage(const string imageName);

	int  getWidth () const;
	int  getHeight() const;
	int  getAnimFps() const;
	int  getAnimationX() const;
	int  getAnimationY() const;	
	int  getAnimationHeight() const;
	int  getAnimationWidth () const;
	
	Vector2f getPosition() const;	
	Vector2f getCenter()   const;	
	Sprite*  getSprite()   const;

	void setPosition(Vector2f position);
	void setCenter  (Vector2f position);
	void setAnimationWidth  (int x);
	void setAnimationHeight (int x);
	void setAnimationX(int x);
	void setAnimationY(int y);
	void SetAnimFps(int &fps);
	void setAnimation(int i);

	bool isPlaying() const;
	void updateSprite();

	void animationUp();
	void animationDown();
	void animationLeft();
	void animationRight();
	

	void draw();

	virtual void play();
	virtual void pause();
	virtual void setDefaultSprite();

	protected:

	Sprite    *mySprite_;
	RenderWindow *win_;
	bool	paused_;

	private:

	Image     &myImage_;
	Vector2i  sizeImage_; 
	Vector2i  sizeSprite_;
	const Vector2i numberOfAnim_;
	int	animationFps_;
	Vector2i  anim_;
	//Clock * Timer_animation;

};

#endif
