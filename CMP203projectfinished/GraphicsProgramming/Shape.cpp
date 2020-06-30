														/////////////////////////////////////////////////////
														// CODE CREATED BY JAMIE HADDOW 0705082 FOR CMP203 //
														/////////////////////////////////////////////////////


#include "shape.h"
void Shape::calculatefloor(int floorsize, float floor)
{
	// used in the render function for passing into the GL_TRIANGLES vertex count needed
	floorVertexCount = 0;
	//2*pi / how many segments of the floor im using
	float theta = ((2 * 3.1415) / floorsize);
	//setting it to 0 to start off so the first triangle will be on 0 angle
	float Theta2 = 0;
	// r * 2
	float diameter = 2 * floor;
	for (int i = 0; i < floorsize; i++)
	{
		//the 1st vertex which is the origin. x,y,z. each loop we will be calling on this to be our first vertex of 3
		//x
		floorTexcoords.push_back(0.5f);
		floorVerts.push_back(0.0f);
		floorNorms.push_back(0.0f);
		//y
		floorTexcoords.push_back(0.5f);
		floorVerts.push_back(0.0f);
		floorNorms.push_back(0.0f);
		//z
		floorVerts.push_back(0.0f);
		floorNorms.push_back(1.0f);

		//The 2nd vertex in the loop is the origin + the radius to get our first outer coordinate.
		//x
		floorTexcoords.push_back(floor * (cosf(Theta2) / diameter) + 0.5f);
		floorVerts.push_back(floor * (cosf(Theta2)));
		floorNorms.push_back(0.0f);
		//y
		floorTexcoords.push_back(floor * (sinf(Theta2) / diameter) + 0.5f);
		floorVerts.push_back(floor * (sinf(Theta2)));
		floorNorms.push_back(0.0f);
		//z
		floorVerts.push_back(0.0f);
		floorNorms.push_back(1.0f);


		if (Theta2 >= (2 * 3.1415))
		{
			Theta2 = 0;
		}
		//incrementing theta2 so each itteration the angle will increase
		else { Theta2 += theta; };

		//The third vertex is the origin + radius then rotated anti clockwise using the Theta2 variable 
		//x
		floorTexcoords.push_back(floor * (cosf(Theta2) / diameter) + 0.5f);
		floorVerts.push_back(floor * (cosf(Theta2)));
		floorNorms.push_back(0.0f);
		//y
		floorTexcoords.push_back(floor * (sinf(Theta2) / diameter) + 0.5f);
		floorVerts.push_back(floor * (sinf(Theta2)));
		floorNorms.push_back(0.0f);
		//z
		floorVerts.push_back(0.0f);
		floorNorms.push_back(1.0f);
		//adding to the vertex count used for render function
		floorVertexCount += 3;
	}
}
void Shape::renderfloor(GLuint item)
{
//using the second render function from the lab exercise to draw my disc

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, floorVerts.data());
	glNormalPointer(GL_FLOAT, 0, floorNorms.data());
	glTexCoordPointer(2, GL_FLOAT, 0, floorTexcoords.data());

	glBindTexture(GL_TEXTURE_2D, item);
	glColor3f(1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLES, 0, floorVertexCount);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

//I needed to create seperate vertexs for the disc(floor) and the disc(log end) otherwise they conflicted. I could have made a vector of vectors but that was unneccessary for 3 vectors
//used for the 3 logs in the scene around the firepit
void Shape::calculatelogend(int size, float r)
{
	// exatly the same as above disc function so uncommented and condensed
	logVerts.clear();
	logNorms.clear();
	logTexcoords.clear();

	logVertexCount = 0;
	float theta = ((2 * 3.1415) / size);
	float Theta2 = 0;
	float diameter = 2 * r;
	for (int i = 0; i < size; i++)
	{
		logVerts.push_back(0.0f);
		logNorms.push_back(0.0f);
		logTexcoords.push_back(0.5f);
		logVerts.push_back(0.0f);
		logNorms.push_back(0.0f);
		logTexcoords.push_back(0.5f);
		logVerts.push_back(0.0f);
		logNorms.push_back(1.0f);

		logTexcoords.push_back(r * (cosf(Theta2) / diameter) + 0.5f);
		logVerts.push_back(r * (cosf(Theta2)));
		logNorms.push_back(0.0f);
		logTexcoords.push_back(r * (sinf(Theta2) / diameter) + 0.5f);
		logVerts.push_back(r * (sinf(Theta2)));
		logNorms.push_back(0.0f);
		logVerts.push_back(0.0f);
		logNorms.push_back(1.0f);


		if (Theta2 >= (2 * 3.1415))
		{
			Theta2 = 0;
		}
		else { Theta2 += theta; };

		logTexcoords.push_back(r * (cosf(Theta2) / diameter) + 0.5f);
		logVerts.push_back(r * (cosf(Theta2)));
		logNorms.push_back(0.0f);
		logTexcoords.push_back(r * (sinf(Theta2) / diameter) + 0.5f);
		logVerts.push_back(r * (sinf(Theta2)));
		logNorms.push_back(0.0f);
		logVerts.push_back(0.0f);
		logNorms.push_back(1.0f);
		logVertexCount += 3;
	}
}
void Shape::renderlogend(GLuint logimg)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, logVerts.data());
	glNormalPointer(GL_FLOAT, 0, logNorms.data());
	glTexCoordPointer(2, GL_FLOAT, 0, logTexcoords.data());
	glBindTexture(GL_TEXTURE_2D, logimg);
	glDrawArrays(GL_TRIANGLES, 0, logVertexCount);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

