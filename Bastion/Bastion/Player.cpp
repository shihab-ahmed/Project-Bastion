#include "Globals.h"
#include "Player.h"
#include "CollisionDetection.h"
#define PI 3.141592654
using namespace std;
Player::Player(float positionX, float positionZ, float initialRotation)
{
	this->Beltangle = 0;
	this->speed = 0.0f;
	this->posX = positionX;
	this->posZ = positionZ;
	this->rotation = initialRotation;
	this->rotationSpeed = 0.0f;
	this->width = 2;
	this->height = 2;
	this->depth = 2;
	this->turretRotation = 0.0f;
	this->turretRotationSpeed = 0.0f;
	this->health = 3;
	this->reloadTime = 30;
	this->reloadCounter = this->reloadTime;
	this->canSeePlayer = false;
	this->sightRange = 23.0f;
	this->sightCounter = 0;
	this->isAimed = false;
	this->destinX = positionX;
	this->destinZ = positionZ;
	this->atDestination = true;
	this->recoilStrength = 0.7f;
	this->recoilDistance = 0.0f;
	this->curRecoilForce = 0.0f;
	this->lastSightingX = positionX;
	this->lastSightingZ = positionZ;
	this->boostSpeed = 0;
	this->boostPower = 0.02f;
	this->shieldStrength = 0;
	this->shieldOpacity = 0.0f;
}


int Player::BeltRotation()
{
	this->Beltangle += 1.0f;
	if (this->Beltangle > 360)
	{
		this->Beltangle -= 360;
	}
	this->Beltangle += 1.0f;
	if (this->Beltangle > 360)
	{
		this->Beltangle -= 360;
	}
	return this->Beltangle;
}

void drawHeadBodyAttacher()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix(); //Final push
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
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
	//Left shoulder armor start

	glPushMatrix();// light start

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
	glPopMatrix(); //light matrix pop



	glPushMatrix();//Light matrix push

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
	glPopMatrix(); //light matrix pop


	glPushMatrix();

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
	glPopMatrix();

	/*........................................................................................*/


}

