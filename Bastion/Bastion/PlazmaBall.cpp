#include "PlazmaBall.h"
#include "Globals.h"
#include "CollisionDetection.h"



PlazmaBall::PlazmaBall(float positionX, float positionY, float positionZ, float velX, float velZ, float initialRotation,float type) {

	this->originalSpeedX = velX - bulletSpeedOriginal * sin(PI / 180 * (initialRotation));
	this->originalSpeedZ = velZ - bulletSpeedOriginal * cos(PI / 180 * (initialRotation));
	this->speedX = this->originalSpeedX;
	this->speedZ = this->originalSpeedZ;
	this->posX = positionX;
	this->posY = positionY;
	this->posZ = positionZ;
	this->type = type;
	this->remainingLife = 100;
}

void PlazmaBall::drawPlazmaBall(float type) 
{
	glPushMatrix();
	if (type == 1)
	{
		lighting->SetDiffuse(0, .7, 1, 1);
		lighting->SetAmbient(0, .7, 1, 1);
		lighting->SetEmmision(0, .7, 1, 1);
		lighting->SetShininess(100);
	}
	else
	{
		lighting->SetDiffuse(1, .1, .1, 1);
		lighting->SetAmbient(1, .1, .1, 1);
		lighting->SetEmmision(1, .1,.1, 1);
		lighting->SetShininess(100);
	}
	glTranslatef(this->posX, this->posY, this->posZ);
	glutSolidSphere(.1, 20, 20);
	lighting->LightReset();
	glPopMatrix();
}

void PlazmaBall::move() 
{
	this->speedX = this->originalSpeedX;
	this->speedZ = this->originalSpeedZ;
	this->posX += this->speedX;
	this->posZ += this->speedZ;
	this->remainingLife -= 1;
	for (int i = 0; i < buildings.size(); i++) 
	{
		if (distanceBetween(this->posX, this->posZ, buildings[i]->givePosX(), buildings[i]->givePosZ()) < 2) 
		{
			this->flagAsDead();
		}
	}
}

void PlazmaBall::flagAsDead() {
	this->remainingLife = 0;
}

bool PlazmaBall::isDead() {
	return this->remainingLife <= 0;
}

float PlazmaBall::givePosX() {
	return this->posX;
}
float PlazmaBall::givePosZ() {
	return this->posZ;
}
float PlazmaBall::getType() {
	return this->type;
}

PlazmaBall::~PlazmaBall()
{
}
