#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"GLUTCallbacks.h"

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

	void Update();

};


