#ifndef PHYSICSSPRITE_H
#define PHYSICSSPRITE_H

#include "BasicSprite.h"

class PhysicsSprite : public BasicSprite
{
public:
	explicit PhysicsSprite(std::string _filename, int _width, int _height, int _sheetX,
		int _sheetY, float _posX, float _posY) 
		: BasicSprite (_filename, _width, _height, _sheetX,
		_sheetY, _posX, _posY)
	{
		speed = 0.0f;
		drag = 0.0f;
		velX = 0.0f;
		velY = 0.0f;
		accX = 0.0f;
		accY = 0.0f;
		maxVelX = 0.0f;
		maxVelY = 0.0f;
	}

	~PhysicsSprite();

	virtual void Update(float deltaTicks);

	float GetAccX();
	float GetAccY();
	float GetVelX();
	float GetVelY();
	void SetAccX( float _accX );
	void SetAccY( float _accY );
	void SetVelX( float _velX );
	void SetVelY( float _velY );
private:

protected:
	float velX,
		velY,
		accX,
		accY,
		maxVelX,
		maxVelY,
		drag,
		speed;
};

#endif