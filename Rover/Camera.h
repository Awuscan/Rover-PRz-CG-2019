#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>
#include <corecrt_math_defines.h>

class Camera
{
public:
	Camera();
	~Camera();
	void update(WPARAM wParam);
	void setPosition(GLfloat position[3]);
private:
	float step = 10.0;
	GLfloat position[3] = { 0,0,50 };
	GLfloat lookAt[3] = { 0,10,50 };
	GLfloat up[3] = { 0,0,1 };
	float rotate = M_PI / 2;
};