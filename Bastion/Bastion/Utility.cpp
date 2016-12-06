#include <GL/glut.h>
#include "Lighting.h"
void DrawLaser()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();


	glPushMatrix();//laser begin
	glEnable(GL_LIGHTING);
	SetDiffuse(.7,0,0);
	SetAmbeint(.3, 0, 0);
	SetSpecuilar(.5,.5,.5);
	SetShininess(80);
	SetEmision(.2,0,0);
	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(1, 1, 1);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end
	glEnable(GL_LIGHTING);
	glPopMatrix();//laser end
}