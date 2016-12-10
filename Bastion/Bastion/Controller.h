#pragma once
#ifndef CONTROLLER_HEADER
#define CONTROLLER_HEADER
void processMouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void mouseMove(int x, int y);
int getEyeY();
int getEyeX();
bool StateWalking();
void getDirection();
float getXPosition();
float getZPosition();
#endif // !CONTROLLER_HEADER
