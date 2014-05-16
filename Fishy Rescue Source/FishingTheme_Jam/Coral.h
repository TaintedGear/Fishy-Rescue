#ifndef CORAL_H
#define CORAL_H

#include "SDL_ttf.h"
#include "BasicSprite.h"
#include "Camera.h"

class Coral : public BasicSprite
{
public:
	explicit Coral(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: BasicSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		maxCapacity = 6;
		totalCapacity = 0;
		isFull = false;

		show = true;
		state = START;
	}

	~Coral();


	void Update(float deltaTicks);

	bool GetIsFull();
	SDL_Rect GetAttractionBox();

	void AddOccupant();

	int GetMaxCapacity();
	int GetTotalCapacity();

private:

	int maxCapacity;
	int totalCapacity;

	bool isFull;

	SDL_Rect attractionBox;
	enum states {START, EMPTY, FULL, END};
};

#endif