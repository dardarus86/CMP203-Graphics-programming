												////////////////////////////////////////////////////
												// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203//
												////////////////////////////////////////////////////
																//FINISHED //COMMENTED
#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>


class Light
{
public:
	//point like with the atenuation value passed into scene and updated through a veriable to give it a fade in/fade out effect
	void fireLight(GLfloat quad);
	//simple ambient value for the scene
	void worldAmbient();
	// point light positioned on the zombie paul with a blue glow
	void paulLight();
	//spot light positioned -20 on the axis of the object and facing the object. Red colour
	void cloudSpotLight();
	//spot light positioned -20 on the axis of the object and facing the object. Green colour
	void chihiroSpotLight();
	//spot light positioned -20 on the axis of the object and facing the object. Red colour
	void chiefSpotLight();
	//spot light positioned -20 on the axis of the object and facing the object. Yellow colour
	void gokuSpotLight();

	

};