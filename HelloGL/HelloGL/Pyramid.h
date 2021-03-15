#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"Structures.h"
#include"SceneObject.h"

class Pyramid:public SceneObject
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;

	GLfloat _rotation;
	Vector3 _position;
	float pos_x, pos_y, pos_z;

public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();


	void Draw();
	void Update();
	int GetPosision_z();
	void SetPosition(float z);

};

