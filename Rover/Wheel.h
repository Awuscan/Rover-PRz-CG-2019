#pragma once
#include "Solid.h"
class Wheel :
	public Solid
{
public:
	Wheel(GLfloat pos[3], GLfloat radius, GLfloat width);
	~Wheel();
	void draw();
	GLfloat radius;
	GLfloat width;
};

