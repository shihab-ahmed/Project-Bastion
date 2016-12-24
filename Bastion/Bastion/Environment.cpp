#include "Globals.h"
#include "Environment.h"



Environment::Environment()
{
}
void Environment::makeGrid(float size) 
{
	glPushMatrix();
	glTranslatef(0,-1,0);
	glBegin(GL_LINES);
	for (int i = -size; i <= size; ++i) {
		glVertex3f(i, 0, -size);
		glVertex3f(i, 0, size);

		glVertex3f(size, 0, i);
		glVertex3f(-size, 0, i);
	}
	glEnd();
	glPopMatrix();
}
void Environment::drawStreet()
{
	for (int i = 0; i < buildings.size(); i++)
	{
		glPushMatrix();
		glTranslatef(buildings[i]->givePosX(),-1.3,buildings[i]->givePosZ());
		glScalef(buildings[i]->giveWidth()+4,1,buildings[i]->giveDepth()+4);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void Environment::drawStreetLamp()
{
	for (int i = 0; i < buildings.size(); i++)
	{
		float posx = buildings[i]->givePosX() + buildings[i]->giveWidth() / 2;
		float posz = buildings[i]->givePosZ() + buildings[i]->giveDepth() / 2;

		glPushMatrix();
		glTranslatef(posx, 0,posz );
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posx, 0,-posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-posx, 0, posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-posx, 0, -posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void Environment::groundFloor(float size)
{
	glPushMatrix();
	glTranslatef(0, -1.3, 0);
	lighting->setGroundColor();
	glScalef(size*2+4,.4, size*2+4);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();
}
Environment::~Environment()
{
}
void BuildingB()
{
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glScalef(2, 2, 4);
	glutSolidCube(1);
	glPopMatrix();
}
void BuildingC()
{
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glScalef(3, 3, 4);
	glutSolidCube(1);
	glPopMatrix();
}
void BuildingD()
{
	glPushMatrix();
	glTranslatef(0, 0, -4);
	glScalef(3, 3, 8);
	glutSolidCube(1);
	glPopMatrix();
}

void Ground()
{
	glPushMatrix();
	glScalef(15, 15, 1);
	glutSolidCube(1);
	glPopMatrix();
}
void Environment::DrawEnvironment()
{
	
}