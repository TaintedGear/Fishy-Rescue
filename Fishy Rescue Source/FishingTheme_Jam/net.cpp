#include "Net.h"


Net::~Net()
{
}

void Net::Update(float deltaTicks, Fish &fish)
{

	switch(state)
	{
	case START:
		frame = 0;
		show = true;
		released = false;
		state = RUNNING;

		break;
	case RUNNING:

		if(CheckCollision(fish.GetCollisionBox(), collisionBox))
		{
			state = RELEASED;
		}

		if(collisionBox.y + 64 <= 0)
		{
			state = CAPTURED;
		}

		break;
	case CAPTURED:
		//do wriggle animation

		if(!timer.GetStarted())
		{
			timer.Start();
		}

		state = END;

		break;
	case RELEASED:

		if(!timer.GetStarted())
		{
			timer.Start();
		}

		if(frame == 5)
		{
			state = END;
			released = true;
			timer.Stop();
		}

		if(timer.GetTicks() >= 100)
		{
			frame += 1;
			timer.Stop();
		}

		break;
	case END:

		if(!timer.GetStarted())
		{
			timer.Start();
		}

		show = false;
		released = false;

		//this needs to be changed to proper level scaling
		posX = (rand() % 2000 - 64);
		posY = (rand() % 1000 + 64);
									

		if(timer.GetTicks() >= 3000)
		{
			state = START;
			timer.Stop();
		}
		break;
	}

	//BasicSprite::Update(deltaTicks);
	collisionBox.x = posX;
	collisionBox.y = posY;
	collisionBox.h = height;
	collisionBox.w = width;

}

bool Net::GetReleased()
{
	return released;
}


float Net::GetOffsetX()
{
	return collisionBox.x; // change this to a var
}
float Net::GetOffsetY()
{
	return collisionBox.y;
}