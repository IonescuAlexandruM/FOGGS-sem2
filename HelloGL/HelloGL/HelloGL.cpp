#include "HelloGL.h"
#include "GlutCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	DrawRightTrig();
	DrawScaleneTrig();
	DrawIsoscelesTrig();
	DrawAcuteTrig();
	DrawObtuseTrig();
	DrawEquilateralTrig();
	glFlush();

}
void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, 0.25);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, 0.25);

		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0.25, -0.25);

		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.25, -0.25);


		glEnd();
	};
}

void HelloGL::DrawRightTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.5, 0.5);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.75, 0.75);

		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0.5, 0.75);

		glEnd();
	};
}

void HelloGL::DrawScaleneTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, 0.5);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.75);

		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.3, 0.6);

		glEnd();
	};
}
void HelloGL::DrawIsoscelesTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, -0.833);

		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, -0.2);

		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.25, -0.2);

		glEnd();
	};
}
void HelloGL::DrawEquilateralTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, 0.633);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.2);

		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.25, 0.2);

		glEnd();
	};
}
void HelloGL::DrawAcuteTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, -0.3);

		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.2, -0.75);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, -0.65);

		glEnd();
	};
}
void HelloGL::DrawObtuseTrig()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.5, -0.5);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.35, -0.75);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.8, -0.6);

		glEnd();
	};
}

HelloGL::~HelloGL(void)
{

}