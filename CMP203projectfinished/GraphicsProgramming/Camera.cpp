													////////////////////////////////////////////////////
													// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203//
													////////////////////////////////////////////////////
																//FINISHED //COMMENTED IN .H

#include "Camera.h"



void Camera::cameraInit(float px, float py, float pz, float fx, float fy, float fz, float ux, float uy, float uz)
{
	position.x = px;
	position.y = py;
	position.z = pz;
	forward.x = fx;
	forward.y = fy;
	forward.z = fz;
	up.x = ux;
	up.y = uy;
	up.z = uz;
	update();

}

void Camera::update()
{
	//Code given by Paul
		// handle rotation 
		// YAW = LEFT to RIGHT. PITCH = UP and DOWN Roll = tilting your head
		cosY = cosf(Yaw*3.1415/180);
		sinY = sinf(Yaw* 3.1415 / 180);
		sinP = sinf(Pitch* 3.1415 / 180);
		cosP = cosf(Pitch*3.1415/180);
		cosR = cosf(Roll*3.1415/180);
		sinR = sinf(Roll*3.1415/180);
	
		// Calculate the three vectors to put into  glu Lookat 
		// Look direction, position and the up vector 
		// This function could also calculate the right vector

		lookAt.x = position.x + forward.x;
		lookAt.y = position.y + forward.y;
		lookAt.z = position.z + forward.z;

		forward.x = sinY * cosP;
		forward.y = sinP; 
		forward.z = cosP * -cosY;

		// Look At Point
		// To calculate add Forward Vector to Camera position.
		// Up Vector 
		up.x = -cosY * sinR - sinY * sinP * cosR;
		up.y = cosP * cosR;
		up.z = -sinY * sinR - sinP * cosR * -cosY;
	// Above code given by Paul

// Side Vector (right)
	right = forward.cross(up);
}

//below functions self explanitory for moving
void Camera::moveForward(float dt)
{
	position.x = position.x + forward.x * dt * movespeed;
	position.z = position.z + forward.z * dt * movespeed;
}
void Camera::moveBackwords(float dt)
{
	position.x = position.x - forward.x * dt * movespeed;
	position.z = position.z - forward.z * dt * movespeed;

}
void Camera::moveLeft(float dt)
{
	position.x = position.x - right.x;
	position.z = position.z - right.z;
}
void Camera::moveRight(float dt)
{
	position.x = position.x + right.x;
	position.z = position.z + right.z;
}
void Camera::moveUp(float dt)
{
	position.y = position.y + up.y;
}
void Camera::moveDown(float dt)
{
	position.y = position.y - up.y;
}
void Camera::setPitchYaw(float pi, float ya)
{
	Pitch = pi;
	Yaw = ya;
}

//Used for controling the mouse
void Camera::controlMouse(float dt, int xDiff, int yDiff)
{
	// if the difference for X is not equal to 0 then calculate the Yaw(left to right)
	if (xDiff != 0)
	{
		Yaw += xDiff  * dt;
	}
	// if the difference for Y is not equal to 0 then calculate the Pitch(up and down)
	if (yDiff != 0)
	{
		Pitch -= yDiff  * dt;
	}
}

//Getters
float Camera::getPosX()
{
	return position.x;
}
float Camera::getPosY()
{
	return position.y;
}
float Camera::getPosZ()
{
	return position.z;
}
float Camera::getLookAtX()
{
	return lookAt.x;
}
float Camera::getLookAtY()
{
	return lookAt.y;
}
float Camera::getLookAtZ()
{
	return lookAt.z;
}
float Camera::getUpX()
{
	return up.x;
}
float Camera::getUpY()
{
	return up.y;
}
float Camera::getUpZ()
{
	return up.z;
}