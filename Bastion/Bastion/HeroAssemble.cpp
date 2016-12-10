#include <iostream>
#include <GL/glut.h>
#include "Hero.h"
#include "Utility.h"
#include "HeroMiddleBody.h"
#include "Controller.h"
using namespace std;
float LeftHandRotation = 0.0;
bool isLeftHandMaxReach = false;
void UpdateRotation()
{
	if (isLeftHandMaxReach)
	{
		LeftHandRotation -= 2.0f;
		if (LeftHandRotation < -20)
		{
			isLeftHandMaxReach = false;
		}
	}
	else
	{
		LeftHandRotation += 2.0f;
		if (LeftHandRotation > 20)
		{
			isLeftHandMaxReach = true;
		}
	}

}

void getHero()
{
	UpdateRotation();


	glPushMatrix(); //Final push

	getDirection();
	glPushMatrix();//head push
	glTranslatef(0,3.1,0);
	glScalef(.6, .6, .6);
	drawHeroHead();
	glPopMatrix();//head pop

	glPushMatrix();//head body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(0,3,-.2);
	glScalef(.5,.5,.5);
	drawHeadBodyAttacher();
	glDisable(GL_LIGHTING);
	glPopMatrix();//head body attacher pop

	glPushMatrix();//body push
	glEnable(GL_LIGHTING);
	glTranslatef(0,2,.8);
	glScalef(.7,.5,.5);
	drawChest();
	glDisable(GL_LIGHTING);
	glPopMatrix();//body pop


	glPushMatrix();//Right Shoulder push
	glEnable(GL_LIGHTING);
	glTranslatef(.2, 3.2, -.2);
	glScalef(1.2, 1.2, 1.2);
	DrawRightShoulder();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Right Shoulder pop

	glPushMatrix();//Left Shoulder push
	glEnable(GL_LIGHTING);
	glTranslatef(-.2, 3.2, -.2);
	glScalef(1.2, 1.2, 1.2);
	DrawLeftShoulder();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left Shoulder pop



	glPushMatrix();//Left hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(1.8, 2.3, -.2);
	glRotatef(LeftHandRotation, 1, 0, 0);
	glScalef(.15,.15,.15);
	drawHandAndBodyAttacher();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left hand and body attacher push

	glPushMatrix();//Left hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(1.8, 2, -.2);
	glRotatef(LeftHandRotation, 1, 0, 0);
	glScalef(.5, .5, .5);
	drawHeroLeftHand();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left hand and body attacher push




	glPushMatrix();//Right hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(-1.8, 2.3, -.2);
	glRotatef(180,0,1,0);
	glRotatef(LeftHandRotation, 1, 0, 0);
	glScalef(.15, .15, .15);
	drawHandAndBodyAttacher();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Right hand and body attacher push

	glPushMatrix();//Right hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(-1.8, 2, -.2);
	glRotatef(-LeftHandRotation, 1, 0, 0);
	glScalef(.5, .5, .5);
	DrawRightHand();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Right hand and body attacher push
	
	glPushMatrix();//Right hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(0, 0.8, 0);
	glScalef(1, 1, 1);
	DrawHeroMiddleBody();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Right hand and body attacher push


	glPushMatrix();//Left Leg attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(1, .2, -.2);
	if (StateWalking())
	{
		glRotatef(-LeftHandRotation, 1, 0, 0);
	}
	glScalef(.5, .5, .5);
	DrawLeftLeg();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left Leg attacher pop

	glPushMatrix();//Left Leg attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(-1, .2, -.2);
	if (StateWalking())
	{
		glRotatef(LeftHandRotation, 1, 0, 0);
	}
	glScalef(.5, .5, .5);
	DrawLeftLeg();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left Leg attacher pop


	glPopMatrix();//hero final pop

}