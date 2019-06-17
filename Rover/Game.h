#pragma once
#pragma comment(lib, "irrKlang.lib")
#include "..\irrKlang\include\irrKlang.h"
#include <vector>
#include <math.h>
#include <corecrt_math_defines.h>
#include <Windows.h>
#include "CheckPoint.h"
#include "Rover.h"

class Game
{
	int score = 0;
	int starttime = 0;
	int lasttime = 0;
	int time = 0;

	irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

	std::vector<CheckPoint> checkPoints;
	GLfloat startPos[3] = { 2000,0,0 };
	GLfloat posC1[3] = { 2000,150,0 };
	GLfloat posC2[3] = { 1000,0,0 };
	GLfloat posC3[3] = { 0,200,0 };
	GLfloat posC4[3] = { -1000,0,0 };
	GLfloat posC5[3] = { -2000,0,0 };

	CheckPoint C1 = CheckPoint(posC1);
	CheckPoint C2 = CheckPoint(posC2);
	CheckPoint C3 = CheckPoint(posC3);
	CheckPoint C4 = CheckPoint(posC4);
	CheckPoint C5 = CheckPoint(posC5);

public:
	Game();
	~Game();

	void draw();
	void check(GLfloat posx, GLfloat posy);
	void start();
	int *getScore() { return &score; }
	int *getTime() { time = lasttime - starttime; return &time; }

};

