#include "GameStatus.h"



GameStatus::GameStatus()
{
	this->Stage = 1;
	this->isGameOver = false;
	this->isPlayerWin = false;
}
void GameStatus::setStage(int stage)
{
	this->Stage = stage;
}
void GameStatus::setIsGameOver(bool state)
{
	this->isGameOver = state;
}
void GameStatus::setIsPlayerWin(bool state)
{
	this->isPlayerWin = state;
}
int GameStatus::getStage()
{
	return this->Stage;
}
bool GameStatus::getIsGameOver()
{
	return this->isGameOver;
}
bool GameStatus::getIsPlayerWin()
{
	return this->isPlayerWin;
}
GameStatus::~GameStatus()
{
}
