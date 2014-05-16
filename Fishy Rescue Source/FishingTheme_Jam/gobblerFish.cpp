#include "GobblerFish.h"

GobblerFish::~GobblerFish()
{
}

void GobblerFish::Update(float deltaTicks, vector<School *> schools)
{

	float diffX = 0.0f;
	float diffY = 0.0f;
	float magnitude = 0.0f;

	switch(state)
	{
	case START:
		show = true;
		state = RUNNING;
		frame = 0;
		break;
	case RUNNING:

		frame = 0;
		//moves the gobbler randomly
		accX = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);
		accY = (((float)rand()/(float)(RAND_MAX) * (speed - -speed)) + -speed);
		
		//checks to see if the fish are within a zone
		for(preySchool = 0; preySchool < schools.size(); preySchool++)
		{
			bool breaked = false;

			for(preyFish = 0; preyFish < 3; preyFish++)
			{
				if(!schools[preySchool]->GetFish(preyFish)->GetSaved())
				{
					if(CheckCollision(schools[preySchool]->GetFish(preyFish)->GetCollisionBox(), attractionBox) &&
						(!schools[preySchool]->GetFish(preyFish)->GetEaten()))
					{
						state = HUNTING;
						breaked = true;
						break;
					}
				}
			}
			if(breaked)
			{
				break;
			}
		}
		
		break;
	case HUNTING:
		
		diffX = schools[preySchool]->GetFish(preyFish)->GetPosX() - posX + (rand() % 50 + -50);
		diffY = schools[preySchool]->GetFish(preyFish)->GetPosY() - posY + (rand() % 50 + -50);
		magnitude = (float)sqrtf(diffX * diffX + diffY * diffY);
		diffX /= magnitude;
		diffY /= magnitude;


		accX += diffX * chargeSpeed;
		accY += diffY * chargeSpeed;

		//do the eating animation;
		if(!timer.GetStarted())
		{
			timer.Start();
		}

		if(timer.GetTicks() >= 100)
		{
			if(!reverse)
			{
				frame += 1;
			}
			else
			{
				frame -= 1;
			}
			timer.Stop();
		}


		if(!schools[preySchool]->GetFish(preyFish)->GetSaved())
		{
			if(!CheckCollision(schools[preySchool]->GetFish(preyFish)->GetCollisionBox(), attractionBox))
			{
				state = RUNNING;
			}
			//if the fish is by the mouth eat the fish
			if(CheckCollision(schools[preySchool]->GetFish(preyFish)->GetCollisionBox(), collisionBox) &&
				(!schools[preySchool]->GetFish(preyFish)->GetEaten()))
			{
				schools[preySchool]->GetFish(preyFish)->SetEaten(true);
				state = EATING;
			}
		}
		else
		{
			state = RUNNING;
		}


		if(frame >= 5)
		{
			frame = 5;
			reverse = true;
		}
		else if(frame <= 0)
		{
			frame = 0;
			reverse = false;
		}
		break;

	case EATING:


		if(!timer.GetStarted())
		{
			timer.Start();
		}
		if(!idleTimer.GetStarted())
		{
			idleTimer.Start();
		}

		if(timer.GetTicks() >= 100)
		{
			if(!reverse)
			{
				frame += 1;
			}
			else
			{
				frame -= 1;
			}
			timer.Stop();
		}

		if(idleTimer.GetTicks() >= 3000)
		{
			state = RUNNING;
			idleTimer.Stop();
		}

		if(frame >= 5)
		{
			frame = 5;
			reverse = true;
		}
		else if(frame <= 0)
		{
			frame = 0;
			reverse = false;
		}
		break;
	case END:
		break;
	};

	//this could all be in a function in basicSprite
	bool negative = velX < 0;

	if(negative)
	{
		flipped = false;
	}
	else
	{
		flipped = true;
	}

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

	attractionBox.x = posX - (width * 2);
	attractionBox.y = posY - (height * 2);
	attractionBox.h = height * 4;
	attractionBox.w = width * 4;

	PhysicsSprite::Update(deltaTicks);
}