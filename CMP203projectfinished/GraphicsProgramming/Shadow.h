												////////////////////////////////////////////////////
												// CODE USED BY JAMIE HADDOW 0705082 FOR CMP203//
												////////////////////////////////////////////////////

#pragma once

#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>
#include "Vector3.h"

class Shadow
{
public:
	static void generateShadowMatrix(float* shadowMatrix, float light_pos[4], GLfloat floor[12]);
};