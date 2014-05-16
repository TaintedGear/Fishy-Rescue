#include "Fish.h"

//Fish::Fish(std::string _filename, int _width, int _height, int _sheetX,
//		int _sheetY, int _posX, int _posY) 
//		: PhysicsSprite(_filename, _width, _height, _sheetX,
//		_sheetY, _posX, _posY)
//{
//
//}


Fish::~Fish()
{
}

void Fish::Update(float deltaTicks)
{ 
	Uint8* key = SDL_GetKeyState(NULL);
	
	switch(state)
	{
	case START:
		show = true;
		flipped = false;
		state = RUNNING;
		break;
	case RUNNING:
		
		if(!timer.GetStarted())
		{
			timer.Start();
		}

		if(key[SDLK_w])
		{
			accY = -speed;
		}
		if(key[SDLK_s])
		{
			accY = speed;
		}
		if(key[SDLK_a])
		{
			accX = -speed;
			flipped = true;
		}
		if(key[SDLK_d])
		{
			accX = speed;
			flipped = false;
		}

		if (posX >= 2000 - width )
		{
			velX *= -1;
		}
		if (posX <= 0)
		{
			velX *= -1;
		}
		if (posY >= 1000 - height)
		{
			velY *= -1;
		}
		if (posY <= 0)
		{
			velY *= -1;
		}

		if(timer.GetTicks() >= 100)
		{
			frame += 1;
			timer.Stop();
		}
		if(frame == 1)
		{
			frame = 0;
		}

		break;
	case DEAD:

		show = false;
		lives -= 1;

		if(lives != 0)
		{
			state = START;
		}
		break;
	}

	PhysicsSprite::Update(deltaTicks);
}