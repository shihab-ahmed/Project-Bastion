#include <GL/glut.h>
#include "Hero.h"
void getHero()
{
	glPushMatrix();//head push
	glTranslatef(0,1.1,-.8);
	glScalef(.6, .6, .6);
	drawHeroHead();
	glPopMatrix();//head pop

	glPushMatrix();//head body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(0,1,-1);
	glScalef(.5,.5,.5);
	drawHeadBodyAttacher();
	glDisable(GL_LIGHTING);
	glPopMatrix();//head body attacher pop

	glPushMatrix();//body push
	glEnable(GL_LIGHTING);
	glScalef(.6,.5,.5);
	drawChest();
	glDisable(GL_LIGHTING);
	glPopMatrix();//body pop

	glPushMatrix();//Right Shoulder push
	glEnable(GL_LIGHTING);
	glTranslatef(0, 1.2, -1);
	DrawRightShoulder();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Right Shoulder pop

	glPushMatrix();//Left Shoulder push
	glEnable(GL_LIGHTING);
	glTranslatef(0, 1.2, -1);
	DrawLeftShoulder();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left Shoulder pop


	glPushMatrix();//Left hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(1.5, .3, -1);
	glScalef(.15,.15,.15);
	drawHandAndBodyAttacher();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left hand and body attacher push

	glPushMatrix();//Left hand and body attacher push
	glEnable(GL_LIGHTING);
	glTranslatef(1.5, -1.5, -1);
	glScalef(.5, .5, .5);
	drawHeroLeftHand();
	glDisable(GL_LIGHTING);
	glPopMatrix();//Left hand and body attacher push
	
}