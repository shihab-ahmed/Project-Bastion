#include <GL/glut.h>
#include "Lighting.h"
void BuildingA()
{
	glPushMatrix();
	glTranslatef(0, 0, -4);
	glScalef(2, 2, 8);
	glutSolidCube(1);
	glPopMatrix();
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
void Environment()
{
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.7,.7,.7);
	SetAmbient(.7, .7, .7);
	glTranslatef(0,-5.5,0);
	glRotatef(90,1,0,0);
	glScalef(3,3,3);

	glPushMatrix();
	Ground();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 4, 0);
	BuildingA();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, -4, 0);
	BuildingB();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4,4, 0);
	BuildingC();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -4, 0);
	BuildingD();
	glPopMatrix();
	
	glDisable(GL_LIGHTING);
	glPopMatrix();
}