// i was having diffiuclty creating the cylinder with triangles and with some support from other students and stackoverflow i was able to create it using quads. 
//Ideally it would have been nice to make this with triangles, however having a triangle AND quad generated shapes at least gave me expereince with both
// i would have like to convert the disc code to this format of using x,y,z in the actual pushbacks as its visually nicer,
//but i also feel that having it more manual allows me to reflect back on the code easier
void Shape::calculateCylinder(int cylindersize, float radius, int h)
{
	//clearing the vectors otherwise they keep growing until the program goes pop and bad things happen with the memory
	cylinderVerts.clear();
	cylinderNorms.clear();
	cylinderTexcoords.clear();
	//again, like above, used for the render function below
	cylinderVertexCount = 0;
	//angle based on the size of the cylinder exactly how we did it for disc
	float theta = ((2 * 3.1415) / cylindersize);
	//the diameter of the circle/cylinder
	float diameter = 2 * radius;
	//used for how tall we make the cylinder
	float height = 0;
	// like we did in the disc
	float Theta2 = 0;


	//used for x,y,z coordinates and u,v f or textures
	float x, y, z, u, v;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < cylindersize; j++) {


			x = radius * cos(Theta2);
			y = height;
			z = radius * sin(Theta2);
			u = ((float)j / cylindersize);
			v = ((float)i / h);

			cylinderVerts.push_back(x);
			cylinderVerts.push_back(y);
			cylinderVerts.push_back(z);
			cylinderNorms.push_back(x);
			cylinderNorms.push_back(y);
			cylinderNorms.push_back(z);
			cylinderTexcoords.push_back(u);
			cylinderTexcoords.push_back(v);

			x = radius * cos(Theta2);
			y = height + 1;
			z = radius * sin(Theta2);
			u = ((float)j / cylindersize);
			v = (((float)i + 1) / h);

			cylinderVerts.push_back(x);
			cylinderVerts.push_back(y);
			cylinderVerts.push_back(z);
			cylinderNorms.push_back(x);
			cylinderNorms.push_back(y);
			cylinderNorms.push_back(z);
			cylinderTexcoords.push_back(u);
			cylinderTexcoords.push_back(v);

			x = radius * cos(Theta2 + theta);
			y = height + 1;
			z = radius * sin(Theta2 + theta);
			u = (((float)j + 1) / cylindersize);
			v = (((float)i + 1) / h);

			cylinderVerts.push_back(x);
			cylinderVerts.push_back(y);
			cylinderVerts.push_back(z);
			cylinderNorms.push_back(x);
			cylinderNorms.push_back(y);
			cylinderNorms.push_back(z);
			cylinderTexcoords.push_back(u);
			cylinderTexcoords.push_back(v);

			x = radius * cos(Theta2 + theta);
			y = height;
			z = radius * sin(Theta2 + theta);
			u = (((float)j + 1) / cylindersize);
			v = ((float)i / h);

			cylinderVerts.push_back(x);
			cylinderVerts.push_back(y);
			cylinderVerts.push_back(z);
			cylinderNorms.push_back(x);
			cylinderNorms.push_back(y);
			cylinderNorms.push_back(z);
			cylinderTexcoords.push_back(u);
			cylinderTexcoords.push_back(v);

			Theta2 += theta;
			cylinderVertexCount += 4;
		}
		//increasing the height of the cylinder
		height += 1;
	}
}

void Shape::renderCylinder(GLuint item)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cylinderVerts.data());
	glNormalPointer(GL_FLOAT, 0, cylinderNorms.data());
	glTexCoordPointer(2, GL_FLOAT, 0, cylinderTexcoords.data());


	glBindTexture(GL_TEXTURE_2D, item);
	glDrawArrays(GL_QUADS, 0, cylinderVertexCount);


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

// function pulling all of these together to create a log used in the scene
void Shape::renderlog(GLuint logimg)
{

	calculatelogend(40, 5.0f);
	calculateCylinder(40, 5, 14);
		glPushMatrix();
			glRotatef(-25, 0, 1, 0);
				glPushMatrix();
					glRotatef(90, 0, 0, 1);
					renderCylinder(logimg);
				glPopMatrix();
				glPushMatrix();
					glRotatef(90, 0, 1, 0);
					renderlogend(logimg);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-14, 0, 0);
					glRotatef(-90, 0, 1, 0);
					renderlogend(logimg);
			glPopMatrix();
		glPopMatrix();
}



