#include <sstream>
#include <SFML/Graphics.hpp>
#include "statusbar.hpp"



StatusBar::StatusBar(RenderWindow *win, Player *player, Camera *camera)
	: player_(player) 
	,win_(win)	
	,camera_(camera)
{
   position_ = camera->getPosition();
   
	StatusBar_  = new Image();
	StatusBar_->LoadFromFile("images/StatusBar/StatusBar.png");
	
	Life_ = new Image();
	Life_->LoadFromFile("images/StatusBar/HP_Bar.png");
	
	Mana_  = new Image();
	Mana_->LoadFromFile("images/StatusBar/Mana_bar.png");
	
	


   statuLife_.SetImage(*Life_);
   statuMana_.SetImage(*Mana_);
   statusBar_.SetImage(*StatusBar_);
   
   FirstSpell_ = player_->getImgSpell(1);
   spriteSpell1_.SetImage(*FirstSpell_);
   spriteSpell1_.SetSubRect(IntRect(192 * 2, 192 * 2, 192 * 3, 192 * 3));
   spriteSpell1_.SetScale(0.5,0.5);
   spriteSpell1_.SetPosition(SPELL1_POSITION_X, SPELL1_POSITION_Y);
   
   SecondSpell_ = player_->getImgSpell(2);
   spriteSpell2_.SetImage(*SecondSpell_);
   spriteSpell2_.SetSubRect(IntRect(192 * 2, 192 * 2, 192 * 3, 192 * 3));
   spriteSpell2_.SetScale(0.5,0.5);
   spriteSpell2_.SetPosition(SPELL2_POSITION_X, SPELL2_POSITION_Y);
   
   ThirdSpell_ = player_->getImgSpell(3);
   spriteSpell3_.SetImage(*ThirdSpell_);
   spriteSpell3_.SetSubRect(IntRect(192 * 2, 192 * 2, 192 * 3, 192 * 3));
   spriteSpell3_.SetScale(0.5,0.5);
   spriteSpell3_.SetPosition(SPELL3_POSITION_X, SPELL3_POSITION_Y);
   
	
	Perso_ = new Font();
   if (!Perso_->LoadFromFile("Fonts/perso.ttf"))
	      cout << "erreur" << endl;
	
	NamePlayer_ = new String();
	*NamePlayer_ = player_->getName();
	NamePlayer_->SetSize(16);
	NamePlayer_->SetStyle(11);
	NamePlayer_->SetColor(Color(0, 0, 0));
	NamePlayer_->SetFont(*Perso_);

   Level_ = new String();
   Level_->SetText("Hp : \nMana : \nAttack : \n");
   Level_->SetSize(16);
	Level_->SetStyle(11);
	Level_->SetColor(Color(0, 0, 0));
	Level_->SetFont(*Perso_);
		 
		 
	HP_Pot_Nb_ = new String();
	HP_Pot_Nb_->SetText(to_string(player_->getNbHP()));	 
	HP_Pot_Nb_->SetSize(20);
	HP_Pot_Nb_->SetStyle(11);
	HP_Pot_Nb_->SetColor(Color(0, 0, 0));
	HP_Pot_Nb_->SetFont(Font::GetDefaultFont());
	//NamePlayer_->SetPosition(10,win_->GetHeight()-23); 
   //string s = std::to_string(42);
   
   MANA_Pot_Nb_ = new String();
	MANA_Pot_Nb_->SetText(to_string(player_->getNbMANA ()));	 
	MANA_Pot_Nb_->SetSize(20);
	MANA_Pot_Nb_->SetStyle(11);
	MANA_Pot_Nb_->SetColor(Color(0, 0, 0));
	MANA_Pot_Nb_->SetFont(Font::GetDefaultFont());

	
	
	CD1_ = new String();
	CD1_->SetText(to_string( (int) player_->getTimer(1)->GetElapsedTime() ));
	CD1_->SetSize(16);
	CD1_->SetStyle(1);
	CD1_->SetColor(Color(0, 0, 0));
	CD1_->SetFont(*Perso_);
	
	CD2_ = new String();
	CD2_->SetText(to_string( (int) player_->getTimer(2)->GetElapsedTime() ));
	CD2_->SetSize(16);
	CD2_->SetStyle(1);
	CD2_->SetColor(Color(0, 0, 0));
	CD2_->SetFont(*Perso_);
	
	CD3_ = new String();
	CD3_->SetText(to_string( (int) player_->getTimer(3)->GetElapsedTime() ));
	CD3_->SetSize(16);
	CD3_->SetStyle(1);
	CD3_->SetColor(Color(0, 0, 0));
	CD3_->SetFont(*Perso_);
	
	DMG1_ = new String();
	DMG1_->SetText(to_string( (int) player_->getDmg(1) ));
	DMG1_->SetSize(16);
	DMG1_->SetStyle(1);
	DMG1_->SetColor(Color::Red);
	DMG1_->SetFont(*Perso_);
	
	DMG2_ = new String();
	DMG2_->SetText(to_string( (int) player_->getDmg(2) ));
	DMG2_->SetSize(16);
	DMG2_->SetStyle(1);
	DMG2_->SetColor(Color::Red);
	DMG2_->SetFont(*Perso_);
	
	DMG3_ = new String();
	DMG3_->SetText(to_string( (int) player_->getDmg(3) ));
	DMG3_->SetSize(16);
	DMG3_->SetStyle(1);
	DMG3_->SetColor(Color::Red);
	DMG3_->SetFont(*Perso_);
	
	
	
	MANA1_ = new String();
	MANA1_->SetText(to_string( (int) player_->getSManaCost(1) ));
	MANA1_->SetSize(16);
	MANA1_->SetStyle(1);
	MANA1_->SetColor(Color::Blue);
	MANA1_->SetFont(*Perso_);
	
	MANA2_ = new String();
	MANA2_->SetText(to_string( (int) player_->getSManaCost(2) ));
	MANA2_->SetSize(16);
	MANA2_->SetStyle(1);
	MANA2_->SetColor(Color::Blue);
	MANA2_->SetFont(*Perso_);
	
	MANA3_ = new String();
	MANA3_->SetText(to_string( (int) player_->getSManaCost(3) ));
	MANA3_->SetSize(16);
	MANA3_->SetStyle(1);
	MANA3_->SetColor(Color::Blue);
	MANA3_->SetFont(*Perso_);

}


