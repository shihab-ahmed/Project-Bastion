#include "Definition.h"
#include "Player.h"
#include "PlazmaBall.h"
#include "Environment.h"
#include "EnemyTank.h"
#include "Building.h"
#include "Lighting.h"
#include "Collectable.h"
#include "text3d.h"
#include "StatusUI.h"
#include "ShieldGenerator.h"
//extern bool keyDown[256];
//extern bool leftMouseDown;
//
//extern bool isFullscreen;
extern float bulletSpeed;
extern float bulletSpeedOriginal;
//extern int playerHealth;
//
//extern float screenShakeMagnitude;
//extern float zoomMagnitude;
//extern int screenWidth, screenHeight;
//extern int numTanks;
//extern int numObstacles;
//extern float radarVisionMagnitude;
//extern bool radarVisionActivated;
//extern bool invincibility;
//
//extern bool slowMotionActivated;
//extern float slowMotionMagnitude;
//extern int slowMotionCounter;
//extern float slowMotionDuration;

extern int mapSize;

//extern int lastMouseX;
//extern float lagDistance;

extern Environment* environment;
extern PlazmaBall* plazmaBall;
extern Player* playerRobot;
extern Lighting* lighting;
extern StatusUI* statusUI;

extern std::vector<PlazmaBall*> plazmaBalls;
extern std::vector<Collectable*> collectables;
extern std::vector<Building*> buildings;
extern std::vector<EnemyTank*> enemyTanks;
extern std::vector<ShieldGenerator*> shieldGenerators;

extern float fogColour[];
extern float originalfogColour[];
