#ifndef SCHOOL_H
#define SCHOOL_H

#include "SDL.h"
#include <iostream>
#include <vector>

#include "Fish.h"
#include "Coral.h"
#include "Camera.h"
#include "SchoolFish.h"

using std::string;
using std::vector;

class School
{
public:
	School(std::string filename, int netPosX, int netPosY);
	~School();

	void Update(float deltaTicks, Fish &fish, vector<Coral *> corals);
	void Draw (SDL_Surface* buffer, Camera &camera);

	SchoolFish* GetFish(int i);
private:
	vector<SchoolFish *> school;
};

#endif