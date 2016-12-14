#ifndef GLOBAL_VARIABLE_HEADER
#define GLOBAL_VARIABLE_HEADER

bool keyDown[256];
bool leftMouseDown = false;

bool isFullscreen = false;
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
int mapSize = 70;
bool invincibility = false;
int lastMouseX = 770;
float lagDistance = 0;
float fogColour[] = { 0.8f,0.8f,0.8f,0.0f };
float originalfogColour[] = { 0.8f,0.8f,0.8f,0.0f };

PlazmaBall* plazmaBall;
Player* playerRobot;
Environment* environment;
std::vector<PlazmaBall*> plazmaBalls;
#endif 