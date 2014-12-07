#include <sstream>
#include <SFML/Graphics.hpp>
#include "statusbar.hpp"

StatusBar::StatusBar(RenderWindow *win, Entity *entity)
  : win_(win)
  , entity_(entity)
{
	statu_bar  = Shape::Rectangle(win_->GetView().GetCenter().x - CAM_WIDTH ,
										   win_->GetView().GetCenter().y + CAM_HEIGHT - 30,
											win_->GetView().GetCenter().x + CAM_WIDTH ,
											win_->GetView().GetCenter().y + CAM_HEIGHT,
											sf::Color(0,0,255,128)); 
}

StatusBar::~StatusBar()
{}

void
StatusBar::display () const
{
	int x = win_->GetView().GetCenter().x - CAM_WIDTH / 2;
	int y = win_->GetView().GetCenter().y + CAM_HEIGHT / 2;

	//statu_bar.SetPosition(x,y);

	String text;

	text.SetFont(sf::Font::GetDefaultFont());
	text.SetColor(sf::Color(0, 0, 0));
	text.SetStyle(sf::String::Bold);
	text.SetSize(15);
	text.SetPosition(10,win_->GetHeight()-23);

	text.SetText("[Active Tools : LINE] [Ctrl+C : Circle , Ctrl+R : Rectangle , Ctrl+P : Palette ]");

	win_->Draw(statu_bar);
	win_->Draw(text);
}
