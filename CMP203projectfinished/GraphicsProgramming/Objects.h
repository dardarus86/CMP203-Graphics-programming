												////////////////////////////////////////////////////
												// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203//
												////////////////////////////////////////////////////
																//FINISHED  //COMMENTED

#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include <vector>
#include "Sphere.h"
#include "Shape.h"
#include "Model.h"
#include "Shadow.h"
#include "Light.h"
#include "SOIL.h"



class Objects {

public:
//class objects used in objects
	Sphere sphere;
	Shape shape;
	Light light;
	Shadow shadow;
//matrix used for shadows
	float shadowMatrix[16];

//models and textures used

//ground and skybox
	GLuint groundImg;
	GLuint skyboxImg;
//firepit
	GLuint firePitImg;
	Model fire;
//stones
	GLuint stonesImg;
	Model stones;
//pot
	GLuint potImg;
	Model pot;
//fence
	GLuint fenceImg;
	Model sceneFence;
//grass
	GLuint grassImg;
	Model sceneGrass;
//bark
	GLuint treeBarkImg;
	Model treeBark;
//branch
	GLuint treeBranchImg;
	Model treeBranch;
//log. procedural generated shape so no model to go with it
	GLuint logImg;
//zombie paul
	GLuint paulImg;
	Model paul;
//goku
	GLuint gokuImg;
	Model goku;
//FF7 cloud
	GLuint cloudImg;
	Model cloud;
//masterchief from  halo
	GLuint haloImg;
	Model halo;
//spirited away chihiro
	GLuint chihiroImg;
	Model chihiro;

//ladder
	GLuint ladderImg;
	Model ladder1;

//project models
	void initialise();
	//arm created in week..4? from the big red book after learning about stacks. Using this for the interaction part of assessment set to translate 0,20,0 (above firepit)
	void arm(GLfloat shoulder, GLfloat elbow);
	//skybox
	void skyBox(GLfloat cPosX, GLfloat cPosY, GLfloat cPosZ);
	//procedural disc for the ground
	void ground();
	//firepit model for centerpiece of scene
	void firePit(GLfloat quad);
	//3 logs around the firepit
	void log();
	//grass object using multiple for loops incrementing a rotate and a translate to populate scene
	void grass();
	//fence object using a for loops incrementing a rotate to populate the outside edge of the (ground)disc
	void fence();
	void ladder();
	//tree object(trunk object + leaves object) using multiple for loops with incrementing rotate and translate with a mix of scaling and varing number of trees per for loop
	void trees();
	//originally a ball but Chris Acornley forced me to use paul or fail my course =(
	void floatingPaul(GLfloat rotation, GLfloat wavez);
	//using the same for loop to place giant zombie pauls to oversee the forest and make sure no shenanigans take place
	void paulOverseers();
	//creating the lights for the 4 spinning objects to indicate the loation of the positional audio. calling this function in musicObjects()
	void musicObjectLights();
	//throwing the previous 6 functions into 1 function to make it cleaner
	void musicObjects(GLfloat rotate);
	//4 miniture versions of the objects in the previous function for the user to clearly see the direction of what sound
	void tinyStencilObjects();
	// X axis stencils. using cull face on all stencils so yu cant see the mirrored object from behind
	void stencilCloud(GLfloat rotateY);
	void stencilGoku(GLfloat rotateY);
	//Z axis stencils
	void stencilChihiro(GLfloat rotateY);
	void stencilHalo(GLfloat rotateY);
	//putting all functions used into a single function to call in scene.render
	void renderWorld(GLfloat shoulder, GLfloat elbow, GLfloat atten, GLfloat rotation, GLfloat rotateY, GLfloat wavez);
	void stencilWorld(GLfloat shoulder, GLfloat elbow, GLfloat atten, GLfloat rotation, GLfloat rotateY, GLfloat wavez);

};