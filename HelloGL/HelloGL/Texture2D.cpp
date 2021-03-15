#include "Texture2D.h"
#include <iostream>
#include <fstream>
using namespace std;

Texture2D::Texture2D()
{

}


Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int FileSize;
	ifstream inFile;
	_width = width;
	_height = height;
	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		cerr << "Can't open texture file " << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end);//seek for end of file
	FileSize = (int)inFile.tellg();
	tempTextureData = new char[FileSize];//create new array to store data
	inFile.seekg(0, ios::beg);//seek for beginning of file
	inFile.read(tempTextureData, FileSize);
	inFile.close();

	cout << path << " loaded." << endl;

	glGenTextures(1, &_ID);//get the next texture
	glBindTexture(GL_TEXTURE_2D, _ID);//bind the texture to the ID
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);//specify details of the image
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	delete[] tempTextureData;//clear the data
	return true;
}