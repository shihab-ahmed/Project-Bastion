#include "StatusUI.h"
#include "Globals.h"
using namespace std;

StatusUI::StatusUI()
{
	this->remainLife = 300;
	this->isDead = false;
}

void StatusUI::drawPlayerStatus(int health,int shield, int score)
{
	string healthString = to_string(health);
	string shieldString = to_string(shield);
	string scoreString =  to_string(score);

	glPushMatrix();
	lighting->LightEnable();
	lighting->SetShieldColor();
	glPushMatrix();
	glTranslatef(5, 2.5, -7.0f);
	glRotatef(-45,0,1,0);
	glScalef(.25, .25, .25);
	t3dDraw3D("Score", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 2.1, -7.0f);
	glRotatef(-45, 0, 1, 0);
	glScalef(.25, .25, .25);
	t3dDraw3D(scoreString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.8, 2.3, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.25, .25, .25);
	t3dDraw3D("Health", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.8, 1.9, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.25, .25, .25);
	t3dDraw3D(healthString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.8, 1.5, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.25, .25, .25);
	t3dDraw3D("Shield", 1, 1, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.8, 1.1, -7.0f);
	glRotatef(45, 0, 1, 0);
	glScalef(.25, .25, .25);
	t3dDraw3D(shieldString.c_str(), 1, 1, 0.2f);
	glPopMatrix();

	lighting->LightReset();
	glPopMatrix();
}
void StatusUI::drawGameStatus()
{
	string status;
	if (gameStatus->getIsPlayerWin())
	{
		lighting->setUITextColorYellow();
		status = "You Win!";
	}
	else
	{
		lighting->setUITextColorYellow();
		status = "You Lose";
	}
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, -7.0f);
	glScalef(.5, .5, .5);
	t3dDraw3D(status, 0, 0, 0.2f);
	glPopMatrix();
	lighting->LightReset();
	glPopMatrix();
}
void StatusUI::drawGameObjective()
{
	remainLife--;

	glPushMatrix();
	lighting->setUITextColorYellow();
	glPushMatrix();
	glTranslatef(0, 1, -7.0f);
	glScalef(.25, .25, .25);
	t3dDraw3D("Objective:", 0, 0, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .5, -7.0f);
	glScalef(.25, .25, .25);
	t3dDraw3D("1.Destroy all Shield Genarator.", 0, 0, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -7.0f);
	glScalef(.25, .25, .25);
	t3dDraw3D("2.Destroy all tanks.", 0, 0, 0.2f);
	glPopMatrix();
	lighting->LightReset();
	glPopMatrix();
}
void StatusUI::drawWelomce()
{
	remainLife--;
	if (remainLife <= 0)flagAsDead(true);
	glPushMatrix();
	lighting->SetShieldColor();
	glPushMatrix();
	glTranslatef(0, 1, -7.0f);
	glScalef(.5, .5, .5);
	t3dDraw3D("Project Bastion", 0, 0, 0.2f);
	glPopMatrix();

	lighting->LightReset();
	glPopMatrix();
}
void StatusUI::flagAsDead(bool state)
{
	this->isDead = state;
}
bool StatusUI::getIsDead()
{
	return this->isDead;
	remainLife = 300;
}
StatusUI::~StatusUI()
{
}
