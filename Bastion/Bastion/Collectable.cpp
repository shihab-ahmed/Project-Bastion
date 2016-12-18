#include "Collectable.h"
#include "Globals.h"
using namespace std;

Collectable::Collectable(float positionX, float positionY, float positionZ,float initialRotation, float type)
{
	this->posX = positionX;
	this->posY = 0;
	this->posZ = positionZ;
	this->type = type;
	this->rotation = initialRotation;
	this->remainingLife = 350;
	this->height = .2;
	this->width = .2;
	this->depth = .2;
}
bool Collectable::isHitBy(Collectable* collectable)
{
	float x = collectable->givePosX() - playerRobot->givePosX();
	float z = collectable->givePosZ() - playerRobot->givePosZ();
	return x*x + z*z < (this->width * 3)*(this->width * 3);
}
float Collectable::getRotation()
{
	this->rotation += 5.0f;
	if (this->rotation > 360)
	{
		rotation = 0;
	}
	return this->rotation;
}
void Collectable::drawCollectable(float type)
{
	this->remainingLife -= 1;
	glPushMatrix();
	if (type == 1)
	{
		lighting->SetDiffuse(.2, 1, 0, 1);
		lighting->SetAmbient(0, 1, 0, 1);
		lighting->SetEmmision(.2,.8, 0, 1);
		lighting->SetShininess(100);
	}
	else
	{
		lighting->SetDiffuse(1, .1, .1, 1);
		lighting->SetAmbient(1, .1, .1, 1);
		lighting->SetEmmision(1, .1, .1, 1);
		lighting->SetShininess(100);
	}
	glTranslatef(this->posX, this->posY, this->posZ);
	glRotatef(this->getRotation(),0,1,0);
	glScalef(this->width, this->height, this->depth);
	glutSolidOctahedron();
	lighting->LightReset();
	glPopMatrix();
}
void Collectable::flagAsDead() {
	this->remainingLife = 0;
}

bool Collectable::isDead() {
	return this->remainingLife <= 0;
}

float Collectable::givePosX() {
	return this->posX;
}
float Collectable::givePosZ() {
	return this->posZ;
}
float Collectable::getType() {
	return this->type;
}
Collectable::~Collectable()
{
}
