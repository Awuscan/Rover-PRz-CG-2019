#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library

class Camera
{
public:
	Camera();
	~Camera();
	GLfloat eye[3] = {};
	GLfloat center[3] = { 0,0,0 };
	GLfloat up[3];
	

};

