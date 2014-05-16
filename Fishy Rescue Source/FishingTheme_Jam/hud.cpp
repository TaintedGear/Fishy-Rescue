#include "Hud.h"

Hud::Hud()
{
	time = 60;
	score = 0;
	deaths = 0;

	timeSurface = NULL;
	scoreSurface = NULL;
	deathSurface = NULL;

	font = TTF_OpenFont("Fonts/LILLIPUT.ttf", 18);

	fontColour.r = 65;
	fontColour.g = 65;
	fontColour.b = 65;

	scorePosition.x = 475;
	scorePosition.y = 20;
	deathPosition.x = 475;
	deathPosition.y = 60;
	timePosition.x = 10;
	timePosition.y = 20;
}

Hud::~Hud()
{
	if(font != NULL)
	{
		//TTF_CloseFont(font);
	}
}

void Hud::Update(int _score, int _deaths)
{
	if(!timer.GetStarted())
	{
		timer.Start();
	}

	if(timer.GetTicks() >= 1000)
	{
		time -= 1;
		timer.Stop();
	}

	score = _score;
	deaths = _deaths; 
}

void Hud::Draw( SDL_Surface* buffer )
{
	std::string sScore;
	std::stringstream out;
	out << score;
	sScore = ("Score:" + out.str());
	std::string sDeath;
	std::stringstream out1;
	out1 << deaths;
	sDeath = ("Deaths:" + out1.str());
	std::string sTime;
	std::stringstream out2;
	out2 << time;
	sTime = ("Time Remaning:" + out2.str());

	if(scoreSurface = TTF_RenderText_Solid(font, sScore.c_str(), fontColour))
	{
		SDL_BlitSurface(scoreSurface, NULL, buffer, &scorePosition);
		SDL_FreeSurface(scoreSurface);
	}
	if(deathSurface = TTF_RenderText_Solid(font, sDeath.c_str(), fontColour))
	{
		SDL_BlitSurface(deathSurface, NULL, buffer, &deathPosition);
		SDL_FreeSurface(deathSurface);
	}
	if(timeSurface = TTF_RenderText_Solid(font, sTime.c_str(), fontColour))
	{
		SDL_BlitSurface(timeSurface, NULL, buffer, &timePosition);
		SDL_FreeSurface(timeSurface);
	}
}

void Hud::Reset()
{
	time = 60;
	score = 0;
	deaths = 0;
}

int Hud::GetTime()
{
	return time;
}

int Hud::GetScore()
{
	return score;
}

int Hud::GetDeaths()
{
	return deaths;
}