#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "config.hpp"
#include "camera.hpp"

#define PLAYER_POSITION_X position_->x - 330
#define PLAYER_POSITION_Y position_->y + 193

#define LVL_POSITION_X position_->x - 297
#define LVL_POSITION_Y position_->y + 250

#define NBHP_POSITION_X position_->x + 284
#define NBHP_POSITION_Y position_->y + 240

#define NBMANA_POSITION_X position_->x + 345
#define NBMANA_POSITION_Y position_->y + 240

#define SPRITE_POSITION_X position_->x - 400
#define SPRITE_POSITION_Y position_->y - 300

#define LIFE_POSITION_X position_->x - 307
#define LIFE_POSITION_Y position_->y + 214

#define MANA_POSITION_X position_->x - 307
#define MANA_POSITION_Y position_->y + 234

#define CD1_POSITION_X position_->x - 65
#define CD1_POSITION_Y position_->y + 267

#define CD2_POSITION_X position_->x + 11
#define CD2_POSITION_Y position_->y + 267

#define CD3_POSITION_X position_->x + 84
#define CD3_POSITION_Y position_->y + 267

#define DMG1_POSITION_X position_->x - 65
#define DMG1_POSITION_Y position_->y + 150

#define DMG2_POSITION_X position_->x + 11
#define DMG2_POSITION_Y position_->y + 150

#define DMG3_POSITION_X position_->x + 84
#define DMG3_POSITION_Y position_->y + 150

#define MANA1_POSITION_X position_->x - 65
#define MANA1_POSITION_Y position_->y + 170

#define MANA2_POSITION_X position_->x + 11
#define MANA2_POSITION_Y position_->y + 170

#define MANA3_POSITION_X position_->x + 84
#define MANA3_POSITION_Y position_->y + 170

#define SPELL1_POSITION_X position_->x - 107
#define SPELL1_POSITION_Y position_->y + 170

#define SPELL2_POSITION_X position_->x - 33
#define SPELL2_POSITION_Y position_->y + 170

#define SPELL3_POSITION_X position_->x + 41
#define SPELL3_POSITION_Y position_->y + 170


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
   // Une statusbar a une image de base, et à ceci s'ajoute les barres de vies, les sorts, les différents attributs du joueur, et les potions

public:

	StatusBar(RenderWindow *win, Player *player, Camera *camera);
	~StatusBar();  

	void display () ;
	void playLifeEffect(Player *player);   // Actualise la barre de vie
	void playManaEffect(Player *player);   // Actualise la barre de mana

	void update();                   // Actualise tous les sprites

	void setPlayer(Player *player);
	void setWindow(RenderWindow *win);
	void setSprite(Sprite sprite);
	void setImage(Image *image);
	void setPosition(Vector2f *position);

	Player*   getPlayer() const;
	RenderWindow* getWindow() const;
	Sprite   getSprite()   const;
	Image*    getImage()    const;
	Vector2f* getPosition() const;
	
	int getCD(int i) const;
	int getDMG(int i) const;

private:
   Player *player_;
	RenderWindow *win_;

	String *NamePlayer_;       // Affiche le nom du joueur
	String *Level_;            
	String *HP_Pot_Nb_;        // Affiche le nombre de potions
	String *MANA_Pot_Nb_;
	String *CD1_;              // Affiche le CD des sorts
	String *CD2_;
	String *CD3_;
	String *DMG1_;             // Affiche les dégats des sorts
	String *DMG2_;
	String *DMG3_;
	String *MANA1_;            // Affiche le cout en Mana des sorts
	String *MANA2_;
	String *MANA3_;
	
	
	Camera *camera_;
	Vector2f *position_;

	Sprite statuLife_;         // Sprite de la barre de vie
	Sprite statuMana_;         // Sprite de la barre de mana
	Sprite statusBar_;         // Sprite de l'image de fond
	Sprite spriteSpell1_;      // Sprite de l'apercu des sorts
	Sprite spriteSpell2_;
	Sprite spriteSpell3_;
	
	Image *Life_;
	Image *Mana_;
	Image *StatusBar_;
	
	Image *FirstSpell_ ;
	Image *SecondSpell_ ;
	Image *ThirdSpell_ ;
	
	Font *Perso_;              // Police personnalisée 
	};	

#endif 
