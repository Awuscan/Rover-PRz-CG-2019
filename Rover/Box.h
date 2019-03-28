#pragma once
#include "Solid.h"
class Box :
	public Solid
{
public:
	Box(GLfloat pos[3], GLfloat width, GLfloat length, GLfloat height);
	~Box();
	void draw();
	GLfloat width;
	GLfloat length;
	GLfloat height;
};

