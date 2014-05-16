#ifndef BASICSPRITE_H
#define BASICSPRITE_H

#include "SDL.h"
#include <iostream>

#include "Camera.h"

using std::string;

class BasicSprite
{
public:

	BasicSprite(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY);
	~BasicSprite();

	virtual void Draw(SDL_Surface *buffer, Camera &camera);
	virtual void Update(float deltaTicks);

	bool CheckCollision(SDL_Rect a, SDL_Rect b);
	//void StartAnimation(int maxFrame, int time, bool reversing);

	float GetPosX();
	float GetPosY();
	int GetHeight();
	int GetWidth();

	SDL_Rect GetCollisionBox();

	void SetPosX(float _posX);
	void SetPosY(float _posY);
	void SetState(int _state);
private:

	SDL_Surface* LoadImage(std::string filename);
protected:

	SDL_Surface *sprite;
	SDL_Rect size;
	SDL_Rect screenPosition;
	SDL_Rect collisionBox;

	int width;
	int height;
	float posX;
	float posY;

	int sheetX;
	int sheetY;

	bool show;
	bool flipped;

	int state;
	int frame;
};

#endif