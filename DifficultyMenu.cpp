#include "DifficultyMenu.hpp"

#define EASYTOP 435
#define EASYBOTTOM 498
#define EASYLEFT 573
#define EASYRIGHT 758

#define INTERMEDIATETOP 514
#define INTERMEDIATEBOTTOM 577
#define INTERMEDIATELEFT 383
#define INTERMEDIATERIGHT 965

#define HARDTOP 585
#define HARDBOTTOM 658
#define HARDLEFT 574
#define HARDRIGHT 770
	
DifficultyMenu::DifficultyMenu () 
{

  _difficultyItems = new std::list<DifficultyItem>;
  sprite_main_difficulty = new	sf::Sprite;

	//Load images from files
	
	image_main = new sf::Image();
	image_main->LoadFromFile("images/DifficultyMenu/DifficultyMenu.png");
	sprite_main_difficulty->SetImage(*image_main);
	
	image_easy = new sf::Image();
	image_easy->LoadFromFile("images/DifficultyMenu/Easy.png");
	sf::Sprite sprite_easy;
	sprite_easy.SetImage(*image_easy);
	
	image_intermediate = new sf::Image();
	image_intermediate->LoadFromFile("images/DifficultyMenu/Intermediate.png");
	sf::Sprite sprite_intermediate;
	sprite_intermediate.SetImage(*image_intermediate);
	
	image_hard = new sf::Image();
	image_hard->LoadFromFile("images/DifficultyMenu/Hard.png");
	sf::Sprite sprite_hard;
	sprite_hard.SetImage(*image_hard);

	//Setup clickable regions
	

	//Easy menu item coordinates
	DifficultyItem easyButton;
	
	easyButton.rect.Top= EASYTOP;
	easyButton.rect.Bottom = EASYBOTTOM;
	easyButton.rect.Left = EASYLEFT;
	easyButton.rect.Right = EASYRIGHT;
	
	easyButton.action = Easy;
	
	easyButton.sprite = sprite_easy;

	//Intermediate menu item coordinates
	DifficultyItem intermediateButton;
	
	intermediateButton.rect.Top = INTERMEDIATETOP;
	intermediateButton.rect.Bottom = INTERMEDIATEBOTTOM;
	intermediateButton.rect.Left = INTERMEDIATELEFT;
	intermediateButton.rect.Right = INTERMEDIATERIGHT;
	
	intermediateButton.action = Intermediate;
	
	intermediateButton.sprite = sprite_intermediate;
	
  //Hard menu item coordinates
  DifficultyItem hardButton;
	
	hardButton.rect.Top= HARDTOP;
	hardButton.rect.Bottom = HARDBOTTOM;
	hardButton.rect.Left = HARDLEFT;
	hardButton.rect.Right = HARDRIGHT;
	
	hardButton.action = Hard;
	
	hardButton.sprite = sprite_hard;

	_difficultyItems->push_back(easyButton);
	_difficultyItems->push_back(intermediateButton);
	_difficultyItems->push_back(hardButton);
}

DifficultyMenu::~DifficultyMenu () 
{
   _difficultyItems->clear();
   delete _difficultyItems;

   delete sprite_main_difficulty;

	delete image_main;
	delete image_easy;
	delete image_intermediate;
	delete image_hard;
	cout << "delete Difficulty Menu terminé" << endl;
}
void DifficultyMenu::Load(sf::RenderWindow *window)
{ 
cout << "Load diff menu" << endl;
  window->Clear(sf::Color::White);
	window->Draw(*sprite_main_difficulty);
	window->Display();
}

DifficultyMenu::DifficultyResult DifficultyMenu::Show(sf::RenderWindow *window)
{
    cout << "Show" << endl;
	return GetDifficultyResponse(window);
}

DifficultyMenu::DifficultyResult  DifficultyMenu::GetDifficultyResponse(sf::RenderWindow *window)
{
	sf::Event difficultyEvent;

	while(42 != 43)
	{

		while(window->GetEvent(difficultyEvent))
		{	    
	
			if(difficultyEvent.Type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(difficultyEvent.MouseButton.X,difficultyEvent.MouseButton.Y);
			}
			if(difficultyEvent.Type == sf::Event::KeyPressed)
			{
						if(difficultyEvent.Key.Code == sf::Key::Escape) 
						return Escape;
			}
			
			if(difficultyEvent.Type == sf::Event::MouseMoved) 
			{
			  HandleMove(difficultyEvent.MouseMove.X,difficultyEvent.MouseMove.Y,window);
			}
			
		}
	}
}


DifficultyMenu::DifficultyResult DifficultyMenu::HandleClick(int x, int y)
{
	for (auto b : *_difficultyItems) {
    if (b.rect.Contains(x, y)) {
      return b.action;  
    }
  }

	return Nothing;
}

void DifficultyMenu::HandleMove(int x, int y, sf::RenderWindow *window)
{	
	bool on_button = false;
	
	for (auto b : *_difficultyItems) {
    if (b.rect.Contains(x, y)) {
      on_button = true;
      window->Clear(sf::Color::White);
	    window->Draw(*sprite_main_difficulty);
	    window->Draw( b.sprite);
    }
  }
	
	if (!on_button) {
		    window->Clear(sf::Color::White);
	      window->Draw(*sprite_main_difficulty);
  }
  
  window->Display();
}


