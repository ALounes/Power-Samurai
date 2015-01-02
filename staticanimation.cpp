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

#include "staticanimation.hpp"

StaticAnimation::StaticAnimation (RenderWindow *win, Image& image, const Vector2i nbrOfAnim, Vector2f position)
	: AnimationEffect(win,image,nbrOfAnim)
	, position_(position)
{}

StaticAnimation ::
~StaticAnimation () {}

void 
StaticAnimation ::run() 
{
	if(isPlaying())
	{
		setCenter(position_);
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}	
		if(isPlaying() && (getAnim() == -1))
			stop();			
	}
}

void 
StaticAnimation ::loop() 
{
	if(isPlaying() )
	{
		setCenter(position_);
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}				
	}
}

