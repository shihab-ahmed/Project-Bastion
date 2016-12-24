#include "Globals.h"
#include "Lighting.h"



Lighting::Lighting()
{

}

void Lighting::LightEnable()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}
void Lighting::LightDisbale()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}
void Lighting::LightReset()
{
	GLfloat mat_ambient[] = { 0, 0, 0, 1.0 };
	GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
	GLfloat mat_specular[] = {0, 0, 0, 1.0 };
	GLfloat shininess[] = { 0 };
	GLfloat mat_emission[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat position[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT1, GL_POSITION, position);
}

void Lighting::SetDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha)
{
	GLfloat mat_diffuse[] = { r, g, b, alpha };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
}
void Lighting::SetAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha)
{
	GLfloat mat_ambient[] = { r, g, b, alpha };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
}
void Lighting::SetSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha)
{
	GLfloat mat_specular[] = { r, g, b, alpha };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
}
void Lighting::SetEmmision(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha)
{
	GLfloat mat_emission[] = { r, g, b, alpha };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
}
void Lighting::SetShininess(GLfloat rate)
{
	GLfloat shininess[] = { rate};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
void Lighting::SetPosition(GLfloat x, GLfloat y, GLfloat z,GLint lightNo)
{
	GLfloat position[] = { x, y, z, 1.0 };
	if (lightNo == 0)glLightfv(GL_LIGHT0, GL_POSITION, position);
	if (lightNo == 1)glLightfv(GL_LIGHT1, GL_POSITION, position);
	if (lightNo == 2)glLightfv(GL_LIGHT2, GL_POSITION, position);
}
void Lighting::SetMetalWhite()
{
	lighting->SetDiffuse(1, 1,1, 1);
	lighting->SetAmbient(1, 1, 1, 1);
	lighting->SetShininess(100);
}
void Lighting::SetMetaBlack()
{
	this->SetDiffuse(.22, .2, .2, 1);
	this->SetAmbient(.22, .2, .2, 1);
	this->SetSpecular(.22, .2, .2, 1);
	this->SetShininess(100);
}
void Lighting::SetMetalSilver()
{
	this->SetDiffuse(.6, .62, .63, 1);
	this->SetAmbient(.6, .62, .63, 1);
	this ->SetSpecular(.2,.2,.2,1);
	this->SetEmmision(.4, .41, .43, 1);
	this->SetShininess(100);
}
void Lighting::SetMetalGold()
{
	this->SetDiffuse(.4, .4, .4, 1);
	this->SetAmbient(.4, .4, .4, 1);
	this->SetShininess(100);
}
void Lighting::SetBlueEnergy()
{
	this->SetDiffuse(.4, .4, .4, 1);
	this->SetAmbient(.4, .4, .4, 1);
	this->SetShininess(100);
}
void Lighting::SetBlueShield()
{
	lighting->SetDiffuse(0, .7, 1, .5);
	lighting->SetAmbient(0, .7, 1, .5);
	lighting->SetEmmision(0, .7, 1, .5);
	lighting->SetShininess(100);
}
void Lighting::setMirrorCollor()
{
	lighting->SetDiffuse(0.7, .7, .7, .1);
	lighting->SetAmbient(0.7, .7, .7, .1);
	lighting->SetEmmision(0.7, .7, .7, .1);
	lighting->SetShininess(100);
}
void Lighting::setPortalBlueColor()
{
	this->SetDiffuse(0.10, 0.82, 1.00, .5);
	this->SetAmbient(0.00, 0.28, 0.70, .5);
	this->SetEmmision(0.40, 0.64, 1.00, .5);
	this->SetShininess(100); 
}
//void Lighting::SetBlueSea()
//{
//	lighting->SetDiffuse(0, .7, 1, .4);
//	lighting->SetAmbient(0, .7, 1, .4);
//	lighting->SetEmmision(0, .7, 1, .4);
//	lighting->SetShininess(100);
//}
void Lighting::SetRedShield()
{
	lighting->SetDiffuse(1, .1, .1, .4);
	lighting->SetAmbient(1, .1, .1, .4);
	lighting->SetEmmision(1, .1, .1, .4);
}
void Lighting::SetBuildingColorWhite() {

	this->SetDiffuse(0.9, 0.92, 0.95, 1); //Which color apply on full Body

	this->SetAmbient(0.4, 0.5, 0.6, 1); //Which color of shadow

	this->SetEmmision(.2,.21,.23,1);

	this->SetShininess(100); //How much it will shine

}
void Lighting::SetShieldColor() {

	this->SetDiffuse(0.10, 0.82, 1.00, 1); //Which color apply on full Body

	this->SetAmbient(0.00, 0.28, 0.70, 1); //Which color of shadow

	this->SetEmmision(0.40, 0.64, 1.00, 1); //If object emmit any light or not

	this->SetShininess(100); //How much it will shine

}
void Lighting::setGroundColor()
{
	this->SetDiffuse(0.7, 0.72,0.75, 1); //Which color apply on full Body

	this->SetAmbient(0.7, 0.72, 0.75, 1); //Which color of shadow
	this->SetEmmision(0.3, 0.32, 0.33, 1);
	this->SetShininess(100); //How much it will shine
}
void Lighting::setUITextColorYellow()
{
	this->SetDiffuse(1, 0.7, 0.0, 1); //Which color apply on full Body

	this->SetAmbient(1, 0.7, 0.0, 1); //Which color of shadow
	this->SetEmmision(0.3, 0.25, 0.0, 1);
	this->SetShininess(100); //How much it will shine
}
void Lighting::setRedLight()
{
	this->SetDiffuse(1,0.1,0.1,1);
	this->SetAmbient(1, 0.1, 0.1, 1);
	this->SetEmmision(1, 0.1, 0.1, 1);
	this->SetShininess(100);
}
void Lighting::setBlueLight()
{
	this->SetDiffuse(0, 0, 1, 1);
	this->SetAmbient(0, 0, 1, 1);
	this->SetEmmision(0, 0, 1, 1);
	this->SetShininess(100);
}
void Lighting::setYellowLight()
{
	this->SetDiffuse(1, 1, 0.1, 1);
	this->SetAmbient(1, 1, 0.1, 1);
	this->SetEmmision(1, 1, 0.1, 1);
	this->SetShininess(100);
}
void Lighting::setMagentaLight()
{
	this->SetDiffuse(1, 0.1, 1, 1);
	this->SetAmbient(1, 0.1, 1, 1);
	this->SetEmmision(1, 0.1, 1, 1);
	this->SetShininess(100);
}
void Lighting::setGreenLeafLight()
{
	this->SetDiffuse(0.2, .7, .2, 1);
	this->SetAmbient(0.2, .6, .2, 1);
	this->SetShininess(100);
}
void Lighting::setBranchLight()
{
	this->SetDiffuse(0.8, .3, .3, 1);
	this->SetAmbient(0.8, .3, .3, 1);
	this->SetShininess(100);
}
Lighting::~Lighting()
{
}
