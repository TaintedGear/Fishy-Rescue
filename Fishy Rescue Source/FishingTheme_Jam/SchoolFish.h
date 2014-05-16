#ifndef SCHOOLFISH_H
#define SCHOOLFISH_H

#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "Coral.h"
#include "PhysicsSprite.h"
#include "Fish.h"

using std::vector;

class SchoolFish : public PhysicsSprite
{
public:
	explicit SchoolFish(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: PhysicsSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		scored = false;
		speed = 500;
		eaten = false;
		closeCoral = 0;
		drag = 1.5f;
		maxVelX = 1000;
		maxVelY = 1000;

		collisionBox.x = posX;
		collisionBox.y = posY;
		collisionBox.h = height;
		collisionBox.w = width;

		saved = false;
		state = START;
	}

	~SchoolFish();

	void Update(float deltaTicks, Fish &fish, vector<Coral *> &corals);

	bool GetScored();
	bool GetSaved();
	bool GetEaten();
	void SetEaten(bool _eaten);
	void SetScored(bool _scored);

private:
	bool scored;
	bool eaten;
	int closeCoral;
	enum states {START, TRAPPED, FOLLOWING, SAVED, DIED};
	bool saved;
};

#endif