#include "Terrain.h"

Terrain::Terrain(unsigned int texID)
{
	glPushMatrix();

	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texID);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (floor.LoadFile("mars.obj"))
	{
		for (int i = 0; i < floor.LoadedMeshes.size(); i++)
		{
			objl::Mesh curMesh = floor.LoadedMeshes[i];

			for (int j = 0; j < curMesh.Indices.size(); j += 3)
			{
				glBegin(GL_TRIANGLES);

				glTexCoord2d(0, 0);
				glVertex3f(
					curMesh.Vertices[curMesh.Indices[j]].Position.X,
					curMesh.Vertices[curMesh.Indices[j]].Position.Y,
					curMesh.Vertices[curMesh.Indices[j]].Position.Z
				);

				glTexCoord2d(0, 1);
				glVertex3f(
					curMesh.Vertices[curMesh.Indices[j + 1]].Position.X,
					curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y,
					curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z
				);

				glTexCoord2d(1, 0);
				glVertex3f(
					curMesh.Vertices[curMesh.Indices[j + 2]].Position.X,
					curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y,
					curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z
				);
				glEnd();
			}
		}
	}
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}


Terrain::~Terrain()
{
}