#ifndef CONFIG_HPP
#define CONFIG_HPP

#define DEFAULT_SPEED 1
#define ZERO 0

enum power {FireBoll = 0, None};

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

#endif
