													/////////////////////////////////////////////////////
													// CODE ADDED BY JAMIE HADDOW 0705082 FOR CMP203   //
													/////////////////////////////////////////////////////
																//FINISHED // COMMENTED IN .H
// Below ifdef required to remove warnings for unsafe version of fopen and fscanf.
// Secure version won't work cross-platform, forcing this small hack.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "model.h"


bool Model::load(char* modelFilename)
{
	bool result;

	// Load in the model data,
	result = loadModel(modelFilename);
	if (!result)
	{
		MessageBoxA(NULL, "Model failed to load", "Error", MB_OK);
		return false;
	}
	return true;
}

void Model::render(GLuint item)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &vertex[0]);
	glNormalPointer(GL_FLOAT, 0, &normals[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &texCoords[0]);
	glBindTexture(GL_TEXTURE_2D, item);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}


// Modified from a mulit-threaded version by Mark Ropper.
bool Model::loadModel(char* filename)
{
	// 3 vectors used for storing the models vertexs,normals and texture coordinates
	vector<Vector3> verts;
	vector<Vector3> norms;
	vector<Vector3> texCs;
	//vector of faces for storing the 3 vectors above and allowing the user to access that information
	vector<unsigned int> faces;
	
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		return false;
	}
	while (true)
	{
		char lineHeader[128];

		// Read first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
		{
			break; // exit loop
		}
		else // Parse
		{
			if (strcmp(lineHeader, "v") == 0) // Vertex
			{
				Vector3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				verts.push_back(vertex);
			}
			else if (strcmp(lineHeader, "vt") == 0) // Tex Coord
			{
				Vector3 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				texCs.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0) // Normal
			{
				Vector3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				norms.push_back(normal);
			}
			else if (strcmp(lineHeader, "f") == 0) // Face
			{
				unsigned int face[9];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &face[0], &face[1], &face[2],
																			&face[3], &face[4], &face[5],
																			&face[6], &face[7], &face[8]);
				if (matches != 9)
				{
					// Parser error, or not triangle faces
					return false;
				}
				
				for (int i = 0; i < 9; i++)
				{
					faces.push_back(face[i]);
				}
			}
		}
	}

	// "Unroll" the loaded obj information into a list of triangles.
	// TODO: By this point all model has been read from the file, but is not in the correct order.
	// You NEED to loop over all the data and sort it into a render ready order/format.
	
	for (int i = 0; i < faces.size(); i+= 3)
	{
		//taking the populated verts vector and pushing it into the vertex array
		vertex.push_back(verts[faces[i] -1 ].x);
		vertex.push_back(verts[faces[i] -1 ].y);
		vertex.push_back(verts[faces[i] -1 ].z);
		//taking the populated texCs vector and pushing it into the texCoords array
		texCoords.push_back(texCs[faces[i + 1] - 1].x);
		texCoords.push_back(texCs[faces[i + 1] - 1].y);
		//taking the populated norms vector and pushing it into the normals array
		normals.push_back(norms[faces[i+2] -1 ].x);
		normals.push_back(norms[faces[i+2] -1 ].y);
		normals.push_back(norms[faces[i+2] -1 ].z);
		
		m_vertexCount += 1;
	}
		
	// Once data has been sorted clear read data (which has been copied and are not longer needed).
	verts.clear();
	norms.clear();
	texCs.clear();
	faces.clear();

	return true;
}






