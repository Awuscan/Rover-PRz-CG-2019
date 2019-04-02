#pragma once
#include "Solid.h"
class Box :
	public Solid
{
public:
	Box(GLfloat pos[3], GLfloat width, GLfloat length, GLfloat height, GLfloat color[3]);
	~Box();
	void draw();
	GLfloat width;
	GLfloat length;
	GLfloat height;
};

