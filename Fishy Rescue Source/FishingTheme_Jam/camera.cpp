#include "Camera.h"

Camera::Camera(int _width, int _height)
{
	width = _width;
	height = _height;

	camera.x = 0;
	camera.y = 0;
	camera.h = height;
	camera.w = width;
}

Camera::~Camera()
{
}

void Camera::Update(float fishX, float fishY, int fishWidth, int fishHeight)
{
	camera.x = (fishX + fishWidth  / 2) - width / 2;
	camera.y = (fishY + fishHeight / 2) - height / 2;

	if(camera.x <= 0)
	{
		camera.x = 0;
	}
	if(camera.x >= 2000 - camera.w)
	{
		camera.x = 2000 - camera.w;
	}
	if(camera.y <= 0)
	{
		camera.y = 0;
	}
	if(camera.y >= 1000 - camera.h)
	{
		camera.y = 1000 - camera.h;
	}
}

SDL_Rect Camera::GetCamera()
{
	return camera;
}