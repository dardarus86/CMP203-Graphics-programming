														////////////////////////////////////////////////////
														// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203//
														////////////////////////////////////////////////////
															        //FINISHED //COMMENTED
#pragma once


#include "Vector3.h"

class Camera
{
public:
	void update();
	//Set up vectors for storing x,y,z positions of
	//Up, Forward, Lookat, Position, Right
	Vector3 up;
	Vector3 forward;
	Vector3 lookAt;
	Vector3 position;
	Vector3 right;

	//Code given by Paul to setup values used for handling rotation
	float cosR, cosP, cosY;
	float sinR, sinP, sinY;
	float Roll, Pitch, Yaw;

	float movespeed = 20;
	//initialize the camera for multiple instances. not using pitch,yaw,roll so didnt inclose them as float pi, float, ya, float ro
	void cameraInit(float px, float py, float pz, float fx, float fy, float fz, float ux, float xy, float xz);

	//Setting up the mouse for looking around
	void controlMouse(float dt, int xDiff, int yDiff);
	
	//9 functions used in the gluLookat() for camera control
	//Getters
	float getPosX();
	float getPosY();
	float getPosZ();
	float getLookAtX();
	float getLookAtY();
	float getLookAtZ();
	float getUpX();
	float getUpY();
	float getUpZ();

	//Functions for camera control on the X,Y,Z axis
	void moveForward(float dt);
	void moveBackwords(float dt);
	void moveLeft(float dt);
	void moveRight(float dt);
	void moveUp(float dt);
	void moveDown(float dt);
	
	//used  for one of the cameras which rotates on the YAW axis
	void setPitchYaw(float pi, float ya);

};

