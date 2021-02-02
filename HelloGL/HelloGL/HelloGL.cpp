#include "HelloGL.h"
#include "GlutCallbacks.h"
Vertex HelloGL::vertices[] =
{ 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)
-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)
1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)
-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0
-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)
-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1
-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)
1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7
1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)
-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4
Color HelloGL::colors[] =
{ 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)
1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)
0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)
0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0
1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)
0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1
0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)
1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7
0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)
0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4


HelloGL::HelloGL(int argc, char* argv[])
{
	//initialize of variables
	rotation = 0;
	rotationPolygon = 0;
	rotationRightTrig = 0;
	rotationScaleneTrig = 0;
	rotationIsoscelesTrig = 0;
	rotationEquilateralTrig = 0;
	rotationAcuteTrig = 0;
	rotationObtuseTrig = 0;
	camera = new Camera();
	//camera->eye.x = 0.0f;
	//camera->eye.y = 0.0f;
	//camera->eye.z = 1.0f;
	camera->eye.x = 5.0f;
	camera->eye.y = 5.0f;
	camera->eye.z = -5.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;




	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	//Set the correct perspective
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	/*DrawPolygon();
	DrawRightTrig();
	DrawScaleneTrig();
	DrawIsoscelesTrig();
	DrawAcuteTrig();
	DrawObtuseTrig();
	DrawEquilateralTrig();*/
	
	glPushMatrix();
	glTranslatef(0.2f, 0.2f, 0.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glutWireTeapot(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2f, -0.2f, -0.0f);
	glutWireSphere((0.1), (100), (10));
	glPopMatrix();

	DrawCube();


	/*glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
	glutWireIcosahedron();
	glutWireOctahedron();
	glutWireTetrahedron();
	glutWireDodecahedron();
	glutWireCone(GLdouble radius, GLdouble height, GLint slices, GLint stacks);
	glutWireTeapot(GLdouble size);*/

	glutSwapBuffers();
	glFlush();


}



void HelloGL::Update()
{
	//reset modelview before each frame
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);


	glutPostRedisplay();
	//Sleep(20);
	

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

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		camera->center.x += 0.1f;
 if (key == 'a')
		camera->center.x -= 0.1f;
	 if (key == 'w')
		camera->eye.z -= 0.1f;
	 if (key == 's')
		camera->eye.z += 0.1f;

	if (key == 'q')
		rotation += 0.8;

	if (key == 'e')
		rotation -= 0.8;

}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	// face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	// face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glEnd();

}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
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
	glTranslatef(0.6f, 0.6f, -5.0f);
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
	glTranslatef(0.0f, 0.6f, -5.0f);
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
	glTranslatef(-0.6f, -0.4f, -5.0f);
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
	glTranslatef(-0.6f, 0.6f, -5.0f);
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
	glTranslatef(0.0f, -0.6f, -5.0f);
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
	glTranslatef(0.6f, -0.6f, -5.0f);
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
	delete camera;
}