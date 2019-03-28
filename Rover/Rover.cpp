#include "Rover.h"



Rover::Rover(GLfloat pos[3]) : Solid(pos)
{
	
}


Rover::~Rover()
{
}

void Rover::draw()
{
	GLfloat posWLF[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0], length / 2 + pos[1],wheelRadius / 2 + pos[2] }; // wheel left front 
	GLfloat posWLC[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0],0 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWLB[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0],-length / 2 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWRF[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0],length / 2 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWRC[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0],0 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWRB[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0],-length / 2 + pos[1],wheelRadius / 2 + pos[2] };

	GLfloat posBSLF[3] = { -width / 2 - wheelArmWidth / 2 + pos[0],length / 3 + pos[1],rideHeigth + height / 2 + pos[2] }; // body suspension left front
	GLfloat posBSLB[3] = { -width / 2 - wheelArmWidth / 2 + pos[0],-length / 4 + pos[1],rideHeigth + height / 2 + pos[2] };
	GLfloat posBSRF[3] = { width / 2 + wheelArmWidth / 2 + pos[0],length / 3 + pos[1],rideHeigth + height / 2 + pos[2] };
	GLfloat posBSRB[3] = { width / 2 + wheelArmWidth / 2 + pos[0],-length / 4 + pos[1],rideHeigth + height / 2 + pos[2] };

	GLfloat posWSLF[3] = { -width / 2 - wheelArmWidth / 2 + pos[0],length / 2 + pos[1],wheelRadius / 2 + pos[2] }; // wheel suspension left front 
	GLfloat posWSLC[3] = { -width / 2 - wheelArmWidth / 2 + pos[0],0 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWSLB[3] = { -width / 2 - wheelArmWidth / 2 + pos[0],-length / 2 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWSRF[3] = { width / 2 + wheelArmWidth / 2 + pos[0],length / 2 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWSRC[3] = { width / 2 + wheelArmWidth / 2 + pos[0],0 + pos[1],wheelRadius / 2 + pos[2] };
	GLfloat posWSRB[3] = { width / 2 + wheelArmWidth / 2 + pos[0],-length / 2 + pos[1],wheelRadius / 2 + pos[2] };

	GLfloat posBody[3] = { pos[0],pos[1],pos[2] + rideHeigth + height / 2 };

	Wheel wlf{ posWLF,wheelRadius,wheelWidth }; //wheel left front
	Wheel wlc{ posWLC,wheelRadius,wheelWidth };
	Wheel wlb{ posWLB,wheelRadius,wheelWidth };
	Wheel wrf{ posWRF,wheelRadius,wheelWidth };
	Wheel wrc{ posWRC,wheelRadius,wheelWidth };
	Wheel wrb{ posWRB,wheelRadius,wheelWidth };

	SuspensionArm  salf{ posBSLF, posWSLF, wheelArmWidth }; //suspension arm left front
	SuspensionArm  salc{ posBSLB, posWSLC, wheelArmWidth };
	SuspensionArm  salb{ posBSLB, posWSLB, wheelArmWidth };
	SuspensionArm  sarf{ posBSRF, posWSRF, wheelArmWidth };
	SuspensionArm  sarc{ posBSRB, posWSRC, wheelArmWidth };
	SuspensionArm  sarb{ posBSRB, posWSRB, wheelArmWidth };

	Wheel wslf{ posWSLF,suspensionShaftRadius,suspensionShaftLenght }; //suspension wheel left front
	Wheel wslc{ posWSLC,suspensionShaftRadius,suspensionShaftLenght };
	Wheel wslb{ posWSLB,suspensionShaftRadius,suspensionShaftLenght };
	Wheel wsrf{ posWSRF,suspensionShaftRadius,suspensionShaftLenght };
	Wheel wsrc{ posWSRC,suspensionShaftRadius,suspensionShaftLenght };
	Wheel wsrb{ posWSRB,suspensionShaftRadius,suspensionShaftLenght };

	Wheel bslf{ posBSLF,suspensionShaftRadius,suspensionShaftLenght };
	Wheel bslb{ posBSLB,suspensionShaftRadius,suspensionShaftLenght };
	Wheel bsrf{ posBSRF,suspensionShaftRadius,suspensionShaftLenght };
	Wheel bsrb{ posBSRB,suspensionShaftRadius,suspensionShaftLenght };

	Box body{ posBody,width,length,height }; //	body


	wlf.draw();
	wlc.draw();
	wlb.draw();
	wrf.draw();
	wrc.draw();
	wrb.draw();

	salf.draw();
	salc.draw();
	salb.draw();
	sarf.draw();
	sarc.draw();
	sarb.draw();
	
	wslf.draw();
	wslc.draw();
	wslb.draw();
	wsrf.draw();
	wsrc.draw();
	wsrb.draw();
	
	bslf.draw();
	bslb.draw();
	bsrf.draw();
	bsrb.draw();

	body.draw();
}
