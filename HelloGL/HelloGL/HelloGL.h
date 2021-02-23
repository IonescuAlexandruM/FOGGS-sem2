#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"GLUTCallbacks.h"
#include"Structures.h"
#include "Cube.h"

#define REFRESHRATE 16





class HelloGL
{
private:
	
	Camera* camera;

	Cube* cube[200];


public:
	//constructor
	HelloGL(int argc, char* argv[]);
	//destructor
	~HelloGL(void);

	void Display();

	void Keyboard(unsigned char key, int x, int y);




	void Update();

};


