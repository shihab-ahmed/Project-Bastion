#include <GL/glut.h>

void TankBody() {
	//Body Middle
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(3, 1.4, 3);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();

	//Body Front
	glPushMatrix();
	glTranslatef(1.3, -.3, 0);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(3, .2, 2.3);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Body Top Front
	glPushMatrix();
	glTranslatef(1.3, .05, 0);
	glRotatef(63, 0, 0, 1);
	glPushMatrix();
	glScalef(3, 1.3, 1.5);
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //GL_LINE_LOOP
	glVertex3f(-.5, -.5, 0);
	glVertex3f(.5, -.5, 0);
	glVertex3f(.5, .5, 0);
	glVertex3f(-.5, .5, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//Side Triangle
	glPushMatrix();
	glTranslatef(.72, -.26, -.75);
	//glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_TRIANGLES); //GL_LINE_LOOP
	glVertex3f(0, 0, 0);
	glVertex3f(1.16, 0, 0);
	glVertex3f(0, .6, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//Side Triangle
	glPushMatrix();
	glTranslatef(.72, -.26, .75);
	//glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_TRIANGLES); //GL_LINE_LOOP
	glVertex3f(0, 0, 0);
	glVertex3f(1.16, 0, 0);
	glVertex3f(0, .6, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

void TankFrontTire() {

	//Front Right
	glPushMatrix();
	glTranslatef(1.6, -.3, -.8);

	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	//Front Left
	glPushMatrix();
	glTranslatef(1.6, -.3, .8);

	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}


void TankRearTire() {

	//Front Right
	glPushMatrix();
	glTranslatef(-.7, -.12, -.75);
	glScalef(1.8, 1.8, 2);
	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	//Front Left
	glPushMatrix();
	glTranslatef(-.7, -.12, .75);
	glScalef(1.8, 1.8, 2);

	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void TankFireSystem() {
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	//For Rotation and Fitting With Body
	glPushMatrix();
	glTranslatef(0, .75, 0);
	glRotatef(90, 0, 1, 0);
	//Box
	glPushMatrix();
	glScalef(2, 1.2, 3);
	glutSolidCube(.2);
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(0, .05, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(0, -.05, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(.05, 0, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(-.05, 0, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Rings
	glPushMatrix();
	glTranslatef(0, 0, 1.22);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 1.18);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, .9);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, .33);
	glScalef(.77, .77, 5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void TankBodyFireJoin() {
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	//Circle join
	glPushMatrix();
	glTranslatef(0, .45, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1.5, 1.5, 1.5);
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	//Cylinder join
	glPushMatrix();
	glTranslatef(0, .65, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, .14, .14, .2, 25, 25);
	glPopMatrix();
}