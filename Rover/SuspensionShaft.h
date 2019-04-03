#pragma once
#include "Solid.h"
class SuspensionShaft :
	public Solid
{
public:
	SuspensionShaft(GLfloat pos[3], GLfloat radius, GLfloat width, GLfloat color[3]);
	~SuspensionShaft();
	void draw();
	void setColor(GLfloat color[3], GLfloat colorSec[3]);
	GLfloat radius;
	GLfloat width;
	GLfloat colorSec[3] = { 0.1,0.1,0.1 };

};

