#include "Globals.h"
#include "Environment.h"



Environment::Environment()
{
	this->solarAngle = 0;
}
void Environment::makeGrid(float size) 
{
	glPushMatrix();
	glTranslatef(0,-1,0);
	glBegin(GL_LINES);
	for (int i = -size; i <= size; ++i) {
		glVertex3f(i, 0, -size);
		glVertex3f(i, 0, size);

		glVertex3f(size, 0, i);
		glVertex3f(-size, 0, i);
	}
	glEnd();
	glPopMatrix();
}
void Environment::drawStreet()
{
	for (int i = 0; i < buildings.size(); i++)
	{
		glPushMatrix();
		glTranslatef(buildings[i]->givePosX(),-1.3,buildings[i]->givePosZ());
		glScalef(buildings[i]->giveWidth()+4,1,buildings[i]->giveDepth()+4);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void Environment::drawStreetLamp()
{
	for (int i = 0; i < buildings.size(); i++)
	{
		float posx = buildings[i]->givePosX() + buildings[i]->giveWidth() / 2;
		float posz = buildings[i]->givePosZ() + buildings[i]->giveDepth() / 2;

		glPushMatrix();
		glTranslatef(posx, 0,posz );
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(posx, 0,-posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-posx, 0, posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-posx, 0, -posz);
		glScalef(1, 4, 1);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void Environment::tree() {
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();
	glScalef(.2,.2,.2);

	glPushMatrix();
	glTranslatef(0,-1.5,0);
	glRotatef(-90, 1, 0, 0);
	lighting->setBranchLight();
	gluCylinder(gluNewQuadric(),.2,.2,3,20,20);
	lighting->LightReset();
	glPopMatrix();
	
	glPushMatrix();
	lighting->setGreenLeafLight();
	glTranslatef(0, 0, 0);
	glRotatef(-90,1,0,0);
	glutSolidCone(1, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .5, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,1,0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1, 2, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setRedLight();
	glTranslatef(0, 3.5, 0);
	glScalef(.25,.25,.25);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glTranslatef(1, .5, 0);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setMagentaLight();
	glTranslatef(-1, .5, 0);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setYellowLight();
	glTranslatef(0, .5, 1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glTranslatef(0, .5, -1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setMagentaLight();
	glRotatef(45,0,1,0);
	glTranslatef(-1, 1, 0);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setYellowLight();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0, 1, 1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0, 1, -1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0, 1, -1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setMagentaLight();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-1, 1.5, 0);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setYellowLight();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 1.5, 1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 1.5, -1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetShieldColor();
	glRotatef(90, 0, 1.5, 0);
	glTranslatef(0, 1.5, -1);
	glScalef(.2, .2, .2);
	glutSolidSphere(1, 20, 20);
	lighting->LightReset();
	glPopMatrix();

	glPopMatrix();
}
void Environment::Block(float posX,float posZ,float Rotation)
{
	glPushMatrix();
	glTranslatef(posX, -.5, posZ);
	glRotatef(Rotation,0,1,0);
	lighting->SetBuildingColorWhite();
	glPushMatrix();
	glTranslatef(-6,0,0);
	glScalef(2, 2, .5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	glScalef(2, 2, .5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glScalef(2, 2, .5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 0, 0);
	glScalef(2, 2, .5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 0, 0);
	glScalef(2, 2, .5);
	glutSolidCube(1);
	glPopMatrix();
	lighting->LightReset();
	glPopMatrix();
	
}
float Environment::SolarAnimationUpdate()
{
	solarAngle += 1.0f;
	if (solarAngle >= 360)
	{
		solarAngle = 0;
	}
	return solarAngle;
}
void Environment::bench()
{
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, -.28, 0);
	//Leg
	glPushMatrix();
	glScalef(.2, 2.3, .2);
	glTranslatef(1.6, 0, 1.2);
	glutSolidCube(.2);
	glPopMatrix();
	glPushMatrix();
	glScalef(.2, 2.3, .2);
	glTranslatef(-1.6, 0, 1.2);
	glutSolidCube(.2);
	glPopMatrix();

	glPushMatrix();
	glScalef(.2, 1.4, .2);
	glTranslatef(1.6, -.06, -1.2);
	glutSolidCube(.2);
	glPopMatrix();
	glPushMatrix();
	glScalef(.2, 1.4, .2);
	glTranslatef(-1.6, -.06, -1.2);
	glutSolidCube(.2);
	glPopMatrix();

	//Middle
	//Below Join
	glPushMatrix();
	glTranslatef(-.32, .02, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(2.3, .4, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.32, .02, 0);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(2.3, .4, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	//UperJoin
	glPushMatrix();
	glTranslatef(-.32, .2, -.04);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(2.7, .3, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.32, .2, -.04);
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(2.7, .3, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	//Upper Handle
	glPushMatrix();
	glTranslatef(-.32, .23, -.32);
	glRotatef(-23, 1, 0, 0);
	glPushMatrix();
	glScalef(.2, 2.3, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.32, .23, -.32);
	glRotatef(-23, 1, 0, 0);
	glPushMatrix();
	glScalef(.2, 2.3, .2);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();

	//Seat
	//Down
	glPushMatrix();
	glTranslatef(0, .02, 0);
	glPushMatrix();
	glScalef(3, .2, 2.5);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();
	//Up
	glPushMatrix();
	glRotatef(67, 1, 0, 0);
	glTranslatef(0, -.205, -.35);
	glPushMatrix();
	glScalef(3, .2, 1.5);
	glutSolidCube(.2);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Environment::globe()
{
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 0);
	//Solar System
	glPushMatrix();
	glTranslatef(0, .7, 0);
	glScalef(.5, .5, .5);
	solarSystem();
	glPopMatrix();

	//Stand
	glPushMatrix();
	lighting->SetMetaBlack();
	glScalef(.8, .8, .8);
	glPushMatrix();
	glutSolidOctahedron();
	glPopMatrix();
	lighting->LightReset();
	lighting->SetBuildingColorWhite();
	glPopMatrix();
	//Base Part
	glPushMatrix();
	glScalef(2, .5, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();
}
void Environment::solarSystem()
{
	SolarAnimationUpdate();

	glPushMatrix();//final push
	glTranslatef(0,1,0);
	glPushMatrix();
	glRotatef(-70, 1, 0, 0);
	glRotatef(20, 0, 1, 0);
	glBegin(GL_LINES);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 0.70;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 1.2;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 1.70;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i<200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = 2.40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();
	//orbits end

	//Sun
	glPushMatrix();
	glPushMatrix();
	glRotatef(solarAngle, 0, 0, 1);
	glutWireSphere(.5, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//Sun end

	//Planet
	glPushMatrix();
	glRotatef(solarAngle - 20, 0, 0, 1);
	glTranslatef(.7, 0, 0);
	glPushMatrix();
	glRotatef(solarAngle, 0, 0, 1);
	glutWireSphere(.1, 15, 15);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(solarAngle - 120, 0, 0, 1);
	glTranslatef(1.2, 0, 0);
	glPushMatrix();
	glRotatef(solarAngle, 0, 0, 1);
	glutWireSphere(.15, 15, 15);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(solarAngle - 70, 0, 0, 1);
	glTranslatef(1.70, 0, 0);
	glPushMatrix();
	glRotatef(solarAngle, 0, 0, 1);
	glutWireSphere(.2, 15, 15);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(solarAngle - 200, 0, 0, 1);
	glTranslatef(2.40, 0, 0);
	glPushMatrix();
	glRotatef(solarAngle, 0, 0, 1);
	glutWireSphere(.25, 15, 15);
	glPopMatrix();
	glPopMatrix();
	//planet end
	glPopMatrix();

	glPopMatrix();//final pop
}
void Environment::Park(float x, float y,float z,float h, float w,float d)
{
	glPushMatrix();//first
	glTranslatef(x, y, z);
	glScalef(w, h, d);
	
	glPushMatrix();
	glScalef(.20, .20, .20);

	glPushMatrix();
	lighting->SetBuildingColorWhite();
	glScalef(5,.5,5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .35, 0);
	glScalef(.5, .5,.5);
	globe();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.6,.5,-2);
	glScalef(.5, .5, .5);
	bench();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, .5,-1.6);
	glRotatef(-90,0,1,0);
	glScalef(.5, .5, .5);
	bench();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, .5, -2);
	glScalef(.5, .5, .5);
	bench();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, .5, 2);
	glRotatef(-90, 0, 1, 0);	
	glScalef(.5, .5, .5);
	bench();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, .5, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(.5, .5, .5);
	bench();
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, .5, 2);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, .5, 2);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, .5, 0);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.7, .5, -.5);
	tree();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, .5, -2);
	tree();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();//last
}
void Environment::PortalArea(float posX,float posZ,float rotation)
{
	glPushMatrix();
	glTranslatef(posX, 0, posZ);

	glPushMatrix();
	glTranslatef(0, 0, 20);

	glPushMatrix();
	lighting->SetBuildingColorWhite();
	glTranslatef(-1.5, .5, 0);
	glScalef(.5, 4, .5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,2.5, 0);
	glScalef(3.5, .5, .5);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->setPortalBlueColor();
	glTranslatef(0, .5, 0);
	glScalef(3, 4, .2);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();

	glPushMatrix();
	lighting->SetBuildingColorWhite();
	glTranslatef(1.5, .5, 0);
	glScalef(.5, 4, .5);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	lighting->LightReset();
	glTranslatef(0,-2, 0);
	glScalef(18, 1, 60);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();

	glPopMatrix();
}
void Environment::Blocades()
{
	glPushMatrix();
	Block(0,-80,0);
	glPopMatrix();

	glPushMatrix();
	Block(50,-80, 0);
	glPopMatrix();

	glPushMatrix();
	Block(-50,-80, 0);
	glPopMatrix();

	glPushMatrix();
	Block(50, 80, 0);
	glPopMatrix();

	glPushMatrix();
	Block(-50, 80, 0);
	glPopMatrix();

	glPushMatrix();
	Block(80,50, 90);
	glPopMatrix();

	glPushMatrix();
	Block(80, -50, 90);
	glPopMatrix();

	glPushMatrix();
	Block(80, 0, 90);
	glPopMatrix();

	glPushMatrix();
	Block(-80, 0, 90);
	glPopMatrix();

	glPushMatrix();
	Block(-80, 50, 90);
	glPopMatrix();

	glPushMatrix();
	Block(-80,-50, 90);
	glPopMatrix();
}
void Environment::Sea(float size)
{
	glPushMatrix();
	glTranslatef(0, -1.6, 0);
	lighting->SetBlueShield();
	glScalef(size * 4 + 4, .4, size * 4 + 4);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();
}
void Environment::groundFloor(float size)
{
	glPushMatrix();
	glTranslatef(0, -1.3, 0);
	lighting->setGroundColor();
	glScalef(size*2+4,.4, size*2+4);
	glutSolidCube(1);
	lighting->LightReset();
	glPopMatrix();
}
Environment::~Environment()
{
}
void BuildingB()
{
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glScalef(2, 2, 4);
	glutSolidCube(1);
	glPopMatrix();
}
void BuildingC()
{
	glPushMatrix();
	glTranslatef(0, 0, -2);
	glScalef(3, 3, 4);
	glutSolidCube(1);
	glPopMatrix();
}
void BuildingD()
{
	glPushMatrix();
	glTranslatef(0, 0, -4);
	glScalef(3, 3, 8);
	glutSolidCube(1);
	glPopMatrix();
}

void Ground()
{
	glPushMatrix();
	glScalef(15, 15, 1);
	glutSolidCube(1);
	glPopMatrix();
}
void Environment::DrawEnvironment()
{
	
}