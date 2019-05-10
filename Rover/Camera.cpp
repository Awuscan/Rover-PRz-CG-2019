#include "Camera.h"



Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::update(WPARAM wParam)
{
	if (wParam == 'W') {
		this->position[0] += step * sin(rotate);
		this->position[1] += step * cos(rotate);
		this->lookAt[0] = this->position[0] + step * sin(rotate);
		this->lookAt[1] = this->position[1] + step * cos(rotate);
	}
	if (wParam == 'S') {
		this->position[0] -= step * sin(rotate);
		this->position[1] -= step * cos(rotate);
		this->lookAt[0] = this->position[0] + 10 * sin(rotate);
		this->lookAt[1] = this->position[1] + 10 * cos(rotate);
	}
	if (wParam == 'A') {	
		this->position[0] += step * sin(rotate - M_PI / 2 );
		this->position[1] += step * cos(rotate - M_PI / 2);
		this->lookAt[0] = this->position[0] + step * sin(rotate);
		this->lookAt[1] = this->position[1] + step * cos(rotate);
	}
	if (wParam == 'D') {
		this->position[0] += step * sin(rotate + M_PI / 2);
		this->position[1] += step * cos(rotate + M_PI / 2);
		this->lookAt[0] = this->position[0] + step * sin(rotate);
		this->lookAt[1] = this->position[1] + step * cos(rotate);
	}
	if (wParam == 'Q') {
		rotate = rotate - (M_PI / 32.0);
		this->lookAt[0] = this->position[0] + step * sin(rotate);
		this->lookAt[1] = this->position[1] + step * cos(rotate);
	}	
	if (wParam == 'E') {
		rotate = rotate + (M_PI / 32.0);
		this->lookAt[0] = this->position[0] + step * sin(rotate);
		this->lookAt[1] = this->position[1] + step * cos(rotate);
	}

	glLoadIdentity();
	gluLookAt(this->position[0], this->position[1], this->position[2], this->lookAt[0], this->lookAt[1], this->lookAt[2], this->up[0], this->up[1], this->up[2]);
}

void Camera::setPosition(GLfloat position[3])
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->position[2] = position[2];
}

