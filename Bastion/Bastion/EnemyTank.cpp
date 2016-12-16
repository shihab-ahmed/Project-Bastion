#include "EnemyTank.h"
#include "Globals.h"
#include "CollisionDetection.h"
using namespace std;

EnemyTank::EnemyTank(float positionX, float positionZ, float initialRotation)
{
	//this->player = player;
	this->height = 3;
	this->width = 3;
	this->depth = 3;

	this->isWalking = true;
	this->speed = 0.0f;
	this->posX = positionX;
	this->posZ = positionZ;
	this->rotation = initialRotation;
	this->originalRotation = initialRotation;
	this->rotationSpeed = 0.0f;
	this->turretRotation = 0.0f;
	this->turretRotationSpeed = 0.0f;
	this->health = 3;
	this->reloadTime = 100;
	this->reloadCounter = this->reloadTime;
	this->canSeePlayer = false;
	this->sightRange = 23.0f;
	this->sightCounter = 0;
	this->isAimed = false;
	this->destinX = positionX;
	this->destinZ = positionZ;
	this->atDestination = true;
	this->recoilStrength = 0.7f;
	this->recoilDistance = 0.0f;
	this->curRecoilForce = 0.0f;
	this->lastSightingX = positionX;
	this->lastSightingZ = positionZ;
	this->boostSpeed = 0;
	this->boostPower = 0.02f;
	this->shieldStrength = 0;
	this->shieldOpacity = 0.0f;
}


EnemyTank::~EnemyTank()
{
}
void TankBody() {
	glPushMatrix();
	glScalef(1,.7,.7);
	//Body Middle
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glScalef(3, 1.4, 3);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.73,-.03,0);
	glRotatef(-20, 0, 0, 1);
	glPushMatrix();
	glScalef(.5, 1.2, 3);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.65, 0, 0);
	glRotatef(-35, 0, 0, 1);
	glPushMatrix();
	glScalef(.5, 1.4, 3);
	glutSolidCube(.5);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

}

