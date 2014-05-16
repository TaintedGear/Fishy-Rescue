#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>
#include <time.h>

#include "Camera.h"
#include "Coral.h"
#include "Net.h"
#include "SceneryFish.h"
#include "GobblerFish.h"

using std::string;
using std::vector;

class Fish;

class Level
{
public:
	Level();
	~Level();

	void LoadLevel(Fish &_fish, vector<Coral *> &corals, vector<Net *> &nets,
		vector<SceneryFish *> &sceneryFish, vector<GobblerFish *> &gobblerFish);

	void ResetLevel(Fish &_fish, vector<Coral *> &corals, vector<Net *> &nets,
		vector<SceneryFish *> &sceneryFish, vector<GobblerFish *> &gobblerFish);

	void DrawForeground(SDL_Surface *buffer, Camera &camera);
	void DrawBackdrop(SDL_Surface* buffer, Camera &camera);
	void DrawBackground(SDL_Surface* buffer, Camera &camera);

private:

	SDL_Surface *foreground;
	SDL_Surface *background;
	SDL_Surface *backdrop;

	std::string dropFilename;
	std::string foreFilename;
	std::string backFilename;

	int state;
	enum {LEVEL1, LEVEL2, LEVEL3};

	Coral* coral;
	Net* net;
	SceneryFish* scenFish;
	GobblerFish* gobFish;

	int coralAmount;
	int netAmount;
	int gobblerAmount;
	int sceneryFishAmount;
};

#endif