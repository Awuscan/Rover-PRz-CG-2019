#include "Solid.h"

Solid::Solid(GLfloat pos [3], GLfloat color[3])
{
	move(pos);
	setColor(color);
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

void Solid::setColor(GLfloat color[3])
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}
