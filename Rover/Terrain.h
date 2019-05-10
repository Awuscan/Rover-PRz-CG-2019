#pragma once
#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include "objLoader.h"

class Terrain
{
public:
	Terrain(unsigned int texID);
	~Terrain();
public:
	objl::Loader floor;
};