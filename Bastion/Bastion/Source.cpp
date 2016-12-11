#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "HeroAssemble.h"
#include "Lighting.h"
#include "Controller.h"
#include "Environment.h"
#include "Tank.h"
#include "Algorithm.h"
#include "PositionData.h"
#include "Tank.h"
#define PI 3.14159265
using namespace std;

float _angle = 0.0;
float _cameraAngle = 0.;
float _ang_tri = 0.0;

Matrix CameraPosition(4, Row(3));


//Lighting
void init(void)
{
	GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 0, 0, 0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glLightfv(GL_LIGHT1, GL_POSITION, position);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(.15, 0.45, 0.85, 0.0);


	//camera setup
	CameraPosition[0][0] = 0;
	CameraPosition[1][0] = 0; //2.5
	CameraPosition[2][0] = -5; //-5
	CameraPosition[3][0] = 1;

	CameraPosition[0][1] = 0;
	CameraPosition[1][1] = 0; //2
	CameraPosition[2][1] = 0; //5
	CameraPosition[3][1] = 1;

	CameraPosition[0][2] = 0;
	CameraPosition[1][2] = 1; //1
	CameraPosition[2][2] = 0;
	CameraPosition[3][2] = 1;
}

//Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
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

	
	

	CameraPosition = Translation(CameraPosition,0,0, getCameraZPosition());
	//CameraPosition = Rotation(CameraPosition, getCameraRotation(),2);
	gluLookAt(CameraPosition[0][0], CameraPosition[1][0], CameraPosition[2][0],
		CameraPosition[0][1], CameraPosition[1][1], CameraPosition[2][1],
				0, 1, 0);
	//gluLookAt(1,0,-1,0,0,0,0,1,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	
	glBegin(GL_LINES);
	glVertex3f(-100,0,0);
	glVertex3f(100, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, -100, 0);
	glVertex3f(0, 100, 0);
	glEnd();

	
	glPushMatrix();
	//glRotatef(_angle, 0, 1, 0);
	getHero();
	//glRotatef(getCameraRotation(), 0, 1, 0);
	Environment();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	glTranslatef(-4,-2,0);
	glScalef(3.5,3.5,3.5);
	TankBody();
	TankBodyFireJoin();
	TankFireSystem();
	TankFrontTire();
	TankRearTire();
	glDisable(GL_LIGHTING);
	glPopMatrix();

	glutSwapBuffers();
}


void update(int value)
{
	_angle += 1.0f;
	if (_angle > 360)
	{
		_angle -= 360;
	}
	_ang_tri += 1.0f;
	if (_ang_tri > 360)
	{
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(35, update, 0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();
	init();
	InitPositionData();
	//CameraPosition = Rotation(CameraPosition, 45, 2);
	ShowMatrix(CameraPosition);

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);


	//adding here the mouse processing callbacks
	glutMouseFunc(processMouse);
	//glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(mouseMove);
	//glutEntryFunc(processMouseEntry);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);


	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}