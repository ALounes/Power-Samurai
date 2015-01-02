#include "gracehopper.hpp"

GraceHopper::GraceHopper(RenderWindow *win, Image &image, Map *myMap, Image* image1, Image* image2, Image* image3)
:Player( win,
			image, 
			Vector2i(GRACE_HOPPER_X,GRACE_HOPPER_Y), 
			String("Grace Hopper"),
			GRACE_HOPPER_LIFE,
			GRACE_HOPPER_MANA, 
			GRACE_HOPPER_POWER,
			myMap,
			GRACE_HOPPER_DMG
			)
{
         setSpellDelay(1, GRACE_HOPPER_DELAY1);
         setSpellDelay(2, GRACE_HOPPER_DELAY2);
         setSpellDelay(3, GRACE_HOPPER_DELAY3);
         setSRange(1, GRACE_HOPPER_RANGE1);
         setSRange(2, GRACE_HOPPER_RANGE2);
         setSRange(3, GRACE_HOPPER_RANGE3);
         setDmg(1, GRACE_HOPPER_DMG1);
         setDmg(2, GRACE_HOPPER_DMG2);
         setDmg(3, GRACE_HOPPER_DMG3);
         setVSpell(1, GRACE_HOPPER_V2I1);
         setVSpell(2, GRACE_HOPPER_V2I2);
         setVSpell(3, GRACE_HOPPER_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, GRACE_HOPPER_MANA_COST1);
         setSManaCost(2, GRACE_HOPPER_MANA_COST2);
         setSManaCost(3, GRACE_HOPPER_MANA_COST3);
         setImgSpritePortrait("Sprites/Personnages/Portrait4.png");
         setSpeed(GRACE_HOPPER_SPEED);
}


GraceHopper::~GraceHopper()
{}
