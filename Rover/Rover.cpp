#include "Rover.h"



Rover::Rover(GLfloat pos[3]) : Solid(pos)
{
	GLfloat posWFL[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2, length / 2,wheelRadius / 2 }; // wheel left front 
	GLfloat posWLC[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2 ,0,wheelRadius / 2 };
	GLfloat posWLB[3] = { -width / 2 - wheelArmWidth - wheelWidth / 2 ,-length / 2,wheelRadius / 2 };
	GLfloat posWRF[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 ,length / 2,wheelRadius / 2 };
	GLfloat posWRC[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 ,0,wheelRadius / 2 };
	GLfloat posWRB[3] = { width / 2 + wheelArmWidth + wheelWidth / 2 ,-length / 2,wheelRadius / 2 };
	
	GLfloat posBSLF[3] = { -width / 2 - wheelArmWidth / 2,length / 3,rideHeigth + height / 2 }; // body suspension left front
	GLfloat posBSLB[3] = { -width / 2 - wheelArmWidth / 2,-length / 4,rideHeigth + height / 2 };
	GLfloat posBSRF[3] = { width / 2 + wheelArmWidth / 2,length / 3,rideHeigth + height / 2 };
	GLfloat posBSRB[3] = { width / 2 + wheelArmWidth / 2,-length / 4,rideHeigth + height / 2 };

	GLfloat posWSLF[3] = { -width / 2 - wheelArmWidth / 2 ,length / 2,wheelRadius / 2 }; // wheel suspension left front 
	GLfloat posWSLC[3] = { -width / 2 - wheelArmWidth / 2 ,0,wheelRadius / 2 };
	GLfloat posWSLB[3] = { -width / 2 - wheelArmWidth / 2 ,-length / 2,wheelRadius / 2 };
	GLfloat posWSRF[3] = { width / 2 + wheelArmWidth / 2 ,length / 2,wheelRadius / 2 };
	GLfloat posWSRC[3] = { width / 2 + wheelArmWidth / 2 ,0,wheelRadius / 2 };
	GLfloat posWSRB[3] = { width / 2 + wheelArmWidth / 2 ,-length / 2,wheelRadius / 2 };
}


Rover::~Rover()
{
}

void Rover::draw()
{


}
