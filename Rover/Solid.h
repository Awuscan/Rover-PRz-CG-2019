#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>
#include <corecrt_math_defines.h>

constexpr auto GL_PI = M_PI;

class Solid
{
public:
	Solid(GLfloat pos[3], GLfloat color[3]);
	~Solid();
	virtual void draw();
	virtual void move(GLfloat pos[3]);
	virtual void setColor(GLfloat color[3]);
	GLfloat pos[3];
	GLfloat color[3];
};