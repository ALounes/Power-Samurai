#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#define DEFAULT_ANIM_FPS 0.25

#include <SFML/Graphics.hpp>
#include "config.hpp"

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
	int  getAnimationWidth () const;
	int  getAnimationHeight() const;
	Sprite* getSprite() const;
	
	void setPosition(Vector2f &position);
	
	virtual void play();
	virtual void pause();
	bool isPlaying() const;

	void SetAnimFps(int &fps);
	int  getAnimFps() const;
	void updateSprite();

	void animationUp();
	void animationDown();
	void animationLeft();
	void animationRight();

	void setAnimation(int i);
	void setAnimationX(int x);
	void setAnimationY(int y);
	int  getAnimationX() const;
	int  getAnimationY() const;

	virtual void setDefaultSprite();

	void display();

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

};

#endif
