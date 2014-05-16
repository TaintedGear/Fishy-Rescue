#include "SchoolFish.h"

SchoolFish::~SchoolFish()
{
}

void SchoolFish::Update(float deltaTicks, Fish &fish, vector<Coral *> &corals)
{

	float diffX = 0.0f;
	float diffY = 0.0f;
	float magnitude = 0.0f;


	switch(state)
	{
	case START:
		scored = false;
		show = true;
		saved = false;
		eaten = false;
		closeCoral = 0;
		state = FOLLOWING;
		break;
	case TRAPPED:
		break;
	case FOLLOWING:

		diffX = fish.GetPosX() - posX + (rand() % 50 + -50);
		diffY = fish.GetPosY() - posY + (rand() % 50 + -50);
		magnitude = (float)sqrtf(diffX * diffX + diffY * diffY);
		diffX /= magnitude;
		diffY /= magnitude;

		accX = diffX * speed;
		accY = diffY * speed;

		if(posX > fish.GetPosX())
		{
			flipped = true;
		}
		else
		{
			flipped = false;
		}

		for(closeCoral = 0; closeCoral < corals.size(); closeCoral++)
		{
			if(CheckCollision(corals[closeCoral]->GetAttractionBox(), collisionBox)
				&& (corals[closeCoral]->GetTotalCapacity() < corals[closeCoral]->GetMaxCapacity()))
			{
				corals[closeCoral]->AddOccupant();
				state = SAVED;
				break;
			}
		}

		if(eaten)
		{
			state = DIED;
		}

		break;
	case SAVED:
		
		saved = true;

		diffX = corals[closeCoral]->GetPosX() - posX;
		diffY = corals[closeCoral]->GetPosY() - posY  + (rand() % 5 + -30);
		magnitude = (float)sqrtf(diffX * diffX + diffY * diffY);
		diffX /= magnitude;
		diffY /= magnitude;

		accX = diffX * speed;
		accY = diffY * speed;

		if(posX > corals[closeCoral]->GetPosX())
		{
			flipped = true;
		}
		else
		{
			flipped = false;
		}

		break;

	case DIED:

		frame = 1;
		accY += (speed / 5);

		if(posY >= 950)
		{
			posY = 950;
		}
		break;
	}

	PhysicsSprite::Update(deltaTicks);
}

bool SchoolFish::GetScored()
{
	return scored;
}

bool SchoolFish::GetSaved()
{
	return saved;
}

bool SchoolFish::GetEaten()
{
	return eaten;
}

void SchoolFish::SetEaten(bool _eaten)
{
	eaten = _eaten;
}

void SchoolFish::SetScored(bool _scored)
{
	scored = _scored;
}