#include "Main.h"
#include "GlobalVariable.h"
#include "text3d.h"
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
	playerRobot = new Player(0,0,0);
	environment = new Environment();
	lighting    = new Lighting();
	statusUI = new StatusUI();


	initRendering();

	addBuilding();
	addEnemyTank();
	addShieldGenerator();

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
void addBuilding()
{
	buildings.push_back(new Building(float(-70), float(-70), 20, 20, 20));
	buildings.push_back(new Building(float( 70), float(-70), 20, 20, 20));
	buildings.push_back(new Building(float(-70), float( 70), 20, 20, 20));
	buildings.push_back(new Building(float( 70), float( 70), 20, 20, 20));

	buildings.push_back(new Building(float(-26), float(-26), 20, 30, 30));
	buildings.push_back(new Building(float( 26), float(-26), 20, 30, 30));
	buildings.push_back(new Building(float(-26), float( 26), 20, 30, 30));
	buildings.push_back(new Building(float( 26), float( 26), 20, 30, 30));

	buildings.push_back(new Building(float(-26), float( 70), 20, 30, 20));
	buildings.push_back(new Building(float( 26), float( 70), 20, 30, 20));
	buildings.push_back(new Building(float(-26), float(-70), 20, 30, 20));
	buildings.push_back(new Building(float( 26), float(-70), 20, 30, 20));

	buildings.push_back(new Building(float(-70), float( 26), 20, 20, 30));
	buildings.push_back(new Building(float(-70), float(-26), 20, 20, 30));
	buildings.push_back(new Building(float( 70), float( 26), 20, 20, 30));
	buildings.push_back(new Building(float( 70), float(-26), 20, 20, 30));
	
}
void addEnemyTank()
{
	enemyTanks.push_back(new EnemyTank( 50,  0,  0));
	enemyTanks.push_back(new EnemyTank( 0, -50,  0));
	enemyTanks.push_back(new EnemyTank(-50, 50,  0));
	enemyTanks.push_back(new EnemyTank( 50,-50, 90));
	enemyTanks.push_back(new EnemyTank( 50, 50, 90));
	enemyTanks.push_back(new EnemyTank( 50,  0, 90));
}
void addShieldGenerator()
{
	shieldGenerators.push_back(new ShieldGenerator(-50, 0, 50, 0));
	shieldGenerators.push_back(new ShieldGenerator(-50, 0,-50, 0));
	shieldGenerators.push_back(new ShieldGenerator( 50, 0, 50, 0));
	shieldGenerators.push_back(new ShieldGenerator( 50, 0,-50, 0));
	shieldGenerators.push_back(new ShieldGenerator(  0, 0, 50, 0));
	shieldGenerators.push_back(new ShieldGenerator(  0, 0,-50, 0));
	shieldGenerators.push_back(new ShieldGenerator( 50, 0,  0, 0));
	shieldGenerators.push_back(new ShieldGenerator(-50, 0,  0, 0));
	shieldGenerators.push_back(new ShieldGenerator(  0, 0,  0, 0));
}
//Initializes 3D rendering
void initRendering()
{

	glClearColor(fogColour[0], fogColour[1], fogColour[2], fogColour[3]);
	// set the fog attributes
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 200.0f);
	glFogfv(GL_FOG_COLOR, fogColour);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.06f);

	// enable the fog
	//glEnable(GL_FOG);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);   //Enable lighting
	glEnable(GL_LIGHT0);     //Enable light #0
	glEnable(GL_LIGHT1);     //Enable light #1
	glEnable(GL_NORMALIZE);  //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
							 //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//Wireframe
	if (isFullscreen)
	{
		glutFullScreen();
		glutWarpPointer(770, 450);
	}
	lighting->SetPosition(0,20,0,0);
	t3dInit();
}

