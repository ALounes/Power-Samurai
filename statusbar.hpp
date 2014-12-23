#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "config.hpp"
#include "camera.hpp"

#define TEXT_POSITION_X position_->x + 217
#define TEXT_POSITION_Y position_->y + 228

#define SPRITE_POSITION_X position_->x - 400
#define SPRITE_POSITION_Y position_->y - 300

#define LIFE_POSITION_X position_->x - 307
#define LIFE_POSITION_Y position_->y + 214

#define MANA_POSITION_X position_->x - 307
#define MANA_POSITION_Y position_->y + 234

#define LIFE_X1 0
#define LIFE_Y1 0
#define LIFE_X2 118
#define LIFE_Y2 12
#define LIFE_COLOR Color(0,255,0,255)
#define LIFE_BORDURE 3
#define LIFE_BORDURE_COLOR Color(0,204,102,255)

#define MANA_X1 0
#define MANA_Y1 0
#define MANA_X2 118
#define MANA_Y2 12
#define MANA_COLOR Color(0,0,255,255)
#define MANA_BORDURE 3
#define MANA_BORDURE_COLOR Color(0,204,102,255)

#define RED_COLOR Color(255,0,0,255)

class StatusBar
{
public:

	StatusBar(RenderWindow *win, Entity *entity, Camera *camera);
	~StatusBar();  

	void display () ;
	void playLifeEffect(Entity *entity);
	void playManaEffect(Entity *entity);

	void setEntity(Entity *entity);
	void setWindow(RenderWindow *win);
	void setSprite(Sprite *sprite);
	void setImage(Image *image);
	void setPosition(Vector2f *position);

	Entity*   getEntity() const;
	RenderWindow* getWindow() const;
	Sprite*   getSprite()   const;
	Image*    getImage()    const;
	Vector2f* getPosition() const;

private:

	RenderWindow *win_;
	Entity *entity_;
	Sprite *mySprite_;
	Sprite *persoSprite_;
	Image  *myImage_;
	String *myText_;
	Camera *camera_;
	Vector2f *position_;

	Shape  statuLife_;
	Shape  statuMana_;
	Shape  statuLifeRed_;
	Shape  statuManaRed_;
};	

#endif 
