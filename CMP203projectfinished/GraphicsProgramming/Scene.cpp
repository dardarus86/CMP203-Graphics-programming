										/////////////////////////////////////////////////////
										// CODE ADDED BY JAMIE HADDOW 0705082 FOR CMP203   //
										/////////////////////////////////////////////////////
#include "Scene.h"
// for the audio system im using in this project  https://www.ambiera.com/irrklang/
using namespace irrklang;

Scene::Scene(Input* in)
{
	// Store pointer for input class
	input = in;
	
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	// the tree model has an issue with the u,v being higher than 1. needed to add these to get the texture to repeat
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//initalizing the camera variables
	camera.cameraInit(3.0f, 3.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	camera2.cameraInit(113.0f, 365.0f, -314.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	camera3.cameraInit(0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	objects.initialise();
	//used to control the different camera modes with numbers 1,2 and 3
	cameraMode = 0;
}

// used in the paulzombie wandering around the scene
float wavez = 50;
float wavezSpeed = 1.0f;

//used for the firepit liht giving it a glowing in and out affect. thisis being passed into the attenuation value of said light
GLfloat atten = 0.06f;
GLfloat attenSpeed = 0.04f;
//using irrklang audio engine to have positional sounds
ISoundEngine* engine = createIrrKlangDevice();
ISound* music1 = engine->play3D("sfx/campfire.ogg",	vec3df(0, 0, 0), true, false, true);
ISound* music2 = engine->play3D("sfx/dragonball.ogg", vec3df(130, 0, 0), true, false, true);
ISound* music3 = engine->play3D("sfx/ff7.ogg", vec3df(-130, 0, 0), true, false, true);
ISound* music4 = engine->play3D("sfx/halo.ogg", vec3df(0, 0, 130), true, false, true);
ISound* music5 = engine->play3D("sfx/spirited.ogg", vec3df(0, 0, -130), true, false, true);


//used for showing the wireframe with - or +
bool wireframe = false;
// used at the start of render for the ambient music in the scene to stop it playing a billion times on top of each other
bool playatstart = false;

void Scene::handleInput(float dt)
{

	if (input->isKeyDown('1'))
	{
		cameraMode = 0;
		input->SetKeyUp('1');
	}
	if (input->isKeyDown('2'))
	{
		cameraMode = 1;
		input->SetKeyUp('2');
	}
	if (input->isKeyDown('3'))
	{
		cameraMode = 2;
		input->SetKeyUp('3');
	}


	switch (cameraMode)
	{
	case 0:
		//camera 1
		if (input->isKeyDown('a'))
		{

			camera.moveLeft(dt);
		}
		if (input->isKeyDown('d'))
		{

			camera.moveRight(dt);

		}
		if (input->isKeyDown('x'))
		{

			camera.moveDown(dt);
		}
		if (input->isKeyDown('z'))
		{

			camera.moveUp(dt);
		}
		if (input->isKeyDown('w'))
		{

			camera.moveForward(dt);
		}
		if (input->isKeyDown('s'))
		{

			camera.moveBackwords(dt);

		}

		xDiff = input->getMouseX() - (width / 2);
		yDiff = input->getMouseY() - (height / 2);
		if (xDiff != 0 || yDiff != 0)
		{
			camera.controlMouse(dt, xDiff, yDiff);
		}
		camera.update();
		break;
		// camera 1 end
		//camera 2
	case 1:
		camera2.update();
		
		break;
		//camera 2 end
		//camera 3
	case 2:
		camera3.setPitchYaw(0, rotation);
		camera3.update();
		break;
		//camera 3 end

		
	}

	// WireFrame
	if (input->isKeyDown('-') && wireframe == false)
	{
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);
		input->SetKeyUp('-');
		wireframe = true;
	}
	if (input->isKeyDown('=')  && wireframe == true)
	{
		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
		input->SetKeyUp('=');
		wireframe = false;
	}
	//controlling elbow of object above firepit
	if (input->isKeyDown('n'))
	{
		input->SetKeyUp('n');
		elbow -= 30.0;
	}
	if (input->isKeyDown('m'))
	{
		input->SetKeyUp('m');
		elbow += 30.0;

	}
	//controlling shoulder of object above firepit
	if (input->isKeyDown('v'))
	{
		input->SetKeyUp('v');
		shoulder -= 30.0;
	}
	if (input->isKeyDown('b'))
	{
		input->SetKeyUp('b');
		shoulder += 30.0;

	}

}
void Scene::update(float dt)
{

	calculateFPS();
	//used for rotating objects in the objects.rednderworld() function
	rotateY += 0.4f;
	// using the wavez and wavezSpped variables created above to control the moving in and out on the Z axis
	wavez = wavez + (wavezSpeed * dt);
	if (wavez >= 60.0f)
	{
		wavez = 60;
		wavezSpeed = -10;
		wavez = wavez - (wavezSpeed * dt);
	}
	else if(wavez <= 40.0f)
	{
		wavez = 40;
		wavezSpeed = 10;
		wavez = wavez + (wavezSpeed * dt);
	}
	//using the atten variable created above for the firepit light glowing effect
	atten = atten + (attenSpeed * dt);
	if (atten > 0.1)
	{
		atten = 0.1;
		attenSpeed = -attenSpeed;
	}
	else if (atten < 0.05f)
	{
		atten = 0.05;
		attenSpeed = -attenSpeed;
	}
	
	// used for paul zombie going around the scene
	rotation += Speed * dt;

	//setting the mouse to the center of the screen
	glutWarpPointer(width / 2, height / 2);
}

void Scene::changecamera()
{
	switch (cameraMode)
	{
	case 0:
		gluLookAt(camera.getPosX(), camera.getPosY(), camera.getPosZ(), camera.getLookAtX(), camera.getLookAtY(), camera.getLookAtZ(), camera.getUpX(), camera.getUpY(), camera.getUpZ());
		break;
	case 1:
		gluLookAt(camera2.getPosX(), camera2.getPosY(), camera2.getPosZ(), 0, 0, 0, camera2.getUpX(), camera2.getUpY(), camera2.getUpZ());
		break;
	case 2:
		gluLookAt(camera3.getPosX(), camera3.getPosY(), camera3.getPosZ(), camera3.getLookAtX(), camera3.getLookAtY(), -camera3.getLookAtZ(), camera3.getUpX(), camera3.getUpY(), camera3.getUpZ());
		break;
	}
}

void Scene::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	changecamera();
	
	glDisable(GL_LIGHTING);
	//	objects.skyBox(camera.getPosX(), camera.getPosY(), camera.getPosZ());
	glEnable(GL_LIGHTING);

	//objects.renderWorld(shoulder, elbow, atten, rotation, rotateY, wavez);
	
	// this was added last minute. The stencil world idea was just to see if i COULD not if i SHOULD. notice the heavy fps drop
	if (input->isKeyDown('k'))
	{
		//objects.stencilWorld(shoulder, elbow, atten, rotation, rotateY, wavez);
	}


	renderTextOutput();
	glutSwapBuffers();


}


// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h)
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 5000.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

	glutWarpPointer(width/2, height/2);
	input->setMousePos(width / 2, height / 2);
}

