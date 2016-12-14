#ifndef _MAIN_H
#define _MAIN_H
#include "Player.h"
#include "Definition.h"
#include "Environment.h"
#include "EnemyTank.h"
void handleKeypress(unsigned char key, int x, int y);
void handleResize(int w, int h);
void handlePassiveMouse(int x, int y);
void handleActiveMouse(int x, int y);
void handleResize(int w, int h);
void initRendering();
void drawScene();
void renderBitmapString(float x, float y, float z, void *font, char *string);
void update(int value);
int main(int argc, char** argv);
void handleKeyUp(unsigned char key, int x, int y);
void checkInput();
void playerFire(int button, int state, int x, int y);
//Environment* environment;
//void handleKeyUp(unsigned char key, int x, int y);
#endif