StatusBar::~StatusBar()
{
   delete StatusBar_;
	delete Life_;
	delete Mana_;
	delete Perso_;
	delete NamePlayer_;
   delete Level_;	 
	delete HP_Pot_Nb_;
   delete MANA_Pot_Nb_;
   delete CD1_;
   delete CD2_;
   delete CD3_;
   delete DMG1_;
   delete DMG2_;
   delete DMG3_;
   delete MANA1_;
   delete MANA2_;
   delete MANA3_;
	
}

void 
StatusBar::update()
{
	//statuLife_.SetScaleX(0.5);
   
   NamePlayer_->SetPosition(PLAYER_POSITION_X, PLAYER_POSITION_Y);
   Level_->SetPosition(LVL_POSITION_X, LVL_POSITION_Y);
   
	HP_Pot_Nb_->SetText(to_string(player_->getNbHP()));	 
   HP_Pot_Nb_->SetPosition(NBHP_POSITION_X, NBHP_POSITION_Y);
   
   string s = "Hp : " + to_string(player_->getLife()) + "/" + to_string(player_->getLifeMax()) + "\nMana : " + to_string(player_->getMana()) + "/" + to_string(player_->getManaMax()) + "\nAttack : " + to_string((int)player_->getAttackDamage()) + "\n";
   Level_->SetText(s);
   
   MANA_Pot_Nb_->SetText(to_string(player_->getNbMANA()));	 
   MANA_Pot_Nb_->SetPosition(NBMANA_POSITION_X, NBMANA_POSITION_Y);
   



   
   if (getCD(1) >= 10)
   {
      CD1_->SetPosition(CD1_POSITION_X - 5, CD1_POSITION_Y);
   }
   else {
      CD1_->SetPosition(CD1_POSITION_X, CD1_POSITION_Y);
   }
   CD1_->SetText(to_string((int) getCD(1) ));
   
   if (getCD(2) >= 10)
   {
      CD2_->SetPosition(CD2_POSITION_X - 5, CD2_POSITION_Y);
   }
   else {
      CD2_->SetPosition(CD2_POSITION_X, CD2_POSITION_Y);
   }
   CD2_->SetText(to_string((int) getCD(2) ));
   
   if (getCD(3) >= 10)
   {
      CD3_->SetPosition(CD3_POSITION_X - 5, CD3_POSITION_Y);
   }
   else {
      CD3_->SetPosition(CD3_POSITION_X, CD3_POSITION_Y);
   }
   CD3_->SetText(to_string((int) getCD(3) ));
   
   
   // DAMAGE TEXT UPDATE
   if (player_->getDmg(1) >= 100)
   {
      DMG1_->SetPosition(DMG1_POSITION_X - 15, DMG1_POSITION_Y);
   }
   else {
      if (player_->getDmg(1) >= 10)
      {
         DMG1_->SetPosition(DMG1_POSITION_X - 5, DMG1_POSITION_Y);
      }
      else {
         DMG1_->SetPosition(DMG1_POSITION_X, DMG1_POSITION_Y);
      }
   }
   DMG1_->SetText(to_string((int) player_->getDmg(1) ));
   
   
   if (player_->getDmg(2) >= 100)
   {
      DMG2_->SetPosition(DMG2_POSITION_X - 15, DMG2_POSITION_Y);
   }
   else {
      if (player_->getDmg(2) >= 10)
      {
         DMG2_->SetPosition(DMG2_POSITION_X - 5, DMG2_POSITION_Y);
      }
      else {
         DMG2_->SetPosition(DMG2_POSITION_X, DMG2_POSITION_Y);
      }
   }
   DMG2_->SetText(to_string((int) player_->getDmg(2) ));
   
   if (player_->getDmg(3) >= 100)
   {
      DMG3_->SetPosition(DMG3_POSITION_X - 15, DMG3_POSITION_Y);
   }
   else {
      if (player_->getDmg(3) >= 10)
      {
         DMG3_->SetPosition(DMG3_POSITION_X - 5, DMG3_POSITION_Y);
      }
      else {
         DMG3_->SetPosition(DMG3_POSITION_X, DMG3_POSITION_Y);
      }
   }
   DMG3_->SetText(to_string((int) player_->getDmg(3) ));
   
   // MANA COST TEXT UPDATE
   if (player_->getSManaCost(1) >= 100)
   {
      MANA1_->SetPosition(MANA1_POSITION_X - 15, MANA1_POSITION_Y);
   }
   else {
      if (player_->getSManaCost(1) >= 10)
      {
         MANA1_->SetPosition(MANA1_POSITION_X - 5, MANA1_POSITION_Y);
      }
      else {
         MANA1_->SetPosition(MANA1_POSITION_X, MANA1_POSITION_Y);
      }
   }
   MANA1_->SetText(to_string((int) player_->getSManaCost(1) ) );
   
   
   if (player_->getSManaCost(2) >= 100)
   {
      MANA2_->SetPosition(MANA2_POSITION_X - 15, MANA2_POSITION_Y);
   }
   else {
      if (player_->getSManaCost(2) >= 10)
      {
         MANA2_->SetPosition(MANA2_POSITION_X - 5, MANA2_POSITION_Y);
      }
      else {
         MANA2_->SetPosition(MANA2_POSITION_X, MANA2_POSITION_Y);
      }
   }
   MANA2_->SetText(to_string((int) player_->getSManaCost(2) ));
   
   if (player_->getSManaCost(3) >= 100)
   {
      MANA3_->SetPosition(MANA3_POSITION_X - 15, MANA3_POSITION_Y);
   }
   else {
      if (player_->getSManaCost(3) >= 10)
      {
         MANA3_->SetPosition(MANA3_POSITION_X - 5, MANA3_POSITION_Y);
      }
      else {
         MANA3_->SetPosition(MANA3_POSITION_X, MANA3_POSITION_Y);
      }
   }
   MANA3_->SetText(to_string((int) player_->getSManaCost(3) ));
   
	statusBar_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
	statuLife_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
	statuMana_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
	
	spriteSpell1_.SetPosition(SPELL1_POSITION_X, SPELL1_POSITION_Y);
	spriteSpell2_.SetPosition(SPELL2_POSITION_X, SPELL2_POSITION_Y);
   spriteSpell3_.SetPosition(SPELL3_POSITION_X, SPELL3_POSITION_Y);
	(player_->getSpritePortrait())->SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
}

