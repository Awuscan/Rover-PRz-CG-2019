#include "Rover.h"

void rotate(int angle,GLfloat pos[3]) {
	
		glTranslatef(pos[0], pos[1], pos[2]);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(-pos[0], -pos[1], -pos[2]);
}

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
	glPushMatrix();


	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(alfa, 0.0f, 0.0f, 1.0f); 
	glTranslatef(-pos[0], -pos[1], -pos[2]);

	drawWheels();
	drawSusp();
	drawBody();
	glPopMatrix();
}

void Rover::drawWheels()
{
	int sign = 1;
	if (velocity < 0) {
		sign = -1;
	}
	glPushMatrix();
	if (alfa > alfaTarget)
	{
		rotate(sign * 15, posWLF);
	}else if (alfa < alfaTarget)
	{
		rotate(sign * -15, posWLF);
	}else if (velocity == 0 && alfa != alfaTarget) {
		rotate(-45, posWLF);
	}
	wlf.draw();
	glPopMatrix();

	glPushMatrix();
	if (alfa > alfaTarget) {
		rotate(sign * 15, posWRF);
	}
	else if (alfa < alfaTarget) {
		rotate(sign * -15, posWRF);
	}
	else if (velocity == 0 && alfa != alfaTarget) {
		rotate(45, posWRF);
	}
	wrf.draw();
	glPopMatrix();


	wlc.draw();
	wrc.draw();


	glPushMatrix();
	if (alfa > alfaTarget) {
		rotate(sign * -15, posWLB);
	}
	else if (alfa < alfaTarget) {
		rotate(sign * 15, posWLB);
	}
	else if (velocity == 0 && alfa != alfaTarget) {
		rotate(-45, posWLB);
	}
	wlb.draw();
	glPopMatrix();

	glPushMatrix();
	if (alfa > alfaTarget) {
		rotate(sign * -15, posWRB);
	}
	else if (alfa < alfaTarget) {
		rotate(sign * 15, posWRB);
	}
	else if (velocity == 0 && alfa != alfaTarget) {
		rotate(45, posWRB);
	}
	wrb.draw();
	glPopMatrix();

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

void Rover::move(GLfloat pos[3], int alfa)
{
	move(pos);
	this->alfa = alfa;
}

void Rover::move(GLfloat pos[3], int alfa, int alfaTarget)
{
	move(pos);
	this->alfa = alfa;
	this->alfaTarget = alfaTarget;
}

void Rover::update(WPARAM wParam)
{
	if (wParam == VK_SPACE)
	{
		velocityTarget = 0;	
		alfaTarget = alfa;
	}

	if (wParam == 'I')
		velocity += constVelocity;

	if (wParam == 'K')
		velocity -= constVelocity;

	if (wParam == 'J')
		alfaTarget += 10;

	if (wParam == 'L')
		alfaTarget -= 10;
}

void Rover::update()
{

	if (velocity != velocityTarget)
	{
		if (velocityTarget > 0)
		{
			if (velocityTarget > velocityMax)
				velocityTarget = velocityMax;
			if (velocity > velocityTarget)
				velocity -= momentum;
			if (velocity < velocityTarget)
				velocity += momentum;
		}
		if (velocityTarget < 0)
		{
			if (velocityTarget < -velocityMax)
				velocityTarget = -velocityMax;
			if (velocity > velocityTarget)
				velocity -= momentum;
			if (velocity < velocityTarget)
				velocity += momentum;
		}
		if (velocityTarget == 0)
		{
			if (velocity > 0)
			{
				velocity -= momentum;
			}
			else {
				velocity += momentum;
			}
		}
	}

	if(velocityTarget != 0 )
	{
		if (velocityTarget > 0)
			velocityTarget -= momentum;
		if (velocityTarget < 0)
			velocityTarget += momentum;
	}

	if (alfa > alfaTarget)
	{
		alfa -= 2;
	}
	else if (alfa < alfaTarget)
	{
		alfa += 2;
	}
	alfa = alfa % 360;

	GLfloat newPos[3] = {
		pos[0] += velocity * sin(-alfa * M_PI / 180 ),
		pos[1] += velocity * cos(-alfa * M_PI / 180),
		pos[2] };
	move(newPos);
}

void Rover::collision()
{
	int bounce;
	if (velocityTarget >= 0) {
		bounce = -1;
	}
	else {
		bounce = 5;
	}
	velocity = 0;
	velocityTarget = 0;
	
	GLfloat newPos[3] = {
		pos[0] += bounce * sin(-alfa * M_PI / 180),
		pos[1] += bounce * cos(-alfa * M_PI / 180),
		pos[2]};
	move(newPos);
}

