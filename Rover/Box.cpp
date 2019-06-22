#include "Box.h"


Box::Box(GLfloat pos[3], GLfloat w, GLfloat l, GLfloat h, GLfloat color[3]) : Solid(pos,color), width(w), length(l), height(h)
{
}

Box::~Box()
{
}

void Box::draw()
{
	double x, y, zup,zdown;
	double i, k;
	int n = 4;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3fv(color);

		x = -width / 2 + pos[0];
		y = length / 2 + pos[1];

		zup = pos[2] + height / 2;
		zdown = pos[2] - height / 2;

			for (i = 0; i <= length / n; i++)
			{
				glVertex3d(x, y, zup);
				glVertex3d(x, y, zdown);
				y -= n;
			}

		for (i = 0; i < width / n; i++)
		{
			glVertex3d(x, y, zup);
			glVertex3d(x, y, zdown);
			x += n;
		}

		for (i = 0; i <= length / n; i++)
		{
			glVertex3d(x, y, zup);
			glVertex3d(x, y, zdown);
			y += n;
		}

		for (i = 0; i <= width / n; i++)
		{
			glVertex3d(x, y, zup);
			glVertex3d(x, y, zdown);
			x -= n;
		}
		glEnd();

		x = -width / 2 + pos[0];
		y = length / 2 + pos[1];

		for (k = 0; k < width / n; k++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glColor3fv(color);

			for (i = 0; i <= (length / n) + 1; i++)
			{
				glVertex3d(x, y, zup);
				glVertex3d(x + n, y, zup);
				y -= n;
			}
			x += n;
			y = length / 2 + pos[1];
			glEnd();
		}

		x = -width / 2 + pos[0];
		y = length / 2 + pos[1];

		for (k = 0; k < width / n; k++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glColor3fv(color);

			for (i = 0; i <= (length / (float)n) + 1; i++)
			{
				glVertex3d(x, y, zdown);
				glVertex3d(x + n, y, zdown);
				y -= n;
			}
			x += n;
			y = length / 2 + pos[1];
			glEnd();
		}
	};
}
