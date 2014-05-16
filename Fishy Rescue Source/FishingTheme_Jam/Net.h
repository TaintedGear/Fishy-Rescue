#ifndef NET_H
#define NET_H

#include <time.h>

#include "BasicSprite.h"
#include "Fish.h"
#include "Timer.h"

class Net : public BasicSprite
{
public:
	explicit Net(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: BasicSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{

		released = false;
		state = START;
	}

	~Net();

	void Update(float deltaTicks, Fish &fish);
	bool GetReleased();

	float GetOffsetX();
	float GetOffsetY();
private:
	int state;
	enum states {START, RUNNING, CAPTURED, RELEASED, END};

	int length;
	bool released;

	Timer timer;
};

#endif