#include "Solid.h"

Solid::Solid(GLfloat point [3])
{
	pos[0] = point[0];
	pos[1] = point[1];
	pos[2] = point[2];
}

Solid::~Solid()
{
}

void Solid::draw()
{
}

void Solid::move(GLfloat pos[3])
{
	this->pos[0] = pos[0];
	this->pos[1] = pos[1];
	this->pos[2] = pos[2];
}
