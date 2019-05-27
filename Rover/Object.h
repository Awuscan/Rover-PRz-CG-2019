#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include "objLoader.h"
#include <string>

class Object
{
public:
	Object(std::string file, GLfloat color[3], GLfloat pos[3], GLfloat rot[4], GLfloat scale);
	~Object();
	void draw();
private:
	GLfloat pos[3];
	GLfloat color[3];
	GLfloat rot[4];
	GLfloat scale;
	objl::Loader floor;
	objl::Mesh curMesh;
	std::string file;
};