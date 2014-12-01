#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "powersamurai.hpp"

#define speed 3

enum direction direction_prec;

using namespace std;
using namespace sf;

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


PowerSamurai::PowerSamurai()
{
	win_ = new RenderWindow(VideoMode(800, 600), "POWER SAMURAI");
}

PowerSamurai::~PowerSamurai()
{
	delete win_;
}

void 
PowerSamurai::run ()
{
	Event event;
	Clock time;
	Clock clock2;
	Vector2f position(win_->GetWidth()/2,win_->GetHeight()/2);
	Clock clock;
	Vector2i test_effect(5,5);

	Shape rect1   = Shape::Rectangle(10,10,20,20,Color(100,0,0));
	Shape rect2   = Shape::Rectangle(350,210,360,220,Color(100,0,0));
	Shape rect3   = Shape::Rectangle(5,5,995,995,Color(0,50,50));

	if(!image_linus.LoadFromFile("sprite/LinusTorvalds.png"))
		cout << "erreur " << endl ;


	if(!perso.LoadFromFile("sprite/gris.png"))
		cout << "erreur " << endl ;
	perso.SetSmooth(true);
	if(!feux.LoadFromFile("sprite/feux.png"))
		cout << "erreur " << endl ;
	feux.SetSmooth(true);
	if(!plan.LoadFromFile("sprite/map.png"))
		cout << "erreur " << endl ;
	plan.SetSmooth(true);

	if (!buffer_son.LoadFromFile("Musique/BinB.ogg"))
		cout << "erreur " << endl ;


	if (!effect_003.LoadFromFile("sprite/effect_003.png"))
		cout << "erreur " << endl ;

	AnimationEffect effect(win_,effect_003,test_effect);

	son.SetBuffer(buffer_son);
	son.SetLoop(true);
 	//son.Play();

	sprite_perso.SetImage(perso);
	sprite_feux.SetImage(feux);	
	sprite_plan.SetImage(plan);
	
	Animation wistiki(win_, perso, Vector2i(32,32));

	LinusTorvalds *linus = new LinusTorvalds(win_,image_linus);

	Camera camera(win_,linus);

	entitys.push_front(linus);

   // Exécution de la boucle principale
   while (win_->IsOpened())
   {
		while (win_->GetEvent(event))
		{
			// Gestion des evenements 
		switch (event.Type)
		{
			case Event::Closed :
				win_->Close();
				break;

			case Event::KeyPressed :
				linus->actionKey(event.Key.Code);
				keyPressedManagement(event.Key.Code);
				effect.play(clock2, false);
				break;

			default: 
				break;
			}
		}
		if((time.GetElapsedTime() > 0.25) && (moving)){
			anim.x++; 
			if(unsigned (anim.x * 32) >= perso.GetWidth())
				anim.x = 0;
			time.Reset();
			moving = false;
		}

		sprite_perso.SetSubRect(IntRect(anim.x*32,anim.y*32,anim.x*32+32,anim.y*32+32));

	
		position.x = sprite_perso.GetPosition().x + 16;
		position.y = sprite_perso.GetPosition().y + 16;
		if(position.x < (win_->GetWidth()/2))
			position.x = 400 ;
		if(position.y < (win_->GetHeight()/2))
			position.y = 300 ;
		if(position.x > 1000 - 400)
			position.x = 1000 - 400 ;
		if(position.y > 1000 - 300)
			position.y = 1000 - 300 ;
		//view.SetFromRect(FloatRect(sprite_perso.GetPosition().x,sprite_perso.GetPosition().y,win_->GetWidth()/2,win_->GetHeight()/2));

		view.SetCenter(position.x, position.y);
		view.SetHalfSize(400, 300);

		// Efface le contenu de la fenetre 
		//win_->Clear();
	
		//win_->SetView(view);
		camera.run();	
	
		win_->Draw(rect3);
		win_->Draw(sprite_plan);

		// Mise a jours des sprites et affichage
		displayEntity(clock);

		win_->Draw(rect1);
		win_->Draw(rect2);

		// ajoute le perso
		win_->Draw(sprite_perso);
      
		//	wistiki.display();
   	

		// Affichage du contenu de la fenêtre à l'écran
		win_->Display();

		// Efface le contenu de la fenetre 
		win_->Clear();
   }
}

