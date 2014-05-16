#ifndef FISH_H
#define FISH_H

#include "SDL.h"
#include "PhysicsSprite.h"
#include "Timer.h"

class Fish : public PhysicsSprite
{
public:
	explicit Fish(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: PhysicsSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		speed = 700;
		drag = 1.5f;
		maxVelX = 1250;
		maxVelY = 1250;
		lives = 3;
		score = 0;
		state = START;
	}

	Fish();

	~Fish();

	void Update(float deltaTicks);
private:
	int lives;
	int score;
	int state;

	Timer timer;

	enum states {START, RUNNING, DEAD};
};

#endif