#include "Game.h"

Game::Game()
{
	checkPoints.push_back(C1);
	checkPoints.push_back(C2);
	checkPoints.push_back(C3);
	checkPoints.push_back(C4);
	checkPoints.push_back(C5);
}


Game::~Game()
{
}

void Game::draw()
{
	for (std::vector<CheckPoint>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
		it->draw();
	}
}
void Game::check(GLfloat posx, GLfloat posy)
{
	if (score != 5) {
		lasttime = GetTickCount();
		for (std::vector<CheckPoint>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
			GLfloat checkPointPosX = it->getPosX();
			GLfloat checkPointPosY = it->getPosY();
			float distance = sqrt((checkPointPosX - posx) * (checkPointPosX - posx) + (checkPointPosY - posy) * (checkPointPosY - posy));
			if (distance <= it->getRadius() + 15) {
				if (it->getVisibility() == 1) {
					score++;
					engine->play2D("point.mp3", false);
					if (score == 5) {
						engine->play2D("success.mp3", false);
					}
				}
					
				it->setVisibility(0);
			}
		}
	}
}

void Game::start()
{
	score = 0;
	starttime = GetTickCount();
	for (std::vector<CheckPoint>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
			it->setVisibility(1);
	}
	engine->play2D("start.mp3", false);
}
