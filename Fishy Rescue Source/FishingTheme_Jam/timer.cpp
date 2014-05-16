
#include "Timer.h"

Timer::Timer()
{
	currentTicks = SDL_GetTicks();
	startTicks = 0;
	pausedTicks = 0;

	started = false;
	paused = false;
}

Timer::~Timer()
{
}

void Timer::Start()
{

		started = true;
		paused = false;

		startTicks = SDL_GetTicks();
}

void Timer::Stop()
{
	started = false;
	paused = false;
}

void Timer::Pause()
{
	if ((started) && (!paused))
	{
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::UnPause()
{
	if (paused)
	{
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}

int Timer::GetTicks()
{
	if (started)
	{
		if (paused)
		{
			return pausedTicks;
		}
		else
		{
			return SDL_GetTicks() - startTicks;
		}
	}

	return 0;
}

void Timer::RegulateFPS(int fps)
{
	currentTicks = SDL_GetTicks();

	if (SDL_GetTicks() < 1000 / fps)
	{
		SDL_Delay (((1000/fps) - SDL_GetTicks()));
	}
	
}

bool Timer::GetStarted()
{
	return started;
}

bool Timer::GetPaused()
{
	return paused;
}