#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "HeroAssemble.h"
#include "Lighting.h"
#define PI 3.14159265
using namespace std;

float _angle = 0.0;
float _cameraAngle = 0.;
float _ang_tri = 0.0;




//Lighting
void init(void)
{
	GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 3, 3, 1.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(.05, 0.05, 0.05, 0.0);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

//Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	//glEnable(GL_CULL_FACE);//wont draw back camera faces speed up process
	//glCullFace(GL_BACK);
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
	glRotatef(_angle,0,1,0);
	//glRotatef(90, 0, 1, 0);
	getHero();
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
	glutInitWindowSize(1000, 600);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();
	init();
	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}