#include "HelloGL.h"
#include "GlutCallbacks.h"




HelloGL::HelloGL(int argc, char* argv[])
{
	//initialize of variables
	
	camera = new Camera();
	//camera->eye.x = 0.0f;
	//camera->eye.y = 0.0f;
	//camera->eye.z = 1.0f;
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 1.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;
	Cube::Load((char*)"cube.txt");
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	




	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
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
	gluPerspective(45, 1, 0.01f, 1000);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();



}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}
	

	glutSwapBuffers();
	glFlush();


}



void HelloGL::Update()
{
	//reset modelview before each frame
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
		
	}


	glutPostRedisplay();
	//Sleep(20);
	



}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		camera->eye.x += 0.1f;
 if (key == 'a')
		camera->eye.x -= 0.1f;
	 if (key == 'w')
		camera->eye.z -= 0.1f;
	 if (key == 's')
		camera->eye.z += 0.1f;

	

}



HelloGL::~HelloGL(void)
{
	delete camera;
	for (int i = 0; i < 200; i++)
	{
		delete cube[i];
	}
}