#ifndef LIGHT_HEADER
#define LIGHT_HEADER
#include <GL/glut.h>
void SetLightPosition(GLfloat x, GLfloat y, GLfloat z);
void SetAmbient(GLfloat x, GLfloat y, GLfloat z);
void SetDiffuse(GLfloat x, GLfloat y, GLfloat z);
void SetSpecuilar(GLfloat x, GLfloat y, GLfloat z);
void SetShininess(GLfloat x);
void SetEmision(GLfloat x, GLfloat y, GLfloat z);
#endif // !LIGHT_HEADER
