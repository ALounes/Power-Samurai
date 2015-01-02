#include "images_animation.hpp"

Images::Images() {

   image_Armor1     = new Image();
   image_Devil1     = new Image();
	image_Dragon1    = new Image();
	image_Fantome1   = new Image();
	image_Fantome2   = new Image();
	image_Reaper1    = new Image();
	image_Squelette  = new Image();
	image_Troll      = new Image();
   
   image_Bat = new Image();
	image_Bee = new Image();
	image_Blueslime     = new Image();
	image_Greendragon1  = new Image();
	image_Greenscorpion = new Image();
	image_Greenslime    = new Image();
	image_Mouse1        = new Image();
	image_Naga          = new Image();
	
	image_Reddragon1    = new Image();
	image_Redeye        = new Image();
	image_Redscorpion   = new Image();
	
	image_Attack1 = new Image();
	image_Attack2 = new Image();
	image_Attack3 = new Image();
	image_Attack4 = new Image();
	image_Attack5 = new Image();
	image_Attack6 = new Image();
	image_Attack7 = new Image();
	image_Attack8 = new Image();
	image_Attack9 = new Image();
	image_Attack10 = new Image();
	
	image_Fire3 = new Image();
	image_Gun1 = new Image();
	image_Gun2 = new Image();
	image_Heal2 = new Image();
	image_Heal3 = new Image();
	image_Heal4 = new Image();
	image_Heal5 = new Image();
	image_Light1 = new Image();
	image_Light2 = new Image();
	image_Light7 = new Image();
	image_Meteor = new Image();
	image_Special2 = new Image();
	image_Special5 = new Image();
	image_Special10 = new Image();
	image_Special12 = new Image();
	image_Special14 = new Image();
	image_Special15 = new Image();
	image_Special17 = new Image();
	image_State1 = new Image();
	image_Sword5 = new Image();
	image_Sword10 = new Image();
	image_Wind1 = new Image();
	image_Wind3 = new Image();
	
	image_Death = new Image();
	image_degats = new Image();
	image_hp_item = new Image();
	image_mana_item = new Image();
	image_projectile = new Image();

   	     
   	     
   	     
   if (!image_Armor1->LoadFromFile("Sprites/Ennemis/Armor1.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Devil1->LoadFromFile("Sprites/Ennemis/Devil1.png"))
		      cout << "erreur " << endl ;	     
 
   if (!image_Dragon1->LoadFromFile("Sprites/Ennemis/Dragon1.png"))
		      cout << "erreur " << endl ;

   if (!image_Fantome1->LoadFromFile("Sprites/Ennemis/Fantome1.png"))
		      cout << "erreur " << endl ;

   if (!image_Reaper1->LoadFromFile("Sprites/Ennemis/Reaper1.png"))
		      cout << "erreur " << endl ;

   if (!image_Squelette->LoadFromFile("Sprites/Ennemis/Squelette.png"))
		      cout << "erreur " << endl ;	      

   if (!image_Troll->LoadFromFile("Sprites/Ennemis/Troll.png"))
		      cout << "erreur " << endl ;

   if (!image_Fantome2->LoadFromFile("Sprites/Ennemis/Fantome2.png"))
		      cout << "erreur " << endl ;

	if (!image_Bat->LoadFromFile("Sprites/Ennemis/Bat.png"))
		      cout << "erreur " << endl ; 	      
   if (!image_Bee->LoadFromFile("Sprites/Ennemis/Bee.png"))
		      cout << "erreur " << endl ; 

	if (!image_Blueslime->LoadFromFile("Sprites/Ennemis/Blueslime.png"))
		      cout << "erreur " << endl ;

	if (!image_Greendragon1->LoadFromFile("Sprites/Ennemis/Greendragon1.png"))
		      cout << "erreur " << endl ;

	if (!image_Greenscorpion->LoadFromFile("Sprites/Ennemis/Greenscorpion.png"))
		      cout << "erreur " << endl ;

	if (!image_Greenslime->LoadFromFile("Sprites/Ennemis/Greenslime.png"))
		      cout << "erreur " << endl ;	      	      	            

	if (!image_Mouse1->LoadFromFile("Sprites/Ennemis/Mouse1.png"))
		      cout << "erreur " << endl ;

	if (!image_Naga->LoadFromFile("Sprites/Ennemis/Naga.png"))
		      cout << "erreur " << endl ;

	if (!image_Reddragon1->LoadFromFile("Sprites/Ennemis/Reddragon1.png"))
		      cout << "erreur " << endl ;

	if (!image_Redeye->LoadFromFile("Sprites/Ennemis/Redeye.png"))
		      cout << "erreur " << endl ;

	if (!image_Redscorpion->LoadFromFile("Sprites/Ennemis/Redscorpion.png"))
		      cout << "erreur " << endl ;
//Sorts
   if (!image_Attack1->LoadFromFile("Sprites/Sorts/Attack1.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack2->LoadFromFile("Sprites/Sorts/Attack2.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack3->LoadFromFile("Sprites/Sorts/Attack3.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack4->LoadFromFile("Sprites/Sorts/Attack4.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack5->LoadFromFile("Sprites/Sorts/Attack5.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack6->LoadFromFile("Sprites/Sorts/Attack6.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack7->LoadFromFile("Sprites/Sorts/Attack7.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack8->LoadFromFile("Sprites/Sorts/Attack8.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack9->LoadFromFile("Sprites/Sorts/Attack9.png"))
		      cout << "erreur " << endl ;    
   if (!image_Attack10->LoadFromFile("Sprites/Sorts/Attack10.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Fire3->LoadFromFile("Sprites/Sorts/Fire3.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Gun1->LoadFromFile("Sprites/Sorts/Gun1.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Gun2->LoadFromFile("Sprites/Sorts/Gun2.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Heal2->LoadFromFile("Sprites/Sorts/Heal2.png"))
		      cout << "erreur " << endl ;    
   
   if (!image_Heal3->LoadFromFile("Sprites/Sorts/Heal3.png"))
		      cout << "erreur " << endl ;    
   if (!image_Heal4->LoadFromFile("Sprites/Sorts/Heal4.png"))
		      cout << "erreur " << endl ;    
   if (!image_Heal5->LoadFromFile("Sprites/Sorts/Heal5.png"))
		      cout << "erreur " << endl ;    
   if (!image_Light1->LoadFromFile("Sprites/Sorts/Light1.png"))
		      cout << "erreur " << endl ;    
   if (!image_Light2->LoadFromFile("Sprites/Sorts/Light2.png"))
		      cout << "erreur " << endl ;    
   if (!image_Light7->LoadFromFile("Sprites/Sorts/Light7.png"))
		      cout << "erreur " << endl ;    
   if (!image_Meteor->LoadFromFile("Sprites/Sorts/Meteor.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special2->LoadFromFile("Sprites/Sorts/Special2.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special5->LoadFromFile("Sprites/Sorts/Special5.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special10->LoadFromFile("Sprites/Sorts/Special10.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special12->LoadFromFile("Sprites/Sorts/Special12.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special14->LoadFromFile("Sprites/Sorts/Special14.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special15->LoadFromFile("Sprites/Sorts/Special15.png"))
		      cout << "erreur " << endl ;    
   if (!image_Special17->LoadFromFile("Sprites/Sorts/Special17.png"))
		      cout << "erreur " << endl ;    
   if (!image_State1->LoadFromFile("Sprites/Sorts/State1.png"))
		      cout << "erreur " << endl ;    
   if (!image_Sword5->LoadFromFile("Sprites/Sorts/Sword5.png"))
		      cout << "erreur " << endl ;    
   if (!image_Sword10->LoadFromFile("Sprites/Sorts/Sword10.png"))
		      cout << "erreur " << endl ;    
   if (!image_Wind1->LoadFromFile("Sprites/Sorts/Wind1.png"))
		      cout << "erreur " << endl ;    
   if (!image_Wind3->LoadFromFile("Sprites/Sorts/Wind3.png"))
		      cout << "erreur " << endl ;   
		      
   if (!image_Death->LoadFromFile("Sprites/Sorts/Death1.png"))
		      cout << "erreur " << endl ;
		      
   if (!image_degats->LoadFromFile("Sprites/Sorts/Blood2.png"))
		      cout << "erreur " << endl ;
		      
   if (!image_hp_item->LoadFromFile("Sprites/Items/hp.png"))
		      cout << "erreur " << endl ;

	if (!image_mana_item->LoadFromFile("Sprites/Items/mana.png"))
		      cout << "erreur " << endl ;	
   
   if (!image_projectile->LoadFromFile("Sprites/Projectiles/Fire1.png"))
		      cout << "erreur " << endl ;   
   
}


Images::~Images() {
     
	delete image_Armor1;
   delete image_Devil1;
   delete image_Dragon1;
	delete image_Fantome1;
	delete image_Fantome2;
	delete image_Reaper1;
	delete image_Squelette;
	delete image_Troll;
   delete image_Bat;
	delete image_Bee;
	delete image_Blueslime;
	delete image_Greendragon1;
	delete image_Greenscorpion;
	delete image_Greenslime;
	delete image_Mouse1;
	delete image_Naga;	
	delete image_Reddragon1;
	delete image_Redeye;
	delete image_Redscorpion; 
	
	delete image_Attack1;
	delete image_Attack2;
	delete image_Attack3;
	delete image_Attack4;
	delete image_Attack5;
	delete image_Attack6;
	delete image_Attack7;
	delete image_Attack8;
	delete image_Attack9;
	delete image_Attack10;
	
	delete image_Fire3;
	delete image_Gun1;
	delete image_Gun2;
	delete image_Heal2;
	delete image_Heal3;
	delete image_Heal4;
	delete image_Heal5;
	delete image_Light1;
	delete image_Light2;
	delete image_Light7;
	delete image_Meteor;
	delete image_Special2;
	delete image_Special5;
	delete image_Special10;
	delete image_Special12;
	delete image_Special14;
	delete image_Special15;
	delete image_Special17;
	delete image_State1;
	delete image_Sword5;
	delete image_Sword10;
	delete image_Wind1;
	delete image_Wind3;
	
	
}

