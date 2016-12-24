#include "Animation.h"
#include "Globals.h"
using namespace std;

Animation::Animation()
{
	this->angleX = 0;
	this->angleY = 0;
	this->angleZ = 0;
	this->camX = 0;
	this->camY = 0;
	this->camZ = -118;
	this->playerReachedOpeningCamera = 120;
	this->openingState1 = false;
	this->openingState2 = false;
	this->openingState3 = false;
	this->openingState4 = false;
	this->openingState5 = false;
	this->openingState6 = false;
	this->openingState7 = false;
}
void Animation::angleXUpdate(float val)
{
	angleX += val;
}
void Animation::angleYUpdate(float val)
{
	angleY += val;
}
void Animation::camYUpdate()
{
	camY -= 0.1f;

}
void Animation::Opening()
{
	if(playerRobot->givePosZ()<playerReachedOpeningCamera)openingState1=true;
	if (openingState1)
	{
		if (angleY == 180)
		{
			openingState2 = true;
			openingState1 = false;
		}
		else
		{
			angleYUpdate(1);
		} 
		
	}
	if (openingState2)
	{

		if (statusUI->getIsDead())
		{
			openingState2 = false;
			openingState3 = true;
		}
		else
		{
			statusUI->drawWelomce();
		}
	}
	if (openingState3)
	{
		if (camY <-20)
		{
			openingState3 = false;
			openingState4 = true;
		}
		else
		{
			camYUpdate();
			angleXUpdate(0.1);
		}
	}
	if (openingState4)
	{
		if (playerRobot->givePosZ() < 70)
		{
			gameStatus->setIsOpeningAnimation(false);

			this->angleX = 0;
			this->angleY = 0;
			this->angleZ = 0;
			this->camX = 0;
			this->camY = 0;
			this->camZ = -118;
			playerRobot->setPosZ(playerGamePosZ);
		}
	}
	glTranslatef(0.0f,0, 0.0f);
	glRotatef(angleY+180, 0.0f, 1.0f, 0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glTranslatef(camX, camY, camZ);

	playerRobot->accelerate(true);
	playerRobot->WalkingState(true);
}
Animation::~Animation()
{
}
