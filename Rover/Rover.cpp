#include "Rover.h"

Rover::Rover(GLfloat pos[3]) : Solid(pos,this->bodyColor)
{
	posWLF[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLF[1] = length / 2 + pos[1];
	posWLF[2] = wheelRadius / 2 + pos[2];

	posWLC[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLC[1] = pos[1];
	posWLC[2] = wheelRadius / 2 + pos[2];

	posWLB[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLB[1] = -length / 2 + pos[1];
	posWLB[2] = wheelRadius / 2 + pos[2];

	posWRF[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRF[1] = length / 2 + pos[1];
	posWRF[2] = wheelRadius / 2 + pos[2];

	posWRC[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRC[1] = pos[1];
	posWRC[2] = wheelRadius / 2 + pos[2];

	posWRB[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRB[1] = -length / 2 + pos[1];
	posWRB[2] = wheelRadius / 2 + pos[2];

	posBSLF[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posBSLF[1] = length / 4 + pos[1];
	posBSLF[2] = rideHeigth + height / 2 + pos[2];

	posBSLB[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posBSLB[1] = -length / 4  + pos[1];
	posBSLB[2] = rideHeigth + height / 2 + pos[2];

	posBSRF[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posBSRF[1] = length / 4 + pos[1];
	posBSRF[2] = rideHeigth + height / 2 + pos[2];

	posBSRB[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posBSRB[1] = -length / 4 + pos[1];
	posBSRB[2] = rideHeigth + height / 2 + pos[2];

	posWSLF[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLF[1] = length / 2 + pos[1];
	posWSLF[2] = wheelRadius / 2 + pos[2];

	posWSLC[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLC[1] = pos[1];
	posWSLC[2] = wheelRadius / 2 + pos[2];

	posWSLB[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLB[1] = -length / 2 + pos[1];
	posWSLB[2] = wheelRadius / 2 + pos[2];

	posWSRF[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRF[1] = length / 2 + pos[1];
	posWSRF[2] = wheelRadius / 2 + pos[2];

	posWSRC[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRC[1] = 0 + pos[1];
	posWSRC[2] = wheelRadius / 2 + pos[2];

	posWSRB[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRB[1] = -length / 2 + pos[1];
	posWSRB[2] = wheelRadius / 2 + pos[2];

	posBody[0] = pos[0];
	posBody[1] = pos[1];
	posBody[2] = pos[2] + rideHeigth + height / 2;

	wlf.move(posWLF);
	wlc.move(posWLC);
	wlb.move(posWLB);
	wrf.move(posWRF);
	wrc.move(posWRC);
	wrb.move(posWRB);

	salf.move(posBSLF, posWSLF);
	salc.move(posBSLB, posWSLC);
	salb.move(posBSLB, posWSLB);
	sarf.move(posBSRF, posWSRF);
	sarc.move(posBSRB, posWSRC);
	sarb.move(posBSRB, posWSRB);

	wslf.move(posWSLF);
	wslc.move(posWSLC);
	wslb.move(posWSLB);
	wsrf.move(posWSRF);
	wsrc.move(posWSRC);
	wsrb.move(posWSRB);

	bslf.move(posBSLF);
	bslb.move(posBSLB);
	bsrf.move(posBSRF);
	bsrb.move(posBSRB);

	body.move(posBody);
}


Rover::~Rover()
{
}

void Rover::draw()
{
	drawWheels();
	drawSusp();
	drawBody();
}

void Rover::drawWheels()
{
	wlf.draw();
	wlc.draw();
	wlb.draw();
	wrf.draw();
	wrc.draw();
	wrb.draw();
}
void Rover::drawSusp()
{
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
}

void Rover::drawBody()
{
	body.draw();
}

void Rover::move(GLfloat newPos[3])
{
	pos[0] = newPos[0];
	pos[1] = newPos[1];
	pos[2] = newPos[2];

	posWLF[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLF[1] = length / 2 + pos[1];
	posWLF[2] = wheelRadius / 2 + pos[2];

	posWLC[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLC[1] = pos[1];
	posWLC[2] = wheelRadius / 2 + pos[2];

	posWLB[0] = -width / 2 - wheelArmWidth - wheelWidth / 2 + pos[0];
	posWLB[1] = -length / 2 + pos[1];
	posWLB[2] = wheelRadius / 2 + pos[2];

	posWRF[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRF[1] = length / 2 + pos[1];
	posWRF[2] = wheelRadius / 2 + pos[2];

	posWRC[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRC[1] = pos[1];
	posWRC[2] = wheelRadius / 2 + pos[2];

	posWRB[0] = width / 2 + wheelArmWidth + wheelWidth / 2 + pos[0];
	posWRB[1] = -length / 2 + pos[1];
	posWRB[2] = wheelRadius / 2 + pos[2];

	posBSLF[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posBSLF[1] = length / 4 + pos[1];
	posBSLF[2] = rideHeigth + height / 2 + pos[2];

	posBSLB[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posBSLB[1] = -length / 4 + pos[1];
	posBSLB[2] = rideHeigth + height / 2 + pos[2];

	posBSRF[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posBSRF[1] = length / 4 + pos[1];
	posBSRF[2] = rideHeigth + height / 2 + pos[2];

	posBSRB[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posBSRB[1] = -length / 4 + pos[1];
	posBSRB[2] = rideHeigth + height / 2 + pos[2];

	posWSLF[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLF[1] = length / 2 + pos[1];
	posWSLF[2] = wheelRadius / 2 + pos[2];

	posWSLC[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLC[1] = pos[1];
	posWSLC[2] = wheelRadius / 2 + pos[2];

	posWSLB[0] = -width / 2 - wheelArmWidth / 2 + pos[0];
	posWSLB[1] = -length / 2 + pos[1];
	posWSLB[2] = wheelRadius / 2 + pos[2];

	posWSRF[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRF[1] = length / 2 + pos[1];
	posWSRF[2] = wheelRadius / 2 + pos[2];

	posWSRC[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRC[1] = 0 + pos[1];
	posWSRC[2] = wheelRadius / 2 + pos[2];

	posWSRB[0] = width / 2 + wheelArmWidth / 2 + pos[0];
	posWSRB[1] = -length / 2 + pos[1];
	posWSRB[2] = wheelRadius / 2 + pos[2];

	posBody[0] = pos[0];
	posBody[1] = pos[1];
	posBody[2] = pos[2] + rideHeigth + height / 2;

	wlf.move(posWLF);
	wlc.move(posWLC);
	wlb.move(posWLB);
	wrf.move(posWRF);
	wrc.move(posWRC);
	wrb.move(posWRB);

	salf.move(posBSLF, posWSLF);
	salc.move(posBSLB, posWSLC);
	salb.move(posBSLB, posWSLB);
	sarf.move(posBSRF, posWSRF);
	sarc.move(posBSRB, posWSRC);
	sarb.move(posBSRB, posWSRB);

	wslf.move(posWSLF);
	wslc.move(posWSLC);
	wslb.move(posWSLB);
	wsrf.move(posWSRF);
	wsrc.move(posWSRC);
	wsrb.move(posWSRB);

	bslf.move(posBSLF);
	bslb.move(posBSLB);
	bsrf.move(posBSRF);
	bsrb.move(posBSRB);

	body.move(posBody);
}

void Rover::update(WPARAM wParam)
{
	float x, y, z;
	if (wParam == VK_SPACE)
	{
		velLtarget = 0;
		velRtarget = 0;
		if (velL > 0)
		velL = sqrt(velL);
		if (velR > 0)
		velR = sqrt(velR);

		if (velL < 0)
			velL = -sqrt(-velL);
		if (velR < 0)
			velR = -sqrt(-velR);
		
	}
	if (wParam == 'I') {
		velLtarget += constVel;
		velRtarget += constVel;
	}


	if (wParam == 'K') {
		velLtarget -= constVel;
		velRtarget -= constVel;
	}

	if (wParam == 'J') {
		velLtarget -= constVel;
		velRtarget += constVel;
	}

	if (wParam == 'L') {
		velLtarget += constVel;
		velRtarget -= constVel;
	}

	//if (velLtarget > velRtarget)
	//{
	//	alfa += 1;
	//}else if (velLtarget > velRtarget)
	//{
	//	alfa -= 1;
	//}
}

void Rover::update()
{

	if (velL != velLtarget)
	{
		if (velLtarget > 0)
		{
			if (velL > velLtarget)
				velL -= momentum;
			if (velL < velLtarget)
				velL += momentum;
		}
		if (velLtarget < 0)
		{
			if (velL > velLtarget)
				velL -= momentum;
			if (velL < velLtarget)
				velL += momentum;
		}
		if (velLtarget == 0)
		{
			if (velL > 0)
			{
				velL -= momentum;
			}
			else {
				velL += momentum;
			}
		}
	}

	if (velR != velRtarget)
	{
		if (velRtarget > 0)
		{
			if (velR > velRtarget)
				velR -= momentum;
			if (velR < velRtarget)
				velR += momentum;
		}
		if (velRtarget < 0)
		{
			if (velR > velRtarget)
				velR -= momentum;
			if (velR < velRtarget)
				velR += momentum;
		}
		if (velRtarget == 0)
		{
			if (velR > 0)
			{
				velR -= momentum;
			}
			else {
				velR += momentum;
			}
		}
	}

	if(velLtarget != 0 )
	{
		if (velLtarget > 0)
			velLtarget -= momentum;
		if (velLtarget < 0)
			velLtarget += momentum;
	}

	if (velRtarget != 0)
	{
		if (velRtarget > 0)
			velRtarget -= momentum;
		if (velRtarget < 0)
			velRtarget += momentum;
	}



	GLfloat newPos[3] = {
		pos[0] += (velL + velR) / 2, //*sin(alfa * 180 / M_PI),
		pos[1] += (velL + velR) / 2, //*cos(alfa * 180 / M_PI),
		pos[2] };
	move(newPos);

}
