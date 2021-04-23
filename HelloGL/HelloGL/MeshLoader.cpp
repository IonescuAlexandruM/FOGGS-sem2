#include "MeshLoader.h"
#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include<algorithm>
#include"objLoader.h"


using namespace std;

namespace MeshLoader
{


	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadCoordinates(ifstream& inFile, Mesh& mesh);


	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		
		mesh.VertexCount = 8;
		
		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			string line = "";
			string prefix = "";
			stringstream ss;
			int count = 0;
			streampos oldpos;
			while (getline(inFile, line))
			{
				//Get the prefix of the line
				ss.clear();
				ss.str(line);
				ss >> prefix;

				if (prefix == "v")//vertex pos
				{
					ss >> mesh.Vertices[count].x;
					ss >> mesh.Vertices[count].y;
					ss >> mesh.Vertices[count++].z;
					oldpos = inFile.tellg();  // stores the position
				}
				
			if(count>0&& prefix!="v")
			{	
				//inFile.seekg(oldpos); // get back to the position
				break;
			}

			}
			for(int i=0;i<count;i++)
			{
				cout << mesh.Vertices[i].x << " " << mesh.Vertices[i].y << " " << mesh.Vertices[i].z << endl;
			}
		}
	}
	

	void MeshLoader::LoadCoordinates(ifstream& inFile, Mesh& mesh)
	{
		 mesh.TexCoordCount=14;
		if (mesh.TexCoordCount > 0)
		{
			mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

			string line = "";
			string prefix = "";
			stringstream ss;
			int count = 0;
			streampos oldpos;
			while (getline(inFile, line))
			{
				//Get the prefix of the line
				ss.clear();
				ss.str(line);
				ss >> prefix;

				if (prefix == "vt")//vertex pos
				{
					ss >> mesh.TexCoords[count].u;
					ss >> mesh.TexCoords[count++].v;
					oldpos = inFile.tellg();  // stores the position
				}
				
				if (count > 0 && prefix != "vt")
				{
				///	inFile.seekg(oldpos); // get back to the position
					break;
				}
			}
			for (int i = 0; i < count; i++)
			{
				cout << mesh.TexCoords[i].u << " " << mesh.TexCoords[i].v << endl;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		mesh.NormalCount = 6;

		if (mesh.NormalCount > 0)
		{
			mesh.Normals = new Normal[mesh.NormalCount];

			string line = "";
			string prefix = "";
			stringstream ss;
			int count = 0;
			streampos oldpos;
			while (getline(inFile, line))
			{
				//Get the prefix of the line
				ss.clear();
				ss.str(line);
				ss >> prefix;

				if (prefix == "vn")//vertex pos
				{
					ss >> mesh.Normals[count].x;
					ss >> mesh.Normals[count].y;
					ss >> mesh.Normals[count++].z;
					oldpos = inFile.tellg();  // stores the position
				}
				if (count > 0 && prefix != "vn")
				{
					//inFile.seekg(oldpos); // get back to the position
					break;
				}
			}
			for (int i = 0; i < count; i++)
			{
				cout << mesh.Normals[i].x << " " << mesh.Normals[i].y << " " << mesh.Normals[i].z << endl;
			}
			
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		 mesh.IndexCount=108;

		 if (mesh.IndexCount > 0)
		 {
			 mesh.Indices = new GLushort[mesh.IndexCount];
			 string line = "";
			 string prefix = "";
			 stringstream ss;
			 int count = 0;
			 streampos oldpos;
			 while (getline(inFile, line))
			 {
				 //Get the prefix of the line
				 ss.clear();
				 ss.str(line);
				 ss >> prefix;
				 int counter = 0;
				 GLint temp_glint = 0;

				 if (prefix == "f")
				 {
					 
					 while (ss >> temp_glint)
					 {
						
						 //Pushing indices into correct arrays
						 if (counter == 0)
							 mesh.Indices[count++] = temp_glint;
						 else if (counter == 1)
							 mesh.Indices[count++] = temp_glint;
						 else if (counter == 2)
							 mesh.Indices[count++] = temp_glint;
						

						 //Handling characters
						 if (ss.peek() == '/')
						 {
							 ++counter;
							 ss.ignore(1, '/');
						 }
						 else if (ss.peek() == ' ')
						 {
							 ++counter;
							 ss.ignore(1, ' ');
						 }

						 //Reset the counter
						 if (counter > 2)
							 counter = 0;

					 }
					// oldpos = inFile.tellg();  // stores the position
				 }
			 }
			 for (int i = 0; i < count; i++)
			 {
				 cout << mesh.Indices[i] << endl;
			 }
		 }
		
	}
	
	

	Mesh* MeshLoader::Load(char* path )
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;
		streampos oldpos;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		oldpos = inFile.tellg();  // stores the position
		//LOAD DATA USING METHODS ABOVE
		LoadVertices(inFile,*mesh);
		inFile.seekg(oldpos); // get back to the position
		LoadCoordinates(inFile, *mesh);
		inFile.seekg(oldpos); // get back to the position
		LoadNormals(inFile, *mesh);
		inFile.seekg(oldpos); // get back to the position
		LoadIndices(inFile,*mesh);
		
		return mesh;
	}
}