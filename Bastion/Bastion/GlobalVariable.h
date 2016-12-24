#ifndef GLOBAL_VARIABLE_HEADER
#define GLOBAL_VARIABLE_HEADER

bool keyDown[256];
bool leftMouseDown = false;

bool isFullscreen = false;
float EnergyCollect = 5;
float EnemyDestroyed = 10;
float bulletSpeed = 0.5f;
float bulletSpeedOriginal = 0.5f;
int playerHealth = 10;
float screenShakeMagnitude = 0.0f;
float zoomMagnitude = 0.0f;
int screenWidth = 0, screenHeight = 0;
int numTanks = 10;
int numObstacles = 20;
float radarVisionMagnitude = 0;
bool radarVisionActivated = false;
bool slowMotionActivated = false;
float slowMotionMagnitude = 0;
int slowMotionCounter = 0;
float slowMotionDuration = 20.0f;
int mapSize = 80;
int worldSize = 100;
bool invincibility = false;
int lastMouseX = 770;
float lagDistance = 0;
float fogColour[] = { 0.9f,0.92f,1.0f ,1};
float originalfogColour[] = { 0.1f,0.6f,0.9f,0.0f };

float playerOpeningPosX = 0;
float playerOpeningPosZ = 135;
float playerGamePosX = 0;
float playerGamePosZ = 0;
float playerWinPosX = 0;
float playerWinPosZ = 0;

GLuint displayListID;

PlazmaBall* plazmaBall;
Player* playerRobot;
Environment* environment;
Lighting* lighting;
StatusUI* statusUI;
GameStatus* gameStatus;
Animation* animation;
std::vector<PlazmaBall*> plazmaBalls;
std::vector<Collectable*> collectables;
std::vector<Building*> buildings;
std::vector<EnemyTank*> enemyTanks;
std::vector<ShieldGenerator*> shieldGenerators;
std::vector<StatusUI*> statusUIs;
#endif 