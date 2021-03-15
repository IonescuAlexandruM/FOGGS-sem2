#include "Cube.h"
#include <iostream>
#include <fstream>
using namespace std;


Vertex* Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numColors = 0;
int Cube::numVertices = 0;
int Cube::numIndices = 0;

Cube::Cube(Mesh* mesh,Texture2D* texture, float x, float y, float z) :SceneObject(mesh, texture)
{	
	Update();
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0.0f;
	

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		


		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::Update()
{
	_rotation += rand() % 2;
	if (_rotation >= 360.0f)
		_rotation = 0.0f;
	
}

int Cube::GetPosision_z()
{
	
	return _position.z;

}

void Cube::SetPosition(float z)
{
	_position.z = z;
}



Cube::~Cube()
{
	delete indexedVertices;
	indexedVertices = nullptr;
	
	delete indexedColors;
	indexedColors = nullptr;

	delete indices;
	indices = nullptr;
}