#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>
#include <corecrt_math_defines.h>

class CheckPoint
{
private:
	GLfloat pos[3];
	GLfloat height = 500;
	GLfloat radius = 20;
	GLfloat color[4] = { 0, 0.5, 1, 0.2};
	int visibility = 1;
public:
	CheckPoint(GLfloat pos[3]);
	~CheckPoint();
	void draw();
	void setVisibility(int visibility);
	int getVisibility() { return visibility; }
	GLfloat* getPos() { return pos; }
	GLfloat getRadius() { return radius; }
	
};

