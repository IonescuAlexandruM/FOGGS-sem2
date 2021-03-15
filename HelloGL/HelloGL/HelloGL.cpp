#include "HelloGL.h"
#include "GlutCallbacks.h"




HelloGL::HelloGL(int argc, char* argv[])
{
	
	InitGL(argc, argv);
	InitObjects();
	
	glutMainLoop();



}

void HelloGL::InitObjects()
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
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube24.txt");
	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	Texture2D* texture_cube = new Texture2D();
	texture_cube->Load((char*)"Penguins.raw", 512, 512);




	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh, texture_cube, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	for(int i=500;i<1000;i++)
	{
		objects[i]=new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f,((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	
}

void HelloGL::InitGL(int argc, char* argv[])
{
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
	glEnable(GL_TEXTURE_2D); // without this you will just get white boxes
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	

	glutSwapBuffers();
	glFlush();


}



void HelloGL::Update()
{
	//reset modelview before each frame
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();

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
		delete objects[i];
	}
}