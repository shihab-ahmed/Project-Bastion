#include <GL/glut.h>
#include "Lighting.h"


void drawHeadBodyAttacher()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix(); //Final push
	//SetLightPosition(0,0,0);
	SetDiffuse(.3,.3,.3);
	SetAmbient(.3,.3,.3);
	glPushMatrix();
	glRotatef(90,1,0,0);
	gluCylinder(quadratic, .3, .3, 1, 20, 20);
	glPopMatrix();
	glPopMatrix(); //final pop
}
void DrawLeftShoulder()
{

	/*........................................................................................*/

	//left shoulder start
	/*...............................................*/
	glPushMatrix();
	glTranslatef(2, -1, 0);
	glColor3ub(243, 231, 189);
	//Left shoulder armor start

	glPushMatrix();// light start
	SetDiffuse(1, .9, .8);
	SetAmbient(1, .9, .8);
	/*................*/
	glPushMatrix();
	glScalef(.2, 1, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*.................*/
	glPushMatrix();
	glTranslatef(-.43, .68, 0);
	glScalef(.5, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*.................*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();//Light end
	/*.................*/
	//Left shoulder armor end

	glPushMatrix();//clip light
	glEnable(GL_LIGHTING);
	SetDiffuse(.7, .7, .7);
	SetAmbient(.7, .7, .7);
	SetShininess(100);
	SetSpecuilar(.5, .5, .5);
	//Left shoulder armor clip 1 start
	/*............................*/
	glPushMatrix();
	glTranslatef(.1, .1, .2);
	glScalef(1, 1, .2);
	/*.................*/
	glPushMatrix();
	glTranslatef(0, .35, 0);
	glScalef(.2, .3, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*.................*/
	glPushMatrix();
	glTranslatef(-.33, .68, 0);
	glScalef(.3, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*.................*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*.................*/
	glPopMatrix();
	/*...........................*/
	//Left shoulder armor clip 1 end

	glColor3ub(171, 131, 94);
	//Left shoulder armor clip 1 start
	/*............................*/
	glPushMatrix();
	glTranslatef(.1, .1, -.2);
	glScalef(1, 1, .2);
	/*...............*/
	glPushMatrix();
	glTranslatef(0, .35, 0);
	glScalef(.2, .3, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*...............*/
	glPushMatrix();
	glTranslatef(-.33, .68, 0);
	glScalef(.3, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*...............*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*...............*/
	glPopMatrix();
	//Left shoulder armor clip 1 end
	/*............................*/
	glDisable(GL_LIGHTING);
	glPopMatrix();//clip light end

	glPopMatrix();
	/*...............................................*/
	//left shoulder end
	/*........................................................................................*/


}
void DrawRightShoulder()
{
	/*........................................................................................*/


	//right shoulder start
	/*....................................................*/
	glPushMatrix();
	glTranslatef(-2, -1, 0);
	glRotatef(180, 0, 1, 0);
	//right shoulder armor start
	/*............*/
	glColor3ub(243, 231, 189);
	glPushMatrix();
	glScalef(.2, 1, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(-.43, .68, 0);
	glScalef(.5, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	//right shoulder armor end


	glPushMatrix();//Lighting
	glEnable(GL_LIGHTING);
	SetDiffuse(.7,.7,.7);
	SetAmbient(.7, .7, .7);
	SetShininess(100);
	SetSpecuilar(.5,.5,.5);
	//right shoulder armor clip 1 start
	/*.........................*/
	glPushMatrix();
	glTranslatef(.1, .1, .2);
	glScalef(1, 1, .2);
	/*............*/
	glPushMatrix();
	glTranslatef(0, .35, 0);
	glScalef(.2, .3, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(-.33, .68, 0);
	glScalef(.3, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPopMatrix();
	/*.........................*/
	//right shoulder armor clip 1 end


	glColor3ub(171, 131, 94);
	//right shoulder armor clip 1 start
	/*.........................*/
	glPushMatrix();
	glTranslatef(.1, .1, -.2);
	glScalef(1, 1, .2);
	/*..............*/
	glPushMatrix();
	glTranslatef(0, .35, 0);
	glScalef(.2, .3, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*..............*/
	glPushMatrix();
	glTranslatef(-.33, .68, 0);
	glScalef(.3, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*..............*/
	glPushMatrix();
	glTranslatef(-.11, .57, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(.4, .2, 1);
	glutSolidCube(1);
	glPopMatrix();
	/*..............*/
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glPopMatrix();
	/*.........................*/
	//right shoulder armor clip 1 end
	glPopMatrix();
	/*....................................................*/
	//right shoulder end
	/*........................................................................................*/
}

void drawHeroHead()
{

	/*........................................................................................*/


	//Head outward start
	glPushMatrix();//Light matrix push
	glEnable(GL_LIGHTING);
	SetDiffuse(1,.9,.8);
	SetAmbient(1, .9, .8);

	/*............*/
	glPushMatrix();
	glScalef(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glScalef(1, 1, 2);
	glTranslatef(0, .2, -.1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(0, .49, .79);
	glRotatef(45, 1, 0, 0);
	glScalef(1, .3, .3);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	//Head outward end
	glDisable(GL_LIGHTING);
	glPopMatrix(); //light matrix pop



	glPushMatrix();//Light matrix push
	glEnable(GL_LIGHTING);
	SetDiffuse(.3, .3, .3);
	SetAmbient(.3, .3, .3);
	//Head inner start
	/*...........................*/
	glPushMatrix();
	glTranslatef(0, .1, .25);
	glScalef(.7, 1, .8);
	/*............*/
	glPushMatrix();
	glScalef(1, 1, 2);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glScalef(1, 1, 2);
	glTranslatef(0, .2, -.1);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPushMatrix();
	glTranslatef(0, .49, .79);
	glRotatef(45, 1, 0, 0);
	glScalef(1, .3, .3);
	glutSolidCube(1);
	glPopMatrix();
	/*............*/
	glPopMatrix();
	/*...........................*/
	//Head inner end
	glDisable(GL_LIGHTING);
	glPopMatrix(); //light matrix pop


	glPushMatrix();
	glEnable(GL_LIGHTING); //Light enable
	//SetLightPosition(0, 0, 2);
	SetDiffuse(0, 1, 1);
	SetAmbient(0, 1, 1);
	//SetEmision(0, .7, .7);
	//Head core start
	/*............*/
	glPushMatrix();
	glTranslatef(0, .1, .95);
	glScalef(.3, .7, .3);
	glutSolidCube(1);
	/*............*/
	glPopMatrix();
	//Head core end
	glDisable(GL_LIGHTING);//Light dissable
	glPopMatrix();

	/*........................................................................................*/


}

void drawChest()
{
	glPushMatrix();//Chest final push

	glPushMatrix();//Front body final push mat
	glTranslatef(0,0,.5);


	glPushMatrix(); //body ligting push
	glEnable(GL_LIGHTING); //Light enable
	SetDiffuse(1, .9, .8);
	SetAmbient(1, .9, .8);
	SetSpecuilar(.2,.2,.2);
	SetShininess(80);

	glPushMatrix();
	glScalef(4, 3, 3);
	//Chest Upper Part Start
	glPushMatrix();
	glScalef(.80, 1, 1);
	glTranslatef(0, -.1, 0);
	glPushMatrix();
	glScalef(.6, 1, 1);
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glScalef(1, .1, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .30, -.45);
	glScalef(1, .5, .1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .3, .05);
	glPushMatrix();
	glScalef(1, 1.2, 1);
	glRotatef(-65, 1, 0, 0);
	glBegin(GL_QUADS); //GL_LINE_LOOP
	glVertex3f(-.5, -.5, 0);
	glVertex3f(.5, -.5, 0);
	glVertex3f(.5, .5, 0);
	glVertex3f(-.5, .5, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//glScalef(1.1,1.1,1.1);
	glTranslatef(.5, .0479, -.4);
	glScalef(1.2, 1.01, 1.01);
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_TRIANGLES); //GL_LINE_LOOP
	glVertex3f(0, 0, 0);
	glVertex3f(.9, 0, 0);
	glVertex3f(0, .5, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, .0499, -.4);
	glScalef(1.2, 1.01, 1.01);
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_TRIANGLES);//GL_LINE_LOOP
	glVertex3f(0, 0, 0);
	glVertex3f(.9, 0, 0);
	glVertex3f(0, .5, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Chest Upper Part End

	glColor3ub(243, 231, 183);
	//Chest Lower Part Start
	glPushMatrix();
	//Horizontal Part
	glTranslatef(0, -.2, 0);
	glScalef(.8, 1, 1);
	glPushMatrix();
	glScalef(1, .1, 1);
	glutSolidCube(1);
	glPopMatrix();
	//Verticle Part
	glPushMatrix();
	glTranslatef(0, .30, -.45);
	glScalef(1, .5, .1);
	glutSolidCube(1);
	glPopMatrix();


	//Upper sheild
	glPushMatrix();
	glTranslatef(0, .3, .05);
	glPushMatrix();
	glScalef(1, 1.2, 1);
	glRotatef(-65, 1, 0, 0);
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
	glTranslatef(.5, .0459, -.4);
	glScalef(1, 1.02, 1.01);
	glRotatef(-90, 0, 1, 0);
	glColor3ub(243, 231, 183);

	glPushMatrix();
	glBegin(GL_TRIANGLES); //GL_LINE_LOOP
	glVertex3f(0, 0, 0);
	glVertex3f(.9, 0, 0);
	glVertex3f(0, .5, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, .0459, -.4);
	glScalef(1, 1.02, 1.01);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glBegin(GL_TRIANGLES);//GL_TRIANGLES
	glVertex3f(0, 0, 0);
	glVertex3f(.9, 0, 0);
	glVertex3f(0, .5, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	//Chest Lower Part End

	//Lower Sheet Start
	glTranslatef(0, -.35, 0);
	glScalef(.8, 2, 1);
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glScalef(1, .1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//Lower Sheet End


	//Front armor front part
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(0, -.85, 1.6);
	glScalef(1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(.6, -.75, 1.6);
	glScalef(.2, 1.2, .2);
	glutSolidCube(1);
	glPopMatrix();


	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(-.6, -.75, 1.6);
	glScalef(.2, 1.2, .2);
	glutSolidCube(1);
	glPopMatrix();
	//Front armor front part

	//Front armor lower part
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(0, -1.45, 1.4);
	glScalef(1.4, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	//Front armor lower end

	glDisable(GL_LIGHTING);
	glPopMatrix();//body lighting pop

	glPushMatrix();
	glEnable(GL_LIGHTING);
	//SetLightPosition(0,0,5);
	SetDiffuse(0, 1, 1);
	SetAmbient(0, 1, 1);
	//Front core
	glColor3ub(100, 200, 200);
	glPushMatrix();
	glTranslatef(0, -0.25, 1.4);
	glScalef(1, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glPopMatrix();
	//Front core end
	glPopMatrix();//Front body final pop mat


	glPushMatrix(); //body ligting push
	glEnable(GL_LIGHTING); //Light enable
	//SetLightPosition(0, 3, 5);
	SetDiffuse(1, .9, .8);
	SetAmbient(1, .9, .8);
	SetSpecuilar(.2, .2, .2);
	SetShininess(80);

	//Shoulder clip 1 start
	glPushMatrix();
	glTranslatef(-1.3,1.1,-1.7);
	glScalef(.6,.2,2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 1 end

	//Shoulder Clip 2 start
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(1.3, 1.1, -1.7);
	glScalef(.6, .2, 2);
	glutSolidCube(1);
	glPopMatrix();
	//SHoulder clip 2 end

	//Shoulder clip 3 part start
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(1.3, -.2, -1.7);
	glScalef(.5, 2.4, 2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 3 part end

	//Shoulder clip 4 part start
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(-1.3, -.2, -1.7);
	glScalef(.5, 2.4, 2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 4 part end

	//Shoulder clip 5 part start
	glColor3ub(243, 231, 183);
	glPushMatrix();
	glTranslatef(0, -.2, -2.6);
	glScalef(2.2, 2.4, .2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 5 part start

	glDisable(GL_LIGHTING);
	glPopMatrix();//Lighting end

	glPopMatrix();//chest final pop
}

void drawHeroLeftHand()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//Hero left hand final push
	glTranslatef(0,-3,0);
	glRotatef(90,1,0,0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix(); //final push for wrist
	glTranslatef(1, .25, 0);
	glRotatef(10, 0, 0, 1);

	glPushMatrix();
	glScalef(1.2,1.2,.8);

	glColor3ub(100, 200, 72);
	glPushMatrix();
	glTranslatef(-.6,0,0);		
	glutSolidCube(1);
	glPopMatrix();
	
	glColor3ub(100, 200, 72);
	glPushMatrix();
	glTranslatef(.6, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	


	glColor3ub(150, 150, 150);
	glPushMatrix();
	glTranslatef(-.6,0,.5);
	glScalef(.15, .15, .15);
	glutSolidTorus(1,1,6,6);
	glPopMatrix();


	glColor3ub(150, 150, 150);
	glPushMatrix();
	glTranslatef(-.6, 0, -.5);
	glScalef(.15, .15, .15);
	glutSolidTorus(1, 1, 6, 6);
	glPopMatrix();

	glPopMatrix();



	//cylinder
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), .3, .3, 3, 20, 20);
	glPopMatrix();

	//wracking ball
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glTranslatef(2.5,0,0);
	glutSolidSphere(1,20,20);
	glPopMatrix();

	glPopMatrix();//final pop for wrist



	//left hand up start

	glPushMatrix(); //final push

	glTranslatef(-1.5, 0, 0);
	glScalef(1.5, 1.5, 1.5);
	
	//Middle part
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();
	//middle part end


	//side part 1
	glColor3ub(50, 200, 50);
	glPushMatrix();
	glTranslatef(0, 0, -.29);
	glScalef(1.1, 1.1, .5);


	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	//side part 1 end

	//side part 2
	glColor3ub(50, 200, 50);
	glPushMatrix();
	glTranslatef(0, 0, .29);
	glScalef(1.1, 1.1, .5);


	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	//side part 2 end

	//cylinder
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glTranslatef(-1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, .25, .25, 1, 20, 20);
	glPopMatrix();


	glPopMatrix();//final pop
	//left hand up end

	//up and down attach start
	glPushMatrix();
	glScalef(1.5,.8,.4);
	glutSolidCube(1);
	glPopMatrix();
	//up and down attach start

	glPopMatrix();//hero Left hand final pop


}

void drawHandAndBodyAttacher()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//hand body attacher final push
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.6, .6, .6);
	SetAmbient(.6, .6, .6);
	glTranslatef(0,0,-5);
	glScalef(1,1,8);
	gluCylinder(quadratic, 1.2, 1.2, 1, 20, 20);
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.6, .6, .6);
	SetAmbient(.6, .6, .6);
	glScalef(1, 1, 3);
	glutSolidTorus(.5, 2, 3, 8);
	glDisable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix(); //head body attacher final pop
}

void DrawGun()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//gun final push
	//main nosel start
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(quadratic, .1, .1, 2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//main nosel end
	
	//main nosel circle  start
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//main nosel circle  start

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5,1,1);
	glutSolidSphere(.2,20,20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end
	
	//2nd nosel start
	glPushMatrix();
	glTranslatef(-1,0,0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(quadratic, .2, .2, 2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//2nd nosel end

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(1, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	//Upper part cube start
	glPushMatrix();
	glTranslatef(-.25, .3, 0);
	glPushMatrix();
	glScalef(1.5, .4, .3);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//Upper part cube end

	//lower part cube start
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.3, .3, .3);
	SetAmbient(.4, .4, .4);
	glTranslatef(0, -.3, 0);
	glPushMatrix();
	glScalef(2, .4, .3);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glPopMatrix();
	//lower part cube end

	//ammo cube start
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.3, .3, .3);
	SetAmbient(.4, .4, .4);
	glTranslatef(-.6, -.65, 0);
	glRotatef(60, 0, 0, 1);
	glPushMatrix();
	glScalef(.7, .4, .2);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glPopMatrix();
	//ammo cube end

	glPushMatrix();//light push
	glEnable(GL_LIGHTING);
	SetDiffuse(.5, .5, .5);
	SetAmbient(.5, .5, .5);
	//attach clip 1 cube start
	glPushMatrix();
	glTranslatef(-1, -.35, .15);
	glPushMatrix();
	glScalef(.7, .3, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 1 cube end

	//attach clip 2 cube start
	glPushMatrix();
	glTranslatef(-1, -.35, -.15);
	glPushMatrix();
	glScalef(.7, .3, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 2 cube end


	//attach clip 3 cube start
	glPushMatrix();
	glTranslatef(-1.35, -.31, .25);
	glRotatef(45, 0, 0, 1);
	glPushMatrix();
	glScalef(.3, .3, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 3 cube end

	//attach clip 4 cube start
	glPushMatrix();
	glTranslatef(-1.35, -.31, -.25);
	glRotatef(45, 0, 0, 1);
	glPushMatrix();
	glScalef(.3, .3, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 4 cube end

	//attach clip 5 cube start
	glPushMatrix();
	glTranslatef(-1.41, -.08, .25);
	glPushMatrix();
	glScalef(.3, .5, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 5 cube end

	//attach clip 6 cube start
	glPushMatrix();
	glTranslatef(-1.41, -.08, -.25);
	glPushMatrix();
	glScalef(.3, .5, .1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 6 cube end

	//attach clip 7 cube start
	glPushMatrix();
	glTranslatef(-1.41, 0.20, 0);
	glPushMatrix();
	glScalef(.3, .1, .6);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//attach clip 7 cube end
	glDisable(GL_LIGHTING);
	glPopMatrix();//Light pop


	glPopMatrix();//gun final pop
}
void RightHandAttacher()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//Hero left hand final push
				   //glTranslatef(0, -3, 0);
				   //glRotatef(90, 1, 0, 0);
				   //glRotatef(-90, 0, 1, 0);


				   //left hand up start

	glPushMatrix(); //final push

	glTranslatef(-1.5, 0, 0);
	glScalef(1.5, 1.5, 1.5);

	//Middle part
	glColor3ub(100, 100, 100);
	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();
	//middle part end


	glPushMatrix();//Light push
	glEnable(GL_LIGHTING);
	SetDiffuse(1, 1, 1);
	SetAmbient(1, 1, 1);

	//side part 1
	glColor3ub(50, 200, 50);
	glPushMatrix();
	glTranslatef(0, 0, -.29);
	glScalef(1.1, 1.1, .5);


	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	//side part 1 end

	//side part 2
	glColor3ub(50, 200, 50);
	glPushMatrix();
	glTranslatef(0, 0, .29);
	glScalef(1.1, 1.1, .5);


	glPushMatrix();
	glScalef(1, 1, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.58, 0, 0);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, .22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-.5, -.22, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(.4, .4, .4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_LIGHTING);
	glPopMatrix();
	//side part 2 end

	//cylinder
	
	glPushMatrix();
	
	glTranslatef(-1.2, 0, 0);
	glEnable(GL_LIGHTING);
	SetDiffuse(.5, .5, .5);
	SetAmbient(.5, .5, .5);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, .25, .25, 1, 20, 20);
	glDisable(GL_LIGHTING);
	glPopMatrix();


	glPopMatrix();//final pop
				  //left hand up end

				  //up and down attach start
	glPushMatrix();
	glEnable(GL_LIGHTING);
	SetDiffuse(.5, .5, .5);
	SetAmbient(.5, .5, .5);
	glScalef(1.5, .8, .4);
	glutSolidCube(1);
	glDisable(GL_LIGHTING);
	glPopMatrix();
	//up and down attach start

	glPopMatrix();//hero Left hand final pop
}
void DrawRightHand()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//final push
	glTranslatef(0,-3,0);
	glRotatef(90,1,0,0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glTranslatef(2.8,.22,0);
	glScalef(1.5,1.5,1.5);
	DrawGun();
	glPopMatrix();



	glPushMatrix(); //gun attacher final push
	glTranslatef(.7,0,0);
	glRotatef(90,0,1,0);
	glScalef(.5,.25,.25);
	//screw 1
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90,0,1,0);
	glutSolidTorus(.5,.5,6,6);
	glPopMatrix();

	//screw attacher
	 glPushMatrix();
	 glScalef(1.5,2,2);
	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	//2nd nosel start
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	gluCylinder(quadratic, .2, .2, 2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//2nd nosel end

	//circle for 2nd nosel start
	glPushMatrix();
	glTranslatef(1, 0, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glScalef(.5, 1, 1);
	glutSolidSphere(.2, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//circle for 2nd nosel end

	glPopMatrix();
	//screw attacher end
	

	//screw 2
	glPushMatrix();
	glTranslatef(1,0,0);
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.5, .5, 6, 6);
	glPopMatrix();

	glPopMatrix(); //gun attacher final pop

	glPushMatrix();
	RightHandAttacher();
	glPopMatrix();

	glPopMatrix();//final pop
	
}