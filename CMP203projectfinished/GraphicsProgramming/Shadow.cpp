										/////////////////////////////////////////////////////
										// CODE USED BY JAMIE HADDOW 0705082 FOR CMP203    //
										/////////////////////////////////////////////////////

#include "Shadow.h"

// For planar shadows. Provide a float shadowmatrix[16] to fill, the light position and the coordinates the describe the floor/geometry to cast the shadow on.
void Shadow::generateShadowMatrix(float* shadowMatrix, float light_pos[4], GLfloat floor[12]) {

	//Defining vertices of plane are PQR with edges PQ and PR
	Vector3 P(floor[0], floor[1], floor[2]);	//top left
	Vector3 Q(floor[3], floor[4], floor[5]);	// bottom left
	Vector3 R(floor[9], floor[10], floor[11]);	// top right

	Vector3 PQ = (Q - P).normalised();
	Vector3 PR = (R - P).normalised();
	Vector3 normal = PR.cross(PQ);

	//Equation of plane is ax + by + cz = d
	//a, b and c are the coefficients of the normal to the plane (i.e. normal = ai + bj + ck)
	//If (x0, y0, z0) is any point on the plane, d = a*x0 + b*y0 + c*z0
	//i.e. d is the dot product of any point on the plane (using P here) and the normal to the plane
	float a, b, c, d;
	a = normal.getX();
	b = normal.getY();
	c = normal.getZ();
	d = normal.dot(P);

	//Origin of projection is at x, y, z. Projection here originating from the light source's position
	float x, y, z;
	x = light_pos[0];
	y = light_pos[1];
	z = light_pos[2];

	//This is the general perspective transformation matrix from a point (x, y, z) onto the plane ax + by + cz = d
	shadowMatrix[0] = d - (b * y + c * z);
	shadowMatrix[1] = a * y;
	shadowMatrix[2] = a * z;
	shadowMatrix[3] = a;

	shadowMatrix[4] = b * x;
	shadowMatrix[5] = d - (a * x + c * z);
	shadowMatrix[6] = b * z;
	shadowMatrix[7] = b;

	shadowMatrix[8] = c * x;
	shadowMatrix[9] = c * y;
	shadowMatrix[10] = d - (a * x + b * y);
	shadowMatrix[11] = c;

	shadowMatrix[12] = -d * x;
	shadowMatrix[13] = -d * y;
	shadowMatrix[14] = -d * z;
	shadowMatrix[15] = -(a * x + b * y + c * z);
}



