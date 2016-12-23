#include "Globals.h"
#include "ShieldGenerator.h"



ShieldGenerator::ShieldGenerator(float positionX, float positionY, float positionZ, float initialRotation)
{
	this->posX = positionX;
	this->posY = 0;
	this->posZ = positionZ;
	this->rotation = initialRotation;
	this->ShieldLife = 3;
	this->ShieldRadius = 2;
	this->height = .2;
	this->width = .2;
	this->depth = .2;
}
void ShieldGenerator::drawShield()
{
	glPushMatrix();
	glTranslatef(this->posX, this->posY, this->posZ);
	//glRotatef(this->getRotation(), 0, 1, 0);
	//glScalef(this->width, this->height, this->depth);
	glutSolidCube(1);
	//lighting->LightReset();
	

	if (this->ShieldLife > -1)
	{
		glPushMatrix();
		lighting->SetRedShield();
		glutSolidSphere(this->ShieldRadius, 30, 30);
		lighting->LightReset();
		glPopMatrix();
	}

	glPopMatrix();
}

ShieldGenerator::~ShieldGenerator()
{
}
