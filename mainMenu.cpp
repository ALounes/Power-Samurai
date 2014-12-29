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
  menuItems_ = new list<MenuItem>;
  sprite_main_all_ = new	Sprite();     
  
	//Chargement des images effectués dès le constructeur en raison de leur coût en ressource
	
	//cout << "CONSTRUCTEUR MainMenu()" << endl;
	music_ = new Music();
	setMusic("Musique/MainMenu.ogg");
	
	image_main_ = new sf::Image();
	image_main_->LoadFromFile("images/MainMenu/MainMenu.png");
	sprite_main_all_->SetImage(*image_main_);		
	
	image_play_ = new sf::Image();
	image_play_->LoadFromFile("images/MainMenu/Play.png");
	Sprite sprite_play;
	sprite_play.SetImage(*image_play_);
	
	image_exit_ = new sf::Image();
	image_exit_->LoadFromFile("images/MainMenu/Exit.png");
	Sprite sprite_exit;
	sprite_exit.SetImage(*image_exit_);
	
	image_difficulty_ = new sf::Image();
	image_difficulty_->LoadFromFile("images/MainMenu/Difficulty.png");
	Sprite sprite_difficulty;
	sprite_difficulty.SetImage(*image_difficulty_);
	
	image_players_ = new sf::Image();
	if (!image_players_->LoadFromFile("images/MainMenu/Players.png"))
		cout << "erreur " << endl ;
	Sprite sprite_players;
	sprite_players.SetImage(*image_players_);
   
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
  

	menuItems_->push_back(playButton);
	menuItems_->push_back(exitButton);
	menuItems_->push_back(difficultyButton);
	menuItems_->push_back(playersButton);
   cout << "CONSTRUCTEUR MainMenu()" << endl;

}


MainMenu::~MainMenu ()
{
  cout << "DESTRUCTEUR MainMenu()" << endl;
  menuItems_->clear();
  delete menuItems_;
  delete sprite_main_all_;

	delete image_main_;
	delete image_play_;
	delete image_exit_;
	delete image_difficulty_;
	delete image_players_;
	delete music_;
}

// Afficher l'image principale
void MainMenu::Load(RenderWindow *window)
{ 
   window->Clear(Color::White);
	window->Draw(*sprite_main_all_);
	window->Display();

}

MainMenu::MenuResult MainMenu::Show(RenderWindow * window)
{

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::GetMenuResponse(RenderWindow * window)
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
	for (auto b : *menuItems_) {
    if (b.rect.Contains(x, y)) {
      return b.action;
      
    }
  }

	return Nothing;
}

void MainMenu::HandleMove(int x, int y, RenderWindow *window)
{	
	
	for (auto b : *menuItems_) {
    if (b.rect.Contains(x, y)) {
      on_button = 4;
      window->Clear(Color::White);
	    window->Draw(*sprite_main_all_);
	    window->Draw( b.sprite );
      
    }
    else {
      --on_button;
    }
  }
	
	if (on_button <= 0) {
		   window->Clear(Color::White);
	      window->Draw(*sprite_main_all_);
  }
  
  window->Display();
}


Music* MainMenu::getMusic() const {
   return music_;
}


void MainMenu::setMusic(string s) {
   music_->OpenFromFile(s);
   music_->SetLoop(true);
}


