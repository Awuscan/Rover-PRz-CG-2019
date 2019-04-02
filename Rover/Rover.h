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
	GLfloat wheelWidth = 3;
	GLfloat suspensionShaftRadius = wheelArmWidth * 1;
	GLfloat suspensionShaftLenght = wheelArmWidth * 1.3;
	GLfloat bodyColor[3] = { 0.8,0.8,0.8 };
	GLfloat wheelColor[3] = { 0.74,0.74,0.74 };
	GLfloat suspensionColor[3] = { 0.5,0.5,0.5 };
	GLfloat suspensionShaftColor[3] = { 0.4,0.4,0.4 };
	
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

	GLfloat posBody[3];

	Wheel wlf{ posWLF,wheelRadius,wheelWidth,wheelColor }; //wheel left front
	Wheel wlc{ posWLC,wheelRadius,wheelWidth,wheelColor };
	Wheel wlb{ posWLB,wheelRadius,wheelWidth,wheelColor };
	Wheel wrf{ posWRF,wheelRadius,wheelWidth,wheelColor };
	Wheel wrc{ posWRC,wheelRadius,wheelWidth,wheelColor };
	Wheel wrb{ posWRB,wheelRadius,wheelWidth,wheelColor };

	SuspensionArm  salf{ posBSLF,posWSLF,wheelArmWidth,suspensionColor }; //suspension arm left front
	SuspensionArm  salc{ posBSLB,posWSLC,wheelArmWidth,suspensionColor };
	SuspensionArm  salb{ posBSLB,posWSLB,wheelArmWidth,suspensionColor };
	SuspensionArm  sarf{ posBSRF,posWSRF,wheelArmWidth,suspensionColor };
	SuspensionArm  sarc{ posBSRB,posWSRC,wheelArmWidth,suspensionColor };
	SuspensionArm  sarb{ posBSRB,posWSRB,wheelArmWidth,suspensionColor };

	Wheel wslf{ posWSLF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor }; //suspension wheel left front
	Wheel wslc{ posWSLC,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel wslb{ posWSLB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel wsrf{ posWSRF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel wsrc{ posWSRC,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel wsrb{ posWSRB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };

	Wheel bslf{ posBSLF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel bslb{ posBSLB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel bsrf{ posBSRF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	Wheel bsrb{ posBSRB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };

	Box body{ pos,width,length,height,bodyColor }; //body
	
};

