#include "playersMenu.hpp"

#define NB_PERSO 4

	
	
PlayersMenu::PlayersMenu () 
{

  _playersItems = new std::list<PlayersItem>;
  position_fleche = new int;
  *position_fleche = 0;

	//Load images from files

	
	//sprite_perso.SetSubRect(IntRect(0,0,32,32));
	
	
	image_p1 = new sf::Image();
	image_p1->LoadFromFile("images/Sprite_perso/blonde.png");
	sf::Sprite * sprite_p1 = new sf::Sprite();
	sprite_p1->SetImage(*image_p1);
	sprite_p1->SetSubRect(IntRect(0,0,32,32));
	sprite_p1->SetPosition(12*32,12*32);
	
	image_p2 = new sf::Image();
	image_p2->LoadFromFile("images/Sprite_perso/fartas.png");
	sf::Sprite * sprite_p2 = new sf::Sprite();
	sprite_p2->SetImage(*image_p2);
	sprite_p2->SetSubRect(IntRect(0,0,32,32));
	sprite_p2->SetPosition(12*32 + 64,12*32);
	
	image_p3 = new sf::Image();
	image_p3->LoadFromFile("images/Sprite_perso/gris.png");
	sf::Sprite * sprite_p3 = new sf::Sprite();
	sprite_p3->SetImage(*image_p3);
	sprite_p3->SetSubRect(IntRect(0,0,32,32));
	sprite_p3->SetPosition(12*32 + 128,12*32);
	
	image_p4 = new sf::Image();
	image_p4->LoadFromFile("images/Sprite_perso/LinusTorvalds.png");
	sf::Sprite * sprite_p4 = new sf::Sprite();
	sprite_p4->SetImage(*image_p4);
	sprite_p4->SetSubRect(IntRect(0,0,32,32));
	sprite_p4->SetPosition(12*32 + 192,12*32);
	
	image_arrow = new sf::Image();
	image_arrow->LoadFromFile("images/Sprite_perso/fleche.png");
	sprite_arrow = new sf::Sprite();
	sprite_arrow->SetImage(*image_arrow);
	
	image_main_players = new sf::Image();
	image_main_players->LoadFromFile("images/PlayersMenu/PlayersMenu.png");
	sprite_main_players = new	sf::Sprite;
	sprite_main_players->SetImage(*image_main_players);
	

	//Setup Players Items
	PlayersItem player1;
	player1.action = p1;
	player1.sprite = sprite_p1;
	player1.texte = String ("Name : Blonde\nHP : \nMana : ", Font::GetDefaultFont(), 20.f);
	player1.texte.SetStyle(11);
	player1.texte.SetColor(Color::White);
	//zone = text.GetRect();
	
	//text_.SetPosition(1024/2 - (zone.Right - zone.Left)/2,GAME_HEIGHT/2 + 10 + (position * 40) + (zone_.Top -  zone_.Bottom)/2);
	player1.texte.SetPosition(12*32 - 10,12*32 + 40);
	
	PlayersItem player2;
	player2.action = p2;
	player2.sprite = sprite_p2;
	player2.texte = String ("Name : p2\nHP : \nMana : ", Font::GetDefaultFont(), 20.f);
	player2.texte.SetPosition(12*32 - 10,12*32 + 40);
	player2.texte.SetStyle(11);
	player2.texte.SetColor(Color::White);
	
	PlayersItem player3;
	player3.action = p3;
	player3.sprite = sprite_p3;
	player3.texte = String ("Name : p3\nHP : \nMana : ", Font::GetDefaultFont(), 20.f);
	player3.texte.SetPosition(12*32 - 10,12*32 + 40);
	player3.texte.SetStyle(11);
	player3.texte.SetColor(Color::White);
	
	PlayersItem player4;
	player4.action = p4;
	player4.sprite = sprite_p4;
	player4.texte = String ("Name : p4\nHP : \nMana : ", Font::GetDefaultFont(), 20.f);
	player4.texte.SetPosition(12*32 - 10,12*32 + 40);
	player4.texte.SetStyle(11);
	player4.texte.SetColor(Color::White);

	_playersItems->push_back(player1);
	_playersItems->push_back(player2);
	_playersItems->push_back(player3);
	_playersItems->push_back(player4);
}

PlayersMenu::~PlayersMenu () 
{
  cout << "Destructeur PlayersMenu()" << endl;
  _playersItems->clear();
   
  delete _playersItems;

  delete sprite_arrow;
  delete position_fleche;
  delete sprite_main_players;

	delete image_p1;
	delete image_p2;
	delete image_p3;
	delete image_p4;
	delete image_arrow;
}
void PlayersMenu::Load(sf::RenderWindow *window)
{ 
cout << "Load Players menu" << endl;
  window->Clear(Color::White);
	window->Draw(*sprite_main_players);
	sprite_arrow->SetPosition(12*32 - 20 + (*position_fleche)*64, 5 + 12*32);
	for (auto b : *_playersItems) {
	  window->Draw(*(b.sprite));
	  //window->Draw(b.texte);
    
  }
  
   window->Draw((_playersItems->begin())->texte);
  
  window->Draw(*sprite_arrow);
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
     if (*position_fleche == 0) {
      *position_fleche = NB_PERSO - 1;
     }
     else {
      --(*position_fleche);
     }
  }
 
  if (position == 1) {
     if (*position_fleche == NB_PERSO - 1) {
      *position_fleche = 0;
     }
     else {
      ++(*position_fleche);
     }
  }
 
  cout << *position_fleche << endl;
  
  sprite_arrow->SetPosition(12*32 - 20 + (*position_fleche)*64, 5 + 12*32);
    cout << "unga1" << endl;
  window->Clear();
  window->Draw(*sprite_main_players);
    cout << "unga2" << endl;
	for (auto b : *_playersItems) {
	    cout << "unga3" << endl;
	  window->Draw(*(b.sprite));
	  cout << "unga4" << endl;
	  //window->Draw(b.texte);
   }
   cout << "iterator :" << endl;
   std::list<PlayersItem>::iterator iter = _playersItems->begin();
   cout << "iterator créé" << endl;
   int ind = 0;
   while (ind < *position_fleche) {
      ++iter;
      ++ind;
   }
   
   cout << "Sortie du for" << endl;
   window->Draw(iter->texte);
   
   cout << *position_fleche << endl;
   
   
   window->Draw(*sprite_arrow);
   window->Display();
   cout << "finHandleKey" << endl;
	return Nothing;
}
