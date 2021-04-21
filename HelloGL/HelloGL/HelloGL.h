#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"GLUTCallbacks.h"
#include"Structures.h"
#include "Cube.h"
#include"Pyramid.h"
#include"SceneObject.h"
#include"MeshLoader.h"
#include "objLoader.h"

#define REFRESHRATE 16


class HelloGL
{
private:
	
	Camera* camera;

	SceneObject* objects[1000];
	Vector4* _lightPosition;
	Lighting* _lightData;

	

public:
	//constructor
	HelloGL(int argc, char* argv[]);
	//destructor
	~HelloGL(void);

	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void Update();

	void InitObjects();
	void InitLight();
	void InitOBJmodels();
	void InitGL(int argc, char* argv[]);
	void DrawString(const char* text, Vector3* position, Color* color);

};


