#include <gl/glut.h>
#include "Environment.h"



Environment::Environment()
{
}

void Environment::makeGrid(float size) 
{
	//glColor4f(0.0f, 0.0f, 1.0f, 1.0f );
	glBegin(GL_LINES);
	for (int i = -size; i <= size; ++i) {
		glVertex3f(i, 0, -size);
		glVertex3f(i, 0, size);

		glVertex3f(size, 0, i);
		glVertex3f(-size, 0, i);
	}
	glEnd();
}
Environment::~Environment()
{
}
void Environment::BuildingA()
{
	glPushMatrix(); //Final push
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 2.5, 0);
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
	glPushMatrix();
	//glEnable(GL_LIGHTING);
	//SetDiffuse(.7, .7, .7);
	//SetAmbient(.7, .7, .7);
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(6, 6, 3);

	glPushMatrix();
	//Ground();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 2, 0);
	this->BuildingA();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(4, -4, 0);
	this->BuildingA();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 4, 0);
	this->BuildingA();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, -4, 0);
	this->BuildingA();
	glPopMatrix();

	//glDisable(GL_LIGHTING);
	glPopMatrix();
}