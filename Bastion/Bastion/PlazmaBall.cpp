#include "PlazmaBall.h"
#include "Globals.h"
#include "CollisionDetection.h"



PlazmaBall::PlazmaBall(float positionX, float positionY, float positionZ, float velX, float velZ, float initialRotation) {

	this->originalSpeedX = velX - bulletSpeedOriginal * sin(PI / 180 * (initialRotation));
	this->originalSpeedZ = velZ - bulletSpeedOriginal * cos(PI / 180 * (initialRotation));
	this->speedX = this->originalSpeedX;
	this->speedZ = this->originalSpeedZ;
	this->posX = positionX;
	this->posY = positionY;
	this->posZ = positionZ;
	this->remainingLife = 500;
}

void PlazmaBall::drawPlazmaBall() {
	glPushMatrix();
	glTranslatef(this->posX, this->posY, this->posZ);
	//glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
}

void PlazmaBall::move() {
	this->speedX = this->originalSpeedX;
	this->speedZ = this->originalSpeedZ;
	this->posX += this->speedX;
	this->posZ += this->speedZ;
	this->remainingLife -= 1;
	for (int i = 0; i < buildings.size(); i++) {
		if (distanceBetween(this->posX, this->posZ, buildings[i]->givePosX(), buildings[i]->givePosZ()) < 2) {
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


PlazmaBall::~PlazmaBall()
{
}
