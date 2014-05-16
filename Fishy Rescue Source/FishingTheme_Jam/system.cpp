#include "System.h"


System::System(std::string _title, bool _fullscreen,
	int _screenWidth, int _screenHeight, int _bpp, int _fps)
{
	title = _title;
	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
	bpp = _bpp;
	fps = _fps;
	fullscreen = _fullscreen;
}

System::~System()
{
}

bool System::Setup()
{
	//sets up SDL, and prepares a back buffer
	if (SDL_Init ( SDL_INIT_EVERYTHING ) == -1)
	{
		return false;
	}
	if(TTF_Init() == -1)
	{
		return false;
	}
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
	{
		return false;
	}

	if(!fullscreen)
	{
		tempBuffer = SDL_SetVideoMode ( screenWidth, screenHeight, bpp, SDL_SWSURFACE );
	}
	else
	{
		tempBuffer = SDL_SetVideoMode ( screenWidth, screenHeight, bpp, SDL_SWSURFACE | SDL_FULLSCREEN) ;
	}

	if(tempBuffer == NULL)
	{
		return false;
	}

	SDL_WM_SetCaption(title.c_str(), NULL);

	return true;
}

bool System::Done()
{

	SDL_PollEvent(&event);

	if ( event.type == SDL_QUIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void System::CleanUp( SDL_Surface *buffer )
{
	SDL_FreeSurface(buffer);

	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}

SDL_Surface* System::GetBuffer()
{
	return tempBuffer;
}

SDL_Event System::GetEvent()
{
	return event;
}