void
PowerSamurai::eventManagement(Event &event)
{

	switch (event.Type)
	{
		case Event::Closed :
			win_->Close();
			break;

		case Event::Resized :
			//win_->SetView(View(FloatRect(0, 0, win_->GetWidth(), win_->GetHeight())));
			break;

		case Event::LostFocus :
			break;

		case Event::GainedFocus :
			break;

		case Event::TextEntered :
			break;

		case Event::KeyPressed :
			//player_fartas->actionKey(event.Key.Code);
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
PowerSamurai::keyPressedManagement (sf::Key::Code keyPressed)
{
  //const sf::Input &input = win_->GetInput();
  switch (keyPressed) {
	case sf::Key::Up :
		moving = true;
		anim.y = UP;
		sprite_perso.Move(0,-speed);
		direction_prec = UP;
		break;
	case sf::Key::Down :
		moving = true;
		anim.y = DOWN;
		sprite_perso.Move(0,speed);
		direction_prec = DOWN;
		break;
	case sf::Key::Left :
		moving = true;
		anim.y =  LEFT;
		sprite_perso.Move(-speed,0);
		direction_prec = LEFT;
		break;
	case sf::Key::Right :
		moving = true;
		anim.y = RIGHT;
		sprite_perso.Move(speed,0);
		direction_prec = RIGHT;
		break;
	case sf::Key::Space :
		if(direction_prec == UP/*input.IsKeyDown(sf::Key::Up)*/){
			sprite_feux.Move(0,-speed);
			fire(UP);
		}
		else if(direction_prec == DOWN){
			sprite_feux.Move(0,speed);
			fire(DOWN);
		 }
		else if(direction_prec == LEFT){
			sprite_feux.Move(-speed,0);
			fire(LEFT);
		}
		else if(direction_prec == RIGHT){
			sprite_feux.Move(speed,0);
			fire(RIGHT);
		}

		//entitys.remove(player_fartas);
		break;
	default: 
		break;
  }
	cout << " x : " << sprite_perso.GetPosition().x << " y : " << sprite_perso.GetPosition().y << endl;	

	if(sprite_perso.GetPosition().x < 0)
		sprite_perso.SetPosition(Vector2f(0,sprite_perso.GetPosition().y));
	else if(sprite_perso.GetPosition().y < 0)
		sprite_perso.SetPosition(Vector2f(sprite_perso.GetPosition().x,0));
	else if(sprite_perso.GetPosition().x  > 1000 - 32/*win_->GetWidth() - 32*/)
		sprite_perso.SetPosition(Vector2f(1000 - 32,sprite_perso.GetPosition().y));
	else if(sprite_perso.GetPosition().y  > 1000 - 32/*win_->GetHeight() - 32*/)
		sprite_perso.SetPosition(Vector2f(sprite_perso.GetPosition().x,1000 - 32));
	
}

void 
PowerSamurai::fire(enum direction dir)
{
	sprite_feux.SetSubRect(IntRect(0,0,64,64));
	sprite_feux.SetPosition(sprite_perso.GetPosition());
	//boule.push_front(sprite_feux);
}

void 
PowerSamurai::addEntity(Entity *entity)
{
	entitys.push_back(entity);
}

void 
PowerSamurai::removeEntity(Entity *entity)
{
	// A FAIRE
}

void 
PowerSamurai::displayEntity(Clock &time)
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
PowerSamurai::addEffect(AnimationEffect *effect)
{
	effects.push_back(effect);
}

void 
PowerSamurai::removeEffect(AnimationEffect *effect)
{
	// A FAIRE
}

void 
PowerSamurai::displayEffect(Clock &time)
{
	bool refresh = false;

	if (time.GetElapsedTime() > EFFECT_FPS_RATE) 
		refresh = true;

	for(auto s : effects){
		if(refresh && s->isPlaying()){
			//s->play();
		}
		s->display();
	}

	if(refresh)
		time.Reset();
}

