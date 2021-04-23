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
	GetMaterial();
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0.0f;
	

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
		glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->Shininess));

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





void Cube::GetMaterial()
{
	_material = new Material();
	_material->Ambient.x = 0.5;
	_material->Ambient.y = 0.5;
	_material->Ambient.z = 0.5;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.5;
	_material->Diffuse.y = 0.5;
	_material->Diffuse.z = 0.5;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0;
	_material->Specular.y = 1.0;
	_material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;
}


Cube::~Cube()
{
	delete indexedVertices;
	indexedVertices = nullptr;

	delete indices;
	indices = nullptr;

	_material = nullptr;
	delete _material;
	
}