#include "Camera.h"

Camera::Camera(GLfloat pos[3], bool rover): rover(rover)
{
	position[0] = pos[0];
	position[1] = pos[1];
	position[2] = pos[2];
}

Camera::~Camera()
{
}

void Camera::update(WPARAM wParam)
{
	switch (wParam) {
	case 'Z':
		if(!rover)
		this->position[2] -= stepMovement;
		break;

	case 'X':
		if (!rover)
		this->position[2] += stepMovement;
		break;

	case 'W':
		if (!rover) {
			this->position[0] += stepMovement * sin(yaw) * cos(pitch);
			this->position[1] += stepMovement * cos(yaw) * cos(pitch);
			this->position[2] += stepMovement * sin(pitch);
		}
		break;

	case 'S':
		if (!rover) {
			this->position[0] -= stepMovement * sin(yaw) * cos(pitch);
			this->position[1] -= stepMovement * cos(yaw) * cos(pitch);
			this->position[2] -= stepMovement * sin(pitch);
		}
		break;

	case 'A':
		if (!rover) {
			this->position[0] += stepMovement * sin(yaw - M_PI / 2);
			this->position[1] += stepMovement * cos(yaw - M_PI / 2);
		}
		break;

	case 'D':
		if (!rover) {
			this->position[0] += stepMovement * sin(yaw + M_PI / 2);
			this->position[1] += stepMovement * cos(yaw + M_PI / 2);
		}
		break;

	case VK_LEFT:
		if (!rover) {
			yaw = (yaw - stepRotation);
			yaw = yaw - round(yaw / (2 * M_PI)) * (2 * M_PI);
			this->lookAt[0] = sin(yaw) * cos(pitch);
			this->lookAt[1] = cos(yaw) * cos(pitch);
			this->lookAt[2] = sin(pitch);
		}
		break;

	case VK_RIGHT:
		if (!rover) {
			yaw = yaw + stepRotation;
			yaw = yaw - round(yaw / (2 * M_PI)) * (2 * M_PI);
			this->lookAt[0] = sin(yaw) * cos(pitch);
			this->lookAt[1] = cos(yaw) * cos(pitch);
			this->lookAt[2] = (pitch);
		}
		break;
	
	case VK_UP:
		pitch += stepRotation;
		if (pitch >= M_PI / 2)
			pitch = M_PI / 2;
		this->lookAt[0] = sin(yaw) * cos(pitch);
		this->lookAt[1] = cos(yaw) * cos(pitch);
		this->lookAt[2] = sin(pitch);
		break;

	case VK_DOWN:
		pitch -= stepRotation;
		if (pitch <= -M_PI / 2)
			pitch = -M_PI / 2;
		this->lookAt[0] = sin(yaw) * cos(pitch);
		this->lookAt[1] = cos(yaw) * cos(pitch);
		this->lookAt[2] = sin(pitch);
		break;

	default:
		break;
	}
	
	this->update();
}

void Camera::update()
{
	glLoadIdentity();
	gluLookAt(this->position[0], this->position[1], this->position[2],
		this->position[0] + this->lookAt[0], this->position[1] + this->lookAt[1], this->position[2] + this->lookAt[2],
		this->up[0], this->up[1], this->up[2]);
}

void Camera::setPosition(GLfloat position[3], int angle)
{

	this->yaw = angle * M_PI / 180 - round(yaw / (2 * M_PI)) * (2 * M_PI);
	this->lookAt[0] = sin(yaw) * cos(pitch);
	this->lookAt[1] = cos(yaw) * cos(pitch);
	this->lookAt[2] = (pitch);

	this->position[0] = position[0] - 50 * sin(yaw) * cos(pitch);
	this->position[1] = position[1] - 50 * cos(yaw) * cos(pitch);
	this->position[2] = position[2] + 50;
}