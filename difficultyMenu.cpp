#include "difficultyMenu.hpp"

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
   Mouse_Refresh = new Clock();
   difficultyItems_ = new list<DifficultyItem>;
   sprite_main_difficulty_ = new	Sprite();

	//Load images from files
	
	image_main_ = new Image();
	image_main_->LoadFromFile("images/DifficultyMenu/DifficultyMenu.png");
	sprite_main_difficulty_->SetImage(*image_main_);
	
	image_easy_ = new Image();
	image_easy_->LoadFromFile("images/DifficultyMenu/Easy.png");
	Sprite sprite_easy;
	sprite_easy.SetImage(*image_easy_);
	
	image_intermediate_ = new Image();
	image_intermediate_->LoadFromFile("images/DifficultyMenu/Intermediate.png");
	Sprite sprite_intermediate;
	sprite_intermediate.SetImage(*image_intermediate_);
	
	image_hard_ = new Image();
	image_hard_->LoadFromFile("images/DifficultyMenu/Hard.png");
	Sprite sprite_hard;
	sprite_hard.SetImage(*image_hard_);

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

	difficultyItems_->push_back(easyButton);
	difficultyItems_->push_back(intermediateButton);
	difficultyItems_->push_back(hardButton);
}

DifficultyMenu::~DifficultyMenu () 
{
   difficultyItems_->clear();
   delete difficultyItems_;

   delete sprite_main_difficulty_;

	delete image_main_;
	delete image_easy_;
	delete image_intermediate_;
	delete image_hard_;
	delete Mouse_Refresh;
}
void DifficultyMenu::Load(RenderWindow *window)
{ 

   window->Clear(Color::White);
	window->Draw(*sprite_main_difficulty_);
	window->Display();
}

DifficultyMenu::DifficultyResult DifficultyMenu::Show(RenderWindow *window)
{
	return GetDifficultyResponse(window);
}

//Suivant les actions effectuées dans la fenêtre, affiche les sprites des boutons colorés ou renvoie le résultat du bouton associé à l'endroit cliqué 
DifficultyMenu::DifficultyResult  DifficultyMenu::GetDifficultyResponse(RenderWindow *window)
{
	Event difficultyEvent;

	while(42 != 43)
	{

		while(window->GetEvent(difficultyEvent))
		{	    
	
			if(difficultyEvent.Type == Event::MouseButtonPressed)
			{
				return HandleClick(difficultyEvent.MouseButton.X,difficultyEvent.MouseButton.Y);
			}

			if(difficultyEvent.Type == Event::KeyPressed)
			{
				if(difficultyEvent.Key.Code == Key::Escape) 
				return Escape;
			}
			if (Mouse_Refresh->GetElapsedTime() > 0.05)
			{
			   if(difficultyEvent.Type == Event::MouseMoved) 
			   {
				   HandleMove(difficultyEvent.MouseMove.X,difficultyEvent.MouseMove.Y,window);
			   }
			}
		}
	}
}


DifficultyMenu::DifficultyResult DifficultyMenu::HandleClick(int x, int y)
{
	for (auto b : *difficultyItems_) 
	{
		if (b.rect.Contains(x, y)) 
		{
      	return b.action;  
		}
	}

	return Nothing;
}

// Si la souris est sur un bouton, on afiche son sprite coloré
void DifficultyMenu::HandleMove(int x, int y, RenderWindow *window)
{	
	bool on_button = false;
	
	for (auto b : *difficultyItems_) 
	{
		if (b.rect.Contains(x, y)) 
		{
			on_button = true;
			window->Clear(Color::White);
			window->Draw(*sprite_main_difficulty_);
			window->Draw( b.sprite);
		}
	}
	
	if (!on_button) 
	{
		window->Clear(Color::White);
		window->Draw(*sprite_main_difficulty_);
	}
  
	window->Display();
}