void EnemyTank::TankTire() {

	//Front Right
	glPushMatrix();
	glTranslatef(-.7, -.35, -1.25);
	glRotatef(this->wheelRotation, 0, 0, 1);
	glScalef(1.8, 1.8, 2);
	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	//Front Left
	glPushMatrix();
	glTranslatef(-.7, -.35, 1.25);
	glRotatef(this->wheelRotation, 0, 0, 1);
	glScalef(1.8, 1.8, 2);

	glPushMatrix();
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(3, .3, 1);
	glPushMatrix();
	glutSolidCube(.1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void TankFireSystem() {
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glPushMatrix();
	glTranslatef(0, -.05, 0);
	//For Rotation and Fitting With Body
	glPushMatrix();
	glTranslatef(0, .75, 0);
	glRotatef(90, 0, 1, 0);
	//Box
	glPushMatrix();
	glScalef(2, 1.2, 3);
	glutSolidCube(.2);
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(0, .05, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(0, -.05, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(.05, 0, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Cylinder
	glPushMatrix();
	glTranslatef(-.05, 0, 0);
	glScalef(1, 1, 32);
	glPushMatrix();
	glScalef(.04, .04, .04);
	gluCylinder(quadratic, .5, .5, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	//Rings
	glPushMatrix();
	glTranslatef(0, 0, 1.22);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 1.18);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, .9);
	glScalef(.77, .77, .5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, .33);
	glScalef(.77, .77, 5);
	glPushMatrix();
	glutSolidTorus(.006, .1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}


void TankBodyFireJoin() {
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	//Circle join
	glPushMatrix();
	glTranslatef(0, .45, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1.5, 1.5, 1.5);
	glutSolidTorus(.06, .2, 25, 25);
	glPopMatrix();

	//Cylinder join
	glPushMatrix();
	glTranslatef(0, .65, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, .14, .14, .2, 25, 25);
	glPopMatrix();
}
void Turret()
{
	glPushMatrix();
	glTranslatef(0,-.05,0);
	glScalef(.8,.8,.8);
	TankBodyFireJoin();
	TankFireSystem();
	glPopMatrix();
}
bool EnemyTank::canMoveTo(float newX, float newZ)
{
	if (newX > mapSize - 1.0f || newX < -mapSize + 1.0f || newZ > mapSize - 1.0f || newZ < -mapSize + 1.0f) {

		return false;
	}
	for (int i = 0; i < buildings.size(); i++) {
		if (distanceBetween(newX, newZ, buildings[i]->givePosX(), buildings[i]->givePosZ()) < 2) {
			return false;
		}
	}
	
	return true;
}
void EnemyTank::move() {
	this->speedX = -(this->speed) * sin(this->rotation * PI / 180);
	this->speedZ = -(this->speed) * cos(this->rotation * PI / 180);

	//cout << "X" << posX << " Z" << posZ << endl;
	if (this->canMoveTo(this->posX + this->speedX , this->posZ)) {
		this->posX += this->speedX;
	
	}
	else {
		this->speedX *= 0.5f;
		this->rotation += 90;
		if (this->rotation >= 360)
		{
			this->rotation = 0;
		}
		//cout << "Rot:" << rotation << endl;
		
	}
	if (this->canMoveTo(this->posX, this->posZ + this->speedZ)) {
		this->posZ += this->speedZ;
	}
	else {
		this->speedZ *= 0.5f;
		this->rotation += 90;
		if (this->rotation >= 360)
		{
			this->rotation = 0;
		}
		//cout << "Rot:" << rotation << endl;
	}

	this->reloadCounter -= 1;
	this->rotation += this->rotationSpeed;
	this->turretRotation -= this->rotationSpeed;
	this->turretRotation += this->turretRotationSpeed;
	this->turretRotationSpeed *= 0.5f;
	this->rotationSpeed *= 0.5f;
	this->speed *= 0.8f;
	this->boostSpeed *= 0.8f;
	/*if (this->rotation > 360.0f) {
		this->rotation -= 360.0f;
	}
	else if (this->rotation < -360.0f) {
		this->rotation += 360.0f;
	}
	if (this->turretRotation > 360.0f) {
		this->turretRotation -= 360.0f;
	}
	else if (this->turretRotation < -360.0f) {
		this->turretRotation += 360.0f;
	}
	this->reloadCounter -= 1;
	this->shieldOpacity *= 0.95f;*/
}
void EnemyTank::rotateTurret(float amount) {
	this->turretRotationSpeed += amount;
	if (this->turretRotation > 180) {
		this->turretRotation -= 360;
	}
	else if (this->turretRotation < -180) {
		this->turretRotation += 360;
	}
}
void EnemyTank::turnTurretToward(float newAngle) {
	this->isAimed = false;
	float curAngle = this->rotation + this->turretRotation;
	if (curAngle > 180) {
		curAngle -= 360;
	}
	else if (curAngle < -180) {
		curAngle += 360;
	}
	if (curAngle > 90 && newAngle < -90) {
		newAngle += 360;
	}
	else if (curAngle < -90 && newAngle > 90) {
		newAngle -= 360;
	}
	if (curAngle < newAngle) {
		if (newAngle - curAngle >= 1.0f) {
			this->rotateTurret(1.0f);
		}
		else {
			this->rotateTurret(newAngle - curAngle);
			this->isAimed = true;
		}
	}
	else if (curAngle > newAngle) {
		if (newAngle - curAngle <= -1.0f) {
			this->rotateTurret(-1.0f);
		}
		else {
			this->rotateTurret(newAngle - curAngle);
			this->isAimed = true;
		}
	}
}
bool EnemyTank::fire() {
	cout << "fired" << endl;
	if (this->reloadCounter <= 0) 
	{
		float angle = this->rotation + this->turretRotation;
		plazmaBalls.push_back(new PlazmaBall(this->posX - 1.0*sin(angle * PI / 180),
			0.65f,
			this->posZ - 1.0*cos(angle * PI / 180), this->speedX, this->speedZ,
			angle
		));
		this->reloadCounter = this->reloadTime;
		//cout << "fired" << endl;
		return true;
	}
	return false;
}
void EnemyTank::runAI() 
{
	float dist = distanceBetween(this->givePosX(), this->givePosZ(), playerRobot->givePosX(), playerRobot->givePosZ());
	//cout << "Dest:" << dist << endl;
	this->sightCounter -= 1;

	if (dist < this->sightRange) {
		this->sightCounter = 10;
		this->canSeePlayer = true;
	}
	else {
		if (this->sightCounter < 0) {
			this->canSeePlayer = false;
			this->destinX = this->lastSightingX;
			this->destinZ = this->lastSightingZ;
			//cout << "last seen:" << destinX <<" Last seen Y:"<<destinZ<< endl;
		}
	}
	
	if (this->canSeePlayer) {
		float bulletCyclesToTarget = dist / bulletSpeed;
		float pX = playerRobot->givePosX() - bulletCyclesToTarget*(playerRobot->giveSpeed())*sin(playerRobot->giveRotation()*PI / 180) - bulletCyclesToTarget*this->speedX;
		float pZ = playerRobot->givePosZ() - bulletCyclesToTarget*(playerRobot->giveSpeed())*cos(playerRobot->giveRotation()*PI / 180) - bulletCyclesToTarget*this->speedZ;
		this->turnTurretToward(this->angleTo(pX, pZ));
		if (this->isAimed) {
			this->fire();
			cout << "fire" << endl;
		}
		this->lastSightingX = playerRobot->givePosX();
		this->lastSightingZ = playerRobot->givePosZ();
	}
	else {
	}

	if (distanceBetween(this->posX, this->posZ, this->destinX, this->destinZ) > 20.0f) {
		this->atDestination = false;
	}
	else {
		this->atDestination = true;
	}


	//if (!(rand() % 30) && this->canSeePlayer) {
	//	this->destinX += rand() % 20 - 10;
	//	this->destinZ += rand() % 20 - 10;
	//}

	if (this->canSeePlayer) {
		this->WalkingState(false);
	}
	else
	{
		this->turretRotation = rotation;
		//cout << "OR:" << this->turretRotation <<"RR:" <<this->rotation<<endl;
		this->WalkingState(true);
		this->accelerate(true);
	}

}
void EnemyTank::rotate(bool directionIsPositive) {
	this->rotationSpeed *= 0.01f;
	if (directionIsPositive) {
		this->rotationSpeed += 10.5;
	}
	else {
		this->rotationSpeed -= 10.5;
	}

}
void EnemyTank::accelerate(bool directionIsForward) 
{
	if (directionIsForward) {
		this->speed += 0.05;
	}
	else {
		this->speed -= 0.05;
	}
}
void EnemyTank::turnToward(float newAngle) {
	float curAngle = this->rotation;
	if (curAngle > 180) {
		curAngle -= 360;
	}
	else if (curAngle < -180) {
		curAngle += 360;
	}
	if (curAngle > 90 && newAngle < -90) {
		newAngle += 360;
	}
	else if (curAngle < -90 && newAngle > 90) {
		newAngle -= 360;
	}
	if (curAngle < newAngle) {
		if (newAngle - curAngle >= 3.5f) {
			this->rotate(true);
		}
	}
	else if (curAngle > newAngle) {
		if (newAngle - curAngle <= -3.5f) {
			this->rotate(false);
		}
	}
}
float EnemyTank::angleTo(float x, float z) {
	float deltaX = x - this->posX;

	float deltaZ = z - this->posZ;
	if (deltaX >= 0 && deltaZ >= 0) {
		return -180 + ((atan(deltaX / deltaZ)) * 180 / PI);
	}
	else if (deltaX >= 0 && deltaZ < 0) {
		return (atan(deltaX / deltaZ) * 180 / PI);
	}
	else if (deltaX < 0 && deltaZ >= 0) {
		return 180 + ((atan(deltaX / deltaZ)) * 180 / PI);
	}
	else /* (deltaX < 0 && deltaZ < 0) */ {
		return ((atan(deltaX / deltaZ)) * 180 / PI);
	}
	return 0;
}
float EnemyTank::getWheelRotation()
{

	if (this->isWalking)
	{
		//cout << "Rotation" << this->wheelRotation << endl;
		this->wheelRotation -= 8.0f;
			if (this->wheelRotation <-360)
			{
				this->wheelRotation = 0;
			}		

	}
	else
	{
		this->wheelRotation = 0;
	}
	return this->wheelRotation;
}
void EnemyTank::damage(int amount) {
	this->health -= amount;
}
bool EnemyTank::isHitBy(PlazmaBall* theBullet) {
	float x = theBullet->givePosX() - this->givePosX();
	float z = theBullet->givePosZ() - this->givePosZ();
	return x*x + z*z < (this->width * 1)*(this->width * 1);
}
void EnemyTank::WalkingState(bool isWalk)
{
	this->isWalking = isWalk;

}
float EnemyTank::playerWidth() {
	return width;
}
float EnemyTank::PlayerHeight() {
	return height;
}
float EnemyTank::PlayerDepth() {
	return depth;
}
bool EnemyTank::isDead() {
	return this->health <= 0;
}

float EnemyTank::givePosX() {
	return this->posX;
}

float EnemyTank::givePosZ() {
	return this->posZ;
}

float EnemyTank::giveSpeedX() {
	return this->speedX;
}

float EnemyTank::giveSpeedZ() {
	return this->speedZ;
}

float EnemyTank::giveRotation() {
	return this->rotation;
}

float EnemyTank::giveRotationSpeed() {
	return this->rotationSpeed;
}

float EnemyTank::giveTurretRotation() {
	return this->turretRotation;
}

float EnemyTank::giveTurretRotationSpeed() {
	return this->turretRotationSpeed;
}

float EnemyTank::giveHealth() {
	return this->health;
}

void EnemyTank::DrawTankType1()
{
	this->getWheelRotation();
	glPushMatrix();//Animate and config push
	glTranslatef(this->posX, 0.0f, this->posZ);
	glRotatef(this->rotation, 0.0f, 1.0f, 0.0f);
	glScalef(width,height,depth);

	glPushMatrix();//final push
	glTranslatef(-.05,-.1,0);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glScalef(.6,.6,.6);
	glPushMatrix();
	TankBody();
	glPopMatrix();


	glPushMatrix();
	glRotatef(this->turretRotation, 0.0f, 1.0f, 0.0f);
	Turret();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1,0,0);
	glScalef(.45,.45,.45);
	TankTire();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.58, 0, 0);
	glScalef(.45, .45, .45);
	TankTire();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.17, 0, 0);
	glScalef(.45, .45, .45);
	TankTire();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.25, 0, 0);
	glScalef(.45, .45, .45);
	TankTire();
	glPopMatrix();

	
	glPopMatrix();//final pop

	glPopMatrix();//animate and config pop
}