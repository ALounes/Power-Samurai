/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*                     Fichier : CONFIG.HPP                        */
/*=================================================================*/
/*******************************************************************/

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define DEFAULT_SPEED 3
#define ZERO 0

enum power {FireBoll = 0, None};

/* POWERSAMURAI */
#define ENTITY_FPS_RATE 0.1

/* BOT */
#define random_minimum 0
#define random_maximum 1000

/* ANIMATION */
#define A_SPRITE_BEGIN_X 0
#define A_SPRITE_BEGIN_Y 0
#define A_SPRITE_END_X getAnimationWidth ()
#define A_SPRITE_END_Y getAnimationHeight()

/* EFFECT ANIMATION */
#define EFFECT_FPS_RATE 0.5

#define EFFECT_SPRITE_BEGIN_X 0
#define EFFECT_SPRITE_BEGIN_Y 0
#define EFFECT_SPRITE_END_X getAnimationWidth ()
#define EFFECT_SPRITE_END_Y getAnimationHeight()

/* ENTITY */
#define E_SPRITE_BEGIN_X getAnimationWidth ()
#define E_SPRITE_BEGIN_Y getAnimationHeight()
#define E_SPRITE_END_X getAnimationWidth ()*2
#define E_SPRITE_END_Y getAnimationHeight()*2

/* MAP */
#define X_MAX_MAP 1500
#define X_MIN_MAP 0

#define Y_MAX_MAP 1500
#define Y_MIN_MAP 0

/* CAMERA */
#define CAM_WIDTH  400
#define CAM_HEIGHT 300

/* PLAYER */
#define PLAYER_LIFE_MAX 100
#define PLAYER_MANA_MAX 100

#endif
