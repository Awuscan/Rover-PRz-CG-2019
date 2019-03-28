#pragma once
#include "Solid.h"
class SuspensionArm :
	public Solid
{
public:
	SuspensionArm(GLfloat pointBody[3], GLfloat pointWheel[3], GLfloat width);
	~SuspensionArm();
	void draw();
	GLfloat posWheel[3];
	GLfloat width;
};

