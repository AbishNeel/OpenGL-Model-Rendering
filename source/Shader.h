#pragma once

#include <glad/glad.h>

class Shader
{
public:
	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

	GLuint _ID;

	void Activate();
	void Delete();
	void CompileErrors(unsigned int shader, const char* type);
};