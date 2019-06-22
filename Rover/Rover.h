#pragma once
#include "Solid.h"
#include "Box.h"
#include "SuspensionArm.h"
#include "Wheel.h"
#include "SuspensionShaft.h"

class Rover :
	public Solid
{
public:
	Rover(GLfloat pos[3]);
	~Rover();
	void draw();
	void drawWheels();
	void drawSusp();
	void drawBody();
	void move(GLfloat pos[3]);
	void move(GLfloat pos[3], int alfa);
	void move(GLfloat pos[3], int alfa, int alfaTarget);

	void update(WPARAM wParam);
	void update();
	int* getVelocity() { return &velocity; }
	int getAlfa() { return alfa; }
	GLfloat getPosx() { return pos[0]; }
	GLfloat getPosy() { return pos[1]; }
	GLfloat getPosz() { return pos[2]; }
	void collision();

private:
	GLfloat width = 20;
	GLfloat length = 30;
	GLfloat height = 10;
	GLfloat wheelArmWidth = 2;
	GLfloat rideHeigth = 12;
	GLfloat wheelRadius = 5;
	GLfloat wheelWidth = 3;
	GLfloat suspensionShaftRadius = wheelArmWidth * 1;
	GLfloat suspensionShaftLenght = wheelArmWidth * 1.3;
	GLfloat bodyColor[3] = { 0.5,0.8,0.5 };
	GLfloat wheelColor[3] = { 0.74,0.74,0.74 };
	GLfloat suspensionColor[3] = { 0.5,0.5,0.5 };
	GLfloat suspensionShaftColor[3] = { 0.4,0.4,0.4 };

	int velocity = 0;
	int velocityTarget = 0;

	int alfa = 0;
	int alfaTarget = 0;

	int constVelocity = 5;

	int momentum = 1;
	int velocityMax = 15;

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

	SuspensionArm salf{ posBSLF,posWSLF,wheelArmWidth,suspensionColor }; //suspension arm left front
	SuspensionArm salc{ posBSLB,posWSLC,wheelArmWidth,suspensionColor };
	SuspensionArm salb{ posBSLB,posWSLB,wheelArmWidth,suspensionColor };
	SuspensionArm sarf{ posBSRF,posWSRF,wheelArmWidth,suspensionColor };
	SuspensionArm sarc{ posBSRB,posWSRC,wheelArmWidth,suspensionColor };
	SuspensionArm sarb{ posBSRB,posWSRB,wheelArmWidth,suspensionColor };

	SuspensionShaft wslf{ posWSLF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor }; //suspension wheel left front
	SuspensionShaft wslc{ posWSLC,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft wslb{ posWSLB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft wsrf{ posWSRF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft wsrc{ posWSRC,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft wsrb{ posWSRB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };

	SuspensionShaft bslf{ posBSLF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft bslb{ posBSLB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft bsrf{ posBSRF,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };
	SuspensionShaft bsrb{ posBSRB,suspensionShaftRadius,suspensionShaftLenght,suspensionShaftColor };

	Box body{ pos,width,length,height,bodyColor }; //body
};