#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"GLUTCallbacks.h"
#include"Structures.h"

#define REFRESHRATE 16





class HelloGL
{
private:
	float rotationPolygon;
	float rotationRightTrig;
	float rotationScaleneTrig;
	float rotationIsoscelesTrig;
	float rotationEquilateralTrig;
	float rotationAcuteTrig;
	float rotationObtuseTrig;
	float rotation;
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];


public:
	//constructor
	HelloGL(int argc, char* argv[]);
	//destructor
	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void DrawRightTrig();
	void DrawScaleneTrig();
	void DrawIsoscelesTrig();
	void DrawEquilateralTrig();
	void DrawAcuteTrig();
	void DrawObtuseTrig();
	void Keyboard(unsigned char key, int x, int y);
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();



	void Update();

};


