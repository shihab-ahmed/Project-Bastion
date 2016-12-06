#include <GL/glut.h>
void SetLightPosition(GLfloat x, GLfloat y, GLfloat z )
{
	GLfloat position[] = { x, y, z, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}
void SetAmbeint(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat mat_ambient_color[] = { x, y, z, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient_color);
}
void SetDiffuse(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat mat_diffuse[] = { x, y, z, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
}
void SetSpecuilar(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat mat_specular[] = { x,y,z, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
}
void SetShininess(GLfloat x)
{
	GLfloat shine[] = { x };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shine);
}
void SetEmision(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat mat_emission[] = {x, y, z, 1 };
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
}