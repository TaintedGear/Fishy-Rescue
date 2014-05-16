#include "PhysicsSprite.h"

PhysicsSprite::~PhysicsSprite()
{
}

void PhysicsSprite::Update( float deltaTicks )
{
	float newVelX = 0.0f;
	float newVelY = 0.0f;
	float newPosX = 0.0f;
	float newPosY = 0.0f;

	//applys drag
	accX += (velX * -1) * drag;
	accY += (velY * -1) * drag;
	
	newPosX = posX + velX * (deltaTicks / 1000);
	newPosY = posY + velY * (deltaTicks / 1000);

	newVelX = velX  + accX * (deltaTicks / 1000);
	newVelY = velY + accY * (deltaTicks / 1000);

	if(newVelX >= maxVelX)
	{
		newVelX = maxVelX;
	}
	else if(newVelX <= -maxVelX)
	{
		newVelX = -maxVelX;
	}
	
	if(newVelY >= maxVelY)
	{
		newVelY = maxVelY;
	}
	else if(newVelY <= -maxVelY)
	{
		newVelY = -maxVelY;
	}


	posX = newPosX;
	posY = newPosY;
	velX = newVelX;
	velY = newVelY;
	accX = 0;
	accY = 0;

	BasicSprite::Update(deltaTicks);
}

float PhysicsSprite::GetAccX()
{
	return accX;
}

float PhysicsSprite::GetAccY()
{
	return accY;
}

float PhysicsSprite::GetVelX()
{
	return velX;
}

float PhysicsSprite::GetVelY()
{
	return velY;
}

void PhysicsSprite::SetAccX(float _accX )
{
	accX = _accX;
}

void PhysicsSprite::SetAccY(float _accY )
{
	accY = _accY;
}

void PhysicsSprite::SetVelX(float _velX)
{
	velX = _velX;
}

void PhysicsSprite::SetVelY(float _velY)
{
	velY = _velY;
}