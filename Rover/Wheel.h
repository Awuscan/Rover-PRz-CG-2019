#pragma once
#include "Solid.h"
class Wheel :
	public Solid
{
public:
	Wheel(GLfloat pos[3], GLfloat radius, GLfloat width, GLfloat color[3]);
	~Wheel();
	void draw();
	void setColor(GLfloat color[3], GLfloat colorSec[3]);
	GLfloat radius;
	GLfloat width;
	GLfloat colorSec[3] = { 0.1,0.1,0.1 };

};

