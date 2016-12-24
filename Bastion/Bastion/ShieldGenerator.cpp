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
	this->height = 3;
	this->width = 3;
	this->depth = 3;
}
void ShieldGenerator::drawShield()
{
	glPushMatrix();
	glTranslatef(this->posX, this->posY, this->posZ);
	//glRotatef(this->getRotation(), 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 0,0);
	glScalef(this->width, this->height, this->depth);
	this->Shield();
	if (this->ShieldLife > -1)
	{
		glPushMatrix();
		lighting->SetRedShield();
		glutSolidSphere(this->ShieldRadius, 30, 30);
		lighting->LightReset();
		glPopMatrix();
	}

	glPopMatrix();
	glPopMatrix();
}

ShieldGenerator::~ShieldGenerator()
{
}
void ShieldGenerator::Shield() {
	Lighting *light;
	light = new Lighting();

	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();
	glutWireCube(1);
	glPushMatrix();
	glTranslatef(0, -.35, 0);
	//Base
	glPushMatrix();
	glScalef(2, .6, 2);
	glutSolidCube(.5);
	glPopMatrix();
	//Middle Piller
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glScalef(1, .9, 15);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .9, .9, 1.2, 25, 25);
	glPopMatrix();
	glPopMatrix();
	//Upper Circle
	glPushMatrix();
	glScalef(.5, .5, .5);
	glTranslatef(0, 1.5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(.2, 25, 25);
	glPopMatrix();
	//Middle Circles
	glPushMatrix();
	glScalef(.7, .5, .7);
	glTranslatef(0, 1.1, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.1, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, .5, 1);
	glTranslatef(0, .8, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.1, .2, 25, 25);
	glPopMatrix();


	light->SetPosition(0, 5, 0, 1);//Which Light Activate
	light->SetShieldColor();
	glPushMatrix();
	glScalef(1.4, .5, 1.4);
	glTranslatef(0, .5, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.1, .2, 25, 25);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	light->LightReset();
}





