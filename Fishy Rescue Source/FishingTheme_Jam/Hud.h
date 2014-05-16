#ifndef HUD_H
#define HUD_H

#include <iostream>
#include <sstream>
#include "SDL_ttf.h"
#include "Timer.h"

class Hud
{
public:
	Hud();
	~Hud();

	void Update(int _score, int _deaths);
	void Draw(SDL_Surface* buffer);

	int GetTime();
	int GetDeaths();
	int GetScore();

	void Reset();
private:

	SDL_Color fontColour;
	TTF_Font *font;
	SDL_Surface *timeSurface;
	SDL_Surface *scoreSurface;
	SDL_Surface *deathSurface;
	SDL_Rect timePosition;
	SDL_Rect scorePosition;
	SDL_Rect deathPosition;

	int time;
	int score;
	int deaths;

	Timer timer;
};

#endif