#include "Coral.h"

Coral::~Coral()
{
}

void Coral::Update( float deltaTicks )
{
	switch(state)
	{
	case START:
		show = true;
		totalCapacity = 0;
		state = EMPTY;
		break;
	case EMPTY:
		isFull = false;

		if(totalCapacity >= maxCapacity)
		{
			state = FULL;
		}
		break;
	case FULL:
		isFull = true;
		break;
	case END:
		show = false;
		break;
	};

	attractionBox.x = posX - ((width * 1.5f) / 2);
	attractionBox.y = posY - ((height * 1.5f) / 2);
	attractionBox.h = height * 1.5f;
	attractionBox.w = width  * 1.5f;

	BasicSprite::Update(deltaTicks);
}


SDL_Rect Coral::GetAttractionBox()
{
	return attractionBox;
}

bool Coral::GetIsFull()
{
	return isFull;
}

int Coral::GetMaxCapacity()
{
	return maxCapacity;
}

int Coral::GetTotalCapacity()
{
	return totalCapacity;
}

void Coral::AddOccupant()
{
	totalCapacity += 1;
}