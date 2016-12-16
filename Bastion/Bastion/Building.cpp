#include "Globals.h"
#include "Building.h"



Building::Building(float positionX, float positionZ, float height,float Width,float Depth)
{
	this->posX = positionX;
	this->posZ = positionZ;
	this->height = height;
	this->width = Width;
	this->depth= Depth;
}


Building::~Building()
{
}
void Building::BuildingA()
{
	glPushMatrix(); //Final push
	glTranslatef(0, .05, 0);
	glScalef(.5,.2,.5);
	glPushMatrix();
	//SetLightEnable();
	//SetDiffuse(0, .8, 1);
	//SetAmbient(0, .8, 1);
	//SetEmision(0, .4, .8);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	//SetLightDisbale();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, 2, 0);
	glScalef(1.2, .5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	glScalef(1.2, .5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(1.2, .5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.1, 0);
	glScalef(1.2, .5, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.8, 0);
	glScalef(1.2, .5, 1.2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, -2, 0);
	glScalef(1.4, 1.4, 1.4);
	glPushMatrix();
	glScalef(1.2, 1, 1.2);
	glutSolidCube(1);
	glPopMatrix();

	//Piller front and back
	glPushMatrix();
	glTranslatef(-.5, 0, .60);
	glScalef(.2, 1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.5, 0, .60);
	glScalef(.2, 1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, 0, -.60);
	glScalef(.2, 1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.5, 0, -.60);
	glScalef(.2, 1, .1);
	glutSolidCube(1);
	glPopMatrix();

	//Piller side
	glPushMatrix();
	glTranslatef(-.6, 0, .55);
	glScalef(.1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.6, 0, .55);
	glScalef(.1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.6, 0, -.55);
	glScalef(.1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.6, 0, -.55);
	glScalef(.1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix(); //light pop

	glPopMatrix();//Final pop matrix

}
void Building::drawSelf() 
{
	glPushMatrix();
	glTranslatef(this->posX, this->height/2.5, this->posZ);
	glScalef(width,height,depth);
	glutWireCube(1);
	this->BuildingA();
	glPopMatrix();
}

float Building::givePosX() {
	return this->posX;
}

float Building::givePosZ() {
	return this->posZ;
}
float Building::giveHeight() {
	return this->height;
}

float Building::giveWidth() {
	return this->width;
}
float Building::giveDepth() {
	return this->depth;
}