// Calculates FPS
void Scene::calculateFPS()
{

	/*frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}*/
}
// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	
	//glDisable(GL_LIGHTING);
	//// Render current mouse position and frames per second.
	//sprintf_s(musicText, "4 Music pieces, go find the models that match the songs");
	//sprintf_s(cameraText, "Camera:3 Cameras, change with numbers 1,2,3. Z and X to go up/down ");
	//sprintf_s(controlsText, "Use M,N,B,V to control the arm in the air above firepit");
	//sprintf_s(wireframeText, "Use the - and + keys for Wireframe");
	//sprintf_s(ghostText, "Look up and press K to see into another DIMENSION!!. Sorry FPS");
	////glColor3f(1.0f, 1.0f, 1.0f);
	//displayText(-1.f, 0.96f, 1.f, 1.f, 1.f, musicText);
	//displayText(-1.f, 0.90f, 1.f, 1.f, 1.f, cameraText);
	//displayText(-1.f, 0.84f, 1.f, 1.f, 1.f, controlsText);
	//displayText(-1.f, 0.78f, 1.f, 1.f, 1.f, wireframeText);
	//displayText(-1.f, 0.72f, 1.f, 1.f, 1.f, ghostText);
	//displayText(-1.f, 0.66f, 1.f, 1.f, 1.f, fps);
	//glEnable(GL_LIGHTING);
	/*displayText3d(3.0f, 3.0f, 1.0f, 0.f, 0.f,0.f, xAxis);*/



}
// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width / (float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}

