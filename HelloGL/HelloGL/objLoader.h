#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include "Structures.h"

using namespace std;

static vector<VertexMaster> loadOBJ(const char* file_name)
{
	vector<Vector3> vertex_position;
	vector<Vector2> vertex_texcoord;
	vector<Vector3>vertex_normal;
	
	vector<GLint>vertex_position_indices;
	vector<GLint>vertex_texcoord_indices;
	vector<GLint>vertex_normal_indices;

	vector<VertexMaster> vertices;


	 stringstream ss;
	ifstream in_file(file_name);
	string line = "";
	string prefix = "";
	Vector3 temp_vec3;
	Vector2 temp_vec2;
	GLint temp_glint = 0;

	if (!in_file.is_open())
	{
		throw"Error:: OBJLOADER:: Could not open file";
	}



	//Read one line at a time
	while (getline(in_file, line))
	{
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		
		if (prefix == "v")//vertex pos
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_position.push_back(temp_vec3);
		}
		else if (prefix == "vt")
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoord.push_back(temp_vec2);
		}
		else if (prefix == "vn")
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normal.push_back(temp_vec3);
		}
		else if (prefix == "f")
		{
			int counter = 0;
			while (ss >> temp_glint)
			{
				//Pushing indices into correct arrays
				if (counter == 0)
					vertex_position_indices.push_back(temp_glint);
				else if (counter == 1)
					vertex_texcoord_indices.push_back(temp_glint);
				else if (counter == 2)
					vertex_normal_indices.push_back(temp_glint);

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
		}
	
		cout << line << endl;

	}
	//build one big vertex array that includes positions, normals, textures coordonates, and colors
	vertices.resize(vertex_position_indices.size(), VertexMaster());
		//load all indices
		for (size_t i = 0; i < vertices.size(); i++)
		{
			vertices[i].position = vertex_position[vertex_position_indices[i] - 1];
			vertices[i].texcoord = vertex_texcoord[vertex_texcoord_indices[i] - 1];
			vertices[i].normal = vertex_normal[vertex_normal_indices[i] - 1];
		}

			//loaded success
		cout << "OBJ file loaded!" << endl;
		return vertices;
}


