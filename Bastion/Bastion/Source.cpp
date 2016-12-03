#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "Hero.h"
#define PI 3.14159265
using namespace std;

float _angle = 0.0;
float _cameraAngle = 0.;
float _ang_tri = 0.0;

//Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);		//Switch to the drawing perspective
	glLoadIdentity();				//Reset the drawing perspective
									//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -10.0);	//Move forward 5 units
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();
	glRotatef(_angle, 0, 1, 0);
	//drawHeroHead();
	drawHeroLeftHand();
	//drawChest();
	glPopMatrix();
	glutSwapBuffers();
}







void update(int value)
{
	_angle += 2.0f;
	if (_angle > 360)
	{
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360)
	{
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}








int main(int argc, char** argv)
{
	cout << "Press s to start and s to off\n 1, 2 , 3,4,5 range of speed" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}