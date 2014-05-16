#ifndef GOBBLER_H
#define GOBBLER_H

#include "SDL.h"
#include<iostream>
#include<vector>
#include<time.h>

using std::vector;

#include "PhysicsSprite.h"
#include "School.h"

class GobblerFish : public PhysicsSprite
{
public:
	explicit GobblerFish(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: PhysicsSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		preyFish = 0;
		preySchool = 0;

		speed = 300;
		chargeSpeed = 500;
		drag = 1.0f;
		maxVelX = 1000;
		maxVelY = 1000;

		collisionBox.x = posX;
		collisionBox.y = posY;
		collisionBox.h = height;
		collisionBox.w = width;

		state = START;
	}

	~GobblerFish();

	void Update(float deltaTicks, vector<School *> schools);
private:
	int chargeSpeed;

	Timer timer;
	Timer idleTimer;

	enum states {START, RUNNING, HUNTING, EATING, END};

	SDL_Rect attractionBox;
	bool reverse;
	int preySchool;
	int preyFish;
};

#endif