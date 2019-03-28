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
	GLfloat height = 10;
	GLfloat wheelArmWidth = 2;
	GLfloat rideHeigth = 12;
	GLfloat wheelRadius = 5;
	GLfloat wheelWidth = 2;
	GLfloat suspensionShaftRadius = wheelArmWidth * 1;
	GLfloat suspensionShaftLenght = wheelArmWidth * 1.3;
	/*
	GLfloat posWLF[3]; // wheel left front 
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

	Wheel wlf{ pos,wheelRadius,wheelWidth }; //wheel left front
	Wheel wlc{ pos,wheelRadius,wheelWidth };
	Wheel wlb{ pos,wheelRadius,wheelWidth };
	Wheel wrf{ pos,wheelRadius,wheelWidth };
	Wheel wrc{ pos,wheelRadius,wheelWidth };
	Wheel wrb{ pos,wheelRadius,wheelWidth };

	SuspensionArm  salf{ posBSLF, posWSLF, wheelArmWidth }; //suspension arm left front
	SuspensionArm  salc{ posBSLB, posWSLC, wheelArmWidth };
	SuspensionArm  salb{ posBSLB, posWSLB, wheelArmWidth };
	SuspensionArm  sarf{ posBSRF, posWSRF, wheelArmWidth };
	SuspensionArm  sarc{ posBSRB, posWSRC, wheelArmWidth };
	SuspensionArm  sarb{ posBSRB, posWSRB, wheelArmWidth };

	Box body{ pos,width,length,height }; //body
	*/
};

