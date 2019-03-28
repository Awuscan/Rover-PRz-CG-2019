#pragma once
#include "Solid.h"
#include "Box.h"
#include "SuspensionArm.h"
#include "Wheel.h"


class Rover :
	public Solid
{
public:
	Rover(GLfloat pos[3]);
	~Rover();
	void draw();
	GLfloat width = 20;
	GLfloat length = 30;
	GLfloat height = 5;
	GLfloat wheelArmWidth = 1;
	GLfloat rideHeigth = 12;
	GLfloat wheelRadius = 50;
	GLfloat wheelWidth = 10;
	GLfloat suspensionShaft = wheelArmWidth * 1.3;

	GLfloat posWFL[3]; // wheel left front 
	GLfloat posWLC[3];
	GLfloat posWLB[3];
	GLfloat posWRF[3];
	GLfloat posWRC[3];
	GLfloat posWRB[3];

	GLfloat posBSLF[3]; // body suspension left front
	GLfloat posBSLB[3];
	GLfloat posBSRF[3];
	GLfloat posBSRB[3];

	GLfloat posWSLF[3]; // wheel suspension left front 
	GLfloat posWSLC[3];
	GLfloat posWSLB[3];
	GLfloat posWSRF[3];
	GLfloat posWSRC[3];
	GLfloat posWSRB[3]; 
};

