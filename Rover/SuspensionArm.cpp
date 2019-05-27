#include "SuspensionArm.h"

SuspensionArm::SuspensionArm(GLfloat posBody[3], GLfloat posWheel[3], GLfloat w, GLfloat color[3]) : Solid(posBody, color), width(w)
{
	this->posWheel[0] = posWheel[0];
	this->posWheel[1] = posWheel[1];
	this->posWheel[2] = posWheel[2];

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
		glColor3fv(color);
		glVertex3fv(p1);
		glVertex3fv(p2);
		glVertex3fv(p3);
		glVertex3fv(p4);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glColor3fv(color);
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
		glColor3fv(color);
		glVertex3fv(p5);
		glVertex3fv(p6);
		glVertex3fv(p7);
		glVertex3fv(p8);
		glEnd();
	};
}

void SuspensionArm::move(GLfloat posBody[3], GLfloat posWheel[3])
{
	this->pos[0] = posBody[0];
	this->pos[1] = posBody[1];
	this->pos[2] = posBody[2];
	this->posWheel[0] = posWheel[0];
	this->posWheel[1] = posWheel[1];
	this->posWheel[2] = posWheel[2];
}