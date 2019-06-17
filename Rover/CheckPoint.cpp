#include "CheckPoint.h"


CheckPoint::CheckPoint(GLfloat pos[3])
{
	this->pos[0] = pos[0];
	this->pos[1] = pos[1];
	this->pos[2] = pos[2];
}


CheckPoint::~CheckPoint()
{
}

void CheckPoint::draw()
{
	if (visibility) {
		glPushMatrix();

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		{
			double x, y, alpha;

			glBegin(GL_TRIANGLE_STRIP);
			glColor4fv(color);
			for (alpha = 0.0; alpha < 2 * M_PI; alpha += M_PI / 16.0)
			{
				x = radius * sin(alpha);
				y = radius * cos(alpha);
				glVertex3d(x + pos[0], y + pos[1], pos[2]);
				glVertex3d(x + pos[0], y + pos[1], pos[2] + height);
			}
			x = radius * sin(0);
			y = radius * cos(0);
			glVertex3d(x + pos[0], y + pos[1], pos[2]);
			glVertex3d(x + pos[0], y + pos[1], pos[2] + height);
			glEnd();
		};
		glPopMatrix();
	}
}

void CheckPoint::setVisibility(int visibility)
{
	this->visibility = visibility;
}
