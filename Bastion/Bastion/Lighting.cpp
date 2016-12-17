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
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
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
Lighting::~Lighting()
{
}
