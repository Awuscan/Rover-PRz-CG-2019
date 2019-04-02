#include "Wheel.h"

Wheel::Wheel(GLfloat point[3], GLfloat r, GLfloat w, GLfloat color[3]) : Solid(point,color), radius(r), width(w)
{
}


Wheel::~Wheel()
{
}

void Wheel::draw()
{
	glPushMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		double x, y, z, alpha;
		
		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(color);
		glVertex3d(pos[0] - width / 2, pos[1], pos[2]);
		for (alpha = 0; alpha < 2 * GL_PI; alpha += GL_PI / 16.0)
		{
			y = pos[1] + radius * sin(alpha);
			z = pos[2] + radius * cos(alpha);
			glVertex3d(pos[0] - width / 2, y, z);
		}
		y = pos[1] + radius * sin(0);
		z = pos[2] + radius * cos(0);
		glVertex3d(pos[0] - width / 2, y, z);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3fv(colorSec);
		for (alpha = 0.0; alpha < 2 * GL_PI; alpha += GL_PI / 16.0)
		{
			y = radius * sin(alpha);
			z = radius * cos(alpha);
			glVertex3d(pos[0] - width / 2, y + pos[1], z + pos[2]);
			glVertex3d(pos[0] + width / 2, y + pos[1], z + pos[2]);
		}
		y = radius * sin(0);
		z = radius * cos(0);
		glVertex3d(pos[0] - width / 2, y + pos[1], z + pos[2]);
		glVertex3d(pos[0] + width / 2, y + pos[1], z + pos[2]);
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(color);
		glVertex3d(pos[0] + width / 2, pos[1], pos[2]);
		for (alpha = 0; alpha < 2 * GL_PI; alpha += GL_PI / 16.0)
		{
			y = pos[1] + radius * sin(alpha);
			z = pos[2] + radius * cos(alpha);
			glVertex3d(pos[0] + width / 2, y, z);
		}
		y = pos[1] + radius * sin(0);
		z = pos[2] + radius * cos(0);
		glVertex3d(pos[0] + width / 2, y, z);
		glEnd();



	};
	glPopMatrix();

}

void Wheel::setColor(GLfloat color[3], GLfloat colorSec[3])
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];

	this->colorSec[0] = colorSec[0];
	this->colorSec[1] = colorSec[1];
	this->colorSec[2] = colorSec[2];
}
