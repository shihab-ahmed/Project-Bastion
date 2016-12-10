#include <GL/glut.h>
#include "Lighting.h"
void DrawHeroMiddleBody()
{
	glPushMatrix();//middle body final push
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.4, .4, .4);
	SetAmbient(.4, .4, .4);
	glRotatef(-90,1,0,0);
	gluCylinder(gluNewQuadric(), .5, .5, 1, 20, 20);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.9, .9, .9);
	SetAmbient(.9, .9, .9);
	glRotatef(-90, 1, 0, 0);
	glScalef(.4,.4,.5);
	glutSolidTorus(.5,1.5,20,20);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(1, .9, .8);
	SetAmbient(1, .9, .8);
	glTranslatef(0,-.65,0);
	glScalef(1.2, .8, 1.8);
	glutSolidCube(1);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();//middle body final pop
}

void drawFoot()
{
	//feet start
	glPushMatrix();//final push
				   //left foot part left start
	glEnable(GL_LIGHTING);
	SetDiffuse(.6, .4, .3);
	SetAmbient(.6, .4, .3);

	glPushMatrix();
	glTranslatef(0, 0, .4);

	glPushMatrix();
	glScalef(1, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.57, .12, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .2, .2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(.68, .29, 0);
	glScalef(.2, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.50, .05, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.2, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	//left foot part left end

	//foot part attach start
	glPushMatrix();
	glTranslatef(-.1, 0, 0);
	glScalef(.5, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	//foot part attach end

	//left foot part right start

	glPushMatrix();
	glTranslatef(0, 0, -.4);

	glPushMatrix();
	glScalef(1, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.57, .12, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .2, .2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(.68, .29, 0);
	glScalef(.2, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.50, .05, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.2, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	//left foot part right end
	glDisable(GL_LIGHTING);
	glPopMatrix();//final pop
				  //foot end
}

void DrawLagPad()
{

	//Lag pad start
	glPushMatrix();//final push 
	glEnable(GL_LIGHTING);
	SetDiffuse(1, 1, 1);
	SetAmbient(1, 1, 1);
	//middle
	glPushMatrix();

	glScalef(.1, 1, .8);
	glutSolidCube(1);
	glPopMatrix();

	//bottom
	glPushMatrix();
	glTranslatef(-.06, -.54, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.1, .2, .8);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.055, .525, .3);
	glRotatef(45, 0, 0, 1);
	glScalef(.1, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.055, .525, -.3);
	glRotatef(45, 0, 0, 1);
	glScalef(.1, .2, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.15, -.02, .35);
	glScalef(.2, 1.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.15, -.02, -.35);
	glScalef(.2, 1.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.15, -.02, .35);
	glScalef(.2, 0.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.16, .58, .35);
	glScalef(.18, 0.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.17, -.59, .35);
	glScalef(.16, 0.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.16, .58, -.35);
	glScalef(.18, 0.1, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.17, -.59, -.35);
	glScalef(.16, 0.1, .1);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glPopMatrix();//final pop
				  //Lag pad end
}

void DrawLeftLegSkeleton()
{
	glPushMatrix(); //light push
	glEnable(GL_LIGHTING);
	SetDiffuse(.4, .4, .4);
	SetAmbient(.4, .4, .4);

	glPushMatrix();//Join 1 push final
	glRotatef(90,0,1,0);
	//main nosel circle  start
	glPushMatrix();
	glTranslatef(.75, 1, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//main nosel circle  start

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(-.75, 1, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	//2nd nosel start
	glPushMatrix();
	glTranslatef(-.75, 1, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(gluNewQuadric(), .5, .5, 1.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//2nd nosel end
	glPopMatrix(); //join 1 pop final

	glPushMatrix();
	glTranslatef(2, 1, 0);//
	glScalef(3.5,.5,1.1);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, .5, 0);
	glRotatef(20, 0, 0, 1);
	glScalef(3, .5, 1.3);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();



	glPushMatrix();//Join 2 push final
	glTranslatef(-3,0,0);
	glRotatef(90, 0, 1, 0);
	glScalef(1.2,1.2,1.2);
	//main nosel circle  start
	glPushMatrix();
	glTranslatef(.60, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//main nosel circle  start

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(-.60, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	//2nd nosel start
	glPushMatrix();
	glTranslatef(-.60, 0, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(gluNewQuadric(), .5, .5, 1.2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//2nd nosel end
	glPopMatrix(); //join 2 pop final

	glPushMatrix();//Join 3 push final
	glTranslatef(4, 1, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(.8, .8, .8);
	//main nosel circle  start
	glPushMatrix();
	glTranslatef(.75, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//main nosel circle  start

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(-.75, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	//2nd nosel start
	glPushMatrix();
	glTranslatef(-.75, 0, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(gluNewQuadric(), .5, .5, 1.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//2nd nosel end
	glPopMatrix(); //join 3 pop final

	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void DrawLeftLeg()
{

	glPushMatrix();//Left leg final push
	glTranslatef(0,-3,0);
	glRotatef(90,1,0,0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-1.4, 1, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(20, 0, 0, 1.5);
	glScalef(1,2.2,1.3);
	glPushMatrix();
	DrawLagPad();
	glPopMatrix();
	glPopMatrix();
	
	DrawLeftLegSkeleton();

	glPushMatrix();
	glTranslatef(2, 1.4, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 2.7, 1.5);
	glPushMatrix();
	DrawLagPad();
	glPopMatrix();
	glPopMatrix();

	//foot
	glPushMatrix();
	glTranslatef(4.5, 1.2, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(2, 2, 2);
	glPushMatrix();
	drawFoot();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();//left leg final pop

}