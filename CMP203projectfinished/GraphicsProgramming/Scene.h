												////////////////////////////////////////////////////////////
												// CODE USED AND ADDED BY JAMIE HADDOW 0705082 FOR CMP203 //
												////////////////////////////////////////////////////////////
																//COMMENTED AND FINISHED


// Scene class. Configures a basic 3D scene.
// Interfaces with the Input class to handle user input
// Calculates and outputs Frames Per Second (FPS) rendered.
// Important functions are the constructor (initialising the scene), 
// update (for process user input and updating scene Objects) and render (renders scene).
#ifndef _SCENE_H
#define _SCENE_H

#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include "Camera.h"
#include <stdio.h>
#include "Model.h"
#include "Objects.h"
#include "include/irrKlang.h"
#include <vector>
#include <math.h>

class Scene {

public:
	Scene(Input* in);

	// Main render function
	void render();
	// Handle input function that receives delta time from parent.
	void handleInput(float dt);
	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);
	// Resizes the OpenGL output based on new window size.
	void resize(int w, int h);
	void changecamera();

	// floats for the mouse locking to the center of the screen for camera controls
	float xDiff = 0;
	float yDiff = 0;
	//used in the arm objet for the interactivity part of the assessment
	float shoulder = 0, elbow = 0;

	

	//creating objects for the relevent classes
	Objects objects;
	Camera camera;
	Camera camera2;
	Camera camera3;
	int cameraMode;
protected:
	// Renders text (x, y positions, RGB colour of text, string of text to be rendered)
	void displayText(float x, float y, float r, float g, float b, char* string);
	/*void displayText3d(float x, float y, float z, float r, float g, float b, char* string);*/
	// A function to collate all text output in a single location
	void renderTextOutput();
	void calculateFPS();
	void audio();

	// For access to user input.
	Input* input;
	//used for 
	float rotation = 0;
	//speed and rotation used for the paulzombie going around the screen rotating on the Y axis
	float Speed = 12;
	float rotateY = 0;
	// For Window and frustum calculation.
	int width, height;
	float fov, nearPlane, farPlane;


	// For text output in the top left of the screen.
	int frame = 0, time, timebase = 0;
	char fps[40];
	char wireframeText[40];
	char musicText[80];
	char cameraText[80];
	char controlsText[80];
	char ghostText[80];
	

};

#endif