#include "livingentity.hpp"


LivingEntity::LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
{
   timer1_ = new Clock();
   timer2_ = new Clock();
   timer3_ = new Clock();
   //Spell1_ = new Image();
   //Spell2_ = new Image();
   //Spell3_ = new Image();
}

LivingEntity::~LivingEntity()
{
   delete timer1_;
	delete timer2_;
	delete timer3_;
	//delete Spell1_;
	//delete Spell2_;
	//delete Spell3_;
//while (!spells.empty()) { delete spells.back(); spells.pop_back(); }
//while (!appliedeffects.empty()) { delete appliedeffects.back(); appliedeffects.pop_back(); }
cout << "DESTRUCTEUR LivingEntity()" << endl;
}

Clock * LivingEntity::getTimer(int i) const {
   switch (i)
	{
      case  1 :
         return timer1_;
         break;
      case  2 :
         return timer2_;
         break; 
      case  3 :
         return timer3_;
  	      break;
      default :
         return timer1_;
         break;
	}
}
void LivingEntity::setTimer(int i, Clock* t) {
   switch (i)
	{
      case  1 :
         timer1_ = t;
         break;
      case  2 :
         timer2_ = t;
         break; 
      case  3 :
         timer3_ = t;
  	      break;
      default :
         timer1_ = t;
         break;
	}
}

int LivingEntity::getSpellDelay(int i) const {
   switch (i)
	{
      case  1 :
         return spell_delay1_;
         break;
      case  2 :
         return spell_delay2_;
         break; 
      case  3 :
         return spell_delay3_;
  	      break;
      default :
         return spell_delay1_;
         break;
	}
}
void LivingEntity::setSpellDelay(int i, int sd) {
   switch (i)
	{
      case  1 :
         spell_delay1_ = sd;
         break;
      case  2 :
         spell_delay2_ = sd;
         break; 
      case  3 :
         spell_delay3_ = sd;
  	      break;
      default :
         spell_delay1_ = sd;
         break;
	}
}

Image* LivingEntity::getImgSpell(int i) const {
   switch (i)
	{
      case  1 :
         return Spell1_;
         break;
      case  2 :
         return Spell2_;
         break; 
      case  3 :
         return Spell3_;
  	      break;
      default :
         return Spell1_;
         break;
	}
}
void LivingEntity::setImgSpell(int i, Image* img) {
   switch (i)
	{
      case  1 : {
         Spell1_ = img;
         break;
      }
      case  2 : {
         Spell2_ = img;

         break; 
      }
      case  3 :
         Spell2_ = img;

  	      break;
      default :
         Spell1_ = img;
         break;
	}
}

int LivingEntity::getSRange(int i) const {
   switch (i)
	{
      case  1 :
         return range1_;
         break;
      case  2 :
         return range2_;
         break; 
      case  3 :
         return range3_;
  	      break;
      default :
         return range1_;
         break;
	}

}
void LivingEntity::setSRange(int i, int r) {
   switch (i)
	{
      case  1 :
         range1_ = r;
         break;
      case  2 :
         range2_ = r;
         break; 
      case  3 :
         range3_ = r;
  	      break;
      default :
         range1_ = r;
         break;
	}
}

int LivingEntity::getDmg(int i) const {
   switch (i)
	{
      case  1 :
         return dmg1_;
         break;
      case  2 :
         return dmg2_;
         break; 
      case  3 :
         return dmg3_;
  	      break;
      default :
         return dmg1_;
         break;
	}
}
void LivingEntity::setDmg(int i, int d) {
   switch (i)
	{
      case  1 :
         dmg1_ = d;
         break;
      case  2 :
         dmg2_ = d;
         break; 
      case  3 :
         dmg3_ = d;
  	      break;
      default :
         dmg1_ = d;
         break;
	}
}

Vector2i LivingEntity::getVSpell(int i) const { 
   switch (i)
	{
      case  1 :
         return v_spell1_;
         break;
      case  2 :
         return v_spell2_;
         break; 
      case  3 :
         return v_spell3_;
  	      break;
      default :
         return v_spell1_;
         break;
	}
}
void LivingEntity::setVSpell(int i, Vector2i v) {
   switch (i)
	{
      case  1 :
         v_spell1_ = v;
         break;
      case  2 :
         v_spell2_ = v;
         break; 
      case  3 :
         v_spell3_ = v;
  	      break;
      default :
         v_spell1_ = v;
         break;
	}
}

int LivingEntity::getSManaCost(int i) const {
   switch (i)
	{
      case  1 :
         return mana_cost1_;
         break;
      case  2 :
         return mana_cost2_;
         break; 
      case  3 :
         return mana_cost3_;
  	      break;
      default :
         return mana_cost1_;
         break;
	}
}

void LivingEntity::setSManaCost(int i, int mc) {
   switch (i)
	{
      case  1 :
         mana_cost1_ = mc;
         break;
      case  2 :
         mana_cost2_ = mc;
         break; 
      case  3 :
         mana_cost3_ = mc;
  	      break;
      default :
         mana_cost1_ = mc;
         break;
	}
}
