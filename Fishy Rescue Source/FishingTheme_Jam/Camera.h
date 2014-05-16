#ifndef CAMERA_H
#define CAMERA_H

#include "SDL.h"


class Camera
{
public:
	Camera(int _width, int _height);
	~Camera();

	void Update(float fishX, float fishY, int fishWidth, int fishHeight); // just for now
	SDL_Rect GetCamera();
private:
	int width;
	int height;

	SDL_Rect camera;
};

#endif