#ifndef TIMER_H
#define TIMER_H

#include "SDL.h"

class Timer
{
public:
	Timer();
	~Timer();

	void Start();
	void Pause();
	void Stop();
	void UnPause();
	int GetTicks();
	void RegulateFPS(int fps);

	bool GetStarted();
	bool GetPaused();

private:

	int currentTicks;
	int startTicks;
	int pausedTicks;

	bool started;
	bool paused;
};

#endif