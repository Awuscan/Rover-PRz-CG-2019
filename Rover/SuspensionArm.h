#pragma once
#include "Solid.h"
class SuspensionArm :
	public Solid
{
public:
	SuspensionArm(GLfloat posBody[3], GLfloat posWheel[3], GLfloat width, GLfloat color[3]);
	~SuspensionArm();
	void draw();
	void move(GLfloat posBody[3], GLfloat posWheel[3]);
	GLfloat posWheel[3];
	GLfloat width;
};

