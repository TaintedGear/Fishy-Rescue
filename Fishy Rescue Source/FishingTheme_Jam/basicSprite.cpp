#include "BasicSprite.h"

BasicSprite::BasicSprite(std::string _filename, int _width, int _height, int _sheetX, 
	int _sheetY, float _posX, float _posY)
{
	frame = 0;
	width = _width;
	height = _height;
	sheetX = _sheetX;
	sheetY = _sheetY;
	posX = _posX;
	posY = _posY;

	sprite = NULL;
	sprite = LoadImage(_filename);
	Uint32 colourKey = SDL_MapRGB(sprite->format, 0xFF, 0, 0xFF);
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colourKey);
}

BasicSprite::~BasicSprite()
{
	SDL_FreeSurface(sprite);
};

SDL_Surface* BasicSprite::LoadImage(std::string filename)
{
	//load the sprite sheet or image;
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	loadedImage = SDL_LoadBMP( filename.c_str() );

	if( loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormat( loadedImage );
	}

	SDL_FreeSurface(loadedImage);

	return optimizedImage;
}

void BasicSprite::Draw(SDL_Surface *buffer, Camera &camera)
{
	if(show)
	{
		size.x = frame * width;
		size.y = sheetY;
		size.h = height;
		size.w = width;

		if(flipped)
		{
			size.y = sheetY + width;
		}

		screenPosition.x = posX - camera.GetCamera().x;
		screenPosition.y = posY - camera.GetCamera().y;
		screenPosition.h = height;
		screenPosition.w = width;

		SDL_BlitSurface(sprite, &size, buffer, &screenPosition);
	}
}

void BasicSprite::Update(float deltaTicks)
{
	//update sprite
	collisionBox.x = posX;
	collisionBox.y = posY;
	collisionBox.h = height;
	collisionBox.w = width;
}

bool BasicSprite::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	float leftA = a.x,
		rightA = a.x + a.w,
		topA = a.y,
		bottomA = a.y + a.h;

	float leftB = b.x,
		rightB = b.x + b.w,
		topB = b.y,
		bottomB = b.y + b.h;

	if(bottomA <= topB)
	{
		return false;
	}
	if(topA >= bottomB)
	{
		return false;
	}
	if(rightA <= leftB)
	{
		return false;
	}
	if(leftA >= rightB)
	{
		return false;
	}

	return true;
}

void BasicSprite::SetState(int _state)
{
	state = _state;
}

float BasicSprite::GetPosX()
{
	return posX;
}

float BasicSprite::GetPosY()
{
	return posY;
}

int BasicSprite::GetWidth()
{
	return width;
}

int BasicSprite::GetHeight()
{
	return height;
}

SDL_Rect BasicSprite::GetCollisionBox()
{
	return collisionBox;
}

void BasicSprite::SetPosX(float _posX)
{
	posX = _posX;
}

void BasicSprite::SetPosY(float _posY)
{
	posY = _posY;
}