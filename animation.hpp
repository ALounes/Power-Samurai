#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#define DEFAULT_ANIM_FPS 0.25

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include <iostream>
#include "stdafx.hpp"

using namespace sf;
using namespace std;

class Animation 
{
	public :

	Animation(RenderWindow *win, Image& image,const Vector2i &nbrOfAnim);
	~Animation();

	void setImage(const string imageName);


   // On calcule, à partir de la largeur de l'image et du nombre de sous images, la largeur des chaque image élémentaire. On assigne les fonctions de récupération de ces sprites.
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

	virtual void play();    //Passe l'animation dans le stade "En cours"
	virtual void pause();   //Pause l'animation
	virtual void setDefaultSprite(); //Lui assigne un sprite par défaut
	
	Sound * getSound() const;
   void setSoundB(string s);

	protected:

	Sprite    *mySprite_;
	RenderWindow *win_;
	bool	paused_;

	private:
   //Chaque animation a un sprite , une image, un son, un buffer
   Sound *myAnimationSound_;
   SoundBuffer *myAnimationSoundB_;
	Image     &myImage_;
	Vector2i  sizeImage_; 
	Vector2i  sizeSprite_;
	const Vector2i numberOfAnim_;
	int	animationFps_;
	Vector2i  anim_;     //Donne l'endroit où l'on est dans l'image.
	//Clock * Timer_animation;

};

#endif