void
StatusBar::display ()
{
   
   

	update();
	playLifeEffect(getPlayer());
	playManaEffect(getPlayer());
	win_->Draw(statusBar_);
	win_->Draw(spriteSpell1_);
	win_->Draw(*NamePlayer_);
	win_->Draw(*Level_);
	win_->Draw(*HP_Pot_Nb_);
	win_->Draw(*MANA_Pot_Nb_);
	win_->Draw(statuLife_);
	win_->Draw(statuMana_);
	win_->Draw( *(player_->getSpritePortrait() ));
	win_->Draw(*CD1_);
	win_->Draw(*CD2_);
	win_->Draw(*CD3_);
	win_->Draw(*DMG1_);
	win_->Draw(*DMG2_);
	win_->Draw(*DMG3_);
	win_->Draw(*MANA1_);
	win_->Draw(*MANA2_);
	win_->Draw(*MANA3_);
	win_->Draw(spriteSpell1_);
	win_->Draw(spriteSpell2_);
	win_->Draw(spriteSpell3_);
	
}


void StatusBar::playLifeEffect(Player *player) {
   statuLife_.SetSubRect( IntRect(0, 0, 100 + (int) 122 * ( (float) player->getLife() / (float) player->getLifeMax() ), 600));
}


void StatusBar::playManaEffect(Player *player) {
   statuMana_.SetSubRect( IntRect(0, 0, 100 + (int) 122 * ( (float) player->getMana() / (float) player->getManaMax() ), 600));	
}

void 
StatusBar::setPosition(Vector2f *position)
{
	position_->x = position->x;
	position_->y = position->y; 
}

void 
StatusBar::setPlayer(Player *player)
{
	player_ = player;
}

void 
StatusBar::setWindow(RenderWindow *win)
{
	win_ = win;
}


void 
StatusBar::setSprite(Sprite sprite)
{
	statusBar_ = sprite;
}


void 
StatusBar::setImage(Image *image)
{
	StatusBar_ = image;
}

Vector2f* 
StatusBar::getPosition() const
{
	return position_;
}


Player*
StatusBar::getPlayer() const
{
	return player_;
}


RenderWindow* 
StatusBar::getWindow() const
{
	return win_;
}


Sprite 
StatusBar::getSprite() const
{
	return statusBar_;
}


Image*  
StatusBar::getImage()  const
{
	return StatusBar_;
}

int StatusBar::getCD(int i) const {
   if ( (int) player_->getTimer(i)->GetElapsedTime() > (int) player_->getSpellDelay(i) )
   {
      return 0;
   }
   else 
      return (int) player_->getSpellDelay(i) - (int) player_->getTimer(i)->GetElapsedTime();
}
