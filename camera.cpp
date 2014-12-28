#include "camera.hpp"

Camera::Camera(RenderWindow *win, Entity *entity)
:win_(win)
,entityFocused_(entity)
{
	position_ = new Vector2f(win_->GetWidth()/2,win_->GetHeight()/2);
	Camera_X = new int;
	Camera_Y = new int;
}

Camera::~Camera() 
{
	delete position_;
	delete Camera_X;
	delete Camera_Y;
}

void 
Camera::setCameraXY(int x, int y) 
{
   *Camera_X = x;
   *Camera_Y = y;
}

int* 
Camera::getCameraX() const 
{
   return Camera_X;
}

int* 
Camera::getCameraY() const 
{
   return Camera_Y;
}


Vector2f* 
Camera::getPosition() const
{
	return position_;
}

void
Camera::run()
{
	position_->x = entityFocused_->getSprite()->GetPosition().x 
					 + entityFocused_->getAnimationWidth();
	position_->y = entityFocused_->getSprite()->GetPosition().y 
					 + entityFocused_->getAnimationHeight();

	if(position_->x < (win_->GetWidth() / 2))
		position_->x = CAM_WIDTH ;
	if(position_->y < (win_->GetHeight() / 2))
		position_->y = CAM_HEIGHT ;
	if(position_->x > *Camera_X - CAM_WIDTH)
		position_->x = *Camera_X - CAM_WIDTH;
	if(position_->y > *Camera_Y - CAM_HEIGHT)
		position_->y = *Camera_Y - CAM_HEIGHT;

	view_.SetCenter(position_->x, position_->y);
	view_.SetHalfSize(CAM_WIDTH, CAM_HEIGHT);

	win_->SetView(view_);
}
