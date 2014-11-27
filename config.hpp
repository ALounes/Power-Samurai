#ifndef CONFIG_HPP
#define CONFIG_HPP

#define DEFAULT_SPEED 1
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

/* ENTITY */
#define E_SPRITE_BEGIN_X getAnimationWidth ()
#define E_SPRITE_BEGIN_Y getAnimationHeight()
#define E_SPRITE_END_X getAnimationWidth ()*2
#define E_SPRITE_END_Y getAnimationHeight()*2

/* MAP */
#define X_MAX_MAP 1000
#define X_MIN_MAP 0

#define Y_MAX_MAP 1000
#define Y_MIN_MAP 0

/* PLAYER */
#define PLAYER_LIFE_MAX 100
#define PLAYER_MANA_MAX 100

#endif
