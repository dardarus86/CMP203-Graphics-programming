															//////////////////////////////////////////////////////
															// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203  //
															//////////////////////////////////////////////////////
																			//FINISHED //COMMENTED IN .H
#include "Light.h"

void Light::paulLight() // light 1
{
	GLfloat Diffuse[] =  { 0.0f, 0.0f, 6.0f, 1.0f };
	GLfloat Position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);;
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2f);
	glEnable(GL_LIGHT1);
}

void Light::fireLight(GLfloat quad) //light 2
{
	GLfloat Diffuse[] =  { 10.0f, 7.8f, 0.5f, 1.0f };
	GLfloat Position[] = { 0.0f,  0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, Position);;
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.3f);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, quad);
	glEnable(GL_LIGHT2);
}

void Light::worldAmbient() //light 3
{
	GLfloat Ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	glLightfv(GL_LIGHT3, GL_AMBIENT, Ambient);
	glEnable(GL_LIGHT3);
}

void Light::cloudSpotLight() //light 4
{
	GLfloat Diffuse[]   = { 2.0f,    0.0f, 0.0f, 1.0f };
	GLfloat Position[]  = { -110.0f, 3.0f, 0.0f, 1.0f };
	GLfloat Direction[] = { -1.0f,   0.0f, 0.0f };

	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 25.0f);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 20.0f);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT4, GL_POSITION, Position);
	glEnable(GL_LIGHT4);
}

void Light::chihiroSpotLight()
{
	GLfloat Diffuse[]   = { 0.0f, 2.0f, 0.0f,    1.0f };
	GLfloat Position[]  = { 0.0f, 3.0f, -110.0f, 1.0f };
	GLfloat Direction[] = { 0.0f, 0.0f, -1.0f };

	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 25.0f);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 20.0f);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT5, GL_POSITION, Position);
	glEnable(GL_LIGHT5);
}

void Light::chiefSpotLight()
{
	GLfloat Diffuse[] =   { 0.0f, 0.0f, 2.0f,   1.0f };
	GLfloat Position[] =  { 0.0f, 3.0f, 110.0f, 1.0f };
	GLfloat Direction[] = { 0.0f, 0.0f, 1.0f };
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 25.0f);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 20.0f);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT6, GL_POSITION, Position);
	glEnable(GL_LIGHT6);
	
}

void Light::gokuSpotLight()
{
	GLfloat Diffuse[] =   { 2.0f,   2.0f, 0.0f, 1.0f };
	GLfloat Position[] =  { 110.0f, 3.0f, 0.0f, 1.0f };
	GLfloat Direction[] = { 1.0f,   0.0f, 0.0f };
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 25.0f);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 20.0f);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT7, GL_POSITION, Position);
	glEnable(GL_LIGHT7);
}


