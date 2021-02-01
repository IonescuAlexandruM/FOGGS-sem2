#include "HelloGL.h"
#include "GlutCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotationPolygon = 0;
	rotationRightTrig = 0;
	rotationScaleneTrig = 0;
	rotationIsoscelesTrig = 0;
	rotationEquilateralTrig = 0;
	rotationAcuteTrig = 0;
	rotationObtuseTrig = 0;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
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



void HelloGL::Update()
{
	glutPostRedisplay();
	
	rotationPolygon += 0.5f;
	if (rotationPolygon >= 360.0f)
		rotationPolygon = 0.0f;

	rotationAcuteTrig += 0.8f;
	if (rotationAcuteTrig >= 360.0f)
		rotationAcuteTrig = 0.0f;

	rotationObtuseTrig += 0.1f;
	if (rotationObtuseTrig >= 360.0f)
		rotationObtuseTrig = 0.0f;

	rotationEquilateralTrig += 0.8f;
	if (rotationEquilateralTrig >= 360.0f)
		rotationEquilateralTrig = 0.0f;

	rotationRightTrig += 0.2f;
	if (rotationRightTrig >= 360.0f)
		rotationRightTrig = 0.0f;

	rotationScaleneTrig += 0.5f;
	if (rotationScaleneTrig >= 360.0f)
		rotationScaleneTrig = 0.0f;

	rotationIsoscelesTrig += 0.8f;
	if (rotationIsoscelesTrig >= 360.0f)
		rotationIsoscelesTrig = 0.0f;
}


void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(rotationPolygon, 0.0f, 0.0f, -1.0f);
	
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
	}
	glPopMatrix();
}

void HelloGL::DrawRightTrig()
{
	glPushMatrix();
	glTranslatef(0.6f, 0.6f, 0.0f);
	glRotatef(rotationRightTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.25, 0.25);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, -0.25);

		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.25);

		glEnd();
	}
	
	
	glPopMatrix();
	
}

void HelloGL::DrawScaleneTrig()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.6f, 0.0f);
	glRotatef(rotationScaleneTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.1);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.15);

		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.3, 0.0);

		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawIsoscelesTrig()
{
	glPushMatrix();
	glTranslatef(-0.6f, -0.4f, 0.0f);
	glRotatef(rotationIsoscelesTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.0, -0.433);

		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, 0.2);

		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.25, 0.2);

		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawEquilateralTrig()
{
	glPushMatrix();
	glTranslatef(-0.6f, 0.6f, 0.0f);
	glRotatef(rotationEquilateralTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.0, 0.233);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.2);

		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.25, -0.2);

		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawAcuteTrig()
{
	glPushMatrix();
	glTranslatef(0.0f, -0.6f, 0.0f);
	glRotatef(rotationAcuteTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.3);

		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.2, -0.25);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, -0.15);

		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawObtuseTrig()
{
	glPushMatrix();
	glTranslatef(0.6f, -0.6f, 0.0f);
	glRotatef(rotationObtuseTrig, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.0, 0.2);

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.35, -0.05);

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.25, -0.25);

		glEnd();
	}
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{

}