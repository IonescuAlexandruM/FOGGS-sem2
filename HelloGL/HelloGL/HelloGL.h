#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include"GL\freeglut.h"
#include"GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3
{
	float x;
	float y;
	float z;

};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
	
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};



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

	void Update();

};


