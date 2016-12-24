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
#include "GameStatus.h"
#include "Animation.h"
extern float bulletSpeed;
extern float bulletSpeedOriginal;
extern int mapSize;
extern int worldSize;
extern float lagDistance;
extern float playerOpeningPosX;
extern float playerOpeningPosZ;
extern float playerGamePosX;
extern float playerGamePosZ;
extern float playerWinPosX;
extern float playerWinPosZ;

extern Environment* environment;
extern PlazmaBall* plazmaBall;
extern Player* playerRobot;
extern Lighting* lighting;
extern StatusUI* statusUI;
extern GameStatus* gameStatus;
extern Animation* animation;
extern std::vector<PlazmaBall*> plazmaBalls;
extern std::vector<Collectable*> collectables;
extern std::vector<Building*> buildings;
extern std::vector<EnemyTank*> enemyTanks;
extern std::vector<ShieldGenerator*> shieldGenerators;
extern std::vector<StatusUI*> statusUIs;

extern float fogColour[];
extern float originalfogColour[];
