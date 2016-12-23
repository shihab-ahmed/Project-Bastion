#include "StatusUI.h"
#include "Globals.h"
using namespace std;

StatusUI::StatusUI()
{
}

void StatusUI::drawPlayerStatus(int health,int shield, int score)
{
	string healthString = to_string(health);
	string shieldString = to_string(shield);
	string scoreString =  to_string(score);

	glPushMatrix();
	lighting->LightEnable();
	//lighting->SetPosition(0,0,-9,1);
	lighting->SetDiffuse(.3,.3,.3,1);
	lighting->SetAmbient(.3,.3,.3, 1);
	lighting->SetEmmision(.2,.2,.2,1);

	glPushMatrix();
	glTranslatef(5, 2.5, -7.0f);
	glRotatef(-45,0,1,0);
	glScalef(.2, .2, .2);
	t3dDraw3D("Score", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 2.1, -7.0f);
	glRotatef(-45, 0, 1, 0);
	glScalef(.2, .2, .2);
	t3dDraw3D(scoreString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.1, 2.3, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.2, .2, .2);
	t3dDraw3D("Health", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.1, 1.9, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.2, .2, .2);
	t3dDraw3D(healthString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.1, 1.5, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.2, .2, .2);
	t3dDraw3D("Shield", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.1, 1.1, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.2, .2, .2);
	t3dDraw3D(shieldString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	lighting->LightReset();
	glPopMatrix();
}
StatusUI::~StatusUI()
{
}
