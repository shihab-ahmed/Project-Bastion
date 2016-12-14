#include "Main.h"
#include "GlobalVariable.h"
//#include "Environment.h"
using namespace std;
int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH) - 100, glutGet(GLUT_SCREEN_HEIGHT) - 100);
	glutInitWindowPosition(50, 50);

	//Create the window
	glutCreateWindow("Tanks!");
	initRendering();
	playerRobot = new Player(0,0,0);
	environment = new Environment();
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(handleKeyUp);
	glutMotionFunc(handleActiveMouse);
	glutPassiveMotionFunc(handlePassiveMouse);
	glutReshapeFunc(handleResize);
	glutIgnoreKeyRepeat(true);
	if (isFullscreen) 
	{
		glutSetCursor(GLUT_CURSOR_NONE);
	}
	glutMouseFunc(playerFire);
	glutIgnoreKeyRepeat(1);



	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}

//Initializes 3D rendering
void initRendering() {

	glClearColor(fogColour[0], fogColour[1], fogColour[2], fogColour[3]);

	// set the fog attributes
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 200.0f);
	glFogfv(GL_FOG_COLOR, fogColour);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.1f);

	// enable the fog
	glEnable(GL_FOG);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
							 //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Wireframe
	if (isFullscreen)
	{
		glutFullScreen();
		glutWarpPointer(770, 450);
	}
}

void update(int value)
{
	checkInput();
	playerRobot->move();

	bool bulletNotDead = true;

	for (int i = 0; i < plazmaBalls.size(); i++) 
	{
		plazmaBalls[i]->move();
		plazmaBalls[i]->flagAsDead();
	}

	for (int i = 0; i < plazmaBalls.size(); i++) 
	{
		if (plazmaBalls[i]->isDead()) {
			//delete plazmaBalls[i];
			//plazmaBalls.erase(plazmaBalls.begin() + i);
		}
	}

	fogColour[0] = (1.0f - radarVisionMagnitude)*originalfogColour[0];
	fogColour[1] = (1.0f - radarVisionMagnitude)*originalfogColour[1];
	fogColour[2] = (1.0f - radarVisionMagnitude)*originalfogColour[2];

	lagDistance *= 0.95;
	screenShakeMagnitude *= 0.95;
	zoomMagnitude *= 0.95;

	//cout << "VM:" << radarVisionActivated<<endl;
	//cout << "FogColor:" << fogColour[0] << endl;

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

//Draws the 3D scene
void drawScene() 
{

	glFogfv(GL_FOG_COLOR, fogColour);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glPushMatrix();

	//Camera start
	glTranslatef(0.0f, -1.5f, -7.0f);
	glRotatef(5, 1.0f, 0.0f, 0.0f);
	glRotatef(-playerRobot->giveRotation(), 0.0f, 1.0f, 0.0f);
	glRotatef(lagDistance, 0.0f, 1.0f, 0.0f);
	glRotatef(-playerRobot->giveTurretRotation(), 0.0f, 1.0f, 0.0f);

	glTranslatef(-playerRobot->givePosX(), 0.0f, -playerRobot->givePosZ());
	//Camera end

	for (int i = 0; i < plazmaBalls.size(); i++) 
	{
		plazmaBalls[i]->drawPlazmaBall();
		cout << "Shot";
	}

	environment->makeGrid(mapSize);
	//Creating line for gun range
	glPushMatrix();
	glTranslatef(playerRobot->givePosX()+playerRobot->playerWidth()/4, (playerRobot->PlayerHeight()) / 16, playerRobot->givePosZ());
	glRotatef(playerRobot->giveRotation() + playerRobot->giveTurretRotation(), 0.0f, 1.0f, 0.0f);
	//glColor4f(0.1f, 0.7f, 1.0f, 0.2f);

	float seperation = 2.0f;

	for (int i = 1; i <= 10; i++) {
		float bulletTravel = (-seperation*i);
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -seperation*i);
		glRotatef(-playerRobot->giveRotation() - playerRobot->giveTurretRotation(), 0.0f, 1.0f, 0.0f);
		glTranslatef(-playerRobot->giveSpeedX()*bulletTravel, 0.0f, -playerRobot->giveSpeedZ()*bulletTravel);
		glutSolidSphere(0.03f, 10, 10);
		glPopMatrix();
	}
	glPopMatrix();
	//done line for gun range

	glutWireCube(1);
	playerRobot->DrawPlayer();
	glPopMatrix();
	
	
	
	glutSwapBuffers();
}

