#include "mainMenu.hpp"

#define PLAYTOP 664
#define PLAYBOTTOM 749
#define PLAYLEFT 816
#define PLAYRIGHT 986

#define EXITTOP 15
#define EXITBOTTOM 77
#define EXITLEFT 780
#define EXITRIGHT 990

#define DIFFICULTYTOP 680
#define DIFFICULTYBOTTOM 750
#define DIFFICULTYLEFT 34
#define DIFFICULTYRIGHT 475

#define PLAYERSTOP 600
#define PLAYERSBOTTOM 665
#define PLAYERSLEFT 25
#define PLAYERSRIGHT 330


MainMenu::MainMenu ()
{
  _menuItems = new std::list<MenuItem>;
  sprite_main_all = new	sf::Sprite;     
  
	//Load images from files
	
	cout << "CONSTRUCTEUR MainMenu()" << endl;
	
	image_main = new sf::Image();
	image_main->LoadFromFile("images/MainMenu/MainMenu.png");
	sprite_main_all->SetImage(*image_main);		
	
	image_play = new sf::Image();
	image_play->LoadFromFile("images/MainMenu/Play.png");
	sf::Sprite * sprite_play = new sf::Sprite();
	sprite_play->SetImage(*image_play);
	
	image_exit = new sf::Image();
	image_exit->LoadFromFile("images/MainMenu/Exit.png");
	sf::Sprite * sprite_exit = new sf::Sprite();
	sprite_exit->SetImage(*image_exit);
	
	image_difficulty = new sf::Image();
	image_difficulty->LoadFromFile("images/MainMenu/Difficulty.png");
	sf::Sprite * sprite_difficulty = new sf::Sprite();
	sprite_difficulty->SetImage(*image_difficulty);
	
	image_players = new sf::Image();
	if (!image_players->LoadFromFile("images/MainMenu/Players.png"))
		cout << "erreur " << endl ;
	sf::Sprite * sprite_players = new sf::Sprite();
	sprite_players->SetImage(*image_players);

	//Setup clickable regions
	
	//Nothing menu item

	//Play menu item coordinates
	MenuItem playButton;
	
	playButton.rect.Top= PLAYTOP;
	playButton.rect.Bottom = PLAYBOTTOM;
	playButton.rect.Left = PLAYLEFT;
	playButton.rect.Right = PLAYRIGHT;
	
	playButton.action = Play;
	
	playButton.sprite = sprite_play;

	//Exit menu item coordinates
	MenuItem exitButton;
	
	exitButton.rect.Top = EXITTOP;
	exitButton.rect.Bottom = EXITBOTTOM;
	exitButton.rect.Left = EXITLEFT;
	exitButton.rect.Right = EXITRIGHT;
	
	exitButton.action = Exit;
	
	exitButton.sprite = sprite_exit;
	
  //Difficulty menu item coordinates
  MenuItem difficultyButton;
	
	difficultyButton.rect.Top= DIFFICULTYTOP;
	difficultyButton.rect.Bottom = DIFFICULTYBOTTOM;
	difficultyButton.rect.Left = DIFFICULTYLEFT;
	difficultyButton.rect.Right = DIFFICULTYRIGHT;
	
	difficultyButton.action = Difficulty;
	
	difficultyButton.sprite = sprite_difficulty;
		
  //Players menu item coordinates
  MenuItem playersButton;
	
	playersButton.rect.Top= PLAYERSTOP;
	playersButton.rect.Bottom = PLAYERSBOTTOM;
	playersButton.rect.Left = PLAYERSLEFT;
	playersButton.rect.Right = PLAYERSRIGHT;
	
	playersButton.action = Players;
	
	playersButton.sprite = sprite_players;
  

	_menuItems->push_back(playButton);
	_menuItems->push_back(exitButton);
	_menuItems->push_back(difficultyButton);
	_menuItems->push_back(playersButton);


}


MainMenu::~MainMenu ()
{
  cout << "DESTRUCTEUR MainMenu()" << endl;
  _menuItems->clear();
  delete _menuItems;
  delete sprite_main_all;

	delete image_main;
	delete image_play;
	delete image_exit;
	delete image_difficulty;
	delete image_players;
}

void MainMenu::Load(sf::RenderWindow *window)
{ 
  window->Clear(sf::Color::White);
	window->Draw(*sprite_main_all);
	window->Display();

}

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow * window)
{

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow * window)
{
	sf::Event menuEvent;


	while(42 != 43)
	{

		while(window->GetEvent(menuEvent))
		{	
			if(menuEvent.Type == sf::Event::MouseButtonPressed)
			{

				return HandleClick(menuEvent.MouseButton.X,menuEvent.MouseButton.Y);
			}
			if(menuEvent.Type == sf::Event::Closed)
			{
				return Exit;

			}		
			
			if(menuEvent.Type == sf::Event::MouseMoved) 
			{
			  HandleMove(menuEvent.MouseMove.X,menuEvent.MouseMove.Y,window);

			}
			
		}
	}

}




MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	for (auto b : *_menuItems) {
    if (b.rect.Contains(x, y)) {
      return b.action;
      
    }
  }

	return Nothing;
}

void MainMenu::HandleMove(int x, int y, sf::RenderWindow *window)
{	

	bool on_button = false;
	
	for (auto b : *_menuItems) {
    if (b.rect.Contains(x, y)) {
      on_button = true;
      window->Clear(sf::Color::White);
	    window->Draw(*sprite_main_all);
	    window->Draw( *(b.sprite) );
      
    }
  }
	
	if (!on_button) {
		    window->Clear(sf::Color::White);
	      window->Draw(*sprite_main_all);
  }
  
  window->Display();
}


