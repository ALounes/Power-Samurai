#include "game.hpp"


#define GAME_WIDTH  1024
#define GAME_HEIGHT 768

#define PLAYING_WIDTH 800
#define PLAYING_HEIGHT 600

#define MAP_1_HEIGHT 26
#define MAP_1_WIDTH 31

#define MAP_2_HEIGHT 47
#define MAP_2_WIDTH 47

Image image_linus;
Image perso;
Image plan;
Image effect_003;
Sprite sprite_plan;
Sprite sprite_perso;
Image feux;
Sprite sprite_feux;
View view;

Vector2i anim(1,DOWN);
bool moving = false;


int pos_x ,pos_y;
SoundBuffer buffer_son;
Sound son;



enum direction direction_prec;

Game::Game ()
{
   cout << "CONSTRUCTEUR game()" << endl;
  _mainMenu = new MainMenu;

  _gameState = new GameState;
  *_gameState = Uninitialized;
  _mainWindow = new sf::RenderWindow(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Power Samurai!!!");
  _mainWindow->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);

  _map_1 = new Map;
  cout << "_map_1 créé" << endl;
  _map_2 = new Map;
  _map_3 = new Map;
  _map_4 = new Map;
  _map_courante = new Map;
  
  cout << "game() terminé" << endl;
}


