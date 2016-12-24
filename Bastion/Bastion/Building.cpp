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
	glTranslatef(this->posX, this->height/2.3, this->posZ);
	glScalef(width,height,depth);
	glutWireCube(1);
	this->BuildingB();
	glPopMatrix();
}
void Building::BuildingB() 
{
	Lighting *light;
	light = new Lighting();

	light->SetPosition(0, 5, 0, 1);//Which Light Activate
	light->SetBuildingColorWhite();

	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();
	glutWireCube(1);
	glPushMatrix();
	glTranslatef(0, -.45, 0);
	//Top Base Part
	glPushMatrix();
	glTranslatef(-.2, .52, -.2);
	glScalef(.8, .9, .8);
	glutSolidCube(.5);
	glPopMatrix();
	//Upper Part
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, .58, .22);
	glScalef(.8, 1.2, .8);
	glutSolidCube(.5);
	glPopMatrix();
	//Pillar
	glPushMatrix();
	glTranslatef(.2, .29, .44);
	glRotatef(90, -1, 0, 0);
	glScalef(1, 1.1, 15);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.2, .29, 0);
	glRotatef(90, -1, 0, 0);
	glScalef(1, 1.1, 15);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.2, .29, 0);
	glRotatef(90, -1, 0, 0);
	glScalef(1, 1.1, 15);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.2, .29, .44);
	glRotatef(90, -1, 0, 0);
	glScalef(1, 1.1, 15);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Lower Part Adjacent
	glPushMatrix();
	glPushMatrix();
	glTranslatef(.3, .15, 0);
	glScalef(.2, .4, .2);
	glutSolidCube(.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.3, .15, .4);
	glScalef(.2, .4, .2);
	glutSolidCube(.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.3, .15, -.4);
	glScalef(.2, .4, .2);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	//Upper Base Part
	glTranslatef(-.12, .17, 0);
	glScalef(1.5, .5, 2);
	glutSolidCube(.5);
	glPopMatrix();
	//Base Part
	glPushMatrix();
	glScalef(2, .2, 2);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	light->LightReset();
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

