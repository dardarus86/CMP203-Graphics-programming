												///////////////////////////////////////////////////////
												// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203   //
												///////////////////////////////////////////////////////
															//FINISHED //COMMENTED IN .H

#include "Objects.h"
//load models
void Objects::initialise()
{
	groundImg = SOIL_load_OGL_texture("gfx/ground.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	skyboxImg = SOIL_load_OGL_texture("gfx/skybox.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	fenceImg = SOIL_load_OGL_texture("gfx/fence.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	firePitImg = SOIL_load_OGL_texture("gfx/firepit.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	stonesImg = SOIL_load_OGL_texture("gfx/stones.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	potImg = SOIL_load_OGL_texture("gfx/pot.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	grassImg = SOIL_load_OGL_texture("gfx/grass.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	treeBarkImg = SOIL_load_OGL_texture("gfx/bark2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	treeBranchImg = SOIL_load_OGL_texture("gfx/branch.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	logImg = SOIL_load_OGL_texture("gfx/bark.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	paulImg = SOIL_load_OGL_texture("gfx/paul.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	cloudImg = SOIL_load_OGL_texture("gfx/cloud.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	haloImg = SOIL_load_OGL_texture("gfx/chief.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	chihiroImg = SOIL_load_OGL_texture("gfx/chihiro.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	gokuImg = SOIL_load_OGL_texture("gfx/goku.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ladderImg = SOIL_load_OGL_texture("gfx/ladderwood.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	fire.load("models/firepit_wood.obj");
	pot.load("models/pot.obj");
	stones.load("models/stones.obj");
	sceneFence.load("models/fence.obj");
	sceneGrass.load("models/grass.obj");
	treeBark.load("models/tree_bark.obj");
	treeBranch.load("models/tree_leaves.obj");
	paul.load("models/paul.obj");
	cloud.load("models/cloud.obj");
	halo.load("models/chief.obj");
	chihiro.load("models/chihiro.obj");
	goku.load("models/goku.obj");
	ladder1.load("models/ladder.obj");
}
void Objects::arm(GLfloat shoulder, GLfloat elbow)
{
	glPushMatrix();
	glTranslatef(0.0f, 20.0f, 0.0f);
		glColor3f(1.0f, 0.70f, 0.42f);
		glTranslatef(-1.0f, 0.0f, 0.0f); 
		glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f); 
		glTranslatef(1.0f, 0.0f, 0.0f); 
			glPushMatrix(); 
				glScalef(2.5f, 0.5f, 0.5f);
				glutSolidCube(1.0); 
			glPopMatrix(); 
		glTranslatef(1.0f, 0.0f, 0.0f); 
		glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.5f, 0.0f, 0.0f); 
			glPushMatrix();
				glScalef(2.5f, 0.5f, 0.5f);
				glutSolidCube(1.0f);
			glPopMatrix();
		glTranslatef(1.75f, 0.0f, 0.0f); 
			glPushMatrix();
				glScalef(1.0f, 0.5f, 1.0f);
				glutSolidCube(1.0f);
			glPopMatrix();
		glColor3f(0.0f, 0.0f, 1.0f); 
		glTranslatef(0.5f, 0.55f, -0.35f);
		glRotatef(75, 0.0f, 0.0f, 1.0f);
			glPushMatrix();
				glScalef(0.75f, 0.25f, 0.25f);
				glutSolidCube(1.0f);
			glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f); 
			glRotatef(30, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.10f, -0.3f);
			glScalef(0.75f, 0.25f, 0.25f);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(-0.1f, 0.5f, 0.75f);
			glScalef(0.75f, 0.25f, 0.25f);
			glutSolidCube(1.0);
			glColor3f(0.0f, 0.0f, 0.0f);
		glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f); 
			glTranslatef(0.0f, 0.0f, 0.4f);
			glScalef(0.75f, 0.25f, 0.25f);
			glutSolidCube(1.0);
			glColor3f(0.0f, 0.0f, 0.0f);
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f); 
			glTranslatef(0.0f, 0.0f, 0.8f);
			glScalef(0.75f, 0.25f, 0.25f);
			glutSolidCube(1.0);
			glColor3f(0.0f, 0.0f, 0.0f);
		glPopMatrix();
	glPopMatrix();

}
void Objects::skyBox(GLfloat cPosX, GLfloat cPosY, GLfloat cPosZ)
{
	glPushMatrix();
		glTranslatef(cPosX, cPosY, cPosZ);
		glRotatef(-5.0, 0.0f, 0.0f, 1.0f);
		//disabling the depth test so its layered last
glDisable(GL_DEPTH_TEST);
glBindTexture(GL_TEXTURE_2D, skyboxImg);
		glColor3f(0.9f, 0.9f, 0.9f);
		sphere.draw();
glEnable(GL_DEPTH_TEST);
	glPopMatrix();
}
void Objects::ground()
{
	glPushMatrix();
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		shape.calculatefloor(40.0f, 150.0f);
		shape.renderfloor(groundImg);
	glPopMatrix();
}
void Objects::firePit(GLfloat quad)
{
	glPushMatrix();
		GLfloat shadowLightPos[4] = { 0, 6, 0, 1 };
		GLfloat shadowfireVerts[12] = { -20.0f, 0.05f, -20.0f, //top left
									   -20.0f, 0.05f, 20.0f, // bottom left
										20.0f, 0.05f, 20.0f, //bottom right
										20.0f, 0.05f, -20.0f };// top right
		shadow.generateShadowMatrix(shadowMatrix, shadowLightPos, shadowfireVerts);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glColor4f(0.0f, 0.0f, 0.0f, 0.2f); // Shadow's colour
		glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
			glPushMatrix();
				glMultMatrixf((GLfloat*)shadowMatrix);
					glPushMatrix();
						glTranslatef(-2.75f, 0.0f, 0.0f);
						glScalef(0.2f, 0.2f, 0.2f);
						glEnable(GL_BLEND);
						glEnable(GL_CULL_FACE);
						glCullFace(GL_FRONT);
						fire.render(firePitImg);
						stones.render(stonesImg);
						pot.render(potImg);
						glDisable(GL_CULL_FACE);
						glDisable(GL_BLEND);
						
						
					glPopMatrix();
			glPopMatrix();
			glEnable(GL_LIGHTING);
			glEnable(GL_TEXTURE_2D);
				glPushMatrix();
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
					glTranslatef(-2.75f, 0.0f, 0.0f);
					glScalef(0.2f, 0.2f, 0.2f);
					fire.render(firePitImg);
					stones.render(stonesImg);
					pot.render(potImg);
					glTranslatef(0.0f, 6.0f, 0.0f);
					light.fireLight(quad);
				glPopMatrix();
	glPopMatrix();



}
void Objects::log()
{
		glPushMatrix();
			for (int i = 0; i < 3; i++)
			{
				glPushMatrix();
					glRotatef(120 * i, 0.0f, 1.0f, 0.0f);
					GLfloat shadowLightPos[4] = { 0, 6, 0, 1 };
					GLfloat shadowLogVerts[12] = { -20.0f, 0.05f, -20.0f, //top left
												   -20.0f, 0.05f, 20.0f, // bottom left
									            	20.0f, 0.05f, 20.0f, //bottom right
										            20.0f, 0.05f, -20.0f };// top right
					shadow.generateShadowMatrix(shadowMatrix, shadowLightPos, shadowLogVerts);
				
					glDisable(GL_LIGHTING);
					glDisable(GL_TEXTURE_2D);
					glColor4f(0.0f, 0.0f, 0.0f, 0.2f); // Shadow's colour
					glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
						glPushMatrix();
							glMultMatrixf((GLfloat*)shadowMatrix);
								glPushMatrix();
								
									glTranslatef(0.0f, 1.0f,7.0f);
									glScalef(0.3f, 0.2f, 0.25f);
									glEnable(GL_BLEND);
									glEnable(GL_CULL_FACE);
									glCullFace(GL_FRONT);
									shape.renderlog(logImg);
									glDisable(GL_CULL_FACE);
									glDisable(GL_BLEND);
								glPopMatrix();
						glPopMatrix();
				//	glTranslatef(0, 1, 0);
				glColor3f(1.0f, 1.0f, 1.0f);
				glEnable(GL_LIGHTING);
				glEnable(GL_TEXTURE_2D);

						glPushMatrix();
							glTranslatef(0.0f, 1.0f, 7.0f);
							glScalef(0.3f, 0.2f, 0.25f);
							shape.renderlog(logImg);
						glPopMatrix();
				glPopMatrix();
			}
		glPopMatrix();
		glColor3f(1.0f, 1.0f, 1.0f); // Shadow's colour
}
void Objects::grass()
{
	for (int i = 0; i < 40; i++)
	{
		glPushMatrix();
		//(360 / 40) giving the rotation amount
			glRotatef(9 * i, 0.0f, 1.0f, 0.0);
			glTranslatef(0.0f, 0.0f, 20.0f);
			glScalef(0.01f, 0.004f, 0.01f);
			sceneGrass.render(grassImg);
		glPopMatrix();
	}

	for (int i = 0; i < 40; i++)
	{
		glPushMatrix();
			glRotatef(9 * i, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, 26.0f);
			glScalef(0.01f, 0.007f, 0.01f);
			sceneGrass.render(grassImg);
		glPopMatrix();
	}

	float grassSize = 40;
	float grassRotate;
	int grassTranslate = 34;
	grassRotate = 360 / grassSize;
		
	for (int j = 0; j < 17; j++)
	{
		for (int i = 0; i < grassSize; i++)
		{
			
			glPushMatrix();
				glRotatef(grassRotate * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, grassTranslate);
				glScalef(0.01f, 0.008f, 0.01f);
				sceneGrass.render(grassImg);
			glPopMatrix();
		}
		grassTranslate = grassTranslate + 7;
		grassSize = grassSize + 5;
		grassRotate = 360 / grassSize;
	}
}
void Objects::fence()
{
	for (int i = 0; i < 40; i++)
	{
		// circle Radius is 150, theta is (2*3.1415/40)
		glPushMatrix();
			glRotatef(9 * i, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, 149.0f);
			glScalef(1.15f, 1.15f, 1.15f);
			sceneFence.render(fenceImg);
		glPopMatrix();
	}

}
void Objects::ladder()
{
	glPushMatrix();
	glTranslatef(0, 5, 10);
	for (int i = 0; i < 20; i++)
	{
		glPushMatrix();
		glTranslatef(0.0f, 10*i, 0.0f);
		ladder1.render(ladderImg);
		glPopMatrix();
	}
	glPopMatrix();
}
void Objects::trees()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	 for (int i = 0; i < 40; i++)//8
		{
			 //(360 / 40) giving the rotation amount
			glPushMatrix();
				glRotatef(9 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 145.0f);
				glScalef(9.5f, 10.5f, 9.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}

	for (int i = 0; i < 34; i++)//7
		{
			glPushMatrix();
				glRotatef(10.58 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 109.0f);
				glScalef(5.5f, 5.5f, 5.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
	for (int i = 0; i < 14; i++)//7
		{
			glPushMatrix();
				glRotatef(25.7 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 93.0f);
				glScalef(6.2f, 8.1f, 7.7f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}


	for (int i = 0; i < 29; i++)//6
		{
			glPushMatrix();
				glRotatef(12.41 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 81.0f);
				glScalef(4.2f, 5.1f, 3.7f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
	for (int i = 0; i < 34; i++)//5
		{
			glPushMatrix();
				glRotatef(10.58 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 67.0f);
				glScalef(4.5f, 4.5f, 4.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
	for (int i = 0; i < 20; i++)//4
		{
			glPushMatrix();
				glRotatef(18 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 55.0f);
				glScalef(4.0f, 4.0f, 4.0f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}

	for (int i = 0; i < 31; i++)//3
		{
			glPushMatrix();
				glRotatef(11.6 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 40.0f);
				glScalef(4.5f, 5.5f, 4.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
	for (int i = 0; i < 19; i++)//2
		{
			glPushMatrix();
				glRotatef(18.94 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 20.0f);
				glScalef(7.5f, 6.5f, 7.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
	for (int i = 0; i < 23; i++)//1
		{
			glPushMatrix();
				glRotatef(15.65 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 30.0f);
				glScalef(6.5f, 3.5f, 6.5f);
				treeBark.render(treeBarkImg);
glEnable(GL_BLEND);
				treeBranch.render(treeBranchImg);
glDisable(GL_BLEND);
			glPopMatrix();
		}
}
void Objects::floatingPaul(GLfloat rotation, GLfloat wavez)
{
	glPushMatrix();
	
	glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
		glPushMatrix();
			glRotatef(rotation, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 3.0f, wavez);
			glScalef(0.05f, 0.05f, 0.05f);
				glPushMatrix();
					glRotatef(180, 0.0f, 1.0f, 0.0f);
					paul.render(paulImg);
					light.paulLight();
				glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void Objects::paulOverseers()
{

	glPushMatrix();
		for (int i = 0; i < 12; i++)//7
		{
			//(360 / 12) giving the rotation amount
			glPushMatrix();
				glRotatef(30 * i, 0.0f, 1.0f, 0.0f);
				glTranslatef(0.0f, 0.0f, 180.0f);
				glRotatef(180, 0, 1, 0);
				glRotatef(20, 1, 0, 0);
				glScalef(3.0f, 3.0f, 3.0f);
				paul.render(paulImg);
			glPopMatrix();
		}
	glPopMatrix();
}
void Objects::musicObjectLights()
{
	glPushMatrix();
		light.cloudSpotLight();
	glPopMatrix();

	glPushMatrix();
		light.chihiroSpotLight();
	glPopMatrix();

	glPushMatrix();
		light.gokuSpotLight();
	glPopMatrix();

	glPushMatrix();
		light.chiefSpotLight();
	glPopMatrix();
}
void Objects::tinyStencilObjects()
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();
		glTranslatef(-17, 0.0f, 0.0f);
		glScalef(0.02f, 0.02f, 0.02f);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		cloud.render(cloudImg);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,-0.1f, -17.0f);
		glScalef(0.3f, 0.3f, 0.3f);
		chihiro.render(chihiroImg);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 17.0f);
		glScalef(3.0f, 3.0f, 3.0f);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
		halo.render(haloImg);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.0f, 0.0f, 0.0f);
		glScalef(4.0f, 4.0f, 4.0f);
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		goku.render(gokuImg);
	glPopMatrix();
}
void Objects::stencilCloud(GLfloat rotateY)
{
glClear(GL_STENCIL_BUFFER_BIT);
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
glEnable(GL_STENCIL_TEST);
glStencilFunc(GL_ALWAYS, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
glDisable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);

	glPushMatrix();
		glTranslatef(-133.0f, 0.0f, 0.0f);
			glBegin(GL_QUADS);
				glVertex3f(0.0f, 14.0f, 6.0f);
				glVertex3f(0.0f, 0.0f, 6.0f);
				glVertex3f(0.0f, 0.0f, -6.0f);
				glVertex3f(0.0f, 14.0f, -6.0f);
			glEnd();
	glPopMatrix();

glDisable(GL_CULL_FACE);
glEnable(GL_DEPTH_TEST);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
glStencilFunc(GL_EQUAL, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
		glTranslatef(-135.0f, 0.0f, 0.0f);
		glScalef(-0.07f, 0.07f, 0.07f);
		glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
		cloud.render(cloudImg);
	glPopMatrix();

glDisable(GL_STENCIL_TEST);
glEnable(GL_BLEND);
glDisable(GL_LIGHTING);
glEnable(GL_LIGHTING);
glDisable(GL_BLEND);

	glPushMatrix();
		glTranslatef(-124.0f, 0.0f, 0.0f);
		glScalef(0.07f, 0.07f, 0.07f);
		glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
		cloud.render(cloudImg);
	glPopMatrix();
}
void Objects::stencilGoku(GLfloat rotateY)
{
glClear(GL_STENCIL_BUFFER_BIT);
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
glEnable(GL_STENCIL_TEST);
glStencilFunc(GL_ALWAYS, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
glDisable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);

	glPushMatrix();
		glTranslatef(133.0f, 0.0f, 0.0f);
			glBegin(GL_QUADS);
				glVertex3f(0.0f, 14.0f, -6.0f);
				glVertex3f(0.0f, 0.0f, -6.0f);
				glVertex3f(0.0f, 0.0f, 6.0f);
				glVertex3f(0.0f, 14.0f, 6.0f);
			glEnd();
	glPopMatrix();

glDisable(GL_CULL_FACE);
glEnable(GL_DEPTH_TEST);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
glStencilFunc(GL_EQUAL, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
		glTranslatef(135.0f, 0.0f, 0.0f);
		glScalef(15.0f, 15.0f, -15.0f);
		glRotatef(180, 0.0f, 1, 0.0f);
		glRotatef(rotateY, 0, 1, 0);
		goku.render(gokuImg);
	glPopMatrix();

glDisable(GL_STENCIL_TEST);
glEnable(GL_BLEND);
glDisable(GL_LIGHTING);
glEnable(GL_LIGHTING);
glDisable(GL_BLEND);

	glPushMatrix();
		glTranslatef(124.0f, 0.0f, 0.0f);
		glScalef(15.0f, 15.0f, 15.0f);
		glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
		goku.render(gokuImg);
	glPopMatrix();
}
void Objects::stencilChihiro(GLfloat rotateY)
{
glClear(GL_STENCIL_BUFFER_BIT);
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
glEnable(GL_STENCIL_TEST);
glStencilFunc(GL_ALWAYS, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
glDisable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glPushMatrix();
		glTranslatef(0.0f, -0.5f, -133.0f);
			glBegin(GL_QUADS);
				glVertex3f(-12.0f, 12.0f, 0.0f);
				glVertex3f(-12.0f, -12.0f, 0.0f);
				glVertex3f(12.0f, -12.0f, 0.0f);
				glVertex3f(12.0f, 12.0f, 0.0f);
			glEnd();
	glPopMatrix();

glDisable(GL_CULL_FACE);
glEnable(GL_DEPTH_TEST);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
glStencilFunc(GL_EQUAL, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glPushMatrix();
		glTranslatef(0.0f, -0.5f, -135.0f);
		glScalef(-0.7f, 0.7f, 0.7f);
		glRotatef(180, 0.0f, 1.0f, 0.0f);
		glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
		chihiro.render(chihiroImg);
	glPopMatrix();

glDisable(GL_STENCIL_TEST);
glEnable(GL_BLEND);
glDisable(GL_LIGHTING);
glEnable(GL_LIGHTING);
glDisable(GL_BLEND);

	glPushMatrix();
		glTranslatef(0.0f, -0.5f, -128.0f);
		glScalef(0.7, 0.7, 0.7);
		glRotatef(rotateY, 0, 1, 0);
		chihiro.render(chihiroImg);
	glPopMatrix();
}
void Objects::stencilHalo(GLfloat rotateY)
{

glClear(GL_STENCIL_BUFFER_BIT);
glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
glEnable(GL_STENCIL_TEST);
glStencilFunc(GL_ALWAYS, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
glDisable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 133.0f);
			glBegin(GL_QUADS);
				glVertex3f(12, 12, 0);
				glVertex3f(12, -12, 0);
				glVertex3f(-12, -12, 0);
				glVertex3f(-12, 12, 0);
			glEnd();
	glPopMatrix();

glDisable(GL_CULL_FACE);
glEnable(GL_DEPTH_TEST);
glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
glStencilFunc(GL_EQUAL, 1, 1);
glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
		glTranslatef(0, 0, 136);
		glScalef(-10, 10, 10);
		glRotatef(-90, 1, 0, 0);
		glRotatef(180, 0, 0,1);
		glRotatef(rotateY, 0, 0, 1);
		halo.render(haloImg);
	glPopMatrix();

glDisable(GL_STENCIL_TEST);
glEnable(GL_BLEND);
glDisable(GL_LIGHTING);
glEnable(GL_LIGHTING);
glDisable(GL_BLEND);

	glPushMatrix();
		glTranslatef(0, 0, 128);
		glScalef(10, 10, 10);
		glRotatef(-90, 1, 0, 0);
		glRotatef(rotateY, 0, 0, 1);
		halo.render(haloImg);
	glPopMatrix();
}
void Objects::musicObjects(GLfloat rotateY)
{
	tinyStencilObjects();
	musicObjectLights();
	stencilGoku(rotateY);
	stencilCloud(rotateY);
	stencilChihiro(rotateY);
	stencilHalo(rotateY);
}
void Objects::renderWorld(GLfloat shoulder, GLfloat elbow, GLfloat atten, GLfloat rotation, GLfloat rotateY, GLfloat wavez)
{
	arm(shoulder, elbow);
	light.worldAmbient();
	ground();
	firePit(atten);
	fence();
	grass();
	log();
	trees();
	paulOverseers();
	floatingPaul(rotation, wavez);
	musicObjects(rotateY);
}
void Objects::stencilWorld(GLfloat shoulder, GLfloat elbow, GLfloat atten, GLfloat rotation, GLfloat rotateY, GLfloat wavez)
{

	glClear(GL_STENCIL_BUFFER_BIT);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glPushMatrix();
		glTranslatef(0.0f, 150.0f, 0.0f);
		glBegin(GL_QUADS);
			glVertex3f(400, 0, -400);
			glVertex3f(400, 0, 400);
			glVertex3f(-400, 0, 400);
			glVertex3f(-400, 0, -400);
		glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glEnable(GL_BLEND);
	glColor4f(0.0, 0.0, 1.0, 0.2);
	glPushMatrix();
		
		glTranslatef(0, 200, 0);
		glRotatef(180, 1, 0, 0);
		arm(shoulder, elbow);
		ground();
		firePit(atten);
		fence();
		grass();
		log();
		trees();
		paulOverseers();
		floatingPaul(rotation, wavez);
		musicObjects(rotateY);

	glPopMatrix();
	glDisable(GL_BLEND);

	glDisable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);



	arm(shoulder, elbow);
	light.worldAmbient();
	ground();
	firePit(atten);
	glEnable(GL_BLEND);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	ladder();
	glDisable(GL_BLEND);
	fence();
	grass();
	log();
	trees();
	paulOverseers();
	floatingPaul(rotation, wavez);
	musicObjects(rotateY);
	
	glPopMatrix();
}

