Game::~Game ()
{
  delete _map_1;
  delete _map_2;
  delete _map_3;
  delete _map_4;
  delete _mainMenu;
  delete _gameState;
  delete _mainWindow;
  delete _difficultyMenu;
  //delete _playersMenu;
}
void Game::Map_Load(void)
{
  cout << "Map_load()" << endl;
  // Creation map 1
  
  _map_1->map_create(MAP_1_HEIGHT,MAP_1_WIDTH);
  cout << "creation terminée()" << endl;
  int static_map_1[MAP_1_HEIGHT][MAP_1_WIDTH] = 
{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,0,0,0,0,1,1,1,0,0,2,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,0,2,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0},
  {0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0},
  {0,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0},
  {0,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,0},
  {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,3,3,1,0,0,0,0,0,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,1,1,1,1,1,3,3,3,3,1,1,1,0,1,1,1,1,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,1,1,1,1,0,1,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  
  cout << "static terminé()" << endl;
  
  for (int i=0; i < MAP_1_HEIGHT; i++) {
    for (int j=0; j < MAP_1_WIDTH; j++) {
      (_map_1->Vector_map)[i][j] = static_map_1[i][j]; 
    }
  }
  cout << "dynamique terminé()" << endl;
  _map_1->image_map->LoadFromFile("images/Maps/map.png");
	_map_1->sprite_map->SetImage(*(_map_1->image_map));
	
	_map_1->set_links(_map_2,_map_3,_map_4);
	
	// Creation map 2
  
  _map_2->map_create(MAP_2_HEIGHT,MAP_2_WIDTH);
  int static_map_2[MAP_2_HEIGHT][MAP_2_WIDTH] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,1,1,1,2,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,0,2,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0},
  {0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0},
  {0,1,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,1,0},
  {0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,0,1,1,0},
  {0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  
  for (int i=0; i < MAP_2_HEIGHT; i++) {
    for (int j=0; j < MAP_2_WIDTH; j++) {
      (_map_2->Vector_map)[i][j] = static_map_2[i][j]; 
    }
  }
  
  _map_2->image_map->LoadFromFile("images/Maps/ruines1.png");
	_map_2->sprite_map->SetImage(*(_map_2->image_map));
	
	_map_2->set_links(_map_1,_map_3,NULL);
	
	cout << "Map chargées" << endl;
	
}

void Game::Start(void)
{
	if(*_gameState != Uninitialized) {
	   cout << "Bug, jeu déjà initialisé" << endl;
		return;
	}
	
	*_gameState = Game::ShowingSplash;
	

	while(!IsExiting())
	{
		GameLoop();
	}
   cout << "fermeture" << endl;
	_mainWindow->Close();
}

bool Game::IsExiting()
{
	if(*_gameState == Game::Exiting) 
		return true;
	else 
		return false;
}

void Game::GameLoop()
{
	switch(*_gameState)
	{
	  case Game::ShowingSplash:
			{
        cout << "Showingsplash" << endl;
				ShowSplashScreen();
				break;
			}
		case Game::ShowingMainMenu:
			{
			  cout << "MainMenu" << endl;
				ShowMainMenu();
				break;
			}
		case Game::ShowingDifficultyMenu:
			{
			  _difficultyMenu = new DifficultyMenu;
			  _difficultyMenu->Load(_mainWindow);
				ShowDifficultyMenu();
            delete _difficultyMenu;
				break;
			}
			
		case Game::ShowingPlayersMenu:
			{
			  _playersMenu = new PlayersMenu;
			  _playersMenu->Load(_mainWindow);
				ShowPlayersMenu();
            delete _playersMenu;
				break;
			}
			
		case Game::Playing:
			{
            //delete _mainMenu;
            _map_courante = _map_1;
            
            _mainWindow->SetSize(PLAYING_WIDTH, PLAYING_HEIGHT);
            _mainWindow->SetPosition((VideoMode::GetDesktopMode().Width - PLAYING_WIDTH)/2, (VideoMode::GetDesktopMode().Height - PLAYING_HEIGHT)/2);
            _mainWindow->Clear();
            cout << "Rungame()" << endl;
            RunGame();
            
            _mainWindow->SetSize(GAME_WIDTH, GAME_HEIGHT);
            _mainWindow->SetPosition((VideoMode::GetDesktopMode().Width - GAME_WIDTH)/2, (VideoMode::GetDesktopMode().Height - GAME_HEIGHT)/2);
            
            //_mainMenu = new MainMenu;
            //_mainMenu->Load(_mainWindow);
            //ShowMainMenu();
				break;
			}
			
			default :
			{
				break;
			}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen *_splashScreen = new SplashScreen;
	_splashScreen->Show(_mainWindow);
	
	*_gameState = Game::ShowingMainMenu;
	
	delete _splashScreen;
}

void Game::ShowMainMenu()
{
   _mainMenu->Load(_mainWindow);
	cout << "mainMenu loaded" << endl;
	
	cout << "Début ShowMainMenu" << endl;
	MainMenu::MenuResult result = _mainMenu->Show(_mainWindow);
	cout << "result obtenu" << endl;
	switch(result)
	{
	case MainMenu::Exit:
			*_gameState = Game::Exiting;
			cout << "result = Exit" << endl;
			
			break;
	case MainMenu::Play:
			*_gameState = Game::Playing;
			break;
	case MainMenu::Difficulty:
			*_gameState = Game::ShowingDifficultyMenu;
			
			break;
	case MainMenu::Players:
			*_gameState = Game::ShowingPlayersMenu;
			break;
	default:
			break;	
	}
	
}

void Game::ShowDifficultyMenu()
{
  DifficultyMenu::DifficultyResult resultat = _difficultyMenu->Show(_mainWindow);

	switch(resultat)
	{
	case DifficultyMenu::Escape:
			*_gameState = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Easy:
			*_gameState = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Intermediate:
			*_gameState = Game::ShowingMainMenu;

			break;
	case DifficultyMenu::Hard:
			*_gameState = Game::ShowingMainMenu;

			break;
	default:    
			break;	
	}
}

void Game::ShowPlayersMenu()
{
  _mainWindow->ShowMouseCursor(false);
  PlayersMenu::PlayersResult resultat = _playersMenu->Show(_mainWindow);
  while (resultat != PlayersMenu::Escape && resultat != PlayersMenu::Return) {
	  resultat = _playersMenu->Show(_mainWindow);
	}
	
	switch(resultat)
	 {
	 case PlayersMenu::Escape:
	  cout << "cas échap" << endl;
			*_gameState = Game::ShowingMainMenu;	
			break;
	 case PlayersMenu::Return:
			*_gameState = Game::ShowingMainMenu;			
			break;
	 default:    
			break;	
	 }
  _mainWindow->ShowMouseCursor(true);
  cout << "delete players terminé" << endl;
}

void Game::RunGame()
{

	Event event;
	Clock time;
	Clock clock2;
	Vector2f position(_mainWindow->GetWidth()/2,_mainWindow->GetHeight()/2);
	Clock clock;
	Vector2i test_effect(5,8);

	if(!image_linus.LoadFromFile("sprite/LinusTorvalds.png"))
		cout << "erreur " << endl ;

	if (!buffer_son.LoadFromFile("Musique/BinB.ogg"))
		cout << "erreur " << endl ;


	if (!effect_003.LoadFromFile("sprite/effect_010.png"))
		cout << "erreur " << endl ;

	son.SetBuffer(buffer_son);
	son.SetLoop(true);
 	//son.Play();

	sprite_perso.SetImage(perso);
	sprite_feux.SetImage(feux);	
	
	sprite_plan = *(_map_courante->sprite_map);
	

	LinusTorvalds *linus = new LinusTorvalds(_mainWindow,image_linus);

	Camera camera(_mainWindow,linus);

	entitys.push_front(linus);

	linus->setPosition(Vector2f(90,90));

	// ANIMATION EFFECT
	AnimationEffect *effect = new AnimationEffect(_mainWindow,effect_003,test_effect,linus);
	addEffect(effect);
	effect->setPosition(Vector2f(300,300));

   // Exécution de la boucle principale
   bool fin_de_boucle = false;
   while (_mainWindow->IsOpened() && !(fin_de_boucle))
   {
		while (_mainWindow->GetEvent(event))
		{
			// Gestion des evenements 
		switch (event.Type)
		{
			case Event::Closed :
			   fin_de_boucle = true;
				*_gameState = Game::ShowingMainMenu;
				break;

			case Event::KeyPressed :
				linus->actionKey(event.Key.Code);
				linus->soclePosition();
				keyPressedManagement(event.Key.Code);
				effect->play();
				break;

			default: 
				break;
			}
		}
		
		view.SetHalfSize(400, 300);

		camera.run();	

		_mainWindow->Draw(sprite_plan);

		// Mise a jours des sprites et affichage
		displayEntity(clock);
	
   	effect->run();

		// Affichage du contenu de la fenêtre à l'écran
		_mainWindow->Display();

		// Efface le contenu de la fenetre 
		_mainWindow->Clear();
}
}

void
Game::eventManagement(Event &event)
{

	switch (event.Type)
	{
		case Event::Closed :
			_mainWindow->Close();
			break;

		case Event::Resized :
			//_mainWindow->SetView(View(FloatRect(0, 0, _mainWindow->GetWidth(), _mainWindow->GetHeight())));
			break;

		case Event::LostFocus :
			break;

		case Event::GainedFocus :
			break;

		case Event::TextEntered :
			break;

		case Event::KeyPressed :
			keyPressedManagement(event.Key.Code);
			break;

		case Event::KeyReleased :
			break;

		case Event::MouseWheelMoved :
			break;

		case Event::MouseButtonPressed :
			break;

		case Event::MouseButtonReleased :
			break;

		case Event::MouseMoved :
			break;

		case Event::MouseEntered :
			break;

		case Event::MouseLeft :
			break;

		case Event::JoyButtonPressed :
			break;

		case Event::JoyButtonReleased :
			break;

		case Event::JoyMoved :
			break;

		default:
			break;
	}
}

void 
Game::keyPressedManagement (sf::Key::Code keyPressed)
{
  switch (keyPressed) {
   case  sf::Key::Escape :
      launchingPause();
		
	 	break;
   case  sf::Key::P :
      _map_courante = _map_courante->getLink(1);
		sprite_plan = *(_map_courante->sprite_map);
		
		break;

	default: 
		break;
  }
	
}

void 
Game::fire(enum direction dir)
{
// à faire

}

void 
Game::addEntity(Entity *entity)
{
	entitys.push_back(entity);
}

void 
Game::removeEntity(Entity *entity)
{
	entitys.remove(entity);
}

void 
Game::displayEntity(Clock &time)
{
	bool refresh = false;

	if (time.GetElapsedTime() > ENTITY_FPS_RATE) 
		refresh = true;

	for(auto s : entitys){
		if(refresh && s->isPlaying()){
			s->update();
		}
		s->display();
	}

	if(refresh)
		time.Reset();
}


void 
Game::addEffect(AnimationEffect *effect)
{
	effects.push_back(effect);
}

void 
Game::removeEffect(AnimationEffect *effect)
{
	effects.remove(effect);
}

void 
Game::displayEffect(Clock &time)
{
	// a faire
}

void Game::launchingPause() {
   bool Ispause = true;
   Shape grey_screen   = Shape::Rectangle(0,0,PLAYING_WIDTH/2,PLAYING_HEIGHT/2,Color(0,0,0));
   
   
	String texte = String ("               Le jeu est en pause.\n\n(P) : Continuer    (Q) : Menu principal", Font::GetDefaultFont(), 40.f);
	texte.SetPosition(2*32,6*32);
	texte.SetStyle(11);
	texte.SetColor(Color::White);
	
   
   _mainWindow->Draw(grey_screen);
   _mainWindow->Draw(texte);
   _mainWindow->Display();
   while (Ispause == true) {
     Event event2;
     
     while (_mainWindow->GetEvent(event2))
		{
			// Gestion des evenements 
		switch (event2.Type)
		{
			case Event::KeyPressed :
     
            switch (event2.Key.Code) {
               case  sf::Key::Escape :
                  Ispause = false;
		            break;
               case  sf::Key::P :
                  Ispause = false;
		
	               break; 
               case  sf::Key::Q :
                  Ispause = false;
		
	        	      break;
	            default :
	               break;
	         }
	         
	         break;
	      default :
	         break;
	   }
    }
   }

}



