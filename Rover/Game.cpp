#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}



void Game::draw()
{
	for (std::vector<CheckPoint*>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
		it->draw();
	}
}
void Game::check(GLfloat posx, GLfloat posy)
{
	for (std::vector<CheckPoint*>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
		GLfloat *checkPointPos = *it->getPos();
		float distance = sqrt((*(checkPointPos + 0) - posx) * (*(checkPointPos + 0) - posx) + (*(checkPointPos + 1) - posy) * (*(checkPointPos + 1) - posy));
		if (distance <= it->getRadius() + 15) {
			if (it->getVisibility() == 1)
				score++;
			it->setVisibility(0);
			
		}
	}
}

void Game::start()
{
	score = 0;
	starttime = GetTickCount();
	for (std::vector<CheckPoint*>::iterator it = checkPoints.begin(); it != checkPoints.end(); ++it) {
			it->setVisibility(1);
	}

}

void Game::add(GLfloat pos[3])
{
	auto checkPoint = CheckPoint{ pos };
	checkPoints.push_back(&checkPoint);
}
