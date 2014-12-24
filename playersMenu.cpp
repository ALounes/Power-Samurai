#include "playersMenu.hpp"

#define NB_PERSO 4

	
	
PlayersMenu::PlayersMenu () 
{

  playersItems_ = new std::list<PlayersItem>;
  position_fleche_ = new int;
  *position_fleche_ = 0;

	//Load images from files

	
	//sprite_perso.SetSubRect(IntRect(0,0,32,32));
	
	
	image_p1_ = new sf::Image();
	image_p1_->LoadFromFile("Sprites/Personnages/P1.png");
	sf::Sprite sprite_p1;
	sprite_p1.SetImage(*image_p1_);
	sprite_p1.SetSubRect(IntRect(0,0,32,32));
	sprite_p1.SetPosition(12*32,12*32);
	
	image_p2_ = new sf::Image();
	image_p2_->LoadFromFile("Sprites/Personnages/P2.png");
	sf::Sprite sprite_p2;
	sprite_p2.SetImage(*image_p2_);
	sprite_p2.SetSubRect(IntRect(0,0,32,32));
	sprite_p2.SetPosition(12*32 + 64,12*32);
	
	image_p3_ = new sf::Image();
	image_p3_->LoadFromFile("Sprites/Personnages/P3.png");
	sf::Sprite sprite_p3;
	sprite_p3.SetImage(*image_p3_);
	sprite_p3.SetSubRect(IntRect(0,0,32,32));
	sprite_p3.SetPosition(12*32 + 128,12*32);
	
	image_p4_ = new sf::Image();
	image_p4_->LoadFromFile("Sprites/Personnages/P4.png");
	sf::Sprite sprite_p4;
	sprite_p4.SetImage(*image_p4_);
	sprite_p4.SetSubRect(IntRect(0,0,32,32));
	sprite_p4.SetPosition(12*32 + 192,12*32);
	
	image_arrow_ = new sf::Image();
	image_arrow_->LoadFromFile("images/PlayersMenu/fleche.png");
	sprite_arrow_ = new sf::Sprite();
	sprite_arrow_->SetImage(*image_arrow_);
	
	image_main_players_ = new sf::Image();
	image_main_players_->LoadFromFile("images/PlayersMenu/PlayersMenu.png");
	sprite_main_players_ = new	sf::Sprite();
	sprite_main_players_->SetImage(*image_main_players_);
	

	//Setup Players Items
	PlayersItem player1;
	player1.action = p1;
	player1.sprite = sprite_p1;
	player1.texte = String ("Name : Athena\nHP : 100\nMana : 200", Font::GetDefaultFont(), 20.f);
	player1.texte.SetStyle(11);
	player1.texte.SetColor(Color::White);
	player1.texte.SetPosition(12*32 - 10,12*32 + 40);
	
	PlayersItem player2;
	player2.action = p2;
	player2.sprite = sprite_p2;
	player2.texte = String ("Name : Fartas\nHP : 200\nMana : 100", Font::GetDefaultFont(), 20.f);
	player2.texte.SetPosition(12*32 - 10,12*32 + 40);
	player2.texte.SetStyle(11);
	player2.texte.SetColor(Color::White);
	
	PlayersItem player3;
	player3.action = p3;
	player3.sprite = sprite_p3;
	player3.texte = String ("Name : Bjarne\nHP : 150\nMana : 150", Font::GetDefaultFont(), 20.f);
	player3.texte.SetPosition(12*32 - 10,12*32 + 40);
	player3.texte.SetStyle(11);
	player3.texte.SetColor(Color::White);
	
	PlayersItem player4;
	player4.action = p4;
	player4.sprite = sprite_p4;
	player4.texte = String ("Name : Linus\nHP : 100\nMana : 200", Font::GetDefaultFont(), 20.f);
	player4.texte.SetPosition(12*32 - 10,12*32 + 40);
	player4.texte.SetStyle(11);
	player4.texte.SetColor(Color::White);

	playersItems_->push_back(player1);
	playersItems_->push_back(player2);
	playersItems_->push_back(player3);
	playersItems_->push_back(player4);
}

PlayersMenu::~PlayersMenu () 
{
  cout << "Destructeur PlayersMenu()" << endl;
  playersItems_->clear();
   
  delete playersItems_;

  delete sprite_arrow_;
  delete position_fleche_;
  delete sprite_main_players_;

	delete image_p1_;
	delete image_p2_;
	delete image_p3_;
	delete image_p4_;
	delete image_arrow_;
}
void PlayersMenu::Load(sf::RenderWindow *window)
{ 
cout << "Load Players menu" << endl;
  window->Clear(Color::White);
	window->Draw(*sprite_main_players_);
	sprite_arrow_->SetPosition(12*32 - 20 + (*position_fleche_)*64, 5 + 12*32);
	
	for (auto b : *playersItems_) {
	  window->Draw(b.sprite);
  }
  
   window->Draw((playersItems_->begin())->texte);
  
  window->Draw(*sprite_arrow_);
  window->Display();

}

PlayersMenu::PlayersResult PlayersMenu::Show(sf::RenderWindow *window)
{
    cout << "Show" << endl;
	return GetPlayersResponse(window);
}

PlayersMenu::PlayersResult  PlayersMenu::GetPlayersResponse(sf::RenderWindow *window)
{
	sf::Event playersEvent;

	while(42 != 43)
	{

		while(window->GetEvent(playersEvent))
		{	    
			if(playersEvent.Type == sf::Event::KeyPressed)
			{
						if(playersEvent.Key.Code == sf::Key::Escape) 
						return Escape;
						
						if(playersEvent.Key.Code == sf::Key::Return) 
						return Return;
						
						if(playersEvent.Key.Code == sf::Key::Left) 
						  return HandleKey(-1,window);
						
						if(playersEvent.Key.Code == sf::Key::Right) 
						  return HandleKey(1,window);
			}
			
			
		}
	}
}


PlayersMenu::PlayersResult PlayersMenu::HandleKey(int position, sf::RenderWindow *window)
{
  if (position == -1) {
     if (*position_fleche_ == 0) {
      *position_fleche_ = NB_PERSO - 1;
     }
     else {
      --(*position_fleche_);
     }
  }
 
  if (position == 1) {
     if (*position_fleche_ == NB_PERSO - 1) {
      *position_fleche_ = 0;
     }
     else {
      ++(*position_fleche_);
     }
  }
 
  cout << *position_fleche_ << endl;
  
  sprite_arrow_->SetPosition(12*32 - 20 + (*position_fleche_)*64, 5 + 12*32);

  window->Clear();
  window->Draw(*sprite_main_players_);

	for (auto b : *playersItems_) {

	  window->Draw(b.sprite);


   }

   std::list<PlayersItem>::iterator iter = playersItems_->begin();

   int ind = 0;
   while (ind < *position_fleche_) {
      ++iter;
      ++ind;
   }
   

   window->Draw(iter->texte);
   
   cout << *position_fleche_ << endl;
   
   
   window->Draw(*sprite_arrow_);
   window->Display();
   cout << "finHandleKey" << endl;
	return Nothing;
}


int * PlayersMenu::getposition() const {
   return position_fleche_;

}
