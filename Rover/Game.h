#pragma once
#include <vector>
#include <math.h>
#include <corecrt_math_defines.h>
#include <Windows.h>
#include "CheckPoint.h"
#include "Rover.h"

class Game
{
	std::vector<CheckPoint*> checkPoints;
	int score = 0;
	int starttime = 0;
	GLfloat startPos[3] = { 2000,0,0 };
public:
	Game();
	~Game();
	void draw();
	void check(GLfloat posx, GLfloat posy);
	void start();
	void add(GLfloat pos[3]);
	int getScore() { return score; }
	int getTime() { return GetTickCount() - starttime; }
};

