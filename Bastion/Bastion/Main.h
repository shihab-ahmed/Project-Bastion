#ifndef _MAIN_H
#define _MAIN_H
#include "Player.h"
#include "Definition.h"
#include "Environment.h"
#include "EnemyTank.h"
#include "Building.h"
#include "CollisionDetection.h"
#include "Lighting.h"
#include "Collectable.h"
#include "StatusUI.h"
void handleKeypress(unsigned char key, int x, int y);
void handleResize(int w, int h);
void handlePassiveMouse(int x, int y);
void handleActiveMouse(int x, int y);
void handleResize(int w, int h);
void initRendering();
void drawScene();
void update(int value);
int main(int argc, char** argv);
void handleKeyUp(unsigned char key, int x, int y);
void checkInput();
void playerFire(int button, int state, int x, int y);
void addBuilding();
void addEnemyTank();
void cleanup();
float computeScale(const char* strs[4]);
void drawUI();
#endif





