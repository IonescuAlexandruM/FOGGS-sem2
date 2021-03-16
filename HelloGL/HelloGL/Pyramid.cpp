#include "Pyramid.h"
#include <iostream>
#include <fstream>
using namespace std;


Vertex* Pyramid::indexedVertices = nullptr;
Color* Pyramid::indexedColors = nullptr;
GLushort* Pyramid::indices = nullptr;

int Pyramid::numColors = 0;
int Pyramid::numVertices = 0;
int Pyramid::numIndices = 0;

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) :SceneObject(mesh, nullptr)
{
	Update();
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0.0f;


}

void Pyramid::Draw()
{
	/*if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);



		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

	}*/
}

void Pyramid::Update()
{

}


Pyramid::~Pyramid()
{
	delete indexedVertices;
	indexedVertices = nullptr;

	delete indexedColors;
	indexedColors = nullptr;

	delete indices;
	indices = nullptr;
}