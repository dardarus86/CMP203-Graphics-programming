												////////////////////////////////////////////////////
												// CODE ADDED BY JAMIE HADDOW 0705082 FOR CMP203  //
												////////////////////////////////////////////////////
														    	//FINISHED // COMMENTED

// I decided not to usee the texture function that was given and instead bind the texture inside the render function to give myself more control over individual textures.
// For example the firepit textures need to be inverted on the Y
// Doing this also allowed me to change the models texture on the fly much quicker


// Model class, represents a loaded OBJ model
// handles the loading/processing of the model file. Also loads and stores its own texture
#ifndef _MODEL_H_
#define _MODEL_H_

// INCLUDES //
#include <glut.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <vector>
#include "Vector3.h"
#include "SOIL.h"
using namespace std;

class Model
{

public:
	bool load(char* modelFilename);
	void render(GLuint item);

private:
	
	bool loadModel(char*);

	int m_vertexCount;
	GLuint texture;
	vector<float> vertex, normals, texCoords;

};

#endif