void drawChest()
{
	glPushMatrix();//Chest final push

	glPushMatrix();//Front body final push mat
	glTranslatef(0, 0, .5);


	glPushMatrix(); //body ligting push
	glPushMatrix();
	glScalef(4, 3, 3);
	//Chest Upper Part Start
	glPushMatrix();
	glScalef(.80, 1, 1);
	glTranslatef(0, -.1, 0);
	glPushMatrix();
	glScalef(.6, 1, 1);

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
	
	glPushMatrix();
	glScalef(1, .1, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//Lower Sheet End


	//Front armor front part
	
	glPushMatrix();
	glTranslatef(0, -.85, 1.6);
	glScalef(1, 1, .2);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(.6, -.75, 1.6);
	glScalef(.2, 1.2, .2);
	glutSolidCube(1);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-.6, -.75, 1.6);
	glScalef(.2, 1.2, .2);
	glutSolidCube(1);
	glPopMatrix();
	//Front armor front part

	//Front armor lower part
	
	glPushMatrix();
	glTranslatef(0, -1.45, 1.4);
	glScalef(1.4, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	//Front armor lower end
	glPopMatrix();//body lighting pop

	glPushMatrix();
	//Front core
	
	glPushMatrix();
	glTranslatef(0, -0.25, 1.4);
	glScalef(1, .2, .6);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//Front core end
	glPopMatrix();//Front body final pop mat


	glPushMatrix(); //body ligting push

	//Shoulder clip 1 start
	glPushMatrix();
	glTranslatef(-1.3, 1.1, -1.7);
	glScalef(.6, .2, 2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 1 end

	//Shoulder Clip 2 start
	
	glPushMatrix();
	glTranslatef(1.3, 1.1, -1.7);
	glScalef(.6, .2, 2);
	glutSolidCube(1);
	glPopMatrix();
	//SHoulder clip 2 end

	//Shoulder clip 3 part start
	
	glPushMatrix();
	glTranslatef(1.3, -.2, -1.7);
	glScalef(.5, 2.4, 2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 3 part end

	//Shoulder clip 4 part start
	
	glPushMatrix();
	glTranslatef(-1.3, -.2, -1.7);
	glScalef(.5, 2.4, 2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 4 part end

	//Shoulder clip 5 part start
	
	glPushMatrix();
	glTranslatef(0, -.2, -2.6);
	glScalef(2.2, 2.4, .2);
	glutSolidCube(1);
	glPopMatrix();
	//Shoulder clip 5 part start
	glPopMatrix();//Lighting end

	glPopMatrix();//chest final pop
}

void drawHeroLeftHand()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//Hero left hand final push
	glTranslatef(0, -3, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix(); //final push for wrist
	glTranslatef(1, 1, 0);
	glRotatef(90, 0, 0, 1);

	glPushMatrix();
	glScalef(1.2, 1.2, .8);

	
	glPushMatrix();
	glTranslatef(-.6, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(.6, 0, 0);
	glutSolidCube(1);
	glPopMatrix();






	glPushMatrix();
	glTranslatef(-.6, 0, .5);
	glScalef(.15, .15, .15);
	glutSolidTorus(1, 1, 6, 6);
	glPopMatrix();


	
	glPushMatrix();
	glTranslatef(-.6, 0, -.5);
	glScalef(.15, .15, .15);
	glutSolidTorus(1, 1, 6, 6);
	glPopMatrix();

	glPopMatrix();



	//cylinder
	
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), .3, .3, 3, 20, 20);
	glPopMatrix();

	//wracking ball
	
	glPushMatrix();
	glTranslatef(2.5, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPopMatrix();//final pop for wrist

	glPushMatrix(); //final push

	glTranslatef(-1.5, 0, 0);
	glScalef(1.5, 1.5, 1.5);

	//Middle part

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
	
	glPushMatrix();
	glTranslatef(-1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, .25, .25, 1, 20, 20);
	glPopMatrix();


	glPopMatrix();

				  //up and down attach start
	glPushMatrix();
	glScalef(1.5, .8, .4);
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
	glTranslatef(0, 0, -5);
	glScalef(1, 1, 8);
	gluCylinder(quadratic, 1.2, 1.2, 1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1, 3);
	glutSolidTorus(.5, 2, 3, 8);
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
	glTranslatef(0, -.3, 0);
	glPushMatrix();
	glScalef(2, .4, .3);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//lower part cube end

	//ammo cube start
	glPushMatrix();
	glTranslatef(-.6, -.65, 0);
	glRotatef(60, 0, 0, 1);
	glPushMatrix();
	glScalef(.7, .4, .2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	//ammo cube end

	glPushMatrix();//light push
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
	//side part 1
	
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
	glPopMatrix();
	//side part 2 end

	//cylinder

	glPushMatrix();

	glTranslatef(-1.2, 0, 0);
	glRotatef(90, 0, 1, 0);
	gluCylinder(quadratic, .25, .25, 1, 20, 20);
	glPopMatrix();


	glPopMatrix();//final pop
				  //left hand up end

				  //up and down attach start
	glPushMatrix();
	glScalef(1.5, .8, .4);
	glutSolidCube(1);
	glPopMatrix();
	//up and down attach start

	glPopMatrix();//hero Left hand final pop
}
void DrawRightHand()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();//final push
	glTranslatef(0, -3, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glTranslatef(.5, 2.7, 0);
	glRotatef(90,0,0,1);
	glScalef(1.5, 1.5, 1.5);
	DrawGun();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5,.2,0);
	glScaled(.6,1.2,.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix(); //gun attacher final push
	glTranslatef(.5, .5, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(.5, .20, .20);
	//screw 1
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.5, .5, 6, 6);
	glPopMatrix();

	//screw attacher
	glPushMatrix();
	glScalef(1.5, 2, 2);
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
	glTranslatef(1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glutSolidTorus(.5, .5, 6, 6);
	glPopMatrix();

	glPopMatrix(); //gun attacher final pop

	glPushMatrix();
	RightHandAttacher();
	glPopMatrix();

	glPopMatrix();//final pop

}
void Player::DrawHeroMiddleBody()
{
	glPushMatrix();//middle body final push
	glPushMatrix();
	glTranslatef(0, -.3, 0);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .5, .5, 1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .2, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(this->BeltRotation(),0,0,1);
	glPushMatrix();
	glScalef(.35, .35, .6);
	glutSolidTorus(.5, 1.5, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glScalef(.2, 1.5, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(.2, 1.5, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 0, 1);
	glScalef(.2, 1.5, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 0, 1);
	glScalef(.2, 1.5, .2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -.65, 0);
	glScalef(1.2, .8, 1.8);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();//middle body final pop
}

void drawFoot()
{
	//feet start
	glPushMatrix();//final push
				   //left foot part left start
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
	glPopMatrix();//final pop
				  //foot end
}

void DrawLagPad()
{

	//Lag pad start
	glPushMatrix();//final push 
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

	glPopMatrix();//final pop
				  //Lag pad end
}

void DrawLeftLegSkeleton()
{
	glPushMatrix(); //light push

	glPushMatrix();//Join 1 push final
	glRotatef(90, 0, 1, 0);
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
	glScalef(3.5, .5, 1.1);
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
	glTranslatef(-3, 0, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(1.2, 1.2, 1.2);
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
	glPopMatrix();
}

void DrawLeftLeg()
{

	glPushMatrix();//Left leg final push
	glTranslatef(0, -3, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-1.4, 1, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(20, 0, 0, 1.5);
	glScalef(1, 2.2, 1.3);
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

void Player::damage(int amount) {
	this->health -= amount;
}
bool Player::isHitBy(PlazmaBall* theBullet) {
	float x = theBullet->givePosX() - this->givePosX();
	float z = theBullet->givePosZ() - this->givePosZ();
	return x*x + z*z < (this->width * 1)*(this->width * 1);
}
float Player::playerLegRotation()
{
	
	if (this->isWalking)
	{
		//cout << "walkng" << endl;
		if (this->legRotationMaxReached)
		{
			this->legRotation -= 1.5f;
			if (this->legRotation <- 15)
			{
				this->legRotationMaxReached = false;
			}
		}
		else
		{
			this->legRotation += 1.5f;
			if (this->legRotation >15)
			{
				this->legRotationMaxReached = true;
			}
		}
		
	}
	else
	{
		//cout << "not walkng" << endl;
		this->legRotation = 0;
	}
	return this->legRotation;
}
void Player::WalkingState(bool isWalk)
{
	this->isWalking = isWalk;

}
void Player::accelerate(bool directionIsForward)
{
	
	if (directionIsForward) {
		this->speed += 0.04;
		
	}
	else {
		this->speed -= 0.04;
	}
}
float Player::givePosX() {
	return this->posX;
}

float Player::givePosZ() {
	return this->posZ;
}
void Player::rotate(bool directionIsPositive) 
{
	this->rotationSpeed *= 0.01f;
	if (directionIsPositive) {
		this->rotationSpeed += 3.5;
	}
	else {
		this->rotationSpeed -= 3.5;
	}
	if (this->boostSpeed > 0.02f) {
		this->rotationSpeed /= (this->boostSpeed)*100.0f;
	}
}
void Player::move() 
{
	this->speedX = -(this->speed) * sin(this->rotation * PI / 180);
	this->speedZ = -(this->speed) * cos(this->rotation * PI / 180);

	if (this->canMoveTo(this->posX + this->speedX, this->posZ)) {
		this->posX += this->speedX;
	}
	else {
		this->speedX *= 0.5f;
	}
	if (this->canMoveTo(this->posX, this->posZ + this->speedZ)) {
		this->posZ += this->speedZ;
	}
	else {
		this->speedZ *= 0.5f;
	}

	this->rotation += this->rotationSpeed;
	this->turretRotation -= this->rotationSpeed;
	this->turretRotation += this->turretRotationSpeed;
	this->turretRotationSpeed *= 0.5f;
	this->rotationSpeed *= 0.5f;
	this->speed *= 0.8f;
	this->boostSpeed *= 0.8f;

	if (this->rotation > 360.0f) {
		this->rotation -= 360.0f;
	}
	else if (this->rotation < -360.0f) {
		this->rotation += 360.0f;
	}
	if (this->turretRotation > 360.0f) {
		this->turretRotation -= 360.0f;
	}
	else if (this->turretRotation < -360.0f) {
		this->turretRotation += 360.0f;
	}
	this->reloadCounter -= 1;

	this->recoilDistance += this->curRecoilForce;
	this->curRecoilForce *= 0.5f;
	this->recoilDistance *= 0.8f;
	this->shieldOpacity *= 0.95f;
}
float Player::giveSpeed()
{
	return this->speed;
}
float Player::giveTurretRotation() {
	return this->turretRotation;
}

float Player::giveTurretRotationSpeed() {
	return this->turretRotationSpeed;
}
float Player::giveSpeedX() {
	return this->speedX;
}

float Player::giveSpeedZ() {
	return this->speedZ;
}

float Player::giveRotation() {
	return this->rotation;
}

float Player::giveRotationSpeed() {
	return this->rotationSpeed;
}
float Player::playerWidth() {
	return width;
}
float Player::PlayerHeight() {
	return height;
}
float Player::PlayerDepth() {
	return depth;
}
void Player::rotateTurret(float amount) 
{
	this->turretRotationSpeed += amount;
	if (this->turretRotation > 180) {
		this->turretRotation -= 360;
	}
	else if (this->turretRotation < -180) {
		this->turretRotation += 360;
	}
}
bool Player::fire() {
	if (this->reloadCounter <= 0) {
		float angle = this->rotation + this->turretRotation;
		plazmaBalls.push_back(new PlazmaBall(this->posX - 1.0*sin(angle * PI / 180),
			0.65f,
			this->posZ - 1.0*cos(angle * PI / 180), this->speedX, this->speedZ,
			angle,1
		));
		this->reloadCounter = this->reloadTime;
		this->curRecoilForce += this->recoilStrength;
		return true;
	}
	return false;
}
bool Player::canMoveTo(float newX, float newZ)
{
	
	if (newX > mapSize - 1.0f || newX < -mapSize + 1.0f || newZ > mapSize - 1.0f || newZ < -mapSize + 1.0f) {
	
		return false;
	}
	if (isClipped(newX+this->speedX, newZ+this->speedZ))
	{
		return false;
	}
	return true;
}
void Player::DrawPlayer()
{
	glPushMatrix(); //Draw player control push matrix

	glTranslatef(this->posX, 0.0f, this->posZ);
	glRotatef(this->rotation, 0.0f, 1.0f, 0.0f);
	glScalef(width,height,depth);

	//cout << "PosX:" << posX << "\tPosY:" << height << "\tPosZ:" << posZ;
	glPushMatrix(); //whole body push
	glRotatef(180,0,1,0);
	glScalef(0.15,0.15,0.15);

	glPushMatrix(); //Player Top matrix
	glRotatef(this->turretRotation, 0.0f, 1.0f, 0.0f);

	glPushMatrix();//head push
	glTranslatef(0, 3.1, 0);
	glScalef(.6, .6, .6);
	drawHeroHead();
	glPopMatrix();//head pop

	glPushMatrix();//head body attacher push
	glTranslatef(0, 3, -.2);
	glScalef(.5, .5, .5);
	drawHeadBodyAttacher();
	glPopMatrix();//head body attacher pop


	glPushMatrix();//body push
	glTranslatef(0, 2, .8);
	glScalef(.7, .5, .5);
	drawChest();
	glPopMatrix();//body pop


	glPushMatrix();//Right Shoulder push
	glTranslatef(.2, 3.2, -.2);
	glScalef(1.2, 1.2, 1.2);
	DrawRightShoulder();
	glPopMatrix();//Right Shoulder pop

	glPushMatrix();//Left Shoulder push
	glTranslatef(-.2, 3.2, -.2);
	glScalef(1.2, 1.2, 1.2);
	DrawLeftShoulder();
	glPopMatrix();//Left Shoulder pop


	glPushMatrix();//Right hand and body attacher push
	glTranslatef(-1.8, 2.3, -.2);
	glRotatef(180, 0, 1, 0);
	//glRotatef(LeftHandRotation, 1, 0, 0);
	glScalef(.15, .15, .15);
	drawHandAndBodyAttacher();
	glPopMatrix();//Right hand and body attacher push

	glPushMatrix();//Left hand and body attacher push
	glTranslatef(1.8, 2, -.2);
	glScalef(.5, .5, .5);
	drawHeroLeftHand();
	glPopMatrix();//Left hand and body attacher push

	glPushMatrix();//Left hand and body attacher push
	glTranslatef(1.8, 2.3, -.2);
	//glRotatef(LeftHandRotation, 1, 0, 0);
	glScalef(.15, .15, .15);
	drawHandAndBodyAttacher();
	glPopMatrix();//Left hand and body attacher push

	glPushMatrix();//Right Hand
	glTranslatef(-1.8, 2, -.2);
	//glRotatef(-LeftHandRotation, 1, 0, 0);
	glScalef(.5, .5, .5);
	DrawRightHand();
	glPopMatrix();//Right Hand
	
	glPopMatrix();//hero top Pop Matrix

	glPushMatrix(); //hero bottom matrix

	//cout << "Rotation"<<rotation<<endl;

	glPushMatrix();//Right hand and body attacher push
	glTranslatef(0, 0.8, 0);
	glScalef(1, 1, 1);
	DrawHeroMiddleBody();
	glPopMatrix();//Right hand and body attacher push

	glPushMatrix();//Left Leg attacher push
	glTranslatef(1, .2, -.2);
	glRotatef(this->playerLegRotation(),1,0,0);
	glScalef(.5, .5, .5);
	DrawLeftLeg();
	glPopMatrix();//Left Leg attacher pop

	glPushMatrix();//right Leg attacher push
	glTranslatef(-1, .2, -.2);
	glRotatef(-(this->playerLegRotation()), 1, 0, 0);
	glScalef(.5, .5, .5);
	DrawLeftLeg();
	glPopMatrix();//right Leg attacher pop

	glPopMatrix(); //hero Bottom pop

	glPopMatrix();//whole body pop

	glPopMatrix();//Draw player control push matrix

}
Player::~Player()
{
}
