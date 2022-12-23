#pragma once
#include <glad/glad.h>
#include "Shader.h"

class Texture
{
public:
	Texture(const char* fileName, const char* texType, GLuint slot);

	// Assigns a texture unit to a texture
	void TexUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();

	GLuint _ID;
	const char* _type;

private:
	GLuint _unit;
};