void update(int value)
{
	checkInput();
	playerRobot->move();

	if ((playerRobot->giveShieldStrength() <= 0.0) || (playerRobot->giveShield()<= 0))
	{
		playerRobot->setShieldTriggered(false);
	}

	bool bulletNotDead = true;
	for (int i = 0; i < plazmaBalls.size(); i++)
	{
		plazmaBalls[i]->move();
		bulletNotDead = true;
		for (int j = 0; j < enemyTanks.size() && bulletNotDead; j++) 
		{
		
			if (enemyTanks[j]->isHitBy(plazmaBalls[i])&&(plazmaBalls[i]->getType()==1))
			{
				enemyTanks[j]->damage(1);
				plazmaBalls[i]->flagAsDead();
				bulletNotDead = false;
			}
		}
		if ((plazmaBalls[i]->getType()==0) && playerRobot->isHitBy(plazmaBalls[i])) 
		{
			if (playerRobot->giveShield() > 0)
			{
				playerRobot->shieldDamage();
				playerRobot->setShieldTriggered(true);
			}
			else
			{
				playerRobot->damage(1);
			}			
			plazmaBalls[i]->flagAsDead();
			
		}
	}
	for (int i = 0; i < plazmaBalls.size(); i++)
	{
		if (plazmaBalls[i]->isDead())
		{
			delete plazmaBalls[i];
			plazmaBalls.erase(plazmaBalls.begin() + i);
		}
	}
	for (int i = 0; i < enemyTanks.size(); i++)
	{
		enemyTanks[i]->move();
		enemyTanks[i]->runAI();
	}

	for (int i = 0; i < collectables.size(); i++)
	{
		if (collectables[i]->isHitBy(collectables[i]) && (collectables[i]->getType() == 1))
		{
			collectables[i]->flagAsDead();
			playerRobot->updateScore(EnergyCollect);
		}
	}
	for (int i = 0; i < collectables.size(); i++)
	{
		if (collectables[i]->isDead())
		{
			delete collectables[i];
			collectables.erase(collectables.begin() + i);
		}
	}
	
	for (int i = 0; i < enemyTanks.size(); i++)
	{
		if (enemyTanks[i]->isDead())
		{
			collectables.push_back(new Collectable(enemyTanks[i]->givePosX(), 1, enemyTanks[i]->givePosZ(), 0, 1));
			delete enemyTanks[i];
			enemyTanks.erase(enemyTanks.begin() + i);
			numTanks--;
			playerRobot->updateScore(EnemyDestroyed);
		}
	}
	/*fogColour[0] = (1.0f - radarVisionMagnitude)*originalfogColour[0];
	fogColour[1] = (1.0f - radarVisionMagnitude)*originalfogColour[1];
	fogColour[2] = (1.0f - radarVisionMagnitude)*originalfogColour[2];*/

	lagDistance *= 0.95;
	screenShakeMagnitude *= 0.95;
	zoomMagnitude *= 0.95;

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

//Draws the 3D scene
void drawScene() 
{

	//glFogfv(GL_FOG_COLOR, fogColour);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -7.0f);
	
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
		if(plazmaBalls[i]->getType()==1) plazmaBalls[i]->drawPlazmaBall(1);
		else
		{
			plazmaBalls[i]->drawPlazmaBall(0);
		}
	}
	for (int i = 0; i < buildings.size(); i++) 
	{
		buildings[i]->drawSelf();
	}
	for (int i = 0; i < enemyTanks.size(); i++)
	{
		enemyTanks[i]->DrawTankType1();
	}
	for (int i = 0; i < collectables.size(); i++) 
	{
		collectables[i]->drawCollectable(collectables[i]->getType());
	}
	for (int i = 0; i < shieldGenerators.size(); i++)
	{
		shieldGenerators[i]->drawShield();
	}
	environment->groundFloor(mapSize);
	environment->drawStreet();
	environment->drawStreetLamp();
	

	//Creating line for gun range
	glPushMatrix();
	glTranslatef(playerRobot->givePosX(), 1.0f, playerRobot->givePosZ());
	glRotatef(playerRobot->giveRotation() + playerRobot->giveTurretRotation(), 0.0f, 1.0f, 0.0f);
	//glColor4f(0.1f, 0.7f, 1.0f, 0.2f);

	float seperation = 2.0f;

	for (int i = 1; i <= 10; i++) 
	{
		float bulletTravel = (-seperation*i);
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -seperation*i);
		glRotatef(-playerRobot->giveRotation() - playerRobot->giveTurretRotation(), 0.0f, 1.0f, 0.0f);
		glTranslatef(-playerRobot->giveSpeedX()*bulletTravel, 0.0f, -playerRobot->giveSpeedZ()*bulletTravel);
		glutSolidSphere(0.05f, 10, 10);
		glPopMatrix();
	}
	glPopMatrix();
	//done line for gun range

	environment->DrawEnvironment();	
	glutWireCube(1);
	playerRobot->DrawPlayer();	
	glPopMatrix();

	statusUI->drawPlayerStatus(playerRobot->giveHealth(),playerRobot->giveShield(),playerRobot->giveScore());

	glutSwapBuffers();
}


void handlePassiveMouse(int x, int y) {
	playerRobot->rotateTurret(0.1*(lastMouseX - x));
	lagDistance += 0.1*(lastMouseX - x);
	lastMouseX = x;
	if (x <= 2 || x >= 1355) {
		glutWarpPointer(770, 450);
		if (leftMouseDown) {
			playerFire(GLUT_LEFT_BUTTON, GLUT_DOWN, 0, 0);
			//cout << "Left mouse";
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
		cleanup();
		exit(0);
	}
	if (keyDown['w']) {
		playerRobot->accelerate(true);
		playerRobot->WalkingState(true);
		//cout << "w" << endl;
	}
	if (keyDown['s']) {
		playerRobot->accelerate(false);
		playerRobot->WalkingState(true);
		//cout << "s" << endl;
	}
	if (!keyDown['w']&& !keyDown['s']) {
		playerRobot->WalkingState(false);
	}
	if (keyDown['a']) {
		playerRobot->rotate(true);
		//cout << "a" << endl;
	}
	if (keyDown['d']) {
		playerRobot->rotate(false);
		//cout << "d" << endl;
	}
	if (keyDown[' '] || leftMouseDown)
	{
		if (playerRobot->fire()) 
		{
			
		}
	}
	
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
			//cout << "is true";
		}
		else {
			leftMouseDown = false;
		}

	}
}
void cleanup() 
{
	t3dCleanup();
}
float computeScale(const char* strs[4]) 
{
	float maxWidth = 0;
	for (int i = 0; i < 4; i++) 
	{
		float width = t3dDrawWidth(strs[i]);
		if (width > maxWidth) {
			maxWidth = width;
		}
	}

	return 2.6f / maxWidth;
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
