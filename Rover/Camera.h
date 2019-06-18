#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <math.h>
#include <corecrt_math_defines.h>

class Camera
{
public:
	Camera(GLfloat pos[3], bool rover);
	~Camera();
	void update(WPARAM wParam);
	void update();
	void setPosition(GLfloat position[3], int angle);
private:
	bool rover;

	float stepMovement = 5.0;
	float stepRotation = M_PI / 45;

	GLfloat position[3] = { 0,0,50 };
	GLfloat lookAt[3] = { 0,1,0 };
	GLfloat up[3] = { 0,0,1 };
	float yaw = 0;
	float pitch = 0;
};