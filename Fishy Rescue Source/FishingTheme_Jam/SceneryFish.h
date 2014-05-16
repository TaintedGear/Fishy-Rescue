#ifndef SCENERYFISH_H
#define SCENERYFISH_H

#include <time.h>

#include "PhysicsSprite.h"
#include "Fish.h"
#include "Timer.h"

class SceneryFish : public PhysicsSprite
{
public:
	explicit SceneryFish(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: PhysicsSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		speed = 100;
		drag = 1.0f;
		maxVelX = 350;
		maxVelY = 350;

		show = true;
		state = START;
	}

	~SceneryFish();

	void Update(float deltaTicks, Fish &fish);
	void Update(float deltaTicks);
private:

	Timer timer;
	enum states {START, RUNNING, END};
};

#endif