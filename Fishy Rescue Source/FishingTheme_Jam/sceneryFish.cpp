#include "SceneryFish.h"

SceneryFish::~SceneryFish()
{
}

void SceneryFish::Update(float deltaTicks, Fish &fish)
{

	bool negative;

	switch(state)
	{
	case START:
		show = true;
		state = RUNNING;
		break;
	case RUNNING:


		accX = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);
		accY = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);

		if(posX >= 2000 - width)
		{
			velX *= -1;
		}
		if(posX <= 0)
		{
			velX *= -1;
		}
		if(posY >= 1000 - height)
		{
			velY *= -1;
		}
		if(posY <= 0)
		{
			velY *= -1;
		}

		negative = velX < 0;

		if(negative)
		{
			flipped = false;
		}
		else
		{
			flipped = true;
		}
		break;
	case END:
		break;
	};

	PhysicsSprite::Update(deltaTicks);
}

void SceneryFish::Update(float deltaTicks)
{
	

		accX = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);
		accY = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);

		if(posX >= 2000 - width)
		{
			velX *= -1;
		}
		if(posX <= 0)
		{
			velX *= -1;
		}
		if(posY >= 1000 - height)
		{
			velY *= -1;
		}
		if(posY <= 0)
		{
			velY *= -1;
		}

		 bool negative = velX < 0;

		if(negative)
		{
			flipped = false;
		}
		else
		{
			flipped = true;
		}

	PhysicsSprite::Update(deltaTicks);
}