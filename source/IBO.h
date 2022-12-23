#pragma once

#include <glad/glad.h>
#include <vector>

class IBO
{
public:
	IBO(std::vector<GLuint>& indices);
	void Bind();
	void Unbind();
	void Delete();

	GLuint _ID;
};