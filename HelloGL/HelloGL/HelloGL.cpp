#include "HelloGL.h"
#include "GlutCallbacks.h"




HelloGL::HelloGL(int argc, char* argv[])
{
	//calls the initialization funtions
	InitGL(argc, argv);
	InitObjects();
	InitLight();
	InitOBJmodels();

	
	glutMainLoop();
}

void HelloGL::InitObjects()
{
	//initialize variables
	camera = new Camera();
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 50.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;
	//loading object from file
	Mesh* cubeMesh = MeshLoader::Load((char*)"cubeNormals.txt");
	//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	//applying texture for the object from file
	Texture2D* texture_cube1 = new Texture2D();
	texture_cube1->Load((char*)"Penguins.raw", 512, 512);


	//creating the objects 
	for (int i = 0; i < 100; i++)
	{
		objects[i] = new Cube(cubeMesh, texture_cube1, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}	
}

void HelloGL::InitGL(int argc, char* argv[])
{
	//initialize the window
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

	//Enable textures, depth test, back face culling, lights
	glEnable(GL_TEXTURE_2D); 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMAL_ARRAY);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);
}

void HelloGL::InitLight()
{
	//initialize lights position
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 1.0;

	//initialize ambient light, diffuse light, specular light
	_lightData = new Lighting();
	_lightData->Ambient.x = 0.8f;
	_lightData->Ambient.y = 0.2f;
	_lightData->Ambient.z = 0.2f;
	_lightData->Ambient.w = 1.0f;
	_lightData->Diffuse.x = 0.6f;
	_lightData->Diffuse.y = 0.8f;
	_lightData->Diffuse.z = 0.6f;
	_lightData->Diffuse.w = 1.0f;
	_lightData->Specular.x = 0.2f;
	_lightData->Specular.y = 0.2f;
	_lightData->Specular.z = 0.8f;
	_lightData->Specular.w = 1.0f;
	

}
void HelloGL::InitOBJmodels()
{
	vector<Mesh*>meshes;

	vector<VertexMaster> mesh;
	mesh = loadOBJ("objfiles/cube.obj");
	//meshes.push_back(new Mesh());
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draws the objects on screen 
	for (int i = 0; i < 100; i++)
	{
		objects[i]->Draw();
	}

	//initialize the text
	Vector3 v = { -2.0f, 2.0f,-10.0f };
	Color c = { 1.0f, 1.0f, -1.0f };
	DrawString("OpenGL FOGGs Project", &v, &c);
	

	Vector3 v1 = { -0.5f,-0.2f ,-2.0f};
	Color c1 = { 0.f,0.f,0.f };
	DrawString("Only penguins drawn on cubes", &v1, &c1);


	glutSwapBuffers();
	glFlush();


}



void HelloGL::Update()
{
	//reset modelview before each frame
	glLoadIdentity();

	//camera viewing
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	
	//uses light data 
	glLightf(GL_LIGHT0, GL_AMBIENT, (_lightData->Ambient.x));
	glLightf(GL_LIGHT0, GL_DIFFUSE, (_lightData->Diffuse.x));
	glLightf(GL_LIGHT0, GL_SPECULAR, (_lightData->Specular.x));
	glLightf(GL_LIGHT0, GL_POSITION, (_lightPosition->x));


	//updates the objects
	for (int i = 0; i <100; i++)
	{
		objects[i]->Update();
	}
	
	glutPostRedisplay();

	



}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	//gets user input
	if (key == 'd')
		camera->eye.x += 0.1f;
	if (key == 'a')
		camera->eye.x -= 0.1f;
	if (key == 'w')
		if (camera->eye.z > 0.1)
			camera->eye.z -= 0.1f;
	if (key == 's')
		camera->eye.z += 0.1f;

}



HelloGL::~HelloGL(void)
{
	delete camera;
	for (int i = 0; i < 100; i++)
	{
		delete objects[i];
	}

	delete _lightData;
	delete _lightPosition;
	
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);


	glPopMatrix();
}
