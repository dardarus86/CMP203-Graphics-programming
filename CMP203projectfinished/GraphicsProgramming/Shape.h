												////////////////////////////////////////////////////
												// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203//
												////////////////////////////////////////////////////

#ifndef _SHAPE_H
#define _SHAPE_H

#include "glut.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <vector>

class Shape
{

public:
	void calculatefloor(int floorsize, float floor);
	void calculatelogend(int logsize, float logr);
	void calculateCylinder(int res, float s, int h);

	void renderfloor(GLuint item);
	void renderlogend(GLuint logimg);
	void renderCylinder(GLuint item);
	void renderlog(GLuint logimg);


	int floorVertexCount, logVertexCount, cylinderVertexCount;

	// i created 3 different vectors just to it very clear in terms of what vector is being used for what
	std::vector<float> floorVerts, floorNorms, floorTexcoords;
	std::vector<float> logVerts, logNorms, logTexcoords;
	std::vector<float> cylinderVerts, cylinderNorms, cylinderTexcoords;
};
#endif 
