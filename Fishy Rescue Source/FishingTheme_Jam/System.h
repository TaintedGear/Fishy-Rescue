#ifndef SYSTEM_H
#define SYSTEM_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <iostream>

using std::string;

class System
{
public:
	System( std::string _title, bool _fullscreen,
		int _screenWidth, int _screenHeight, int _bpp, int _fps);
	~System();

	bool Setup();
	bool Done();
	void CleanUp( SDL_Surface *buffer );

	SDL_Surface* GetBuffer();
	SDL_Event GetEvent();

private:

	SDL_Event event;

	SDL_Surface *tempBuffer;

	int screenWidth,
		screenHeight,
		bpp,
		fps;

	bool fullscreen;
	std::string title;
};

#endif