#include "GameStatus.h"



GameStatus::GameStatus()
{
	this->Stage = 1;
	this->isAnimation = false;
	this->isGameOver = false;
	this->isPlayerWin = false;
	this->isWinAnimation = false;
	this->isLostAnimation = false;
	this->isOpeningAnimation = false;
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
void GameStatus::setIsOpeningAnimation(bool state)
{
	this->isOpeningAnimation = state;
	this->isAnimation = state;
}
void GameStatus::setIsLostAnimation(bool state)
{
	this->isLostAnimation = state;
	this->isAnimation = state;
}
void GameStatus::setIsWinAnimation(bool state)
{
	this->isWinAnimation = state;
	this->isAnimation = state;
}
void GameStatus::setAnimation(bool state)
{
	this->isAnimation = state;
}
int GameStatus::getStage()
{
	return this->Stage;
}
bool GameStatus::getAnimation()
{
	return this->isAnimation;
}
bool GameStatus::getIsGameOver()
{
	return this->isGameOver;
}
bool GameStatus::getIsPlayerWin()
{
	return this->isPlayerWin;
}
bool GameStatus::getIsOpeningAnimation()
{
	return this->isOpeningAnimation;
}
bool GameStatus::getIsLostAnimation()
{
	return this->isLostAnimation;
}
bool GameStatus::getIsWinAnimation()
{
	return this->isPlayerWin;
}
GameStatus::~GameStatus()
{
}
