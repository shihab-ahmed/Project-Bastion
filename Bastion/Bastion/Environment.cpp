#include <gl/glut.h>
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