void renderBitmapString(float x, float y, float z, void *font, char *string)
{
	/*char *c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}*/
}


void handlePassiveMouse(int x, int y) {
	playerRobot->rotateTurret(0.1*(lastMouseX - x));
	lagDistance += 0.1*(lastMouseX - x);
	lastMouseX = x;
	if (x <= 2 || x >= 1355) {
		glutWarpPointer(770, 450);
		if (leftMouseDown) {
			playerFire(GLUT_LEFT_BUTTON, GLUT_DOWN, 0, 0);
			cout << "Left mouse";
		}
		lastMouseX = 770;
	}
}

void handleActiveMouse(int x, int y) {
	handlePassiveMouse(x, y);
}

void checkInput() 
{
	if (keyDown[27]) {
		exit(0);
	}
	if (keyDown['w']) {
		playerRobot->accelerate(true);
		playerRobot->WalkingState(true);
		cout << "w" << endl;
	}
	if (keyDown['s']) {
		playerRobot->accelerate(false);
		playerRobot->WalkingState(true);
		cout << "s" << endl;
	}
	if (!keyDown['w']&& !keyDown['s']) {
		playerRobot->WalkingState(false);
	}
	if (keyDown['a']) {
		playerRobot->rotate(true);
		cout << "a" << endl;
	}
	if (keyDown['d']) {
		playerRobot->rotate(false);
		cout << "d" << endl;
	}
	if (keyDown[' '] || leftMouseDown)
	{
		if (playerRobot->fire()) 
		{
			cout << "i am here";
		}
	}
	/*if (keyDown['i']) {
		playerRobot->boost();
		screenShakeMagnitude += 0.02;
	}
	if (keyDown['e']) {
		zoomMagnitude += 0.02;
	}
	if (keyDown['k']) {
		int direction = playerRobot->centerTurret();
		if (direction > 0) {
			lagDistance += 2.5;
		}
		else if (direction < 0) {
			lagDistance -= 2.5;
		}
	}
	if (keyDown['u']) {
		radarVisionActivated = true;
	}
	if (keyDown['o']) {
		slowMotionActivated = true;
	}
	if (keyDown['j']) {
		if (playerTank->giveRotationSpeed() > 0.5f) {
			playerTank->rotateTurret(1.0f);
		}
		else if (playerTank->giveRotationSpeed() < -0.5f) {
			playerTank->rotateTurret(-1.0f);
		}
		playerTank->rotateTurret(1.5f);
		lagDistance += 2.5;
	}
	if (keyDown['l']) {
		if (playerTank->giveRotationSpeed() > 0.5f) {
			playerTank->rotateTurret(1.0f);
		}
		else if (playerTank->giveRotationSpeed() < -0.5f) {
			playerTank->rotateTurret(-1.0f);
		}
		playerTank->rotateTurret(-1.5f);
		lagDistance -= 2.5;
	}

	}*/
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {    //The current mouse coordinates
	keyDown[key] = true;
}

void handleKeyUp(unsigned char key, int x, int y) {
	keyDown[key] = false;
}

//Called when the window is resized
void handleResize(int w, int h) 
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
	screenWidth = w;
	screenHeight = h;
}

void playerFire(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			leftMouseDown = true;
			cout << "is true";
		}
		else {
			leftMouseDown = false;
		}

	}
}

////void createTank(float x, float y) {
////	tanks.push_back(new Tank(x, y, 0.0f));
////}
////
////void createObstacle(float x, float z, float r) {
////	obstacles.push_back(new Obstacle(x, z, r));
////}
//
////void drawHealthBars() 
////{
////	glPushMatrix();
////	glTranslatef(0.0f, 1.1f, -3.0f);
////	glColor4f(1.0f, 0.3f, 0.3f, 0.2f);
////	glPushMatrix();
////	glScalef(2 * playerTank->giveHealth(), 1.0f, 1.0f);
////	glutSolidCube(0.1f);
////	glPopMatrix();
////
////	glTranslatef(0.0f, -0.1f, 0.0f);
////	glColor4f(0.2f, 0.2f, 1.0f, 0.3f);
////	glPushMatrix();
////	glScalef(2 * playerTank->giveShieldStrength(), 1.0f, 1.0f);
////	glutSolidCube(0.1f);
////	glPopMatrix();
////	glPopMatrix();
////}
