#include <gl/glut.h>
#include "Environment.h"



Environment::Environment()
{
}

void Environment::makeGrid(float size) 
{
	//glColor4f(0.0f, 0.0f, 0.0f, 1.0f );
	glBegin(GL_LINES);
	for (int i = -size; i <= size; ++i) {
		glVertex3f(i, 0, -size);
		glVertex3f(i, 0, size);

		glVertex3f(size, 0, i);
		glVertex3f(-size, 0, i);
	}
	glEnd();
}
Environment::~Environment()
{
}
