#include "Wheel.h"

Wheel::Wheel(GLfloat point[3], GLfloat r, GLfloat w) : Solid(point), radius(r), width(w)
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
		glColor3d(0.8, 0.0, 0);
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
		glColor3d(0.0, 0.8, 0);
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
		glColor3d(0.8, 0.0, 0);
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
