#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "entity.hpp"

class Camera
{
	public :

	Camera(RenderWindow* win, Entity* entity);
	~Camera();
	
	void run();

	private:
	RenderWindow *win_;
	Vector2f *position_;
	View view_;
	Entity *entityFocused_;
	
};

#endif
