#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"Structures.h"
#include"SceneObject.h"


class Cube: public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;

	GLfloat _rotation;
	Vector3 _position;
	float pos_x, pos_y, pos_z;

	Material* _material;

public:
	Cube(Mesh* mesh,Texture2D* texture,float x,float y,float z);
	~Cube();


	void Draw();
	void Update();
	int GetPosision_z();
	void SetPosition(float z);
	void GetMaterial();
};

