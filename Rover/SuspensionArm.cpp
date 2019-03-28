#include "SuspensionArm.h"

SuspensionArm::SuspensionArm(GLfloat pointBody[3], GLfloat pointWheel[3], GLfloat w) : Solid(pointBody), width(w)
{
	posWheel[0] = pointWheel[0];
	posWheel[1] = pointWheel[1];
	posWheel[2] = pointWheel[2];
}

SuspensionArm::~SuspensionArm()
{
}

void SuspensionArm::draw()
{
	GLfloat p1[3] = { pos[0] - width / 2,pos[1] - width / 2,pos[2] };
	GLfloat p2[3] = { pos[0] - width / 2,pos[1] + width / 2,pos[2] };
	GLfloat p3[3] = { pos[0] + width / 2,pos[1] - width / 2,pos[2] };
	GLfloat p4[3] = { pos[0] + width / 2,pos[1] + width / 2,pos[2] };

	GLfloat p5[3] = { posWheel[0] - width / 2,posWheel[1] - width / 2,posWheel[2] };
	GLfloat p6[3] = { posWheel[0] - width / 2,posWheel[1] + width / 2,posWheel[2] };
	GLfloat p7[3] = { posWheel[0] + width / 2,posWheel[1] - width / 2,posWheel[2] };
	GLfloat p8[3] = { posWheel[0] + width / 2,posWheel[1] + width / 2,posWheel[2] };

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3fv(p1);
		glVertex3fv(p2);
		glVertex3fv(p3);
		glVertex3fv(p4);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3fv(p1);
		glVertex3fv(p5);
		glVertex3fv(p3);
		glVertex3fv(p7);
		glVertex3fv(p4);
		glVertex3fv(p8);
		glVertex3fv(p2);
		glVertex3fv(p6);
		glVertex3fv(p1);
		glVertex3fv(p5);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3d(0.5, 0.5, 0.5);
		glVertex3fv(p5);
		glVertex3fv(p6);
		glVertex3fv(p7);
		glVertex3fv(p8);
		glEnd();

	};
}
