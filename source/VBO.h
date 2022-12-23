#pragma once
#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 normal;
	glm::vec2 textureUV;
};

class VBO
{
public:
	VBO(std::vector<Vertex>& vertices);
	void Bind();
	void Unbind();
	void Delete();

	GLuint _ID;
};

