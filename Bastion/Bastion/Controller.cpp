#include <iostream>
#include <GL/glut.h>
using namespace std;
float deltaAngle = 0.0f;
int xOrigin = -1;



bool isWalk = false;
float lastx, lasty;
float cRadius = 10.0f;
float OriginX = 0, OriginY = 0;
int EyeX = 0, EyeY = 0, EyeZ = 0, UpX = 0, UpY, UpZ;
int Face;
bool FaceLeft, FaceRight, FaceForward=true, FaceBackward,isRotateRight,isRotateLeft;
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;


void processMouse(int button, int state, int x, int y) 
{
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON)
	{		
		// when the button is released
		if (state == GLUT_UP)
		{
			cout << "Left"<<endl;
		}
		else 
		{
			xOrigin = x;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		// when the button is released
		if (state == GLUT_UP)
		{
			cout << "RIGHT"<<endl;
		}
		else 
		{// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}
int getEyeX()
{
	return EyeX;
}
int getEyeY()
{
	return EyeY;
}
void mouseMove(int x, int y) 
{
	EyeX = x/10;
	EyeY = y/10;
	
}
bool StateWalking()
{
	return isWalk;
}
float getXPosition()
{
	return xpos;
}
float getZPosition()
{
	return zpos;
}
int getRotation()
{
	//glRotatef(angle, 0, 1, 0);
	if (isRotateRight)
	{
		angle -= 2.0f;
	}
	if (isRotateLeft)
	{
		angle += 2.0f;
	}
	return angle;
}
void getDirection()
{
	if (isRotateLeft || isRotateRight)
	{
		glRotatef(getRotation(), 0, 1, 0);
		glTranslatef(xpos, ypos, zpos);
	}
	if (isWalk)
	{
		glTranslatef(xpos, ypos, zpos);
		glRotatef(getRotation(), 0, 1, 0);		
	}
	//glRotatef(getRotation(), 0, 1, 0);


	if (FaceForward & isWalk)
	{
		zpos += 0.1f;
	}
	if (FaceBackward & isWalk)
	{

		zpos -= 0.1f;
	}
	if (FaceRight & isWalk)
	{
		xpos -= 0.1f;
	}
	if (FaceLeft & isWalk)
	{
		xpos += 0.1f;
	}
}

void keyboard(unsigned char key, int x, int y) 
{
	if (key == 'w')//
	{
		isWalk = true;
		FaceLeft = false;
		FaceRight = false;
		FaceForward = true;
		FaceBackward = false;
	}
	if (key == 's')//
	{
		isWalk = true;
		FaceLeft = false;
		FaceRight = false;
		FaceForward = false;
		FaceBackward = true;

	}
	if (key == 'a')
	{
		isWalk = true;
		FaceLeft = true;
		FaceRight = false;
		FaceForward = false;
		FaceBackward = false;
	}

	if (key == 'd')
	{
		isWalk = true;
		FaceLeft = false;
		FaceRight = true;
		FaceForward = false;
		FaceBackward = false;
	}

	if (key == 'q')//zoom out
	{
		isRotateRight = false;
		isRotateLeft = true;
	}
	if (key == 'e')//zoom in
	{
		isRotateRight = true;
		isRotateLeft = false;

	}

	/*if (key == 'w')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos += float(sin(yrotrad));
		zpos -= float(cos(yrotrad));
		ypos -= float(sin(xrotrad));
	}

	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		ypos += float(sin(xrotrad));
	}

	if (key == 'd')
	{
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * 0.2;
		zpos += float(sin(yrotrad)) * 0.2;
	}

	if (key == 'a')
	{
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * 0.2;
		zpos -= float(sin(yrotrad)) * 0.2;
	}
*/

}
void keyboardUp(unsigned char key, int x, int y)
{
	if (key == 'w')//zoom out
	{
		isWalk = false;
	}
	if (key == 's')//zoom out
	{
		isWalk = false;
	}
	if (key == 'a')//zoom out
	{
		isWalk = false;
	}
	if (key == 'd')//zoom out
	{
		isWalk = false;
	}

	if (key == 'q')//zoom out
	{
		isRotateRight = false;
		isRotateLeft = false;
	}
	if (key == 'e')//zoom in
	{
		isRotateRight = false;
		isRotateLeft = false;

	}
	

}