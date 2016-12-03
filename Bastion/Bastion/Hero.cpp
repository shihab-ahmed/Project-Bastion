#include <GL/glut.h>




void DrawLeftShoulder()
{

	/*........................................................................................*/

	//left shoulder start
	/*...............................................*/
	glPushMatrix();
	glTranslatef(2, -1, 0);
	glColor3ub(243, 231, 189);
	//Left shoulder armor start
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
	/*.................*/
	//Left shoulder armor end

	glColor3ub(171, 131, 94);
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



	glColor3ub(171, 131, 94);
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
	glColor3f(.8, .8, .7);
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



	//Head inner start
	glColor3f(.3, .3, .3);
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




	//Head core start
	glColor3f(0, 1, 1);
	/*............*/
	glPushMatrix();
	glTranslatef(0, .1, .95);
	glScalef(.3, .7, .3);
	glutSolidCube(1);
	/*............*/
	glPopMatrix();
	//Head core end


	/*........................................................................................*/


}

void drawChest()
{
	glPushMatrix();
	glScalef(4, 3, 3);
	//glTranslatef(0,-.7,.5);

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

	//Front core
	glColor3ub(100, 200, 200);
	glPushMatrix();
	glTranslatef(0, -0.25, 1.4);
	glScalef(1, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	//Front core end


}

void drawHeroLeftHand()
{
	glutWireCube(1);
}



