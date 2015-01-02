/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*******************************************************************/

#include "splashScreen.hpp"


void SplashScreen::Show(sf::RenderWindow *renderWindow)
{
  sf::Clock time;
	sf::Image image1;
	sf::Image image2;
	
	if(image1.LoadFromFile("images/SplashScreen/SplashScreen.png") != true)
	{
		return;
	}
	
	if(image2.LoadFromFile("images/SplashScreen/keypress.png") != true)
	{
		return;
	}

	sf::Sprite sprite1(image1);
	sf::Sprite sprite2(image2);
	
	renderWindow->Draw(sprite1);
	renderWindow->Display();

	sf::Event event;
	
	while(true)
	{
	  if(time.GetElapsedTime() > 0.5 && time.GetElapsedTime() < 1){
	    renderWindow->Clear();
	    renderWindow->Draw(sprite1);
	    renderWindow->Draw(sprite2);
	    renderWindow->Display();
		}
		else if (time.GetElapsedTime() > 1) {
		  renderWindow->Clear();
		  renderWindow->Draw(sprite1);
		  renderWindow->Display();
			time.Reset();
		}
	
		while(renderWindow->GetEvent(event))
		{
			if(event.Type == sf::Event::EventType::KeyPressed 
				|| event.Type == sf::Event::EventType::MouseButtonPressed
				|| event.Type == sf::Event::EventType::Closed )
			{
				return;
			}
		}
	}
}
